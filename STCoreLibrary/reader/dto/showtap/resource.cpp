//
// Created by 이종일 on 2020/12/23.
//

#include <dto/showtap/include_package.h>

using namespace showtap;

bool Resource::serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const {
    writer->StartObject();

    writer->String(K_RESOURCE_RELATIVE_PATH);
    writer->String(relativePath.c_str());

    writer->String(K_RESOURCE_SIZE);
    writer->String(size.c_str());

    writer->String(K_RESOURCE_FULL_NAME);
    writer->String(name.c_str());

    writer->String(K_RESOURCE_NAME);
    writer->String(nameWithoutExtension.c_str());

    writer->String(K_RESOURCE_EXTENSION);
    writer->String(extension.c_str());

    writer->String(K_RESOURCE_TYPE_CLOUD);
    writer->Int(static_cast<int>(ref));

    writer->String(K_RESOURCE_TYPE_FILE);
    writer->Int(static_cast<int>(type));

    writer->String(K_RESOURCE_PDF_INDEX);
    writer->Int(pdfPage);

    writer->String(K_RESOURCE_N_TEXT);
    writer->String(text.c_str());

    writer->String(K_RESOURCE_N_STICKER_NAME);
    writer->String(sticker.c_str());

    writer->String(K_RESOURCE_N_SLIDE_TARGET);
    if(link == nullptr) writer->Null();
    else {
        writer->StartObject();

        writer->String(K_RESOURCE_N_SLIDE_TARGET_INDEX);
        writer->Int64(link->index);

        writer->String(K_RESOURCE_N_SLIDE_TARGET_ID);
        writer->Int(link->id);

        writer->EndObject();
    }

    writer->String(K_RESOURCE_N_URL);
    writer->String(url.c_str());

    writer->String(K_RESOURCE_N_COLOR);
    writer->String(color.c_str());

    writer->EndObject();

    return true;
}

bool Resource::deserialize(rapidjson::Value &value) {
    relativePath = UString::normalizeNFC(UString::decodeURL(value[K_RESOURCE_RELATIVE_PATH].GetString()));

    size = value[K_RESOURCE_SIZE].GetString();

    name = UString::normalizeNFC(UString::decodeURL(value[K_RESOURCE_FULL_NAME].GetString()));
    nameWithoutExtension = UString::normalizeNFC(UString::decodeURL(value[K_RESOURCE_NAME].GetString()));
    extension = value[K_RESOURCE_EXTENSION].GetString();

    ref = Ref(value[K_RESOURCE_TYPE_CLOUD].GetInt());
    type = File(value[K_RESOURCE_TYPE_FILE].GetInt());

    pdfPage = value[K_RESOURCE_PDF_INDEX].GetInt();

    if(owner == Owner::Object){
        if(instanceof<Slide>(oParent)){
            link = new Link;

            if(value.HasMember(K_RESOURCE_N_SLIDE_TARGET)){
                auto info = value[K_RESOURCE_N_SLIDE_TARGET].GetObject();

                link->index = info[K_RESOURCE_N_SLIDE_TARGET_INDEX].GetInt();
                link->id = info[K_RESOURCE_N_SLIDE_TARGET_ID].GetInt64();
            }else{
                std::vector<std::string> v = UString::split(value[K_RESOURCE_TEXT].GetString(), '|');

                link->index = stoi(v[0]);
                link->id = strtoll(v[1].c_str(), nullptr, 10);

                v.clear();
            }
        }
        else if(instanceof<URL>(oParent)){
            if(value.HasMember(K_RESOURCE_N_URL)){
                url = value[K_RESOURCE_N_URL].GetString();
            }else{
                url = value[K_RESOURCE_TEXT].GetString();
            }
        }
        else if(instanceof<Text>(oParent)){
            if(value.HasMember(K_RESOURCE_N_TEXT)){
                text = value[K_RESOURCE_N_TEXT].GetString();
            }else{
                text = value[K_RESOURCE_TEXT].GetString();
            }
        }
        else if(instanceof<Mark>(oParent)){
            if(value.HasMember(K_RESOURCE_N_STICKER_NAME)){
                sticker = value[K_RESOURCE_N_STICKER_NAME].GetString();
            }else{
                sticker = value[K_RESOURCE_TEXT].GetString();
            }
        }
    }else if(owner == Owner::Page){
        if(!(getType() == File::Image || getType() == File::PDF)){
            if(value.HasMember(K_RESOURCE_N_COLOR)){
                color = value[K_RESOURCE_N_COLOR].GetString();
            }else{
                color = value[K_RESOURCE_TEXT].GetString();
            }
        }
    }

    return true;
}

void Resource::setFileType(const char *ext) {
    if(isAllowedImage(ext)){
        type = File::Image;
    }
    else if(isAllowedVideo(ext)){
        type = File::Video;
    }
    else if(isAllowedAudio(ext)){
        type = File::Audio;
    }
    else if(isEqual(ext, "pdf")){
        type = File::PDF;
    }
    else{
        type = File::ETC;
    }
}

void Resource::setResourceFile(const std::string &path) {
    relativePath = path;

    name = UFile::getFilenameFromPath(path);
    nameWithoutExtension = UFile::getFilenameFromPath(path, true);

    extension = UFile::getExtension(name);

    setFileType(extension.c_str());
}

