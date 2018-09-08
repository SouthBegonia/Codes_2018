#include<stdio.h>
#include<windows.h>
void setxy(int x, int y); 
void gotoxy(int x,int y);
static void SetPos(int x, int y);

int main()
{
	int a=0,b=0;
	printf("A0123456789\n");
	printf("B0123456789\n");
	SetPos(3,1);	//x列，y行 
	printf("*");
	
	return 0;
}

//设置CMD窗口光标位置
void setxy(int x, int y)  //x,y为光标座标
{
   COORD coord = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void gotoxy(int x,int y)    //设置光标的位置
{      
	COORD c;      
	c.X=x-1;      
	c.Y=y-1;      
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

static void SetPos(int x, int y)
{
    COORD point = { x, y };//光标要设置的位置x,y
    HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
    SetConsoleCursorPosition(HOutput, point);//设置光标位置
}
