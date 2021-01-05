//
// Created by 이종일 on 2020/12/28.
//

#include <display.h>

using namespace showtap;

void Display::setDisplaySize(int width, int height) {
    if(width > height){
        w = width;
        h = height;
    }else{
        w = height;
        h = width;
    }
}

void Display::calculateContainerSize() {
    if(!isManual){
        double wr = getWindowRatio();

        if(wr < ratio){
            double d = wr / ratio;

            int thick = (int)(((1.0 - d) / 2.0) * h);

            cw = w;
            ch = h - thick;
        }else{
            double d = ratio / wr;

            int thick = (int)(((1.0 - d) / 2.0) * w);

            cw = w - thick;
            ch = h;
        }
    }

    container.left = 0;
    container.top = 0;
    container.right = cw;
    container.bottom = ch;
}

void Display::setManualSize(int width, int height) {
    // 설정한 컨테이너 넓이 / 높이가 바깥으로 넘어가게 된다면 컨테이너는 화면사이즈에 맞추도록 한다.
    cw = (width < w) ? width : w;
    ch = (height < h) ? height : h;

    ratio = (cw > ch) ? cw / (double)ch : ch / (double)cw;

    isManual = true;
}



