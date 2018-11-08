/*自引用结构-2*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    struct student
    {
        char *name;
        int score;
        struct student *next;
    };

    struct student *p,*q,*r,*current;   //当前节点 current

    p = (struct student *) malloc(sizeof(struct student));
    p->name = "Jack";
    p->score = 90;

    q = (struct student *) malloc(sizeof(struct student));
    q->name = "Rose";
    q->score = 91;

    r = (struct student *) malloc(sizeof(struct student));
    r->name = "Ben";
    r->score = 60;

    p->next = q;
    q->next = r;
    r->next = NULL;

    printf("There are three student in my class\n");
    current = p;

    while(current != NULL)
    {
        printf("%10s %10d\n",current->name,current->score);
        current = current->next;
    }

    getchar();
    return 0;
}

