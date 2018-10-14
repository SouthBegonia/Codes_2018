/*低精度到高精度引起的截断
事例1：pow函数内int型到 float，double 型造成的截断
事例2：较低精度 float型进行 += 造成的截断*/
#include <stdio.h>
#include <math.h>

int main()
{
   /*pow函数内的截断*/
   int ans_1=0;
   int i=0;
   float j=0, ans_2=0;
   double k=0, ans_3=0;
   
   /*float到double的截断
   参考地址：https://blog.csdn.net/ruheshiluo/article/details/9258625*/
   float a_1 = 1.f/81;
   float b_1 = 0;
   double a_2 = 1.0/81;
   double b_2 = 0;
   
   
   
   /*ans_1,i 为 int 类型
   此类型的显隐式转换会造成截断*/
   ans_1=pow(10.0,i+4);
   printf("int:    ans_1 =%d\n",ans_1);
   printf("float:  ans_1 =%f\n",(float)ans_1);
   printf("double: ans_1 =%lf\n\n",(double)ans_1);
   
   /*ans_2,j 为 float 类型*/
   ans_2=pow(10.0,j+4.0);
   printf("int:    ans_2=%d\n",(int)ans_2);
   printf("float:  ans_2=%f\n",ans_2);
   printf("double: ans_2=%lf\n\n",(double)ans_2);
   
   /*ans_3,k 为 double 类型*/
   ans_3=pow(10.0,k+4.0);
   printf("int:    ans_3=%d\n",(int)ans_3);
   printf("float:  ans_3=%f\n",(float)ans_3);
   printf("double: ans_3=%lf\n\n",ans_3);
   
   
   
   /*a_1,b_1 为 float 类型*/
   for (int i = 0; i < 729; ++ i)
   		b_1 += a_1;     // += 引起的截断
   printf("%.15g\n", b_1);
    
    /*a_2,b_2 为 double 类型*/
   for (int i = 0; i < 729; ++ i)
		b_2 += a_2;
   printf("%.15g\n", b_2);
   
   getchar();
   return 0;
}
