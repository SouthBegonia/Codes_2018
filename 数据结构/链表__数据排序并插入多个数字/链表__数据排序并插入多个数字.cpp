#include<stdio.h>
#include<stdlib.h>
int data[101], n;
void quicksort(int left, int right)    //快速排序函数(升序) 
{
	int i, j, t, temp;
	if (left > right)
		return;                        

	temp = data[left];                    //temp中存的就是基准数（假定为数组首位a[1]）
	i = left;
	j = right;
	while (i != j)                     
	{
		//从右往左对比，若右边的数大于基准数（符合升序），标记左移
		while (data[j] >= temp && i < j)
			j--;
		//在从左往右对比，若左边的数小于基准数（符合升序），则右移
		while (data[i] <= temp && i < j)
			i++;

		//当找到 a[j]<temp && a[i]>temp 且标记不相遇(i<j)时，交换两个数
		if (i < j)
		{
			t = data[i];
			data[i] = data[j];
			data[j] = t;
		}
	}
	//当标记相遇(i=j)时，对应的数值与基准数(a[left])交换，即基准数归位
	data[left] = data[i];
	data[i] = temp;

	quicksort(left, i - 1);            //处理左侧的分组，这里是一个递归的过程
	quicksort(i + 1, right);           //继续处理右边的分组，right依旧为 n 

}

int main()
{
	int right[101];
	int i, t, len;

	printf("数组元素个数：");
	scanf_s("%d", &n);
	printf("输入：");
	for (i = 1; i <= n; i++)
		scanf_s("%d", &data[i]);
	len = n;

	quicksort(1, n);             //调用快速排序函数

	for (i = 1; i <= n; i++)
	{
		if (i != n)
			right[i] = i + 1;
		else
			right[i] = 0;
	}

	len++;
	printf("插入的一个数字(可小于首位元素)：");
	scanf_s("%d", &data[len]);

	t = 1;
	while (t != 0)
	{
		if (data[1] > data[len])
		{
			right[len] = right[0];       //理解为首位元素的地址变更为新插入的数的地址
			right[0] = len;
			break;
		}

		if (data[right[t]] > data[len])              //如果当前结点的下一结点的值大于待插入的数，则，将数插入到中间
		{
			right[len] = right[t];                   //将新插入的数的下一个结点标号等于当前结点的下一结点编号
			right[t] = len;                          //当前结点的下一结点编号就是新插入数字的编号
			break;
		}
		t = right[t];
	}



	t = 1;                                //正常遍历输出
	printf("插入并排序后数组为： ");
	if (right[0] != 0)
	{
		// printf("新首位元素地址为data[%d]\n", right[0]);
		printf("%d ", data[right[0]]);
	}

	while (t != 0)
	{
		printf("%d ", data[t]);
		t = right[t];
	}
	getchar();
	getchar();
	return 0;
}



/*            采用结构体，但排序暂无办法，
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *head, *now, *last, *t;
	int num[1000], num_all=0;
	int i, n, a, k=0;
	head = NULL;
	last = NULL;

	printf("起始数组有几个元素：");
	scanf_s("%d", &n);
	printf("输入元素：");

	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &a);
		now = (struct node*)malloc(16);
		now->data = a;
		now->next = NULL;
		if (head == NULL)
			head = now;
		else
			last->next = now;
		last = now;
	}

	void queue(1,n);
	/*
	printf("插入几个数？ \n");
	scanf_s("%d", &num_all);
	k = num_all;                            //k用于鉴定num_all是否改变
	printf("插入的数为：");
	for (i = 1; i <= num_all; i++)
	{
		scanf_s("%d", &num[i]);
	}

	
	for (i = 1; i <= num_all;i++)
	{
		t = head;
		k = num_all;
		while (t != NULL)
		{
			if (t->next->data > num[i])
			{
				now = (struct node *)malloc(16);
				now->data = num[i];
				now->next = t->next;
				t->next = now;
				k--;
				continue;
			}
			if (k != num_all)
				continue;
			t = t->next;
		}
	}
	

	t = head;
	while (t != NULL)
	{
		printf("%d", t->data);
		t = t->next;
	}
	
	getchar();
	getchar();
	return 0;
}
void queue(int left,int right)
{
	int i, j, t, temp;
	if()
	
}
*/