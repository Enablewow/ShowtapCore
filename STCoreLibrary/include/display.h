//
// Created by 이종일 on 2020/12/28.
//

#ifndef SHOWTAP_LIBRARY_DISPLAY_H
#define SHOWTAP_LIBRARY_DISPLAY_H

#include <iostream>

namespace showtap {
    struct RECT {
        int left = 0, right = 0, top = 0, bottom = 0;

        int getWidth() const { return right - left; }
        int getHeight() const { return bottom - top; }
    };

    struct Ratio { double R4_3 = 4/(double)3, R16_9 = 16/(double)9; };

    class Display {
        int w = 0, h = 0; // 화면 사이즈
        int cw = 0, ch = 0; // 컨테이너 사이즈

        double ratio = 0.0;

        RECT container;

        /**
         * 화면 자동 맞춤 설정 On / Off (기본값 Off)
         */
        bool isManual = false;
        bool isVertical() const { return w < h; }

        /**
         * @return 화면이 가지고 있는 비율을 계산한다.
         */
        double getWindowRatio() const { return !isVertical() ? w / (double)h : h / (double)w; }

    public:
        /**
         * 화면 사이즈를 입력한다
         */
        void setDisplaySize(int, int);

        /**
         * 컨테이너 사이즈를 임의로 설정한다.
         */
        void setManualSize(int, int);

        void setRatio(double r){ ratio = r; }

        void calculateContainerSize();

        RECT getContainerRect() const { return container; }
    };
}

#endif //SHOWTAP_LIBRARY_DISPLAY_H
