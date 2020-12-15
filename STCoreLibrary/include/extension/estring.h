//
// Created by 이종일 on 2020/12/11.
//

#ifndef SHOWTAP_CORE_LIBRARY_ESTRING_H
#define SHOWTAP_CORE_LIBRARY_ESTRING_H

#include <iostream>
#include <cstdio>
#include <string>

#define IS_ALNUM(ch) \
            ( ch >= 'a' && ch <= 'z' ) || \
            ( ch >= 'A' && ch <= 'Z' ) || \
            ( ch >= '0' && ch <= '9' ) || \
            ( ch >= '-' && ch <= '.' )

char* url_decode( const char* str ){

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

char* url_encode( const char* str ){

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

bool endsWth(const std::string &str, const std::string &cmp){
    if (str.length() >= cmp.length()) {
        return (0 == str.compare (str.length() - cmp.length(), cmp.length(), cmp));
    } else {
        return false;
    }
}


#endif //SHOWTAP_CORE_LIBRARY_ESTRING_H
