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
	bool writeImage(char *name);                                //����ͼƬ  
	void makeGray();                                                    //����ɫͼת��Ϊ�Ҷ�ͼ  
	void Binarization();                                                 //��ֵ��  
	void showBmpHead(BMPHEAD BmpHead);         //��ʾ��Ϣͷ
	int getWidth() { return width; } //��ʾ�ļ�ͷ  
	void showBmpInfo(BMPNEWS BmpInfo);             
	int getHeight() { return height; }
	IMAGEDATA *getData() { return imagedata; }
private:                                               
	char *imageName;                                                 //ͼ����  
	int width, height;                                                    //ͼ��Ŀ���  
	BMPHEAD bmpHead;                                            //�ļ�ͷ  
	BMPNEWS bmpInfo;                                              //��Ϣͷ  
	IMAGEDATA *imagedata = NULL;                         //�洢ͼƬ������Ϣ�Ķ�ά����  
	FILE *fpin=NULL, *fpout=NULL;                              //�ļ�ָ��,ע��ָ��ĳ�ʼ����
	bool readImage();                                                   //��ȡͼƬ
};

#endif // !IMAGE_H
