//
// Created by 이종일 on 2020/12/23.
//

#ifndef SHOWTAP_LIBRARY_RESOURCE_H
#define SHOWTAP_LIBRARY_RESOURCE_H

#include <dto/abs_json.h>
#include <dto/showtap/enumerates.h>

#include <logger.h>

#define K_RESOURCE_ABSOLUTE_PATH "fileUrlPath"
#define K_RESOURCE_SIZE "fileSize"
#define K_RESOURCE_NAME "fileName"
#define K_RESOURCE_TYPE_CLOUD "cloudType"
#define K_RESOURCE_TEXT "_resourceText"
#define K_RESOURCE_PDF_INDEX "pageIndexInPDF"
#define K_RESOURCE_RELATIVE_PATH "filePath"
#define K_RESOURCE_TYPE_FILE "fileType"
#define K_RESOURCE_FULL_NAME "fileFullName"

// ---- Not Use ---- //
#define K_RESOURCE_LINKED "isLinkConnect"
#define K_RESOURCE_EXTENSION "fileExtension"
#define K_RESOURCE_URL "resourceURL"
// ----------------- //
namespace showtap {
    class Resource : public BaseJson {
        std::string absolutePath;
        std::string relativePath;
        std::string size;
        std::string name;
        std::string nameWithoutExtension;
        std::string text;
        std::string extension;
        std::string url;


        Ref ref = Ref::None;
        File type = File::Folder;

        int pdfPage = -1;

        bool hasLink = false;
    public:
        static const char* directory(Resource &res){
            return "";
        }

        File getType() const { return type; }

        bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
        bool deserialize(rapidjson::Value &value) override;
    };
}

#endif //SHOWTAP_LIBRARY_RESOURCE_H
