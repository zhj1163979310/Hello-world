#include "stdio.h"  
#include <time.h>
 
int a_1[200] = {0};  
int b_1[200] = {0};//辅助数组  
  
void dgCal(int a[],int b,int i)  
{  
	int temp;
    if(i>a[0])  
    {  
        a[0]++;  
    }  
    temp=a[i]+b;  
    if(temp>=10)  
    {  
        a[i]=temp%10;  
        dgCal(a,temp/10,i+1);  
    }  
    else  
    {  
        a[i]=temp;  
    }  
}  
  
void calculator(int a[],int b[])  
{  
    int temp=0, i;  

    for(i=1;i<=b[0];i++)  
    {  
        temp=a[i]+b[i];  
			
        if(temp>=10)  
        {  
            a[i]=temp%10;  
            dgCal(a,temp/10,i+1);//使用递归进位  
        }  
        else  
        {  
            a[i]=temp;  
        }  
          
    }  
}  
  
void copyArray(int a[],int b[])  
{  
	int i;

    for(i=0;i<=a[0];i++)  
    {  
        b[i]=a[i];  
    }  
}  
  
void printa(int a[])  
{  
	int i;
    printf("位数：%d\n",a[0]);  
    for(i=a[0];i>=1;i--)  
    {  
        printf("%d",a[i]);  
    }  
    printf("\n");   
}  
  
void printb(int b[])  
{  
	int i=0;
    printf("位数：%d\n",b[0]);  
    for(i=b[0];i>=1;i--)  
    {  
        printf("%d",b[i]);  
    }  
    printf("\n");   
}  
  
int main()  
{  
    int i,j;  
    clock_t start, finish;  
    double  duration;
  
    a_1[0]=1;  
    a_1[1]=2;  
 
    for(i=3;i<=10;i++)//从3开始  
    {   
        copyArray(a_1,b_1);  
        for(j=0;j<i-1;j++)//相加i-1次  
        {  
            calculator(a_1,b_1);  
        }  
    }  
    printf("100的阶乘：\n");   
    printa(a_1);  
    printf("99的阶乘：\n");   
    printb(b_1);  
  
 
    return 0;  
}
