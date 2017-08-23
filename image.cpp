#include "image.h"

Image::Image(char *name)
{
	imageName = name;
	cout << imageName << endl;
	if (readImage())
		cout << "ͼƬ��ȡ�ɹ���" << endl;
	else
		cout << "1ͼƬ��ȡʧ�ܣ�" << endl;
}

Image::~Image()
{
	delete[] imagedata;
}

bool Image::writeImage(char *name)
{
	if (!fopen_s(&fpout, name, "wb"))
	{
		fwrite(&bmpHead, sizeof(BITMAPFILEHEADER), 1, fpout);
		fwrite(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, fpout);
		fwrite(imagedata, sizeof(RGB),width*height,fpout);
		fclose(fpout);
		return true;
	}
	else
	{
		cout << "ͼƬ����ʧ��!" << endl;
		return false;
	}
}

void Image::makeGray()
{
	int sum = 0;
	for (int i = 0; i < width*height; i++)
	{
		sum=(*(imagedata + i)).blue + (*(imagedata + i)).green + (*(imagedata + i)).red;
		(*(imagedata + i)).blue = (*(imagedata + i)).green = (*(imagedata + i)).red = (char)(sum / 3);
	}
}

void Image::Binarization()
{
	makeGray();
	for (int i= 0; i < width*height; i++)
	{
		if ((*(imagedata + i)).blue <= 100)
			(*(imagedata + i)).blue = (*(imagedata + i)).green = (*(imagedata + i)).red = 0;
		else
			(*(imagedata + i)).blue = (*(imagedata + i)).green = (*(imagedata + i)).red = 255;
	}
}

void Image::showBmpHead()
{
	cout << "\nͼƬ�ļ�ͷ:" << endl;
	cout << "  ͼƬ��ʶ��" << bmpHead.bfType << endl;
	cout << "  ͼƬ��С:" << bmpHead.bfSize << endl;
	cout << "  ������_1:" << bmpHead.bfReserved1 << endl;
	cout << "  ������_2:" << bmpHead.bfReserved2 << endl;
	cout << "  ʵ��λͼƬ���ݵ�ƫ���ֽ���:" << bmpHead.bfOffBits << endl;
}

void Image::showBmpInfo()
{
	cout << "ͼƬ��Ϣͷ:" << endl;
	cout << "  �ṹ��ĳ���:" << bmpInfo.biSize << endl;
	cout << "  λͼ��:" << bmpInfo.biWidth << endl;
	cout << "  λͼ��:" << bmpInfo.biHeight << endl;
	cout << "  ƽ����:" << bmpInfo.biPlanes << endl;
	cout << "  ������ɫλ��:" << bmpInfo.biBitCount << endl;
	cout << "  ѹ����ʽ:" << bmpInfo.biCompression << endl;
	cout << "  ʵ��λͼ����ռ�õ��ֽ���:" << bmpInfo.biSizeImage << endl;
	cout << "  X����ֱ���:" << bmpInfo.biXPelsPerMeter << endl;
	cout << "  Y����ֱ���:" << bmpInfo.biYPelsPerMeter << endl;
	cout << "  ʹ�õ���ɫ��:" << bmpInfo.biClrUsed << endl;
	cout << "  ��Ҫ��ɫ��:" << bmpInfo.biClrImportant << endl;
}

bool Image::readImage()
{
	if (!fopen_s(&fpin, imageName, "rb"))
	{
		fread(&bmpHead, sizeof(BITMAPFILEHEADER), 1, fpin);
		fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, fpin);
		height=bmpInfo.biHeight;
		width = bmpInfo.biWidth;
		width = (width*sizeof(BYTE) + 3) / 4 * 4; 
		imagedata = new RGB[width*height];                      //!!!
		fread(imagedata,sizeof(RGB),height*width,fpin);      //!!!
		fclose(fpin);
		return true;
	}
	else
	{
		cout << "2ͼƬ��ȡʧ��" << endl;
		return false;
	}
}
