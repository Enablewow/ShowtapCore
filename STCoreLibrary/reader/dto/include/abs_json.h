//
// Created by 이종일 on 2020/12/10.
//

#ifndef SHOWTAP_CORE_LIBRARY_ABS_JSON_H
#define SHOWTAP_CORE_LIBRARY_ABS_JSON_H

#include <iostream>

#include <rapidjson/writer.h>
#include <rapidjson/fwd.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/document.h>

class BaseJson {
    virtual bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const = 0;
    virtual bool deserialize(rapidjson::Value &value) = 0;

public:
    bool import(std::string json){
        rapidjson::Document d;

        d.Parse(json.c_str());

        return deserialize(d);
    }
};

#endif //SHOWTAP_CORE_LIBRARY_ABS_JSON_H
