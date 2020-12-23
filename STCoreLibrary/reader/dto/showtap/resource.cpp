//
// Created by 이종일 on 2020/12/23.
//

#include <dto/showtap/resource.h>

using namespace showtap;

bool Resource::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {

    return true;
}

bool Resource::deserialize(rapidjson::Value &value) {
    absolutePath = value[K_RESOURCE_ABSOLUTE_PATH].GetString();
    relativePath = value[K_RESOURCE_RELATIVE_PATH].GetString();

    size = value[K_RESOURCE_SIZE].GetString();

    name = value[K_RESOURCE_FULL_NAME].GetString();
    nameWithoutExtension = value[K_RESOURCE_NAME].GetString();

    ref = Ref(value[K_RESOURCE_TYPE_CLOUD].GetInt());
    type = File(value[K_RESOURCE_TYPE_FILE].GetInt());

    text = value[K_RESOURCE_TEXT].GetString();
    pdfPage = value[K_RESOURCE_PDF_INDEX].GetInt();

    //hasLink = value[K_RESOURCE_LINKED].GetBool();
    //extension = value[K_RESOURCE_EXTENSION].GetString();
    //url = value[K_RESOURCE_URL].GetString();

    return true;
}

