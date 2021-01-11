//
// Created by 이종일 on 2020/12/23.
//

#include <cstring>

#define K_RESOURCE_ABSOLUTE_PATH "fileUrlPath"
#define K_RESOURCE_SIZE "fileSize"
#define K_RESOURCE_NAME "fileName"
#define K_RESOURCE_TYPE_CLOUD "cloudType"
#define K_RESOURCE_TEXT "_resourceText"
#define K_RESOURCE_PDF_INDEX "pageIndexInPDF"
#define K_RESOURCE_RELATIVE_PATH "filePath"
#define K_RESOURCE_TYPE_FILE "fileType"
#define K_RESOURCE_FULL_NAME "fileFullName"
#define K_RESOURCE_EXTENSION "fileExtension"


#define K_RESOURCE_N_URL "url"
#define K_RESOURCE_N_STICKER_NAME "sticker"
#define K_RESOURCE_N_COLOR "color"
#define K_RESOURCE_N_TEXT "text"
#define K_RESOURCE_N_SLIDE_TARGET "slide"
#define K_RESOURCE_N_SLIDE_TARGET_ID "id"
#define K_RESOURCE_N_SLIDE_TARGET_INDEX "index"

class Resource : public BaseJson {
    Page *pParent = nullptr;
    Object *oParent = nullptr;

    Owner owner = Owner::None;

    std::string absolutePath;
    std::string relativePath;
    std::string size;
    std::string name;
    std::string nameWithoutExtension;
    std::string extension;

    std::string text;
    std::string sticker;
    std::string url;
    std::string color;

    Link *link = nullptr;

    Ref ref = Ref::None;
    File type = File::Folder;

    int pdfPage = -1;

    void setFileType(const char *ext);
public:
    File getType() const { return type; }

    void setResourceFile(std::string const &path);

    void setPageOwner(Page *p) { pParent = p; owner = Owner::Page; }
    void setObjectOwner(Object *o) { oParent = o; owner = Owner::Object; }

    std::string getResourceText() const { return text; }
    std::string getResourceFileName() const { return name; }

    bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
    bool deserialize(rapidjson::Value &value) override;

    ~Resource(){
        pParent = nullptr;
        oParent = nullptr;

        link = nullptr;
    }
};
