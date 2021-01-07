//
// Created by 이종일 on 2021/01/07.
//

#ifndef SHOWTAP_LIBRARY_IMEDIA_H
#define SHOWTAP_LIBRARY_IMEDIA_H

namespace showtap {
    class IMedia {
    public:
        virtual void setMediaFile(std::string path) = 0;
        virtual std::string getMediaName() const = 0;
    };
}

#endif //SHOWTAP_LIBRARY_IMEDIA_H
