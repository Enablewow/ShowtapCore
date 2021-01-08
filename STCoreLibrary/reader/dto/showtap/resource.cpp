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
    absolutePath = UString::normalizeNFC(UString::decodeURL(value[K_RESOURCE_ABSOLUTE_PATH].GetString()));
    relativePath = UString::normalizeNFC(UString::decodeURL(value[K_RESOURCE_RELATIVE_PATH].GetString()));

    size = value[K_RESOURCE_SIZE].GetString();

    name = UString::normalizeNFC(UString::decodeURL(value[K_RESOURCE_FULL_NAME].GetString()));
    nameWithoutExtension = UString::normalizeNFC(UString::decodeURL(value[K_RESOURCE_NAME].GetString()));

    ref = Ref(value[K_RESOURCE_TYPE_CLOUD].GetInt());
    type = File(value[K_RESOURCE_TYPE_FILE].GetInt());

    text = value[K_RESOURCE_TEXT].GetString();
    pdfPage = value[K_RESOURCE_PDF_INDEX].GetInt();

    hasLink = value[K_RESOURCE_LINKED].GetBool();
    extension = value[K_RESOURCE_EXTENSION].GetString();

    if(!value[K_RESOURCE_URL].IsNull())
        url = UString::normalizeNFC(UString::decodeURL(value[K_RESOURCE_URL].GetString()));

    return true;
}

void Resource::setFileType(const char *ext) {
    if(strcmp(ext, "png") || strcmp(ext, "jpg") || strcmp(ext, "jpeg") || strcmp(ext, "bmp") || strcmp(ext, "ico")){
        type = File::Image;
    }
    else if(strcmp(ext, "mp4") || strcmp(ext, "avi") || strcmp(ext, "mov")){
        type = File::Video;
    }
    else if(strcmp(ext, "mp3") || strcmp(ext, "wav")){
        type = File::Audio;
    }
    else if(strcmp(ext, "pdf")){
        type = File::PDF;
    }
    else{
        type = File::ETC;
    }
}

void Resource::setResourceFile(const std::string &path) {
    UString::replace(absolutePath, relativePath, path);

    relativePath = path;
    url = absolutePath;

    name = UFile::getFilenameFromPath(path);
    nameWithoutExtension = UFile::getFilenameFromPath(path, true);

    extension = UFile::getExtension(name);

    setFileType(extension.c_str());
}

