/*自引用结构*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    struct node
    {
        char *name;
        int score;
        struct node *next;
    };

    struct node *p,*q;
    p = (struct node *) malloc(sizeof(struct node));

    p->name = "Jack";
    p->score = 90;
    p->next = NULL;

    q = (struct node *) malloc(sizeof(struct node));
    q->name = "Rose";
    q->score = 91;
    q->next = p;

    printf("%s %d\n",q->name,q->score);
    printf("%s %d\n",q->next->name,q->next->score);

    getchar();
    return 0;
}
