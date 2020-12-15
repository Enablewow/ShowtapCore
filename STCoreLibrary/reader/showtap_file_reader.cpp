//
//  showtap_file_reader.cpp
//  STCoreLibrary
//
//  Created by 이종일 on 2020/11/12.
//

#include <showtap_file_reader.hpp>

int FileReader::extract(){
    if(!stream.is_open()) return ERR_FILE_EMPTY;
    if(dest.empty()) return ERR_DESTINATION_EMPTY;

    int f = stream.tellg();
    stream.seekg(0, ios::end);
    int e = stream.tellg();

    int size = e - f;
    stream.seekg(0, ios::beg);

    log("Showtap File Size: %d", size);

    extractBinaryThumbnail();
    extractBinaryResources();

    //stream.close();

    return 0;
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
    //log("Content Size: %d", size);
    stream.seekg(sizeof(unsigned long), ios::cur);

    while(!stream.eof()){
        long nsize = readSize();

        string fname = readString(nsize, true);
        long fsize = readSize();

        if(endsWth(fname, F_EXT_METADATA)){
            log("Metadata File length: %d", fsize);
            string metadatas = readString(fsize);

            log("%s", metadatas.c_str());
        }else{
            log("%s Store file...", fname.c_str());
        }

        stream.seekg(fsize, ios::cur);
    }

    log("Parse end??");
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

    string decoded(url_decode(text.c_str()));

    return decoded;
}

string FileReader::readString(long size, bool decodeBase64) {
    string result = readString(size);

    if(!decodeBase64) return result;

    string decode;
    Base64::Decode(result, decode);

    return decode;
}

