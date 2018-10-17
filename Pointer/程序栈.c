/*程序栈存放栈帧(stack frame)，栈帧也称为活跃记录(activation record)或 活跃帧(activation frame)
栈帧存放函数参数和局部变量。
程序栈通常占据该区域的下部，而堆用的则是上部。*/
#include<stdio.h>

void function2()
{
    int *var1;
    int var2;
    printf("Program Stack Example\n");
    printf("&var1=%p &var2=%p\n",&var1,&var2);
}

void function1()
{
    int *var3;
    function2();
    printf("&var3=%p\n",&var3,var3);
}
int main()
{
    int *var4;
    int var5;
    function1();
    printf("&var4=%p  &var5=%p\n",&var4,&var5);

    return 0;
}

/*地址末3位：
&var4 = F2C +4
&var5 = F28 +44
&var3 = EFC +16
&var1 = ECC +4
&var2 = EC8

结论：系统在创建栈帧时，将参数以跟声明时相反的顺序推到帧上(例如最先声明的 var4 和最后声明的 var2)
*/
