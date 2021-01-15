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
#include <locale>
#include <codecvt>
#include <cwchar>

#include <constants.hpp>
#include <base64.h>
#include <logger.h>

#include <rapidjson/document.h>

#include <extension/efile.h>

#include <dto/thumbnail_info.h>

#include <dto/showtap/include_package.h>

using namespace std;
using namespace macaron;
using namespace rapidjson;

namespace showtap {
    class FileReader {
        ifstream stream;
        int length = 0;

        string root;
        string dest;
        string path_metadata;

        showtap::Metadata *metadata;

        map<string, string> renameMap;

        void extractBinaryThumbnail();
        void extractBinaryResources();
        void remappingChangedFile();

        long readSize();
        string readString(long);
        string readString(long, bool);

        bool isAvaliable(){ return stream.tellg() < length; }

    public:
        explicit FileReader(const string& path, const string &r){
            const char *_path = path.c_str();
            root = r;

            Log::print("File: %s", path.c_str());

            string filename = UFile::getFilenameFromPath(path, true);
            dest = UFile::getTemporaryStapDirectory(root, filename);

            stream.open(_path, ios_base::in | ios_base::binary);

            int f = stream.tellg();
            stream.seekg(0, ios::end);
            int e = stream.tellg();

            length = e - f;

            Log::print("Size: %d", length);

            stream.seekg(0, ios::beg);
        }

        int extract();
        string getMetadataPath() const { return path_metadata; }

        ~FileReader(){
            delete metadata;
            metadata = nullptr;

            renameMap.clear();

            if(stream.is_open()){
                stream.close();
            }
        }
    };
}


#endif /* showtap_file_reader_hpp */
