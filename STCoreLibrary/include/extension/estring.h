//
// Created by 이종일 on 2020/12/11.
//

#ifndef SHOWTAP_CORE_LIBRARY_ESTRING_H
#define SHOWTAP_CORE_LIBRARY_ESTRING_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <iomanip>
#include <random>

#include <codecvt>

#include <extension/utf8proc.h>

#define IS_ALNUM(ch) \
            ( ch >= 'a' && ch <= 'z' ) || \
            ( ch >= 'A' && ch <= 'Z' ) || \
            ( ch >= '0' && ch <= '9' ) || \
            ( ch >= '-' && ch <= '.' )

#define REGEX_EXTENSION std::regex("\\.[a-zA-Z0-4]+$")

#define UUID_LENGTH 20

class UString {
    static unsigned int random_char();

public:
    static char* decodeURL(const char* str);
    static char* encodeURL(const char* str);

    static bool endsWith(const std::string &str, const std::string &cmp);
    static bool startsWith(const std::string &str, const std::string &cmp);

    static std::vector<std::string> split(const std::string &s, char delim);

    static int hexToIntColor(std::string const &str);
    static int hexToIntColor(const char *str);

    static std::string intToHexCode(unsigned int color);

    static std::string UUID();

    static std::string endFrom(const std::string &str, int length);

    static char* left_trim(char* szX);
    static char* right_trim(char* szX);
    static char* trim(char* szX);

    static std::string utf8_substr(const std::string& str, unsigned int start, unsigned int len);

    static bool replace(std::string &statement, std::string const &src, std::string const &replacement);
    static bool replaceAll(std::string &statement, std::string const &src, std::string const &replacement);

    static std::wstring stows(std::string const &src);
    static std::string wstos(std::wstring const &src);

    static std::string normalizeNFC(std::string const &src);
};

inline const char * boolstring(bool state){
    return state ? "true" : "false";
}

inline bool isEqual(const std::string &a1, const std::string &a2){
    return strcmp(a1.c_str(), a2.c_str()) == 0;
}

#endif //SHOWTAP_CORE_LIBRARY_ESTRING_H
