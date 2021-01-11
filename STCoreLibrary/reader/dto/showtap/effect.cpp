//
// Created by 이종일 on 2021/01/06.
//

#include <dto/showtap/include_package.h>

using namespace showtap;

bool Effect::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_EFFECT_ANIMATION);
    writer->Int(motion);

    writer->String(K_EFFECT_STROKE);
    writer->Int(stroke);

    writer->String(K_EFFECT_ROUND);
    writer->Int(round);

    writer->String(K_EFFECT_SOUND);
    writer->Int(sound);

    writer->String(K_EFFECT_VOLUME);
    writer->Double(volume);

    writer->String(K_EFFECT_DIRECTION);
    writer->Int(direction);

    /*
    writer->String(K_EFFECT_STYLE);
    writer->Int(style);
    */

    writer->String(K_EFFECT_COLOR);
    color.empty() ? writer->Null() : writer->String(color.c_str());

    writer->EndObject();

    return true;
}

bool Effect::deserialize(rapidjson::Value &value) {
    motion = value[K_EFFECT_ANIMATION].GetInt();
    stroke = value[K_EFFECT_STROKE].GetInt();
    round = value[K_EFFECT_ROUND].GetInt();
    direction = value[K_EFFECT_DIRECTION].GetInt();

    sound = value[K_EFFECT_SOUND].GetInt();
    volume = value[K_EFFECT_VOLUME].GetDouble();

    if(!value[K_EFFECT_COLOR].IsNull()){
        color = value[K_EFFECT_COLOR].GetString();
    }

    //style = value[K_EFFECT_STYLE].GetInt();

    return true;
}