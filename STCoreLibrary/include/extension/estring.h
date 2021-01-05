//
// Created by 이종일 on 2020/12/11.
//

#ifndef SHOWTAP_CORE_LIBRARY_ESTRING_H
#define SHOWTAP_CORE_LIBRARY_ESTRING_H

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <iomanip>
#include <random>


#define IS_ALNUM(ch) \
            ( ch >= 'a' && ch <= 'z' ) || \
            ( ch >= 'A' && ch <= 'Z' ) || \
            ( ch >= '0' && ch <= '9' ) || \
            ( ch >= '-' && ch <= '.' )

#define REGEX_EXTENSION std::regex("\\.[a-zA-Z0-4]+$")

#define UUID_LENGTH 20

class UString {
    static unsigned int random_char() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        return dis(gen);
    }

public:
    static char* decodeURL(const char* str){

        int i, j = 0, len;
        char* tmp;
        char hex[3];

        len = strlen( str );
        hex[2] = 0;

        tmp = (char*)malloc( sizeof(char) * (len+1) );

        for( i = 0 ; i < len ; i++, j++ ){

            if( str[i] != '%' )
                tmp[j] = str[i];

            else{

                if( IS_ALNUM(str[i+1]) && IS_ALNUM(str[i+2]) && i < (len-2) ){

                    hex[0] = str[i+1];
                    hex[1] = str[i+2];
                    tmp[j] = strtol( hex, nullptr, 16 );

                    i += 2;

                }
                else
                    tmp[j] = '%';

            }

        }
        tmp[j] = 0;

        return tmp;

    }

    static char* encodeURL(const char* str ){

        int i, j = 0, len;

        char* tmp;

        len = strlen( str );
        tmp = (char*) malloc( (sizeof(char) * 3 * len) +1 );

        for( i = 0 ; i < len ; i++ ){

            if( IS_ALNUM( str[i] ) )
                tmp[j] = str[i];

            else{

                snprintf( &tmp[j], 4, "%%%02X\n", (unsigned char)str[i] );
                j += 2;

            }
            j++;

        }
        tmp[j] = 0;
        return tmp;
    }

    static bool endsWith(const std::string &str, const std::string &cmp){
        if (str.length() >= cmp.length()) {
            return (0 == str.compare (str.length() - cmp.length(), cmp.length(), cmp));
        } else {
            return false;
        }
    }

    static bool startsWith(const std::string &str, const std::string &cmp){
        if(str.length() >= cmp.length()){
            return (0 == str.compare(0, cmp.length(), cmp));
        }else{
            return false;
        }
    }

    static std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> result;
        std::stringstream ss (s);
        std::string item;

        while (getline (ss, item, delim)) {
            result.push_back (item);
        }

        return result;
    }

    static int hexToIntColor(std::string const &str){
        if(!startsWith(str, "#")) return 0;

        return std::stoi(str.substr(1, str.size() - 1));
    }

    static int hexToIntColor(const char *str){
        return hexToIntColor(std::string(str));
    }

    static std::string intToHexCode(unsigned int color){
        std::stringstream stream;

        stream << "#" << std::setw(8) << std::setfill('0') << std::hex << color;

        return stream.str();
    }

    static std::string UUID() {
        std::stringstream ss;

        for (auto i = 0; i < UUID_LENGTH; i++) {
            const auto rc = random_char();

            std::stringstream hexstream;

            hexstream << std::hex << rc;

            auto hex = hexstream.str();
            ss << (hex.length() < 2 ? '0' + hex : hex);
        }

        return ss.str();
    }

    static std::string endFrom(const std::string &str, int length){
        return str.substr(str.length() - length, length);
    }

    static const char * boolean(bool state){
        return state ? "true" : "false";
    }

    static char* left_trim(char* szX){
        if(' '==szX[0]) while(' '==(++szX)[0]);
        return szX;
    }

    static char* right_trim(char* szX){
        int i = strlen(szX);
        while(' '==szX[--i]) szX[i] = 0;
        return szX;
    }

    static char* trim(char* szX){
        szX = left_trim(szX);
        szX = right_trim(szX);

        return szX;
    }

    static std::string utf8_substr(const std::string& str, unsigned int start, unsigned int len){
        if (len == 0) return "";

        unsigned int c, i, ix, q, min = std::string::npos, max = std::string::npos;

        for (q=0, i=0, ix=str.length(); i < ix; i++, q++){
            if (q == start) min = i;
            if (q <= start + len || len == std::string::npos) max=i;

            c = (unsigned char) str[i];
            if      (
                //c>=0   &&
                    c<=127) i+=0;
            else if ((c & 0xE0) == 0xC0) i+=1;
            else if ((c & 0xF0) == 0xE0) i+=2;
            else if ((c & 0xF8) == 0xF0) i+=3;
                //else if (($c & 0xFC) == 0xF8) i+=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
                //else if (($c & 0xFE) == 0xFC) i+=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
            else return "";//invalid utf8
        }

        if (q<= start + len || len == std::string::npos){ max=i; }
        if (min==std::string::npos || max==std::string::npos) { return ""; }

        return str.substr(min,max);
    }

    static bool replace(std::string &statement, std::string const &src, std::string const &replacement){
        size_t f = statement.find(src);
        size_t r = f + src.length();

        statement.replace(f, r, replacement);

        return true;
    }

    static std::wstring stows(std::string const &src){
        std::wstring ws;
        ws.assign(src.begin(), src.end());

        return ws;
    }

    static std::string wstos(std::wstring const &src){
        std::string s;
        s.assign(src.begin(), src.end());

        return s;
    }
};

#endif //SHOWTAP_CORE_LIBRARY_ESTRING_H
