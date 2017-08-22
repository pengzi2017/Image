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
	if (!fopen_s(&fpout, name, "w"))
	{
		WORDS ftype = 0x4d42;
		fwrite(&ftype, sizeof(WORDS), 1, fpout);
		fwrite(&bmpHead, sizeof(BMPHEAD), 1, fpout);
		fwrite(&bmpInfo, sizeof(BMPNEWS), 1, fpout);
		fwrite(imagedata, sizeof(IMAGEDATA)*width,height, fpout);
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

void Image::showBmpHead(BMPHEAD BmpHead)
{
	cout << "\nͼƬ�ļ�ͷ:" << endl;
	cout << "  ͼƬ��С:" << BmpHead.bfSize << endl;
	cout << "  ������_1:" << BmpHead.bfReserved1 << endl;
	cout << "  ������_2:" << BmpHead.bfReserved2 << endl;
	cout << "  ʵ��λͼƬ���ݵ�ƫ���ֽ���:" << BmpHead.bfOffBits << endl;
}

void Image::showBmpInfo(BMPNEWS BmpInfo)
{
	cout << "ͼƬ��Ϣͷ:" << endl;
	cout << "  �ṹ��ĳ���:" << BmpInfo.biSize << endl;
	cout << "  λͼ��:" << BmpInfo.biWidth << endl;
	cout << "  λͼ��:" << BmpInfo.biHeight << endl;
	cout << "  ƽ����:" << BmpInfo.biPlanes << endl;
	cout << "  ������ɫλ��:" << BmpInfo.biBitCount << endl;
	cout << "  ѹ����ʽ:" << BmpInfo.biCompression << endl;
	cout << "  ʵ��λͼ����ռ�õ��ֽ���:" << BmpInfo.biSizeImage << endl;
	cout << "  X����ֱ���:" << BmpInfo.biXPelsPerMeter << endl;
	cout << "  Y����ֱ���:" << BmpInfo.biYPelsPerMeter << endl;
	cout << "  ʹ�õ���ɫ��:" << BmpInfo.biClrUsed << endl;
	cout << "  ��Ҫ��ɫ��:" << BmpInfo.biClrImportant << endl;
}

bool Image::readImage()
{
	if (!fopen_s(&fpin, imageName, "rb"))
	{
		WORDS ftype;
		fread(&ftype, sizeof(WORDS), 1, fpin);
		if (ftype != 0x4d42)
		{
			cout << "�ⲻ��һ��BMPͼ" << endl;
			return false;
		}
		fread(&bmpHead, sizeof(BMPHEAD), 1, fpin);
		fread(&bmpInfo, sizeof(BMPNEWS), 1, fpin);
		if (bmpInfo.biBitCount != 24)
		{
			cout << "�ⲻ��һ��24λͼ" << endl;
			return false;
		}
		height=bmpInfo.biHeight;
		width = bmpInfo.biWidth;
		width = (width*sizeof(BYTES) + 3) / 4 * 4;                              //!!!
		imagedata = new IMAGEDATA[width*height];                      //!!!
		fread(imagedata, sizeof(IMAGEDATA)*width, height, fpin);   //!!!
		fclose(fpin);
		return true;
	}
	else
	{
		cout << "2ͼƬ��ȡʧ��" << endl;
		return false;
	}
}
