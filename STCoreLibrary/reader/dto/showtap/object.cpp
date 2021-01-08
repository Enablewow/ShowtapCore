//
// Created by 이종일 on 2020/12/10.
//

#include <dto/showtap/object.h>

using namespace showtap;

bool Object::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {

    writer->StartObject();

    writer->String(K_OBJECT_TYPE);
    writer->Int(static_cast<int>(type));

    writer->String(K_OBJECT_POSITION_X);
    writer->Double(x);

    writer->String(K_OBJECT_POSITION_Y);
    writer->Double(y);

    writer->String(K_OBJECT_WIDTH);
    writer->Double(width);

    writer->String(K_OBJECT_HEIGHT);
    writer->Double(height);

    writer->String(K_OBJECT_HIDDEN);
    writer->Bool(isHidden);

    writer->String(K_OBJECT_ON);
    writer->Bool(isOn);

    writer->String(K_OBJECT_ALPHA);
    writer->Double(alpha);

    writer->String(K_OBJECT_RESOURCE);
    res == nullptr ? writer->Null() : res->serialize(writer);

    writer->String(K_OBJECT_EFFECT);
    effect.serialize(writer);

    writer->String(K_OBJECT_FONT);
    font == nullptr ? writer->Null() : font->serialize(writer);

    writer->String(K_OBJECT_CHILDREN);
    if(children.empty()) writer->Null();
    else{
        writer->StartArray();

        for(auto &o : children){
            o->serialize(writer);
        }

        writer->EndArray();
    }

    writer->EndObject();

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

    effect.deserialize(value[K_OBJECT_EFFECT]);

    if(!value[K_OBJECT_FONT].IsNull()){
        font = new Font;

        font->deserialize(value[K_OBJECT_FONT]);
    }

    if(!value[K_OBJECT_RESOURCE].IsNull()){
        res = new Resource;

        res->deserialize(value[K_OBJECT_RESOURCE]);
    }
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

void Object::traversingChangeMediaResource(Object *o, const std::string& orig, const std::string& change) {
    if(dynamic_cast<IMedia *>(o) != nullptr){
        auto media = dynamic_cast<IMedia *>(o);

        auto _name = UFile::getFilenameFromPath(orig);
        auto _compare = media->getMediaName();

        //Log::print("Compare: %s %s", _name.c_str(), _compare.c_str());

        if(media->getMediaName() == UFile::getFilenameFromPath(orig))
            media->setMediaFile(change);
    }

    if(children.empty()) return;

    for(auto &child : o->children){
        traversingChangeMediaResource(child, orig, change);
    }
}

void Object::changeMediaResource(const std::string &orig, const std::string &change) {
    traversingChangeMediaResource(this, orig, change);
}


