/*链表实现队列(先进先出)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void Insert();
void Delete();
void Display();
void Quit();

struct Student
{
    int id;
    int score;
    struct Student *next;
};
struct Student *x,*head,*current;

int main()
{
    /*链表的第一个节点不存放数据*/
    head = (struct Student *)malloc(sizeof(struct Student));
    head->next = NULL;

    while(1)
    {
        int a;

        printf("1)Insert\n2)Delete\n3)Display\n4)Quit\n");
        printf("Please choose:");
        scanf("%d",&a);
        printf("\n");

        switch(a)
        {
            case 1: Insert();
                break;
            case 2: Delete();
                break;
            case 3: Display();
                break;
            case 4: Quit();
                break;
        }
    }
    getchar();
    return 0;
}

void Insert()
{
    x = (struct Student *)malloc(sizeof(struct Student));

    printf("Please input your ID: ");
    scanf("%d",&x->id);
    printf("Please input your score: ");
    scanf("%d",&x->score);

    x->next = NULL;

    if(head->next == NULL)
        head->next = x;
    else
    {
        /*追踪链表的尾节点*/
        current = head->next;
        while(current->next != NULL)
            current = current->next;
        current->next = x;
    }
    printf("Insert success!\n");
    printf("==================================\n");
}

void Delete()
{
    char ch;

    if(head->next == NULL)
    {
        printf("The queue is empty!\n");
        printf("==================================\n");
        return ;
    }
    printf("Are you sure (y/n)? ");
    ch = getche();
    if(tolower(ch) == 'y')
    {
        current = head->next;
        head->next = current->next;
        printf("\n%d record has been deleted !",current->id);
        free(current);
    }
    printf("==================================\n");
}

void Display()
{
    if(head->next == NULL)
        printf("The queue is empty!\n");
    else
    {
        /*将head'指定给current，用current指针将链表的所有节点输出*/
        current = head->next;
        while(current != NULL)
        {
            printf("ID: %d, score=%d\n",current->id,current->score);
            current = current->next;
        }
    }
    printf("==================================\n");
}

void Quit()
{
    exit(0);
}
