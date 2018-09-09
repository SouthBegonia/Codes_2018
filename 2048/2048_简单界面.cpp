/*
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int addrandom(void);
void printchart(void);
void left(void);
void right(void);
void up(void);
void down(void);
void initlize(void);
void statr_game(void);
static void setpos(int x, int y);

int i, j;	//二维数组行列 
int chart[4][4];	//游戏主体
int ch;      //读取键盘输入
int sign;	  //游戏继续标志 
int score;  //得分
int zero;   //可添加随机数的空位
int rnum1 , rnum2;  //游戏初始页面随机 2 数字的位置
char play;    //是否继续游戏

/*初始化数组及各变量*/
void initlize(void)
{

	chart[4][4] = { 0 };	//初始化二维数组
	ch=0;
	sign=1;	  	//游戏继续标志
	score=0;  	//得分初始为0
	zero=0;
	rnum1 = 0, rnum2 = 0;   //游戏初始页面随机 2 数字的位置
	play=0;

	/*初始设定：在随机两个位置设置数字2*/
	for (i = 0; i < 2; i++)
	{
		rnum1 = rand() % 4;
		rnum2 = rand() % 4;
		chart[rnum1][rnum2] = 2;
	}

}

/*每次在两个随机空位置添加数字2且检验*/
int addrandom(void)
{
	int add_rnum1=0,add_rnum2=0;
	int randmax=2;		//剩余需添加随机数的个数 
	zero=0;
	
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(chart[i][j]==0)
				zero+=1;
	if(zero>=2)         //当空位数大于等于2才进行添加
	{
		do
		{
			add_rnum1 = rand() % 4;
			add_rnum2 = rand() % 4;
			if(chart[add_rnum1][add_rnum2]==0)
			{
				chart[add_rnum1][add_rnum2] = 2;
				randmax--;
			}
		}while(randmax!=0);
		return 1;		//添加成功
	}
	return 0;	//添加失败(无可用空位)，游戏结束
	
}

/*打印图表*/ 
void printchart(void)
{
	int x=28,y=10,l=3;
	setpos(x,y-2);		//先设定光标位置
	system("cls");
	printf("        得分：%d\n",score);
	
	printf("%*c",x,' ');
	printf("┌────┬────┬────┬────┐\n");
	for (i = 0; i < 4; i++)
		{
			printf("%*c",x,' ');
			for (j = 0; j < 4; j++)
				{
					printf("│%4d", chart[i][j]);
				}
				printf("│\n");
			if(l>0)
			{
				printf("%*c",x,' ');
				printf("├────┼────┼────┼────┤\n");
				l--;
			}
		}
		printf("%*c",x,' ');
		printf("└────┴────┴────┴────┘");
}

/*跳转光标位置*/
static void setpos(int x, int y)
{
    COORD point = { x, y };//光标要设置的位置x,y
    HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
    SetConsoleCursorPosition(HOutput, point);//设置光标位置
}

/*左键'a'*/ 
void left()
{
	int k,j;
	int line;
	
	for(line=0;line<4;line++)	//4行 
		for(k=0,j=1;j<4;j++)	//左侧标记k，右侧j 
		{
			if(chart[line][j]>0)	//右标记起第一个非零数 如2020 
			{
				if(chart[line][k]==chart[line][j])		//若左右两数相同，则合并 
				{
					chart[line][k]=2* chart[line][k];
					chart[line][j]=0;
					score+=chart[line][k];		//累计得分 
					k+=1;
				} 
				else if(chart[line][k]==0)	//若左标记为0 如 0020 则左移数字 
				{
					chart[line][k]=chart[line][j];
					chart[line][j]=0;
				}else		// 若两数不等且有间隔 如4020 则左移数字使其临近 
				{
					chart[line][k+1]=chart[line][j];
					if(j!=k+1)
					{
						chart[line][j]=0;
					}
					k+=1;	
					/*移动一次后，即左标记数值改变，则不可再改变，仅能改变下一个左标记
					如 4 2 2 0 左移后为 4 4 0 0 而不是 8 0 0 0
					*/ 
				}
			}
		}
}

/*右键'd*/
void right(void)
{
	int k,j;
	int line;
	
	for(line=0;line<4;line++)	//4行 
		for(k=3,j=2;j>=0;j--)
		{
			if(chart[line][j]>0)
			{
				if(chart[line][j]==chart[line][k])
				{
					chart[line][k]= 2 * chart[line][k];
					chart[line][j]=0;
					score+=chart[line][k];
					k--;
				}else if(chart[line][k]==0)
				{
					chart[line][k]=chart[line][j];
					chart[line][j]=0;
				}else 
				{
					chart[line][k-1]=chart[line][j];
					if(j!=k-1)
					{
						chart[line][j]=0;
					}
					k--;
				}
			}
		}
}

/*上键'w'*/
void up(void)
{
	int k,j;
	int row;	// 4列 
	
	for(row=0;row<4;row++)
		for(k=0,j=1;j<4;j++)
		{
			if(chart[j][row]>0)
			{
				if(chart[j][row]==chart[k][row])
				{
					chart[k][row]=2*chart[k][row];
					chart[j][row]=0;
					score+=chart[k][row];	
					k++;
				}else if(chart[k][row]==0)
				{
					chart[k][row]=chart[j][row];
					chart[j][row]=0;
				}else
				{
					chart[k+1][row]=chart[j][row];
					if(j!=k+1)
					{
						chart[j][row]=0;
					}
					k++;
				}
			}
		}
}

/*下键's'*/
void down(void)
{
	int k,j;
	int row;
	
	for(row=0;row<4;row++)
		for(k=3,j=2;j>=0;j--)
		{
			if(chart[j][row]>0)
			{
				if(chart[k][row]==chart[j][row])
				{
					chart[k][row]=2*chart[k][row];
					chart[j][row]=0;
					score+=chart[k][row];
					k--;
				}else if(chart[k][row]==0)
				{
					chart[k][row]=chart[j][row];
					chart[j][row]=0;
				}else
				{
					chart[k-1][row]=chart[j][row];
					if(j!=k-1)
					{
						chart[j][row]=0;
					}
					k--;
				}
			}
		}
}

/*开始游戏*/
void start_game(void)
{
	fflush(stdin);
	system("cls");
	initlize();     //初始化数组及各变量
	srand(time(NULL));		//设定种子
	setpos(0,0);		//移动一次后的清屏
	
	printchart();		//打印起始图表

	while(1)
	{
		//读取键盘
		switch(ch=getch())
		{
			case 'a':
			case 'A':
           	case 75 :
				left();
				break;
			case 'd':
		    case 'D':
       	  	case 77 :
				right();
				break;
      	 	case 'w':
			case 'W':
			case 72 :
				up();
				break;
        	case 's':
       	 	case 'S':
        	case 80 :
				down();
				break;
		}
	fflush(stdin);
	sign=addrandom();	//添加随机位置数，返回添加情况，真 1 假 0

	setpos(0,0);		//移动一次后的清屏
	printchart();		//打印添加随机数后的界面
	if(sign==0)         //当判定游戏结束则退出
		break;
	}		//若添加成功，游戏继续
	fflush(stdin);
	printf("\n%*c",29,' ');
	printf("游戏结束！继续游戏:(Y\\N)");
	
	//fgets(play,sizeof(buf),stdin);
	//sscanf(play,"%s",&play);
	return;
}

 int main()
{
	start_game();
	
	for(;;)
	{
		play=getch();
		if(play=='Y' || play =='y')
			start_game();
		else if(play=='N' || play=='n')
			break;
	}
	printf("Done!\n");
	getchar();
	return 0;
}
 
