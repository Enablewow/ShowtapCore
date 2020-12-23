//
// Created by 이종일 on 2020/12/10.
//

#include <dto/showtap/object.h>

using namespace showtap;

bool Object::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {

    return true;
}

bool Object::deserialize(rapidjson::Value &value) {
    x = value[K_OBJECT_POSITION_X].GetDouble();
    y = value[K_OBJECT_POSITION_Y].GetDouble();

    width = value[K_OBJECT_WIDTH].GetDouble();
    height = value[K_OBJECT_HEIGHT].GetDouble();

    isHidden = value[K_OBJECT_HIDDEN].GetBool();
    isOn = value[K_OBJECT_ON].GetBool();

    alpha = value[K_OBJECT_ALPHA].GetFloat();

    return true;
}

