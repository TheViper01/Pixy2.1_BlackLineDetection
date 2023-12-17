#pragma once

#include<stdint.h>
#include"rgb2hsv.h"


class Pixy2BlackLineDetectionService
{
public:
	Pixy2BlackLineDetectionService(const int *_image, int width, int height) {
		this->height = height;
		this->width = width;
		this->image = _image;
	}
	~Pixy2BlackLineDetectionService(){}

	RGBcolor getPixel(int x, int y) {
		int offset = (y * this->width) + x;
		RGBcolor ff;
		ff.R = (this->image[offset] >> 0) & (int)0xff;
		ff.G = (this->image[offset] >> 8) & (int)0xff;
		ff.B = (this->image[offset] >> 16) & (int)0xff;
		return ff;
	}

	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}


private:
	int width;
	int height;
	const int*image;

};
