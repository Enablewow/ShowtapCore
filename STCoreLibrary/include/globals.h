//
// Created by 이종일 on 2020/12/22.
//

#ifndef SHOWTAP_CORE_LIBRARY_GLOBALS_H
#define SHOWTAP_CORE_LIBRARY_GLOBALS_H

#if defined(PLATFORM_ANDROID)
    const char *root = nullptr;
    const char *path_metadata = nullptr;
#elif defined(PLATFORM_IOS)
    extern const char *root;
    extern const char *path_metadata;
#endif

#endif //SHOWTAP_CORE_LIBRARY_GLOBALS_H
