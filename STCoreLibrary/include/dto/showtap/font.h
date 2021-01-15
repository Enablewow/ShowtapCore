//
// Created by 이종일 on 2021/01/06.
//
#define K_FONT_STYLE_BOLD "isBold"
#define K_FONT_STYLE_ITALIC "isItalic"
#define K_FONT_STYLE_UNDERLINE "isUnderLine"
#define K_FONT_SIZE "fontSize"
#define K_FONT_ALIGN "fontAlignment"
#define K_FONT_COLOR "fontColor"
#define K_FONT_BACKGROUND "backgroundColor"
#define K_FONT_INFO "font"

#define K_FONT_FAMILY_NAMES "fontFamilyNames"
#define K_FONT_FAMILY_NAME "fontFamilyName"
#define K_FONT_NAME "fontName"

class FontInfo : public BaseJson {
    std::string familyName;
    std::string fontName;

    std::vector<std::string> familyNames;

public:
    bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
    bool deserialize(rapidjson::Value &value) override;
};

class Font : public BaseJson {
    bool bold = false;
    bool italic = false;
    bool underline = false;

    int size = 0;
    int align = 0;

    std::string color;
    std::string background;

    FontInfo *info;

public:
    bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
    bool deserialize(rapidjson::Value &value) override;
};
