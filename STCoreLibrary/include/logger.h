//
// Created by 이종일 on 2020/12/23.
//

#ifndef SHOWTAP_LIBRARY_LOGGER_H
#define SHOWTAP_LIBRARY_LOGGER_H

#define LOG_BUF 1024
#define LOG_TAG "CoreLibrary"

class Log {
public :
    static void print(const char *format, ...){
        va_list args;
        va_start(args, format);

        char buf[LOG_BUF];

        vsprintf(buf, format, args);

#ifdef PLATFORM
        #if PLATFORM == ANDROID
                    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, buf, nullptr);
                #endif
#endif

        va_end(args);
    }

    static void print(std::string text){
#ifdef PLATFORM
        #if PLATFORM == ANDROID
            __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, text.c_str(), nullptr);
        #endif
#endif
    }
};


#endif //SHOWTAP_LIBRARY_LOGGER_H
