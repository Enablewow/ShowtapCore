//
// Created by 이종일 on 2020/12/10.
//

#include <dto/showtap/object.h>

using namespace showtap;

bool Object::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {

    return true;
}

bool Object::deserialize(rapidjson::Value &value) {
    setCommonAttributes(value);

    if(type == Type::Tapcon || type == Type::Group || type == Type::Image)
        setChildAttrributes(value[K_OBJECT_CHILDREN]);

    return true;
}

void Object::setCommonAttributes(rapidjson::Value &value) {
    x = value[K_OBJECT_POSITION_X].GetDouble();
    y = value[K_OBJECT_POSITION_Y].GetDouble();

    width = value[K_OBJECT_WIDTH].GetDouble();
    height = value[K_OBJECT_HEIGHT].GetDouble();

    isHidden = value[K_OBJECT_HIDDEN].GetBool();
    isOn = value[K_OBJECT_ON].GetBool();

    alpha = value[K_OBJECT_ALPHA].GetFloat();

    if(!value[K_OBJECT_RESOURCE].IsNull()){
        Resource r;
        r.deserialize(value[K_OBJECT_RESOURCE]);

        res = r;
    }

    effect.deserialize(value[K_OBJECT_EFFECT]);
    font.deserialize(value[K_OBJECT_FONT]);
}

void Object::setChildAttrributes(rapidjson::Value &value) {
    if(value.IsNull()) return;

    auto arr = value.GetArray();

    for(auto &a : arr){
        Object *c;

        switch(Type(a[K_OBJECT_TYPE].GetInt())){
            case Type::Tapcon: c = new Tapcon; break;
            case Type::Group: c = new Group; break;
            case Type::Image: c = new Image; break;
            case Type::Audio: c = new Audio; break;
            case Type::Video: c = new Video; break;
            case Type::Mark: c = new Mark; break;
            case Type::Slide: c = new Slide; break;
            case Type::Text: c = new Text; break;
            case Type::URL: c = new URL; break;
            default: continue;
        }

        c->deserialize(a);

        children.push_back(c);
    }
}
