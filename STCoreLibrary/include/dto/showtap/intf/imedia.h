//
// Created by 이종일 on 2021/01/07.
//

class IMedia {
public:
    virtual void setMediaFile(std::string path) = 0;
    virtual std::string getMediaName() const = 0;
};
