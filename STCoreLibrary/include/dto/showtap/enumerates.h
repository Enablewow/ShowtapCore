//
// Created by 이종일 on 2020/12/23.
//

#ifndef SHOWTAP_LIBRARY_ENUMERATES_H
#define SHOWTAP_LIBRARY_ENUMERATES_H


namespace showtap {
    enum class Ref { None = 0, Inner = 1, ICloud = 2, Dropbox = 3, GoogleDrive = 4, OneDrive = 5, Gallery = 6, FileApp = 7 };
    enum class File { Folder = 0, Showtap = 1, PDF = 2, Image = 3, Video = 4, Audio = 5, ETC = 6, Temp = 7 };
    enum class Background { Image = 0, PDF = 1, Color = 2 };
    enum class Type { None = -1, Tapcon = 0, Group = 1, Image = 2, Video = 3, Mark = 4, Audio = 5, URL = 6, Text = 7, Slide = 8 };
    enum class Owner { None = -1, Page = 0, Object = 1 };
}

#endif //SHOWTAP_LIBRARY_ENUMERATES_H
