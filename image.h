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
	bool writeImage(char *name);                                //����ͼƬ  
	void makeGray();                                                    //����ɫͼת��Ϊ�Ҷ�ͼ  
	void Binarization();                                                 //��ֵ��  
	void showBmpHead();         //��ʾ��Ϣͷ
	int getWidth() { return width; } //��ʾ�ļ�ͷ  
	void showBmpInfo();             
	int getHeight() { return height; }
	RGB *getData() { return imagedata; }
private:                                               
	char *imageName;                                                 //ͼ����  
	int width, height;                                                    //ͼ��Ŀ��  
	BITMAPFILEHEADER bmpHead;                                            //�ļ�ͷ  
	BITMAPINFOHEADER bmpInfo;                                              //��Ϣͷ  
	RGB *imagedata = NULL;                         //�洢ͼƬ������Ϣ�Ķ�ά����  
	FILE *fpin=NULL, *fpout=NULL;                              //�ļ�ָ��,ע��ָ��ĳ�ʼ����
	bool readImage();                                                   //��ȡͼƬ
};

#endif // !IMAGE_H

