//
//  constants.hpp
//  STCoreLibrary
//
//  Created by 이종일 on 2020/11/12.
//

#ifndef constants_hpp
#define constants_hpp

#include <iostream>
#include <errors.hpp>
#include <globals.h>

#define ARGS_HELP "help"

#define ARGS_READ "read"
#define ARGS_SAVE "save"

// READ_ARGS
#define ARGS_R_FILE_PATH "-f"
#define ARGS_R_DEST_PATH "-d"
#define ARGS_R_WINDOW_SIZE "-s"

// SAVE_ARGS
#define ARGS_OS "-os"

#define RESULT_OK 0

#define LOG_BUF 1024
#define LOG_TAG "CoreLibrary"

#define F_EXT_METADATA ".info"

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

#endif /* constants_hpp */

