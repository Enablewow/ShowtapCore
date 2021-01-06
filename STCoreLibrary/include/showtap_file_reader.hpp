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
#include <map>

#include <constants.hpp>
#include <base64.h>
#include <logger.h>

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>

#include <extension/efile.h>
#include <extension/estring.h>

#include <dto/thumbnail_info.h>
#include <dto/showtap/metadata.h>

using namespace std;
using namespace macaron;
using namespace rapidjson;

class FileReader {
private:
    ifstream stream;
    int length = 0;

    string dest;
    string path_metadata;

    showtap::Metadata metadata;

    map<string, string> renameMap;

    void extractBinaryThumbnail();
    void extractBinaryResources();
    void remappingChangedFile();

    long readSize();
    string readString(long);
    string readString(long, bool);

    bool isAvaliable(){ return stream.tellg() < length; }

public:
    FileReader(const string& path){
        const char *_path = path.c_str();

        string filename = UFile::getFilenameFromPath(path, true);
        dest = UFile::getTemporaryStapDirectory(filename);

        stream.open(_path, ios_base::in | ios_base::binary);

        int f = stream.tellg();
        stream.seekg(0, ios::end);
        int e = stream.tellg();

        length = e - f;
        stream.seekg(0, ios::beg);
    }
    
    int extract();
    string getMetadataPath() const { return path_metadata; }
};

#endif /* showtap_file_reader_hpp */