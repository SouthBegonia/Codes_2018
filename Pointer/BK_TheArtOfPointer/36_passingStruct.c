#include<stdio.h>

struct Student
{
	char mane[20];
	int score;
	char *passdown;
};

void passOrdown(struct Student *p)
{
	if(p->score >= 60)
		p->passdown = "PASS";
	else
		p->passdown = "DOWN";
}

void output(struct Student *q)
{
	int i;
	printf("\n\n%10s %10s %20s\n","Names","Score","Pass or Down");
	for(int i;i<42;i++)
		printf("=");
	printf("\n");
	printf("%10s %10d %20s\n",q->mane,q->score,q->passdown);
}

int main()
{
	struct Student stu;
	printf("Input A name:");
	scanf("%s",stu.mane);
	printf("Input A score:");
	scanf("%d",&stu.score);
	
	passOrdown(&stu);
	output(&stu);
	
	printf("stu = %p  &stu = %p\n",stu,&stu);
	printf("stu.name = %p  &stu.name  =%p\n",stu.mane,&stu.mane);
	printf("&stu.score = %p\n",&stu.score);
	printf("sizeof(stu) = %d",sizeof(stu));
	
	fflush(stdin);
	getchar();
	return 0;
}

