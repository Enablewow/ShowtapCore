//
// Created by 이종일 on 2020/12/23.
//

#ifndef SHOWTAP_LIBRARY_PAGE_H
#define SHOWTAP_LIBRARY_PAGE_H

#include <vector>

#include <dto/abs_json.h>

#include <dto/showtap/enumerates.h>
#include <dto/showtap/resource.h>
#include <dto/showtap/object.h>

#include <sys/time.h>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>

#define K_PAGE_ID "pageId"
#define K_PAGE_HIDDEN "hidden"
#define K_PAGE_RESOURCE "resource"
#define K_PAGE_OBJECT "showObjects"

// ----Not Use---- //
#define K_PAGE_TITLE "title"
#define K_PAGE_COMMENT "comment"
#define K_PAGE_OFFSET_X "x"
#define K_PAGE_OFFSET_Y "y"
#define K_PAGE_OFFSET_WIDTH "width"
#define K_PAGE_OFFSET_HEIGHT "height"
// --------------- //

namespace showtap {
    class Page : public BaseJson, IMedia {
        int64_t id = -1;

        bool isHidden = false;
        Resource background;

        std::vector<Object *> children;

        void issueNewId();

    public:
        Page() { issueNewId(); };
        explicit Page(int64_t _id) : id(_id) {};

        bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
        bool deserialize(rapidjson::Value &value) override;

        int64_t getPageId() const { return id; }
        Background getBackgroundType() const;

        int getChildrenSize() const { return children.size(); }
        std::vector<Object *> getChildren() const { return children; }

        std::string toString() const {
            std::stringstream ss;

            ss << "---- Page Info ----\n";
            ss << "Id: " << id << "\n";
            ss << "Children: " << children.size() << "\n";

            ss << "(";
            for (auto iter = children.begin(); iter < children.end(); iter++){
                ss << (*iter)->getClassName();

                if(children.end() - 1 != iter){
                    ss << ", ";
                }
            }

            ss << ")";

            return ss.str();
        };

        void setMediaFile(std::string path) override {
            if(getBackgroundType() == Background::Color) return;

            background.setResourceFile(path);
        }

        std::string getMediaName() const override {
            return getBackgroundType() == Background::Color ? background.getResourceText() :background.getResourceFileName();
        }
    };
}

#endif //SHOWTAP_LIBRARY_PAGE_H
