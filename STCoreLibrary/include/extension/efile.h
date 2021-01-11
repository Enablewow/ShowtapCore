//
// Created by 이종일 on 2020/12/15.
//

#ifndef SHOWTAP_CORE_LIBRARY_EFILE_H
#define SHOWTAP_CORE_LIBRARY_EFILE_H

#include <iostream>

#include <sys/stat.h>
#include <sys/types.h>

#include <regex>

#include <extension/estring.h>
#include <logger.h>

#ifndef REGEX_EXTENSION
    #define REGEX_EXTENSION std::regex("\\.([a-zA-Z0-4]+)$")
#endif

#define F_BUFFER 1024
#define F_COPY_BUFFER (F_BUFFER * 8)
#define F_DIR_PERMISSION 0771

#define F_MAX_LENGTH_FILENAME 256

class UFile {
public :
    /**
     * 파일 경로 문자열에서 파일 이름만 추출하도록 한다. removeExtension 값에 따라 파일이름 전체를 가져올 수 있거나 확장자를 제거한 파일이름을 가져올 수 있다.
     *
     * @param path 파일 경로
     * @param removeExtension 확장자를 포함할지 안할 지. 기본 값은 false 이다.
     * @return 파일 명
     */
    static std::string getFilenameFromPath(std::string const &path, bool removeExtension = false);
    static std::string getExtension(std::string const &name);
    static std::string shortenFilename(std::string const &name);

    /**
     * Temp Directory 경로 문자열을 가져온다.
     *
     * @return
     */
    static std::string getTemporaryDirectory(const std::string &r);

    /**
     * Temp Directory 에서 해당 쇼탭 파일의 리소스가 풀린 경로 문자열을 가져온다.
     *
     * @return
     */
    static std::string getTemporaryStapDirectory(const std::string &r, const std::string &filename);

    /**
     * 기준 폴더의 하위 폴더를 생성한다.
     * 폴더의 기본 Root Directory 는 constant 헤더에 있는 값에 따라 달라지며, 다른 directory 로도 설정이 가능하다.
     *
     * @param path 생성되는 폴더 경로
     *
     * @return
     */
    static bool makeDirectory(std::string const &path, std::string const &r);

    static bool exist(const char *path);
    static bool existDirectory(const char *path);

    static const char* getRelativeDirectoryFromExtension(const char *ext);
};

inline bool isAllowedImage(const char *ext){
    return isEqual(ext, "png") || isEqual(ext, "jpg") || isEqual(ext, "jpeg") || isEqual(ext, "bmp") || isEqual(ext, "ico");
}

inline bool isAllowedVideo(const char *ext){
    return isEqual(ext, "mp4") || isEqual(ext, "avi") || isEqual(ext, "mov");
}

inline bool isAllowedAudio(const char *ext){
    return isEqual(ext, "mp3") || isEqual(ext, "wav");
}

#endif //SHOWTAP_CORE_LIBRARY_EFILE_H
