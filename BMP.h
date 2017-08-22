#ifndef BMP_H//Ԥ������  
#define BMP_H  

typedef unsigned char BYTES;               //Ϊ�˱�����ϵͳ����ı�������system�У���ͻ���������s��
typedef unsigned short WORDS;
typedef unsigned int DWORDS;
typedef long LONGS;

//BMP�ļ�ͷ��14�ֽڣ�  
typedef struct tagBITMAPFILEHEADER {
	//WORDS bfType;                                  //λͼ�ļ������ͣ�����ΪBM(�ڽṹ���ж�ȡ�ᷢ�����������ں����ж�ȡ)  ����������
	DWORDS bfSize;                                 //λͼ�ļ��Ĵ�С�����ֽ�Ϊ��λ  
	WORDS bfReserved1;                         //λͼ�ļ������֣�����Ϊ0  
	WORDS bfReserved2;                         //λͼ�ļ������֣�����Ϊ0  
	DWORDS bfOffBits;                           //λͼ���ݵ���ʼλ�ã��������λͼ�ļ�ͷ��ƫ������ʾ�����ֽ�Ϊ��λ  
}BMPHEAD;

//BMP��Ϣͷ��40�ֽڣ�  
typedef struct tagBITMAPINFOHEADER {
	DWORDS biSize;                               //���ṹ��ռ���ֽ���  
	LONGS biWidth;                               //λͼ�Ŀ�ȣ�������Ϊ��λ  
	LONGS biHeight;                              //λͼ�ĸ߶ȣ�������Ϊ��λ  
	WORDS biPlanes;                             //Ŀ���豸�ļ��𣬱���Ϊ1  
	WORDS biBitCount;                         //ÿ�����������λ����������1��˫ɫ����4(16ɫ����8(256ɫ��16(�߲�ɫ)��24�����ɫ��֮һ  
	DWORDS biCompression;               //λͼѹ�����ͣ�������0����ѹ����,1(BI_RLE8ѹ�����ͣ���2(BI_RLE4ѹ�����ͣ�֮һ  
	DWORDS biSizeImage;                    //λͼ�Ĵ�С(���а�����Ϊ�˲���������4�ı�������ӵĿ��ֽ�)�����ֽ�Ϊ��λ  
	LONGS biXPelsPerMeter;                //λͼˮƽ�ֱ��ʣ�ÿ��������  
	LONGS biYPelsPerMeter;                //λͼ��ֱ�ֱ��ʣ�ÿ��������  
	DWORDS biClrUsed;                       //λͼʵ��ʹ�õ���ɫ���е���ɫ��  
	DWORDS biClrImportant;               //λͼ��ʾ��������Ҫ����ɫ��  
}BMPNEWS;

//������Ϣ  
//8λBMPͼ1���ֽڴ���һ�����أ����Կ��Բ��ýṹ�洢�������飬ֱ����һ��ָ�뼴��  
typedef struct tagIMAGEDATA {
	BYTES blue;
	BYTES green;
	BYTES red;
}IMAGEDATA;

#endif  
