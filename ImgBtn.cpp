#include "ImgBtn.h"

using namespace std;

ImgBtn::ImgBtn(float x, float y, float w, float h, string imgName) : Btn(x, y, w, h) {
    texture.loadFromFile(resDir + imgName);
    shape.setTexture(&texture);
}
