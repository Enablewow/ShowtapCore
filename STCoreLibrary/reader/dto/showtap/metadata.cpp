//
// Created by 이종일 on 2020/12/16.
//

#include <dto/showtap/metadata.h>

using namespace showtap;

bool Metadata::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_META_VERSION);
    writer->Int(version);

    writer->String(K_META_OS);
    writer->String(std::string(1, os).c_str());

    writer->String(K_META_RATIO);
    writer->Double(ratio);

    writer->String(K_META_PATH);
    writer->String(path.c_str());

    writer->String(K_META_FILENAME);
    writer->String(name.c_str());

    writer->String(K_META_SAVED);
    writer->Bool(saved);

    writer->String(K_META_CURRENT_INDEX);
    writer->Int(currentIndex);

    writer->String(K_META_POINTER_INDEX);
    writer->Int(pointer.index);

    writer->String(K_META_POINTER_SIZE);
    writer->Int(pointer.size);

    writer->String(K_META_BACKGROUND);
    background == -1 ? writer->Null() : writer->String(UString::intToHexCode(background).c_str());

    writer->String(K_META_PAGES);
    writer->StartArray();

    for (auto &page : pages){
        page->serialize(writer);
    }

    writer->EndArray();

    writer->EndObject();

    return true;
}

bool Metadata::deserialize(rapidjson::Value &value) {
    version = value[K_META_VERSION].GetInt();
    os = value[K_META_OS].GetString()[0];

    ratio = value[K_META_RATIO].GetDouble();
    path = value[K_META_PATH].GetString();
    name = value[K_META_FILENAME].GetString();

    saved = value[K_META_SAVED].GetBool();
    currentIndex = value[K_META_CURRENT_INDEX].GetInt();
    pointer.index = value[K_META_POINTER_INDEX].GetInt();
    pointer.size = value[K_META_POINTER_SIZE].GetInt();

    for(auto &a : value[K_META_PAGES].GetArray()){
        Page *_p = new Page;

        _p->deserialize(a);

        pages.push_back(_p);
    }

    background = !value[K_META_BACKGROUND].IsNull() ? UString::hexToIntColor(value[K_META_BACKGROUND].GetString()) : -1;

    return true;
}

int Metadata::findIndexById(long id) const {
    int ret = -1, i = 0;

    for(auto iter = pages.begin(); iter < pages.end(); iter++, i++){
        if((*iter)->getPageId() == id){
            ret = (*iter)->getPageId();

            break;
        }
    }

    return ret;
}