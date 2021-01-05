//
// Created by 이종일 on 2020/12/10.
//

#ifndef SHOWTAP_CORE_LIBRARY_SHOWTAP_OBJECT_H
#define SHOWTAP_CORE_LIBRARY_SHOWTAP_OBJECT_H

#include <vector>

#include <dto/abs_json.h>
#include <dto/showtap/enumerates.h>

#include <extension/estring.h>
#include <display.h>
#include <logger.h>

#define K_OBJECT_POSITION_X "x"
#define K_OBJECT_POSITION_Y "y"
#define K_OBJECT_WIDTH "width"
#define K_OBJECT_HEIGHT "height"
#define K_OBJECT_HIDDEN "isHidden"
#define K_OBJECT_ON "isOn"
#define K_OBJECT_ALPHA "alpha"
#define K_OBJECT_RESOURCE "resource"
#define K_OBJECT_CHILDREN "childs"
#define K_OBJECT_EFFECT "effect"
#define K_OBJECT_OPTION "additionalOption"
#define K_OBJECT_TYPE "showObjectType"


namespace showtap {
    class Object {
    protected:
        Type type;
        std::string tag = UString::UUID();

        double x = 0.0, y = 0.0;
        double width = 0.0, height = 0.0;

        bool isHidden = false;
        bool isOn = false;

        float alpha = 0.0f;

        std::vector<Object *> child;

    public:
        explicit Object(const Type _type = Type::None) : type(_type) {}
        ~Object(){
            child.clear();
        }

        void setCommonAttributes(rapidjson::Value &value);
        void setChildAttrributes(rapidjson::Value &value);

        virtual Object deserialize(rapidjson::Value &value) { return Object(); };

        const char* toString(){
            char buf[256];

            sprintf(buf, "Object: %s", tag.c_str());

            return buf;
        }
    };

    class Tapcon : public Object {
    public:
        Tapcon() : Object(Type::Tapcon){}
        Object deserialize(rapidjson::Value &value) override;
    };

    class Group : public Object {
    public:
        Group() : Object(Type::Group){}
        Object deserialize(rapidjson::Value &value) override;
    };

    class Image : public Object {
    public:
        Image() : Object(Type::Image){}
        Object deserialize(rapidjson::Value &value) override;
    };

    class Video : public Object {
    public:
        Video() : Object(Type::Video){}
        Object deserialize(rapidjson::Value &value) override;
    };

    class Audio : public Object {
    public:
        Audio() : Object(Type::Audio){}
        Object deserialize(rapidjson::Value &value) override;
    };

    class Mark : public Object {
    public:
        Mark() : Object(Type::Mark){}
        Object deserialize(rapidjson::Value &value) override;
    };

    class URL : public Object {
    public:
        URL() : Object(Type::URL){}
        Object deserialize(rapidjson::Value &value) override;
    };

    class Text : public Object {
    public:
        Text() : Object(Type::Text){}
        Object deserialize(rapidjson::Value &value) override;
    };

    class Slide : public Object {
    public:
        Slide() : Object(Type::Slide){}
        Object deserialize(rapidjson::Value &value) override;
    };
}


#endif //SHOWTAP_CORE_LIBRARY_SHOWTAP_OBJECT_H
