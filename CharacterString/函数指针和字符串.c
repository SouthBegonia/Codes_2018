/*运用函数指针和字符串，对指针数组*names[] 内元素进行排序*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>   //tolower

/*普通 strcmp比较，存在局限*/
int compare(const char *s1, const char *s2)
{
    return strcmp(s1,s2);
}

/*转换成小写*/
char* stringToLower(const char *string)
{
    char *tmp = (char *)malloc(strlen(string)+1);
    char *start = tmp;

    while(*string != 0)
    {
        *tmp++ = tolower(*string++);
    }
    *tmp = 0;
    return start;
}

/*将字符串转换为小写，再进行比较，结果返回*/
int compareIgnoreCase(const char *s1, const char *s2)
{
    char *t1 = stringToLower(s1);
    char *t2 = stringToLower(s2);

    int result = strcmp(t1,t2);
    free(t1);
    free(t2);

    return result;
}

/*声明使用的函数指针*/
typedef int (fptrOperation)(const char *,const char *);

/*冒泡排序*/
void sort(char *array[], int size, fptrOperation Operation)
{
    int swap = 1;
    while(swap)
    {
        swap = 0;
        for(int i=0;i<size-1;i++)
        {
            if(Operation(array[i],array[i+1]) > 0)
            {
                swap = 1;
                char *tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
    }
}

/*打印结果*/
void displayNames(char *names[], int size)
{
    for(int i=0;i<size;i++)
        printf("%s   ",names[i]);
    printf("\n");
}

int main()
{
    char *names[] = {"Bob","Ted","Carol","Alice","alice"};
    char *names_2[] = {"Bob","Ted","Carol","Alice","alice"};

    printf("compareIgnoreCase:");
    sort(names,5,compareIgnoreCase);
    displayNames(names,5);

    printf("compare:          ");
    sort(names_2,5,compare);
    displayNames(names_2,5);

    return 0;
}
