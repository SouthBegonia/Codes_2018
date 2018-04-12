/**/
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
		q.tail++;
	}

	while (q.head < q.tail)                     //当队列不为空时执行循环
	{
		printf("%d ", q.data[q.head]);          //打印队首并将队首出队
		q.head++;

		q.data[q.tail] = q.data[q.head];        //将出列的新队首添加到队尾
		q.tail++;

		q.head++;                               //再将队首出队
	}
	getchar();
	getchar();
	return 0;
}