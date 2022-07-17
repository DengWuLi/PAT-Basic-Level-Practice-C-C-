/*  PTA 1002 写出这个数
 *  2022/07/17
 * */
#include<stdio.h>
#include<math.h>
int main()
{
	char a[100];
	int sum = 0, c = 0, ss = 0;//c用于记录数字
	int gg = 0, z = 0;
	int mm = 0;
	gets(a);//输入到字符数组，算出总和
	for (int x = 0; a[x] != '\0'; x++)
	{
		sum = a[x] - 48 + sum;
	}
	ss = sum;
	//判断多少位
	while (sum != 0)
	{
		sum /= 10;
		c++;
	}
	// 开始输出
	for (int i = c; i > 0; i--)
	{
		z = ss / pow(10, i - 1);
		z = z % 10;
		if (i == 1)
		{
			switch (z)
			{
				case 0:printf("ling");
					break;
				case 1: printf("yi");
					break;
				case 2: printf("er");
					break;
				case 3: printf("san");
					break;
				case 4: printf("si");
					break;
				case 5: printf("wu");
					break;
				case 6: printf("liu");
					break;
				case 7: printf("qi");
					break;
				case 8: printf("ba");
					break;
				case 9: printf("jiu");
					break;
				
			}
		}
		else
		{
			switch (z)
			{
				case 0:printf("ling ");
					break;
				case 1: printf("yi ");
					break;
				case 2: printf("er ");
					break;
				case 3: printf("san ");
					break;
				case 4: printf("si ");
					break;
				case 5: printf("wu ");
					break;
				case 6: printf("liu ");
					break;
				case 7: printf("qi ");
					break;
				case 8: printf("ba ");
					break;
				case 9: printf("jiu ");
					break;
			}
		}
		
	}
	getchar();
	return 0;
}
