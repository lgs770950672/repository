# repository
my repository
=还是拿上面的21543举例，那么，应用next_permutation算法的过程如下：

#x = 1；
##y = 3
*1和3交换*
**得23541**
~~翻转541~~
>得23145
//23145即为所求的21543的下一个排列。参考实现代码如下：
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

bool CalcAllPermutation1(char* perm, int num){
	int i;

	//①找到排列中最后（最右）一个升序的首位位置i，x = ai
	for (i = num - 2; (i >= 0) && (perm[i] >= perm[i + 1]); --i){
		;
	}
	// 已经找到所有排列
	if (i < 0){
		return false;
	}

	int k;
	//②找到排列中第i位右边最后一个比ai 大的位置j，y = aj
	for (k = num - 1; (k > i) && (perm[k] <= perm[i]); --k){
		;
	}

	//③交换x，y
	swap(perm[i], perm[k]);
	//④把第(i+ 1)位到最后的部分翻转
	reverse(perm + i + 1, perm + num);
	//cout << perm;
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
