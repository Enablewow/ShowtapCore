//
// Created by 이종일 on 2020/12/10.
//

#include <dto/thumbnail_info.h>

using namespace showtap;

bool ThumbnailInfo::deserialize(rapidjson::Value &value) {
    this->name = value[K_THUMB_NAME].GetString();
    this->data = std::stringstream(value[K_THUMB_DATA].GetString());

    return true;
}

bool ThumbnailInfo::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_THUMB_NAME);
    writer->String(this->name.c_str());

    writer->String(K_THUMB_DATA);
    writer->String(this->data.str().c_str());

    writer->EndObject();

    return true;
}

ThumbnailInfo::~ThumbnailInfo() {
    this->data.flush();
}
