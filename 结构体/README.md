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

1.访问普通结构体的成员，采用 **结构变量名.结构体成员** 访问
```
typedef struct {
	int days;
	char place[100];
} Party;

int main()
{
	int days;
	char place[100];
	Party li;

	li.days = 12;
	strcpy(li.place,"Home");
	
	printf("days = %d\n",li.days);
	printf("place = %s\n",li.place);
	
	return 0;
}

```

2.访问指针所指向的结构体成员，采用 **结构变量名->结构体成员** 访问
