//
// Created by 이종일 on 2020/12/16.
//

#ifndef SHOWTAP_CORE_LIBRARY_SHOWTAP_METADATA_H
#define SHOWTAP_CORE_LIBRARY_SHOWTAP_METADATA_H

#include <iostream>
#include <dto/include/abs_json.h>

#define K_META_OS "os"
#define K_META_VERSION "version"
#define K_META_RATIO "ratio"
#define K_META_PATH "_localDataPath"
#define K_META_FILENAME "fileName"
#define K_META_SAVED "isSave"
#define K_META_CURRENT_INDEX "currentIndex"
#define K_META_POINTER_INDEX "pointerIndex"
#define K_META_POINTER_SIZE "pointerSize"
#define K_META_BACKGROUND "showBackgroundColor"
#define K_META_PAGES "showTapPages"

#endif //SHOWTAP_CORE_LIBRARY_SHOWTAP_METADATA_H

class ShowtapMetadata : public BaseJson {
    std::string name;
    char os = 'A';

    double ratio = 0.0;
    int version = 0;

    std::string path;
    bool saved = false;
    bool isCreateNew = true;

    int currentIndex = 0;

    struct {
        int index = 0;
        int size = 0;
    } pointer;

    int background = 0;

public:
    bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
    bool deserialize(rapidjson::Value &value) override;

    std::string getFilename() const { return name; }

    std::string toString();
};
