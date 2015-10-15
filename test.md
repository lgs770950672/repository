# repository
my repository
=还是拿上面的21543举例，那么，应用next_permutation算法的过程如下：



```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void reverse(char *s, char *e)
{
	while(s < e)  
		swap(*s++ , *e--);
}


bool CalcAllPermutation4 (char *str, int num)
{
	if (!str) return false;
	int i, k;

	//①找到排列中最后（最右）一个升序的首位位置i，x = ai  ai < ai+1
	for (i = num - 2; (i >= 0); i--)
	{
		if (str[i] < str[i+1]) {
			break;
		}		
	}
	if (i < 0) return false;
	//②找到排列中第i位右边最后一个比ai 大的位置j，y = aj
	for (k = num - 1; (k > 0); k--)
	{
		if (str[k] > str[i])
		{
			break;
		}
	}
	if (k < 0) return false;
	//③交换x，y
	swap(str[i], str[k]);
	//④把第(i + 1)位到最后的部分翻转
	reverse(str + i + 1, str + num - 1);
	return true;
}

int main()
{
	char str[] = "abc";
	int str_len = strlen(str);
	//abc
	//acb	
	//bac
	//bca
	//cab
	//cba
	
	do 
	{
		printf("%s\n", str);		
		
	} while (CalcAllPermutation4(str, str_len));

	system("pause");
	return 0;
}
```
然后在主函数里循环判断和调用calcAllPermutation函数输出全排列即可。
