
#include<iostream>
#include"image.h"
using namespace std;

int main()
{
	Image bmp("e:\\c++\\imageChar\\image\\test.bmp");
	//bmp.makeGray();
	bmp.showBmpHead();
	bmp.showBmpInfo();
	cout<<bmp.getWidth()<<endl;
	cout<<bmp.getHeight()<<endl;
	bmp.writeImage("..\\image\\sea1.bmp");
	//bmp.Binarization();
	bmp.writeImage("..\\image\\sea2.bmp");
	
	/*
	IMAGEDATA *data = bmp.getData();
	FILE *fpin = NULL;
	fopen_s(&fpin, "e:\\c++\\imageChar\\image\\draw1.txt", "w");
	for (int i = bmp.getHeight()*bmp.getWidth(); i>0;i--)
	{
		if ((*(data +i)).blue ==0)
			fprintf(fpin, "%c",'*');
		else
			fprintf(fpin, "%c",' ');
		if (i%bmp.getWidth()== 0)
			fprintf(fpin, "%c\n", ' ');
	}
	fclose(fpin);
	*/

	int a;
	cout << "success" << endl;
	cin >> a;
	return 0;
}