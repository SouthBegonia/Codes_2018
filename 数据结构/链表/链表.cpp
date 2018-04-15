/*
	程序功能：创建n个元素的链表，读入一个数，插入到链表内介于2数间的位置。
	链表特点：解决数组不可插入删除的特点。
	链表原理：链表结构体包括数值域(data)和后继指针( *next)。链表头用 *head，用于遍历
				读入的数据 a 存储到结点的数值域 data ，即 p->data = a
				把当前结点后继指针 *next 指向空，即 p->next = NULL
*/
#include<stdio.h>
#include<stdlib.h>                           //调用 malloc()

struct node                                  //表示链表类型的结构体
{
	int data;                                //存储数据的域
	struct node *next;                       //后继指针
};

int main()
{
	struct node *head, *p, *q, *t;
	int i, n, a;
	scanf_s("%d", &n);
	head = NULL;                            //链表头初始化
	q = NULL;

	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &a);
		p = (struct node *)malloc(sizeof(struct node));  
		/*
			malloc()函数：动态申请指定大小的内存，默认是(void *)类型(未确定类型的指针)。
						  (struct node *)强制转换了malloc指针类型为 node * 型。
						  sizeof(struct node) = 16 
			p = malloc()：表示指针p指向了malloc函数所申请的内存空间
			
		*/

		p->data = a;                       //将数据储存到当前结点的data域中
		p->next = NULL;                    //设置当前结点的后继指针指向空，表示当前结点的下一结点为空
		if (head == NULL)
			head = p;                      //如果这是第一个创建的结点，则将头指针指向这个结点
	 	else
			q->next = p;                   //若不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
		q = p;                             //指针q也指向当前结点
		/*
			p：表示当前结点
			q：表示上一结点
		*/
	}

	scanf_s("%d", &a);                     //输入待插入的数
	t = head;                              //从链表头部开始遍历
	 while (t != NULL)                      //当没有到达链表底部时候开始循环
	{
		if (t->next->data > a)             //如果当前结点的下一个结点的值大于待插入的数，则将数插入到中间
		{
			p = (struct node *)malloc(sizeof(struct node));     //动态申请一个空间来存放新的结点
			p->data = a;
			p->next = t->next;              //新增结点的后继指针指向当前结点的后继指针所指向的结点
			t->next = p;                    //当前结点的后继指针指向新的结点
			break;                          //插入完成，跳出
		}
		t = t->next;                        //继续下一个结点
	}

	t = head;                               //输出链表中的所有数
	while (t != NULL)
	{
		printf("%d ", t->data);
		t = t->next;                        //继续下一结点
	}
	getchar();
	getchar();

	return 0;
}