#include<iostream>
#include"image.h"
using namespace std;

int main()
{
	Image bmp("e:\\c++\\imageChar\\image\\boy.bmp");
	bmp.makeGray();
	bmp.showBmpHead();
	bmp.showBmpInfo();
	cout<<bmp.getWidth()<<endl;
	cout<<bmp.getHeight()<<endl;
	bmp.writeImage("..\\image\\boy1.bmp");
	bmp.Binarization();
	bmp.writeImage("..\\image\\boy2.bmp");
	
	
	RGB *data = bmp.getData();
	FILE *fpin = NULL;
	fopen_s(&fpin, "e:\\c++\\imageChar\\image\\draw1.txt", "w");
	for (int i =2599 ; i>=0;i--)//bmp.getHeight()*bmp.getWidth()
	{
		if ((*(data +i)).blue ==0)
			fprintf(fpin, "%c",'*');
		else
			fprintf(fpin, "%c",' ');
		if ((i+1)%51 == 0)
		{
			fprintf(fpin, "%c\n", ' ');
		}
	}
	fclose(fpin);
	

	int a;
	cout << "success" << endl;
	cin >> a;
	return 0;
}