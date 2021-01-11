//
// Created by 이종일 on 2021/01/07.
//

#include <extension/estring.h>


unsigned int UString::random_char() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    return dis(gen);
}

char *UString::decodeURL(const char *str) {
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

char *UString::encodeURL(const char *str) {

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

bool UString::endsWith(const std::string &str, const std::string &cmp) {
    if (str.length() >= cmp.length()) {
        return (0 == str.compare (str.length() - cmp.length(), cmp.length(), cmp));
    } else {
        return false;
    }
}

bool UString::startsWith(const std::string &str, const std::string &cmp) {
    if(str.length() >= cmp.length()){
        return (0 == str.compare(0, cmp.length(), cmp));
    }else{
        return false;
    }
}

std::vector<std::string> UString::split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int UString::hexToIntColor(const std::string &str) {
    if(!startsWith(str, "#")) return 0;

    return (int)std::strtol(str.substr(1, str.size() - 1).c_str(), nullptr, 16);
}

int UString::hexToIntColor(const char *str) {
    return hexToIntColor(std::string(str));
}

std::string UString::intToHexCode(unsigned int color) {
    std::stringstream stream;

    stream << "#" << std::setw(8) << std::setfill('0') << std::hex << color;

    return stream.str();
}

std::string UString::UUID(){
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

std::string UString::endFrom(const std::string &str, int length) {
    return str.substr(str.length() - length, length);
}

char *UString::left_trim(char *szX) {
    if(' '==szX[0]) while(' '==(++szX)[0]);
    return szX;
}

char *UString::right_trim(char *szX) {
    int i = strlen(szX);
    while(' '==szX[--i]) szX[i] = 0;
    return szX;
}

char *UString::trim(char *szX) {
    szX = left_trim(szX);
    szX = right_trim(szX);

    return szX;
}

std::string UString::utf8_substr(const std::string &str, unsigned int start, unsigned int len) {
    if (len == 0) return "";

    unsigned int c, i, ix, q;
    size_t min = std::string::npos, max = std::string::npos;

    for (q=0, i=0, ix=str.length(); i < ix; i++, q++){
        if (q == start) min = i;
        if (q <= start + len || len == (unsigned int) std::string::npos) max = i;

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

    if (q <= start + len || len == (unsigned int)std::string::npos) max = i;
    if (min == std::string::npos || max==std::string::npos) return "";

    return str.substr(min,max);
}

bool UString::replace(std::string &statement, const std::string &src, const std::string &replacement) {
    size_t f = statement.find(src);

    statement.replace(f, src.length(), replacement);
    statement.shrink_to_fit();

    return true;
}

bool UString::replaceAll(std::string &statement, const std::string &src, const std::string &replacement) {
    size_t start_pos = 0;

    while((start_pos = statement.find(src, start_pos)) != std::string::npos) {
        statement.replace(start_pos, src.length(), replacement);
        start_pos += replacement.length(); // Handles case where 'to' is a substring of 'from'
    }

    statement.shrink_to_fit();

    return true;
}

std::wstring UString::stows(const std::string &src) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    return converter.from_bytes(src);
}

std::string UString::wstos(const std::wstring &src) {
    std::string s;
    s.assign(src.begin(), src.end());

    return s;
}

std::string UString::normalizeNFC(const std::string &src) {
    return (const char *)utf8proc_NFC((const uint8_t *)src.c_str());
}
