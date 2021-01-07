//
//  showtap_file_reader.cpp
//  STCoreLibrary
//
//  Created by 이종일 on 2020/11/12.
//

#include <showtap_file_reader.hpp>

int FileReader::extract(){
    if(!stream.is_open() || length == 0) return ERR_EMPTY_FILE;
    if(dest.empty()) return ERR_EMPTY_DESTINATION;

    extractBinaryThumbnail();
    extractBinaryResources();

    //remappingChangedFile();

    return RESULT_OK;
}

void FileReader::extractBinaryThumbnail() {
    long size = readSize();
    string json = readString(size);

    showtap::ThumbnailInfo th;
    th.import(json);
}

void FileReader::extractBinaryResources() {
    // Content Size 는 사용하는 일이 없기 때문에 스킵으로 변경하도록 한다.
    //long size = readSize();
    //print("Content Size: %d", size);
    stream.seekg(sizeof(unsigned long), ios::cur);

    ofstream fos;

    while(isAvaliable()){
        // 파일 이름을 가져온다
        long nsize = readSize();
        string fpath = readString(nsize, true);

        // 파일이름이 너무 길면 파일명을 자른 후 저장소에 저장 한다.
        string origName = UFile::getFilenameFromPath(fpath);
        string newName = UFile::shortenFilename(origName);
        if(origName != newName){
            renameMap[origName] = newName;

            UString::replace(fpath, origName, newName);
        }

        if(UString::startsWith(fpath, "./"))
            fpath = fpath.replace(0, 2, "");

        string fdest = dest + "/" + fpath;

        // 파일의 폴더가 없으면 폴더를 만들어 준다.
        if(!UFile::existDirectory(fdest.c_str()))
            UFile::makeDirectory(fdest, root);

        // 파일 Binary 를 가져온다.
        long fsize = readSize();
        //Log::print("Extract file: %s (ns: %d) size: %d", fpath.c_str(), nsize, fsize);

        bool _exist = UFile::exist(fdest.c_str());

        int flag = _exist ? (ios::in | ios::out) : ios::out;

        fos.open(fdest, flag | ios::binary);
        fos.seekp(0, ios::beg);

        int of = fos.tellp();
        fos.seekp(0, ios::end);
        int oe = fos.tellp();

        fos.seekp(0, ios::beg);

        int osize = oe - of;

        if(osize > 0 && osize == fsize) { // 같은 정보의 데이터라면 저장을 스킵한다.
            stream.seekg(fsize, ios::cur);

            if(UString::endsWith(fpath, F_EXT_METADATA)){
                stringstream ss;
                ss << fos.rdbuf();

                metadata.import(ss.str());

                path_metadata = fdest;
            }
        }else{
            if(UString::endsWith(fpath, F_EXT_METADATA)){
                string metadatas = readString(fsize);

                fos.write(metadatas.c_str(), metadatas.size());
                metadata.import(metadatas);

                path_metadata = fdest;
            }else{
                char buf[F_COPY_BUFFER];

                size_t i = 0, bs = sizeof buf;
                while(i < fsize){
                    if(fsize - i < bs) bs = fsize - i;
                    //Log::print("Size: %d / %d Buffer Size: %d", size, i, bs);

                    stream.read(buf, bs);
                    fos.write(buf, bs);

                    i += bs;
                }

                //print("Extracted");
            }
        }

        fos.close();
    }

    stream.close();
}

long FileReader::readSize() {
    auto *buf = new char[sizeof(long)];
    stream.read(buf, sizeof buf);

    long size =
            (buf[3] << 24) |
            (buf[2] << 16) |
            (buf[1] << 8) |
            (buf[0]);

    //Log::print("Buffer Size: %d Word: %s real size: %ld", sizeof buf, &buf, size);

    delete[] buf;

    return size;
}

string FileReader::readString(long size) {
    stringstream ss;

    char buf[F_COPY_BUFFER];

    size_t i = 0, bs = sizeof buf;
    while(i < size){
        if(size - i < bs) bs = size - i;
        //Log::print("Size: %d / %d Buffer Size: %d", size, i, bs);

        stream.read(buf, bs);
        ss.write(buf, bs);

        i += bs;
    }

    string decoded(UString::decodeURL(ss.str().c_str()));
    ss.flush();

    //Log::print("End: %s", UString::endFrom(decoded, 30).c_str());
    //Log::print("%s ... %s", text.substr(0, 30).c_str(), UString::endFrom(text, 30).c_str());

    return decoded;
}

string FileReader::readString(long size, bool decodeBase64) {
    string result = readString(size);

    if(!decodeBase64) return result;

    string decode = UString::base64_decode(result);
    Base64::Decode(result, decode);

    Log::print("Read String: %s", decode.c_str());

    return decode;
}

void FileReader::remappingChangedFile() {
    if (renameMap.empty()) return;

    for(auto &kv : renameMap){
        metadata.changeMediaResource(kv.first, kv.second);
    }

    /*
    StringBuffer jb;
    Writer<StringBuffer> writer(jb);

    metadata.serialize(&writer);
    string json = jb.GetString();

    ofstream cpy(dest + "/copy.info");
    cpy << jb.GetString();
    cpy.close();
    */
}