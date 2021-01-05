//
// Created by 이종일 on 2020/12/23.
//

#include <dto/showtap/page.h>

using namespace showtap;

bool Page::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {

    writer->StartObject();

    writer->String(K_PAGE_ID);
    writer->Int64(id);

    writer->String(K_PAGE_HIDDEN);
    writer->Bool(isHidden);

    writer->EndObject();

    return true;
}

bool Page::deserialize(rapidjson::Value &value) {
    id = value[K_PAGE_ID].GetInt64();
    isHidden = value[K_PAGE_HIDDEN].GetBool();

    Resource r;
    r.deserialize(value[K_PAGE_RESOURCE]);

    background = r;

    auto arr = value[K_PAGE_OBJECT].GetArray();
    Object *temp;
    for(auto iter = arr.begin(); iter < arr.end(); iter++){
        temp = new Tapcon();
        temp->deserialize(*iter);

        children.push_back(temp);
    }

    return true;
}

Background Page::getBackgroundType() const {
    switch(background.getType()){
        case File::Image: return Background::Image;
        case File::PDF: return Background::PDF;
        default: return Background::Color;
    }
}