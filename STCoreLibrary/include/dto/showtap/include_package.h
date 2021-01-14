//
// Created by 이종일 on 2021/01/11.
//



#ifndef SHOWTAP_LIBRARY_INCLUDE_PACKAGE_H
#define SHOWTAP_LIBRARY_INCLUDE_PACKAGE_H

#include <extension/efile.h>
#include <extension/estring.h>

#include <base64.h>
#include <display.h>

#include <rapidjson/reader.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stream.h>
#include <rapidjson/encodedstream.h>

#include <dto/abs_json.h>
#include <dto/showtap/enumerates.h>

namespace showtap {
    class IMedia;

    typedef struct{
        int index;
        int64_t id;
    } Link;

    class FontInfo;
    class Font;
    class Effect;

    class Resource;

    class Object;

    class Tapcon;
    class Group;

    class Image;
    class Video;
    class Audio;
    class Mark;
    class Slide;
    class Text;
    class URL;

    class Page;

    class Metadata;

    template <typename Base, class T>
    inline bool instanceof(T *clz){
        return dynamic_cast<const Base *>(clz) != nullptr;
    }

    #include <dto/showtap/intf/imedia.h>
    #include <dto/showtap/font.h>
    #include <dto/showtap/effect.h>
    #include <dto/showtap/resource.h>
    #include <dto/showtap/object.h>
    #include <dto/showtap/page.h>
    #include <dto/showtap/metadata.h>
}

#endif //SHOWTAP_LIBRARY_INCLUDE_PACKAGE_H
