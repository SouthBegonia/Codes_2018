# 结构体

> 结构是C语言中一种用户自定义的数据类型，允许储存不同的数据项。

-------
## 定义结构体

```
struct Tag {
	...
	member
	...
} variable;
```
- Tag: 结构体的**标签**(名称)
- member: **变量定义**(结构体成员)
- variable: 声明的**结构变量**

## 创建结构体

一般情况下，**标签**，**变量定义**，**声明的结构体**这3部分至少要出现2个才可顺利使用结构体。
1.标准`struct`创建
```
struct Man {
	char name[100];
	char address[100];
	int phone; 
} jack;		//声明结构变量 jack
struct Man aleax;	//声明结构变量 aleax
```

2.`typedef`创建
```
typedef struct {
	char name[100];
	char address[100];
	int phone;
} Man;
Man jack;		//声明结构变量 jack
```

## 访问结构体成员

1.访问**普通**结构体的成员，采用 ` . ` 访问
```
typedef struct {
	int days;
	char place[100];
} Party;

int main()
{
	int days;
	char place[100];
	Party li;		//普通结构体
	Party *p = &li;		//指针指向的结构体

	li.days = 12;
	strcpy(li.place,"Home");
	
	printf("days = %d\n",li.days);		//访问结构体成员
	printf("place = %s\n",li.place);
	
	return 0;
}

```

2.访问**指针**所指向的结构体成员，可采用 `->` 或 ` (* ).` 访问
```
/* 方法1 */
printf("days = %d\n",ptr->days);
printf("place = %s\n",ptr->place);

/* 方法2 */
printf("days = %d\n",(*ptr).days);
printf("place = %s\n",(*ptr).place);
```

## 其他说明
1.区别**结构体常量**及**结构体变量**
```
struct Student {
	char name[20];
	int score;
};

/*创建结构体常量
可以直接使用，访问成员*/
struct Student stu;

/*创建结构体变量
除非指向其他结构体，否则需要分配内存才可使用*/
struct Student *pstu;

```