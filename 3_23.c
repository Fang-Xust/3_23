1.在屏幕上输出以下图案： 
      * 
     *** 
    ***** 
   ******* 
  ********* 
 *********** 
************* 
 *********** 
  ********* 
   ******* 
    ***** 
     *** 
      * 
2.求出0～999之间的所有“水仙花数”并输出。

3.求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字， 
例如：2+22+222+2222+22222 


1、
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main() 
{
	char arr1[] = "*****************************************************";
	char arr2[] = "                                                     ";
	int left=0;
	int right=strlen(arr1)-1;
	int mid = left + (right - left) / 2;
	for (left=mid,right=mid; left >= 0 && right <= strlen(arr2)-1; left--,right++)
	{                                  //算出中间的下标mid，并赋给left和right
		arr2[left] = '*';              //从中间向两边给字符数组赋值'*',打印上三角
		arr2[right] = '*';
		printf("%s\n",arr2);
		Sleep(100);                   //Sleep()函数是#include<windows.h>下的函数，可以让程序执行到它时暂停100ms，单位是毫秒
	}
	for (left = 0, right = strlen(arr1)-1; left <=mid && right >= mid; left++, right--)
	{                                  //算出两边的下标，并赋给left和right
		arr1[left] = ' ';              //从两边向中间给字符数组赋值' ',打印下三角
		arr1[right] = ' ';
		printf("%s\n",arr1);
		Sleep(100);
	}
	system("pause");
	return 0;
}
////////int main()
////////{
////////	int line = 0;
////////	scanf("%d",&line);
////////	//上半部分
////////	int i = 0;
////////	int j = 0;
////////	for (i = 0; i < line; i++)
////////	{
////////		for (j = 0; j < line-1-i; j++)
////////		{
////////			printf(" ");
////////		}
////////		for (j = 0; j < 2 * i + 1; j++)
////////		{
////////			printf("*");
////////		}
////////		printf("\n");
////////	}
////////	//下半部分
////////	for (i = 0; i < line - 1; i++)
////////	{
////////		for (j = 0; j <= i; j++)
////////		{
////////			printf(" ");
////////		}
////////
////////		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
////////		{
////////			printf("*");
////////		}
////////		printf("\n");
////////	}
////////	system("pause");
////////	return 0;
////////}
2、
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i, j, k, r;
	printf("0-999之间的水仙花数是：\n");
	for (i = 1; i < 1000; i++)
	{
		j = i / 100;                  //百位
		k = (i / 10) - (j * 10);      //十位
		r = i % 10;                   //个位
		if (i == pow(j, 3) + pow(k, 3)+pow(r, 3) && i != 1)
		{                                 //pow()函数是求次方的函数，用头文件#include<math.h>包含
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}


3、
#include<stdio.h>
#include<stdlib.h>
int main() 
{                              //求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和
	int a;
	int Sn=0,sum=0;
	scanf("%d",&a);
	for (int i = 0; i < 5; i++)
	{
		sum = (sum * 10) + a;       //这里加上a，a是个位数字
		Sn = Sn + sum;              //把上一步算出来的结果进行累加
	}
	printf("%d", Sn);
	system("pause");
	return 0;
}
