/*
	程序功能：A、B各有6张牌（1~9），轮流打出首牌；
假如桌面的栈(s)中含有相同牌号，则该人把相同牌（包含相同的）之间所有牌依次取出，依次放入手牌队尾；
出牌后一方手牌为空则另一方胜利。
	栈的实现：桌面牌 s 。
	队列的实现：A、B手牌 q1,q2 。
*/
#include<stdio.h>
struct queue                                //双方手牌结构体
{
	int  data[1001];
	int head;
	int tail;
};
struct stack                                //桌面牌结构体
{
	int data[10];
	int top;
};

int main()
{
	struct queue q1, q2;
	struct stack s;
	int mark[10];                           //定义牌的种类为 1~9
	int i, t;

	q1.head = 1; q1.tail = 1;               //初始化队列
	q2.head = 1; q2.tail = 1;
	s.top = 0;                              //初始化栈

	for (i = 1; i <= 9; i++)                //用来标记哪些牌在桌面上
		mark[i] = 0;

	for (i = 1; i <= 3; i++)                // 随意设定读入A、B的手牌数
	{
		scanf_s("%d", &q1.data[q1.tail]);
		q1.tail++;
	}
	for (i = 1; i <= 3; i++)
	{
		scanf_s("%d", &q2.data[q2.tail]);
		q2.tail++;
	}

	while (q1.head < q1.tail && q2.head < q2.tail)  //当双方手牌不空
	{
		t = q1.data[q1.head];                       // A出一张牌
		if (mark[t] == 0)                           //无重牌
		{
			q1.head++;                              //A打出的牌出队
			s.top++;                                
			s.data[s.top] = t;                      //打出牌放到桌面，即入栈
			mark[t] = 1;                            //标记桌面已有这种牌
		}
		else                                        //有重牌
		{
			q1.head++;                              //A打出的牌出队
			q1.data[q1.tail] = t;                   //A打出的牌移到手牌的末尾
			q1.tail++;

			while (s.data[s.top] != t)
			{
				mark[s.data[s.top]] = 0;            //取消标记
				q1.data[q1.tail] = s.data[s.top];   //依次放入队尾
				q1.tail++;
				s.top--;                            //桌面减少一张牌，栈顶减1
			}
			mark[s.data[s.top]] = 0;
			q1.data[q1.tail] = s.data[s.top];  
			q1.tail++;
			s.top--;
			/*
				在while下免再添加一遍64~67行代码是因为while内条件没包含在牌内的相同的牌，
		     若不添加，则不拿取桌面里相同的那张牌，其结果也随之改变。
			*/
		}

		t = q2.data[q2.head];                       //B出牌
		if (mark[t] == 0)                           //无重牌
		{
			q2.head++;                             
			s.top++;
			s.data[s.top] = t;
			mark[t] = 1;
		}
		else                                        //有重牌
		{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while (s.data[s.top] != t)              //桌面上的牌依次放到B手牌末尾
			{
				mark[s.data[s.top]] = 0;            //取消标记
				q2.data[q2.tail] = s.data[s.top];   //依次放入队尾
				q2.tail++;
				s.top--;
			}
			mark[s.data[s.top]] = 0;
			q2.data[q2.tail] = s.data[s.top];    
			q2.tail++;
			s.top--;
			/*
				同上所述，添加以上代码才满足条件。
			*/
		}
	}
	
	if (q2.head == q2.tail)                          //当一方手牌为空
	{
		printf("A赢\n");
		printf("A当前的手牌是：");
		for(i=q1.head;i<=q1.tail-1;i++)
			printf("%d ",q1.data[i]);
		printf("\n");
			if (s.top > 0)
			{
				printf("桌面上的牌是：");
					for (i = 1; i <= s.top; i++)
						printf("%d ", s.data[i]);
			}
			else
				printf("桌上已经没牌了\n");
	}
	else 
	{
		printf("B赢\n");
		printf("B当前的手牌是：");
		for (i = q2.head; i <= q2.tail - 1; i++)
			printf("%d ", q2.data[i]);
		printf("\n");
		if (s.top > 0)
		{
			printf("桌面上的牌是：");
			for (i = 1; i <= s.top; i++)
				printf("%d ", s.data[i]);
		}
		else
			printf("桌面上已经没牌了\n");
	}

	/*
		若不添加69~72、99~102代码段，表示不拿取桌面上1张相同的牌（仅拿了刚出队的相同牌）
			例1：
			输入:2 4 1 2 5 6
				 3 1 3 5 6 4
			输出：A赢
				A当前的手牌是：5 6 2 3 1 4 6 5
				桌面上的牌是：2 1 3 4
			例2：
			输入:1 2 1
			     3 4 5
			输出: A赢
				A当前手牌是： 1 2 1 3
				桌面上的牌是：1 4

		添加代码段后：
			例1：
			输入：2 4 1 2 5 6
				  3 1 3 5 6 4
			输出：B赢
				B当前的手牌是：6 5 2 3 4 1
				桌面上的牌是： 3 4 5 6 2 1
			例2：
			输入：1 2 1
			      3 4 5
			输出：A赢
				A当前的手牌是：1 4 2 3 1
				桌面上的牌是： 5
	*/
	getchar();
	getchar();
	return 0;
}