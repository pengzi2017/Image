#ifndef IMAGE_H
#define IMAGE_H
#include<Windows.h>
#include<iostream>
#include<fstream>
using namespace std;
typedef struct 
{
	BYTE blue;
	BYTE green;
	BYTE red;
}RGB;
class Image
{
public:
	Image(char *name);
	~Image();
	bool writeImage(char *name);                                //保存图片  
	void makeGray();                                                    //将彩色图转换为灰度图  
	void Binarization();                                                 //二值化  
	void showBmpHead();         //显示信息头
	int getWidth() { return width; } //显示文件头  
	void showBmpInfo();             
	int getHeight() { return height; }
	RGB *getData() { return imagedata; }
private:                                               
	char *imageName;                                                 //图像名  
	int width, height;                                                    //图像的宽高  
	BITMAPFILEHEADER bmpHead;                                            //文件头  
	BITMAPINFOHEADER bmpInfo;                                              //信息头  
	RGB *imagedata = NULL;                         //存储图片像素信息的二维数组  
	FILE *fpin=NULL, *fpout=NULL;                              //文件指针,注意指针的初始化；
	bool readImage();                                                   //读取图片
};

#endif // !IMAGE_H

