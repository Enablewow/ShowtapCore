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

    data = metadata;

    return RESULT_OK;
}

void FileReader::extractBinaryThumbnail() {
    long size = readSize();
    string decoded = readString(size);

    thumbnail_info th;
    th.import(decoded);
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
        if(UString::startsWith(fpath, "./")){
            fpath = fpath.replace(0, 2, "");
        }

        string fdest = dest + "/" + fpath;

        // 파일의 폴더가 없으면 폴더를 만들어 준다.
        if(!UFile::existDirectory(fdest.c_str()))
            UFile::makeDirectory(fdest);

        // 파일 Binary 를 가져온다.
        long fsize = readSize();

        bool _exist = UFile::exist(fdest.c_str());

        //print("Path: %s, Exist %s", fpath.c_str(), _exist ? "true" : "false");

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
        }else{
            if(UString::endsWith(fpath, F_EXT_METADATA)){
                //print("Extract Metadatas");
                string metadatas = readString(fsize);

                fos.write(metadatas.c_str(), metadatas.size());

                metadata.import(metadatas);
            }else{
                //print("Extract file: %s size: %d", fpath.c_str(), fsize);

                int bs = F_COPY_BUFFER;
                long remain = fsize;

                while(remain > 0){
                    if(remain - bs < 0)
                        bs = (int) remain;

                    char buf[bs];

                    stream.read(buf, bs);
                    fos.write(buf, bs);

                    remain -= bs;
                }

                //print("Extracted");
            }
        }

        fos.close();
    }

    stream.close();
}

long FileReader::readSize() {
    unsigned long buf_size;

    stream.get(reinterpret_cast<char *>(&buf_size), sizeof buf_size);
    stream.seekg(1, ios::cur);

    return buf_size & 0xfffffff;
}

string FileReader::readString(long size) {
    char buf;
    string text;

    for(int i=0; i<size; i++){
        stream.get(buf);

        text += buf;
    }

    string decoded(UString::decodeURL(text.c_str()));

    return decoded;
}

string FileReader::readString(long size, bool decodeBase64) {
    string result = readString(size);

    if(!decodeBase64) return result;

    string decode;
    Base64::Decode(result, decode);

    return decode;
}

