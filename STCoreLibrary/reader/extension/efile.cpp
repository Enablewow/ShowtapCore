//
// Created by 이종일 on 2021/01/07.
//

#include <extension/efile.h>

std::string UFile::getFilenameFromPath(const std::string &path, bool removeExtension) {
    std::string split = path.substr(path.find_last_of("/\\") + 1);
    if(!removeExtension)
        return split;

    split = split.replace(split.find_last_of('.'), split.size(), "");

    return split;
}

std::string UFile::getExtension(const std::string &name) {
    std::smatch matched;
    std::regex_search(name, matched, std::regex("\\.([a-zA-Z0-4]+)$"));

    return matched[1].str();
}

std::string UFile::shortenFilename(std::string const &name) {
    if(name.length() < F_MAX_LENGTH_FILENAME) return name;

    std::string newName = UString::utf8_substr(name, 0, 20);
    std::string ext = getExtension(name);

    newName += "_1";
    newName += "." + ext;

    return newName;
}

std::string UFile::getTemporaryDirectory(const std::string &r){
    return r + "/temp";
}

std::string UFile::getTemporaryStapDirectory(const std::string &r, const std::string &filename){
    return getTemporaryDirectory(r) + "/" + filename;
}

bool UFile::makeDirectory(std::string const &path, std::string const &r){
    std::string _path = path;
    std::string _rel = _path.replace(0, r.length(), "");

    bool matched = std::regex_search(_rel, REGEX_EXTENSION);
    std::vector<std::string> v = UString::split(_rel, '/');
    if(matched)
        v.erase(v.end() - 1);

    std::string dir = r;

    for(auto iter = v.begin(); iter < v.end() ; iter++){
        if(iter->empty()) continue;

        dir += "/" + *iter;
        const char *_dir = dir.c_str();

        if(!existDirectory(_dir)) {
            if(mkdir(_dir, F_DIR_PERMISSION) == 0){
                chmod(_dir, F_DIR_PERMISSION);
            }
        }
    }

    return true;
}

bool UFile::exist(const char *path){
    struct stat info{};

    return stat(path, &info) == 0;
}

bool UFile::existDirectory(const char *path){
    struct stat info{};

    if(stat(path, &info) == -1)
        return false;

    switch(info.st_mode & S_IFMT){
        case S_IFDIR: case S_IFREG : return true;
        default: return true;
    }
}

const char *UFile::getRelativeDirectoryFromExtension(const char* ext) {
    if(isAllowedImage(ext)){
        return "image";
    }else if(isAllowedVideo(ext)){
        return "video";
    }else if(isAllowedAudio(ext)){
        return "audio";
    }else if(isEqual(ext, "pdf")){
        return "pdf";
    }

    return "etc";
}
