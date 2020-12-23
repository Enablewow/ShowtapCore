//
// Created by 이종일 on 2020/12/10.
//

#ifndef SHOWTAP_CORE_LIBRARY_SHOWTAP_OBJECT_H
#define SHOWTAP_CORE_LIBRARY_SHOWTAP_OBJECT_H

#include <vector>

#include <dto/abs_json.h>
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


namespace showtap {
    class Object : public BaseJson {
        double x = 0.0, y = 0.0;
        double width = 0.0, height = 0.0;

        bool isHidden = false;
        bool isOn = false;

        float alpha = 0.0f;

        std::vector<Object> child;

    public:
        bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
        bool deserialize(rapidjson::Value &value) override;
    };

    class Tapcon : public Object {};
    class Group : public Object {};
    class Image : public Object {};
    class Video : public Object {};
    class Audio : public Object {};
    class Mark : public Object {};
    class URL : public Object {};
    class Text : public Object {};
    class Slide : public Object {};
}


#endif //SHOWTAP_CORE_LIBRARY_SHOWTAP_OBJECT_H
