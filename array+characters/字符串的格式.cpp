#include<stdio.h>
#include<string.h>
int main()
{
	char a; int b; short c; float d; double e; double m[5];
	
	char x[5]={"Rorn"};   //只计入Mike\0共5字符，占5字节 
    char y[]="Harry";     //!!!字符串格式!!! 
    
	char z[10];    //必须有范围才可等待输入 
	
	printf("各种数据类型大小：字节\n"); 
	printf("char=%d\nint=%d\nshort=%d\nfloat=%d\ndouble=%d\ndouble m[5]=%d\n",sizeof(a),sizeof(b),sizeof(c),sizeof(d),sizeof(e),sizeof(m));
	
	//字符串的格式： 
	printf("\n%s\t%s\n",x,y);
	printf("两字符串占用大小:%-3d%-3d\n",sizeof(x),sizeof(y));
	
	//输入字符串的格式： 
	printf("\nInput some string:"); 
	gets(z);       //必须有范围才可输入
	printf("%s\n大小为：%d",z,sizeof(z));   //占用大小仍为10字节 
	return 0;
}
