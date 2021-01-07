//
// Created by 이종일 on 2020/12/16.
//

#ifndef SHOWTAP_CORE_LIBRARY_SHOWTAP_METADATA_H
#define SHOWTAP_CORE_LIBRARY_SHOWTAP_METADATA_H

#include <vector>

#include <dto/abs_json.h>
#include <dto/showtap/page.h>

#include <extension/estring.h>
#include <extension/efile.h>

#define K_META_OS "os"
#define K_META_VERSION "version"
#define K_META_RATIO "ratio"
#define K_META_PATH "_localDataPath"
#define K_META_FILENAME "fileName"
#define K_META_SAVED "isSave"
#define K_META_CURRENT_INDEX "currentIndex"
#define K_META_POINTER_INDEX "pointerIndex"
#define K_META_POINTER_SIZE "pointerSize"
#define K_META_BACKGROUND "showBackGroundColor"
#define K_META_PAGES "showTapPages"

namespace showtap {
    class Metadata : public BaseJson {
        std::string name;

#if PLATFORM == ANDROID
        char os = 'A';
#elif PLATFORM == IOS
        char os = 'I';
#else
    char os = 'D';
#endif
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

        std::vector<Page *> pages;

        int background = -1;

    public:
        bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
        bool deserialize(rapidjson::Value &value) override;

        std::string getFilename() const { return name; }
        std::vector<Page *> getPages() const { return pages; }

        double getFileRatio() const { return ratio; }

        int findIndexById(long id) const;
        void changeMediaResource(const std::string &orig, const std::string &change);

        std::string toString() const {
            std::stringstream ss;
            ss << "------ Metadata Info ------\n";
            ss << "File: " << name << "\n";
            ss << "Path: " << path << "\n";
            ss << "Page: " << pages.size() << " Pages\n";
            ss << "-------------\n";

            return ss.str();
        }

        ~Metadata(){
            pages.clear();
        }
    };
}

#endif //SHOWTAP_CORE_LIBRARY_SHOWTAP_METADATA_H