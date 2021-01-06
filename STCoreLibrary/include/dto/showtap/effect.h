//
// Created by 이종일 on 2021/01/06.
//

#ifndef SHOWTAP_LIBRARY_EFFECT_H
#define SHOWTAP_LIBRARY_EFFECT_H

#include <dto/abs_json.h>

#include <extension/estring.h>

#include <logger.h>

#define K_EFFECT_ANIMATION "motion"
#define K_EFFECT_STROKE "stroke"
#define K_EFFECT_ROUND "round"
#define K_EFFECT_STYLE "viewStyle"
#define K_EFFECT_SOUND "sound"
#define K_EFFECT_VOLUME "soundVolume"
#define K_EFFECT_DIRECTION "direction"
#define K_EFFECT_COLOR "strokeColor"

namespace showtap {
    class Effect : public BaseJson {
        int motion = 0;
        int stroke = 0;
        int round = 0 ;
        int sound = 0;
        double volume = 0.0;
        int direction = 0;

        int color = -1;

        //int style = 0;

        public:
            bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
            bool deserialize(rapidjson::Value &value) override;
    };
}

#endif //SHOWTAP_LIBRARY_EFFECT_H
