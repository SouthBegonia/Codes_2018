/*
根据硬件(CPU)的特征,对于不同数据类型的可配置地址受到一定的限制.
为了提高CPU的效率,编译器会适当地进行 边界调整(布局对齐) ,在结构体中插入合适的填充物(也可以手工填充).
但即便使用手工进行布局对其,也不能提高可移植性.
*/
#include<stdio.h>

typedef struct {
	int int1;
	double double1;
	char char1;
	double double2;
} Hoge;

int main()
{
	Hoge hoge;
	
	printf("hoge........%p\n",&hoge);
	printf("int1........%p\n",&hoge.int1);
	printf("double1.....%p\n",&hoge.double1);
	printf("char1.......%p\n",&hoge.char1);
	printf("double2.....%p\n",&hoge.double2);
	
	putchar('\n');
	
	printf("hoge size...%d\n",sizeof(Hoge));
	printf("int1........%d\n",sizeof(hoge.int1));
	printf("double1.....%d\n",sizeof(hoge.double1));
	printf("char1.......%d\n",sizeof(hoge.char1));
	printf("double2.....%d\n",sizeof(hoge.double2));

	/*在我的环境(Dev c++/Win GCC 6.3.0)下显示结果如下
	hoge........0061FF10
	int1........0061FF10	此处 int1 到 double1 间隔 8 个字节,说明前4字节为 int1 大小,后面 4 字节为 "填充物"
	double1.....0061FF18    
	char1.......0061FF20    此处同理填充了 7 字节
	double2.....0061FF28

    按一个个变量大小计算以为得到 21,但在我的环境下为 32
	hoge size...32  21+4+7=32
	int1........4   此处int虽然占4字节,但回看上面地址
	double1.....8
	char1.......1
	double2.....8
*/
	getchar();
	return 0;
}
