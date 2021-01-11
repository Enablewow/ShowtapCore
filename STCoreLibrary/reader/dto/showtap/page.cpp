//
// Created by 이종일 on 2020/12/23.
//

#include <dto/showtap/include_package.h>

using namespace showtap;

bool Page::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_PAGE_ID);
    writer->Int64(id);

    writer->String(K_PAGE_HIDDEN);
    writer->Bool(isHidden);

    writer->String(K_PAGE_RESOURCE);
    background.serialize(writer);

    writer->String(K_PAGE_OBJECT);

    if(children.empty()) writer->Null();
    else{
        writer->StartArray();

        for(auto &tapcon : children){
            tapcon->serialize(writer);
        }

        writer->EndArray();
    }

    writer->EndObject();

    return true;
}

bool Page::deserialize(rapidjson::Value &value) {
    isHidden = value[K_PAGE_HIDDEN].GetBool();

    background.setPageOwner(this);
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

void Page::issueNewId() {
    auto time = std::chrono::system_clock::now();
    auto mill = std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch());

    id = mill.count();
}
