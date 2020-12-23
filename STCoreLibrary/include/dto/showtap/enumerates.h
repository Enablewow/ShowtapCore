//
// Created by 이종일 on 2020/12/23.
//

#ifndef SHOWTAP_LIBRARY_ENUMERATES_H
#define SHOWTAP_LIBRARY_ENUMERATES_H


namespace showtap {
    enum class Ref { None = 0, Inner = 1, ICloud = 2, Dropbox = 3, GoogleDrive = 4, OneDrive = 5, Gallery = 6, FileApp = 7 };
    enum class File { Folder = 0, Showtap = 1, PDF = 2, Image = 3, Video = 4, Audio = 5, ETC = 6, Temp = 7 };
    enum class Background { Image = 0, PDF = 1, Color = 2 };
}

#endif //SHOWTAP_LIBRARY_ENUMERATES_H