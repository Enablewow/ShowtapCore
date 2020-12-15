//
//  showtap_file_reader.hpp
//  STCoreLibrary
//
//  Created by 이종일 on 2020/11/12.
//

#ifndef showtap_file_reader_hpp
#define showtap_file_reader_hpp

#include <iostream>
#include <fstream>

#include <constants.hpp>
#include <base64.h>

#include <rapidjson/document.h>

#include <extension/estring.h>

#include <dto/include/thumbnail_info.h>

using namespace std;
using namespace macaron;
using namespace rapidjson;

#endif /* showtap_file_reader_hpp */

class FileReader {
private:
    ifstream stream;

    string dest;

    void extractBinaryThumbnail();
    void extractBinaryResources();

    long readSize();
    string readString(long);
    string readString(long, bool);

public:
    FileReader(const string& path){
        const char *_path = path.c_str();
        log("Received path [%s]", _path);

        stream.open(_path, ios_base::binary);
    }

    void setDestination(string dest){
        this->dest = dest;
    }
    
    int extract();
};
