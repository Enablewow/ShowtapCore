//
// Created by 이종일 on 2021/01/06.
//

#include <dto/showtap/include_package.h>

using namespace showtap;

bool Font::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_FONT_STYLE_BOLD);
    writer->Bool(bold);

    writer->String(K_FONT_STYLE_ITALIC);
    writer->Bool(italic);

    writer->String(K_FONT_STYLE_UNDERLINE);
    writer->Bool(underline);

    writer->String(K_FONT_SIZE);
    writer->Int(size);

    writer->String(K_FONT_ALIGN);
    writer->Int(align);

    writer->String(K_FONT_COLOR);
    writer->String(color.c_str());

    writer->String(K_FONT_BACKGROUND);
    background.empty() ? writer->Null() : writer->String(background.c_str());

    writer->String(K_FONT_INFO);
    info.serialize(writer);

    writer->EndObject();

    return true;
}

bool Font::deserialize(rapidjson::Value &value) {

    bold = value[K_FONT_STYLE_BOLD].GetBool();
    italic = value[K_FONT_STYLE_ITALIC].GetBool();
    underline = value[K_FONT_STYLE_UNDERLINE].GetBool();

    size = value[K_FONT_SIZE].GetInt();
    align = value[K_FONT_ALIGN].GetInt();

    color = value[K_FONT_COLOR].GetString();

    if(!value[K_FONT_BACKGROUND].IsNull())
        background = value[K_FONT_BACKGROUND].GetString();

    info.deserialize(value[K_FONT_INFO]);

    return true;
}

bool FontInfo::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_FONT_NAME);
    writer->String(fontName.c_str());

    writer->String(K_FONT_FAMILY_NAME);
    writer->String(familyName.c_str());

    writer->String(K_FONT_FAMILY_NAMES);
    writer->StartArray();

    for(auto &s : familyNames){
        writer->String(s.c_str());
    }

    writer->EndArray();

    writer->EndObject();

    return true;
}

bool FontInfo::deserialize(rapidjson::Value &value) {
    auto arr = value[K_FONT_FAMILY_NAMES].GetArray();
    for(auto &a : arr){
        familyNames.emplace_back(a.GetString());
    }

    familyName = value[K_FONT_FAMILY_NAME].GetString();
    fontName = value[K_FONT_NAME].GetString();

    return true;
}