#ifndef BMP_H//预处理器  
#define BMP_H  

typedef unsigned char BYTES;               //为了避免与系统定义的变量名（system中）冲突，后面加了s；
typedef unsigned short WORDS;
typedef unsigned int DWORDS;
typedef long LONGS;

//BMP文件头（14字节）  
typedef struct tagBITMAPFILEHEADER {
	//WORDS bfType;                                  //位图文件的类型，必须为BM(在结构体中读取会发生错误，所以在函数中读取)  ？？？？？
	DWORDS bfSize;                                 //位图文件的大小，以字节为单位  
	WORDS bfReserved1;                         //位图文件保留字，必须为0  
	WORDS bfReserved2;                         //位图文件保留字，必须为0  
	DWORDS bfOffBits;                           //位图数据的起始位置，以相对于位图文件头的偏移量表示，以字节为单位  
}BMPHEAD;

//BMP信息头（40字节）  
typedef struct tagBITMAPINFOHEADER {
	DWORDS biSize;                               //本结构所占用字节数  
	LONGS biWidth;                               //位图的宽度，以像素为单位  
	LONGS biHeight;                              //位图的高度，以像素为单位  
	WORDS biPlanes;                             //目标设备的级别，必须为1  
	WORDS biBitCount;                         //每个像素所需的位数，必须是1（双色），4(16色），8(256色）16(高彩色)或24（真彩色）之一  
	DWORDS biCompression;               //位图压缩类型，必须是0（不压缩）,1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一  
	DWORDS biSizeImage;                    //位图的大小(其中包含了为了补齐行数是4的倍数而添加的空字节)，以字节为单位  
	LONGS biXPelsPerMeter;                //位图水平分辨率，每米像素数  
	LONGS biYPelsPerMeter;                //位图垂直分辨率，每米像素数  
	DWORDS biClrUsed;                       //位图实际使用的颜色表中的颜色数  
	DWORDS biClrImportant;               //位图显示过程中重要的颜色数  
}BMPNEWS;

//像素信息  
//8位BMP图1个字节代表一个像素，所以可以不用结构存储像素素组，直接用一个指针即可  
typedef struct tagIMAGEDATA {
	BYTES blue;
	BYTES green;
	BYTES red;
}IMAGEDATA;

#endif  
