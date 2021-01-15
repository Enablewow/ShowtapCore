//
// Created by 이종일 on 2020/12/10.
//

#include <iostream>
#include <vector>

#define K_OBJECT_POSITION_X "x"
#define K_OBJECT_POSITION_Y "y"
#define K_OBJECT_WIDTH "width"
#define K_OBJECT_HEIGHT "height"
#define K_OBJECT_HIDDEN "isHidden"
#define K_OBJECT_ON "isOn"
#define K_OBJECT_ALPHA "alpha"
#define K_OBJECT_RESOURCE "resource"
#define K_OBJECT_CHILDREN "childs"
#define K_OBJECT_EFFECT "effect"
#define K_OBJECT_FONT "additionalOption"
#define K_OBJECT_TYPE "showObjectType"


class Object : public BaseJson {
    void traversingChangeMediaResource(Object *o, const std::string& orig, const std::string& change);

protected:
    Type type;
    std::string tag = UString::UUID();

    double x = 0.0, y = 0.0;
    double width = 0.0, height = 0.0;

    bool isHidden = false;
    bool isOn = false;

    float alpha = 0.0f;

    std::vector<Object *> children;

    Resource *res = nullptr;
    Font *font = nullptr;
    Effect *effect = nullptr;

public:
    explicit Object(const Type _type = Type::None) : type(_type) {
        effect = new Effect;
    }

    void setCommonAttributes(rapidjson::Value &value);
    void setChildAttrributes(rapidjson::Value &value);
    void changeMediaResource(const std::string &orig, const std::string &change);

    bool serialize(rapidjson::Writer<rapidjson::StringBuffer> *writer) const override;
    bool deserialize(rapidjson::Value &value) override;

    std::string getTag() const { return tag; }

    std::string toString() const {
        std::stringstream ss;

        ss << "Class: " << getClassName() << "\n";
        ss << "Tag: " << tag << "\n";
        ss << "Children: " << children.size() << " Child\n";
        ss << "(";

        for(auto iter = children.begin(); iter < children.end(); iter++){
            ss << (*iter)->getClassName();

            if(children.end() - 1 != iter) ss << ", ";
        }

        ss << ")";

        return ss.str();
    }

    virtual std::string getClassName() const { return "Object"; }

    ~Object(){
        for(auto& a : children){
            delete a;
        }

        children.clear();

        res = nullptr;
        font = nullptr;
        effect = nullptr;
    }
};

class Tapcon : public Object {
public:
    Tapcon() : Object(Type::Tapcon) {}

    std::string getClassName() const override { return "Tapcon"; }
};

class Group : public Object {
public:
    Group() : Object(Type::Group){}

    std::string getClassName() const override { return "Group"; }
};

class Image : public Object, public IMedia {
public:
    Image() : Object(Type::Image){}

    std::string getClassName() const override { return "Image"; }

    void setMediaFile(std::string path) override { res->setResourceFile(path); }
    std::string getMediaName() const override { return res->getResourceFileName(); }
};

class Video : public Object, public IMedia {
public:
    Video() : Object(Type::Video){}

    std::string getClassName() const override { return "Video"; }

    void setMediaFile(std::string path) override { res->setResourceFile(path); }
    std::string getMediaName() const override { return res->getResourceFileName(); }
};

class Audio : public Object, public IMedia {
public:
    Audio() : Object(Type::Audio){}

    std::string getClassName() const override { return "Audio"; }

    void setMediaFile(std::string path) override { res->setResourceFile(path); }
    std::string getMediaName() const override { return res->getResourceFileName(); }
};

class Mark : public Object {
public:
    Mark() : Object(Type::Mark){}

    std::string getClassName() const override { return "Mark"; }
};

class URL : public Object {
public:
    URL() : Object(Type::URL){}

    std::string getClassName() const override { return "URL"; }
};

class Text : public Object {
public:
    Text() : Object(Type::Text){}

    std::string getClassName() const override { return "Text"; }
};

class Slide : public Object {
public:
    Slide() : Object(Type::Slide){}

    std::string getClassName() const override { return "Slide"; }
};
