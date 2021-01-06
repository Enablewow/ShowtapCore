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

    writer->String(K_PAGE_RESOURCE);
    background.serialize(writer);

    writer->EndObject();

    return true;
}

bool Page::deserialize(rapidjson::Value &value) {
    id = value[K_PAGE_ID].GetInt64();
    isHidden = value[K_PAGE_HIDDEN].GetBool();

    background.deserialize(value[K_PAGE_RESOURCE]);

    auto _objs = &value[K_PAGE_OBJECT];
    if(_objs->IsNull()) return true;

    auto arr = _objs->GetArray();

    for(auto iter = arr.begin(); iter < arr.end(); iter++){
        Object *tapcon;

        Type type = Type((*iter)[K_OBJECT_TYPE].GetInt());

        switch(type){
            case Type::Tapcon: tapcon = new Tapcon; break;
            case Type::Group: tapcon = new Group; break;
            default: continue;
        }

        tapcon->deserialize(*iter);
        children.push_back(tapcon);
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