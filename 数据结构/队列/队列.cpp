/*
    程序功能：一个队列，删除首位数字，将其后一位移动到末尾，删除的数字组成数组打印。
	队列特点：只允许在队列的首位(head)进行删除操作，称为出队，而在队列的尾部(tail)进行插入操作。
	当队列没有元素时候(head==tail)，称为空队列。
*/
#include<stdio.h>
struct queue
{
	int data[100];                              //队列主体
	int head;                                   //队首
	int tail;                                   //队尾
};

int main()
{
	struct queue q;
	int i;

	q.head = 1;                                 //初始化队列
	q.tail = 1;

	for (i = 1; i <= 9; i++)                    //读入数字
	{
		scanf_s("%d", &q.data[q.tail]);           
		q.tail++;                               //末尾留出空位供新队首
	}

	while (q.head < q.tail)                     //当队列不为空时执行循环
	{
		printf("%d ", q.data[q.head]);          //打印队首
		q.head++;                               //队首出队(队列1号元素删除操作)，同时指向二号元素

		q.data[q.tail] = q.data[q.head];        //将新队首(2号元素)添加到队尾
		q.tail++;                               //再添加尾空位

		q.head++;                               //1号元素已经删除，2号元素移动到末尾，再指向下一元素
	}
	getchar();
	getchar();
	return 0;
}