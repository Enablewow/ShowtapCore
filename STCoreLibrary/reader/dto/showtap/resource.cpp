//
// Created by 이종일 on 2020/12/23.
//

#include <dto/showtap/resource.h>

using namespace showtap;

bool Resource::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_RESOURCE_ABSOLUTE_PATH);
    writer->String(absolutePath.c_str());

    writer->String(K_RESOURCE_RELATIVE_PATH);
    writer->String(relativePath.c_str());

    writer->String(K_RESOURCE_SIZE);
    writer->String(size.c_str());

    writer->String(K_RESOURCE_FULL_NAME);
    writer->String(name.c_str());

    writer->String(K_RESOURCE_NAME);
    writer->String(nameWithoutExtension.c_str());

    writer->String(K_RESOURCE_TYPE_CLOUD);
    writer->Int(static_cast<int>(ref));

    writer->String(K_RESOURCE_TYPE_FILE);
    writer->Int(static_cast<int>(type));

    writer->String(K_RESOURCE_TEXT);
    writer->String(text.c_str());

    writer->String(K_RESOURCE_PDF_INDEX);
    writer->Int(pdfPage);

    writer->String(K_RESOURCE_LINKED);
    writer->Bool(hasLink);

    writer->String(K_RESOURCE_EXTENSION);
    writer->String(extension.c_str());

    writer->String(K_RESOURCE_URL);
    url.empty() ? writer->Null() : writer->String(url.c_str());

    writer->EndObject();

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

    hasLink = value[K_RESOURCE_LINKED].GetBool();
    extension = value[K_RESOURCE_EXTENSION].GetString();

    if(!value[K_RESOURCE_URL].IsNull())
        url = value[K_RESOURCE_URL].GetString();

    return true;
}

