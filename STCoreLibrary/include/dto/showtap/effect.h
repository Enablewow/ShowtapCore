//
// Created by 이종일 on 2021/01/06.
//

#define K_EFFECT_ANIMATION "motion"
#define K_EFFECT_STROKE "stroke"
#define K_EFFECT_ROUND "round"
#define K_EFFECT_STYLE "viewStyle"
#define K_EFFECT_SOUND "sound"
#define K_EFFECT_VOLUME "soundVolume"
#define K_EFFECT_DIRECTION "direction"
#define K_EFFECT_COLOR "strokeColor"

class Effect : public BaseJson {
    int motion = 0;
    int stroke = 0;
    int round = 0 ;
    int sound = 0;
    double volume = 0.0;
    int direction = 0;

    std::string color;

    //int style = 0;

    public:
        bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
        bool deserialize(rapidjson::Value &value) override;
};
