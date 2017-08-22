#ifndef IMAGE_H
#define IMAGE_H
#include"BMP.h"
#include<iostream>
#include<fstream>
using namespace std;
class Image
{
public:
	Image(char *name);
	~Image();
	bool writeImage(char *name);                                //保存图片  
	void makeGray();                                                    //将彩色图转换为灰度图  
	void Binarization();                                                 //二值化  
	void showBmpHead(BMPHEAD BmpHead);         //显示信息头
	int getWidth() { return width; } //显示文件头  
	void showBmpInfo(BMPNEWS BmpInfo);             
	int getHeight() { return height; }
	IMAGEDATA *getData() { return imagedata; }
private:                                               
	char *imageName;                                                 //图像名  
	int width, height;                                                    //图像的宽高  
	BMPHEAD bmpHead;                                            //文件头  
	BMPNEWS bmpInfo;                                              //信息头  
	IMAGEDATA *imagedata = NULL;                         //存储图片像素信息的二维数组  
	FILE *fpin=NULL, *fpout=NULL;                              //文件指针,注意指针的初始化；
	bool readImage();                                                   //读取图片
};

#endif // !IMAGE_H

