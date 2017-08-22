#include "image.h"

Image::Image(char *name)
{
	imageName = name;
	cout << imageName << endl;
	if (readImage())
		cout << "图片读取成功！" << endl;
	else
		cout << "1图片读取失败！" << endl;
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
		cout << "图片保存失败!" << endl;
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
	cout << "\n图片文件头:" << endl;
	cout << "  图片大小:" << bmpHead.bfSize << endl;
	cout << "  保留字_1:" << bmpHead.bfReserved1 << endl;
	cout << "  保留字_2:" << bmpHead.bfReserved2 << endl;
	cout << "  实际位图片数据的偏移字节数:" << bmpHead.bfOffBits << endl;
}

void Image::showBmpInfo()
{
	cout << "图片信息头:" << endl;
	cout << "  结构体的长度:" << bmpInfo.biSize << endl;
	cout << "  位图宽:" << bmpInfo.biWidth << endl;
	cout << "  位图高:" << bmpInfo.biHeight << endl;
	cout << "  平面数:" << bmpInfo.biPlanes << endl;
	cout << "  采用颜色位数:" << bmpInfo.biBitCount << endl;
	cout << "  压缩方式:" << bmpInfo.biCompression << endl;
	cout << "  实际位图数据占用的字节数:" << bmpInfo.biSizeImage << endl;
	cout << "  X方向分辨率:" << bmpInfo.biXPelsPerMeter << endl;
	cout << "  Y方向分辨率:" << bmpInfo.biYPelsPerMeter << endl;
	cout << "  使用的颜色数:" << bmpInfo.biClrUsed << endl;
	cout << "  重要颜色数:" << bmpInfo.biClrImportant << endl;
}

bool Image::readImage()
{
	if (!fopen_s(&fpin, imageName, "rb"))
	{
		WORDS ftype;
		fread(&ftype, sizeof(WORDS), 1, fpin);
		if (ftype != 0x4d42)
		{
			cout << "这不是一个BMP图" << endl;
			return false;
		}
		fread(&bmpHead, sizeof(BMPHEAD), 1, fpin);
		fread(&bmpInfo, sizeof(BMPNEWS), 1, fpin);
		if (bmpInfo.biBitCount != 24)
		{
			cout << "这不是一个24位图" << endl;
			return false;
		}
		height=bmpInfo.biHeight;
		width = bmpInfo.biWidth;
		width = (width*sizeof(BYTES) + 3) / 4 * 4; 
		imagedata = new IMAGEDATA[width*height];                      //!!!
		fread(imagedata, sizeof(IMAGEDATA)*width, height, fpin);      //!!!
		fclose(fpin);
		return true;
	}
	else
	{
		cout << "2图片读取失败" << endl;
		return false;
	}
}
