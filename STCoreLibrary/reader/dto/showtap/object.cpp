//
// Created by 이종일 on 2020/12/10.
//

#include <dto/showtap/object.h>

using namespace showtap;

void Object::setCommonAttributes(rapidjson::Value &value) {
    double x = value[K_OBJECT_POSITION_X].GetDouble();

    double y = value[K_OBJECT_POSITION_Y].GetDouble();

    double width = value[K_OBJECT_WIDTH].GetDouble();
    double height = value[K_OBJECT_HEIGHT].GetDouble();

    isHidden = value[K_OBJECT_HIDDEN].GetBool();
    isOn = value[K_OBJECT_ON].GetBool();

    alpha = value[K_OBJECT_ALPHA].GetFloat();
}

void Object::setChildAttrributes(rapidjson::Value &value) {
    if(value.IsNull()) return;

    auto arr = value.GetArray();
    Object *c;

    for(auto &a : arr){
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

        child.push_back(c);
    }
}

Object Tapcon::deserialize(rapidjson::Value &value) {
    Tapcon t;

    t.setCommonAttributes(value);
    t.setChildAttrributes(value[K_OBJECT_CHILDREN]);

    return t;
}

Object Group::deserialize(rapidjson::Value &value) {
    Group g;

    g.setCommonAttributes(value);
    g.setChildAttrributes(value[K_OBJECT_CHILDREN]);

    return g;
}

Object Image::deserialize(rapidjson::Value &value) {
    Image i;

    i.setCommonAttributes(value);
    i.setChildAttrributes(value[K_OBJECT_CHILDREN]);

    return i;
}

Object Video::deserialize(rapidjson::Value &value) {
    Video v;

    v.setCommonAttributes(value);

    return v;
}

Object Audio::deserialize(rapidjson::Value &value) {
    Audio a;

    a.setCommonAttributes(value);

    return a;
}

Object Mark::deserialize(rapidjson::Value &value) {
    Mark m;

    m.setCommonAttributes(value);

    return m;
}

Object URL::deserialize(rapidjson::Value &value) {
    URL u;

    u.setCommonAttributes(value);

    return u;
}

Object Text::deserialize(rapidjson::Value &value) {
    Text t;

    t.setCommonAttributes(value);

    return t;
}

Object Slide::deserialize(rapidjson::Value &value) {
    Slide s;

    s.setCommonAttributes(value);

    return s;
}