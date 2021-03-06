//
// Created by 이종일 on 2020/12/10.
//

#ifndef SHOWTAP_CORE_LIBRARY_THUMBNAILINFO_H
#define SHOWTAP_CORE_LIBRARY_THUMBNAILINFO_H

#include <iostream>
#include <sstream>

#include <dto/abs_json.h>

#define K_THUMB_DATA "thumbDataString"
#define K_THUMB_NAME "thumbFullName"

namespace showtap {
    class ThumbnailInfo : public BaseJson {
        std::stringstream data;
        std::string name;

    public:
        int length(){ return data.str().size(); }

        bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
        bool deserialize(rapidjson::Value &value) override;

        const char* getName(){ return name.c_str(); }

        virtual ~ThumbnailInfo();
    };
}


#endif //SHOWTAP_CORE_LIBRARY_THUMBNAILINFO_H