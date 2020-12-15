//
// Created by 이종일 on 2020/12/10.
//

#include <dto/include/thumbnail_info.h>

bool thumbnail_info::deserialize(rapidjson::Value &value) {
    this->name = value[K_THUMB_NAME].GetString();
    this->data = std::stringstream(value[K_THUMB_DATA].GetString());

    return true;
}

bool thumbnail_info::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_THUMB_NAME);
    writer->String(this->name.c_str());

    writer->String(K_THUMB_DATA);
    writer->String(this->data.str().c_str());

    writer->EndObject();

    return true;
}

thumbnail_info::~thumbnail_info() {
    this->data.flush();
}
