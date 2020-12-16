//
// Created by 이종일 on 2020/12/15.
//

#ifndef SHOWTAP_CORE_LIBRARY_EFILE_H
#define SHOWTAP_CORE_LIBRARY_EFILE_H

#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

#include <extension/estring.h>

#define F_COPY_BUFFER 1024 * 8

bool existDirectory(const char*);

/**
 * 파일 경로 문자열에서 파일 이름만 추출하도록 한다. removeExtension 값에 따라 파일이름 전체를 가져올 수 있거나 확장자를 제거한 파일이름을 가져올 수 있다.
 *
 * @param path 파일 경로
 * @param removeExtension 확장자를 포함할지 안할 지. 기본 값은 false 이다.
 * @return 파일 명
 */
std::string getFilenameFromPath(std::string const &path, bool removeExtension = false){
    std::string split = path.substr(path.find_last_of("/\\") + 1);
    if(!removeExtension)
        return split;

    split = split.replace(split.find_last_of('.'), split.size(), "");

    return split;
}

/**
 * Temp Directory 경로 문자열을 가져온다.
 * Root Directory 는 contstant 헤더에 있는 값에 따라 달라진다.
 *
 * @return
 */
std::string getTemporaryDirectory(){
    return std::string(root) + "/temp";
}

/**
 * Temp Directory 에서 해당 쇼탭 파일의 리소스가 풀린 경로 문자열을 가져온다.
 * Root Directory 는 contstant 헤더에 있는 값에 따라 달라진다.
 *
 * @return
 */
std::string getTemporaryStapDirectory(std::string const &filename){
    return getTemporaryDirectory() + "/" + filename;
}

/**
 * 기준 폴더의 하위 폴더를 생성한다.
 * 폴더의 기본 Root Directory 는 constant 헤더에 있는 값에 따라 달라지며, 다른 directory 로도 설정이 가능하다.
 *
 * @param path 생성되는 폴더 경로
 * @param r 기준 Root Directory
 *
 * @return
 */
bool makeDirectory(std::string const &path, std::string const &r = std::string(root)){
    std::string _path = path;
    std::string _rel = _path.replace(0, r.length(), "");

    bool matched = std::regex_search(_rel, REGEX_EXTENSION);
    std::vector<std::string> v = split(_rel, '/');
    if(matched)
        v.erase(v.end() - 1);

    std::string dir = r;

    for(auto iter = v.begin(); iter < v.end() ; iter++){
        if(iter->empty()) continue;

        dir += "/" + *iter;
        const char *_dir = dir.c_str();

        if(!existDirectory(_dir)) mkdir(_dir, S_IRWXU);
    }

    return true;
}

bool existDirectory(const char *path){
    struct stat info{};

    if(stat(path, &info) == -1)
        return false;

    switch(info.st_mode & S_IFMT){
        case S_IFDIR: case S_IFREG : return true;
        default: return true;
    }
}

#endif //SHOWTAP_CORE_LIBRARY_EFILE_H
