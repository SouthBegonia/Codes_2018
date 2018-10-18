/*建造结构体，使用结构体指针传递给函数进行赋值，更换顺序，打印*/
#include<stdio.h>
#include<stdlib.h>

int len;    //构建学生信息数

struct Student
{
    int age;
    float score;
    char name[100];
};

/*读取len个学生结构体的各项信息*/
void Inputstudent(struct Student *pst)
{
    int i;
    for(i=1;i<=len;i++)
    {
        printf("第%d个学生的信息：\n",i);
        printf("age=");
        scanf("%d",&pst[i].age);       //注意此处格式
        printf("score=");
        scanf("%f",&pst[i].score);
        printf("name=");
        scanf("%s",&pst[i].name);
    }
    printf("\n");
}

/*根据学生分数升序排序(冒泡排序)*/
void swap(struct Student *st)
{
    int i,j;
    struct Student t;

    for(i=1;i<len;i++)
        for(j=1;j<=len-i;j++)
        {
            if(st[j].score > st[j+1].score)
            {
                t=st[j];
                st[j]=st[j+1];
                st[j+1]=t;
            }
        }
}

/*打印排序后的学生信息*/
void Outputstudent(struct Student *pstu)
{
    int i;
    for(i=1;i<=len;i++)
    {
        printf("第%d个学生信息：\n",i);
        printf("age=%d\n",pstu[i].age);
        printf("name=%s\n",pstu[i].name);
        printf("score=%f\n",pstu[i].score);
    }
}

int main()
{
    struct Student *st;
    printf("输入学生个数：");
    scanf("%d",&len);

    st=(struct Student *)malloc(len * sizeof(struct Student *));

    Inputstudent(st);   //因为是指针，故是 st 而不是 &st
    swap(st);
    Outputstudent(st);

    return 0;
}
