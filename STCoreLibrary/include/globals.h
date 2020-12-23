//
// Created by 이종일 on 2020/12/22.
//

#ifndef SHOWTAP_CORE_LIBRARY_GLOBALS_H
#define SHOWTAP_CORE_LIBRARY_GLOBALS_H

#include <dto/include/showtap_metadata.h>

const char *root = nullptr;
ShowtapMetadata data;

struct Display {
    int width = 0;
    int height = 0;

    double ratio = 0.0;

    bool isVertical() const { return width < height; }
} display;

#endif //SHOWTAP_CORE_LIBRARY_GLOBALS_H
