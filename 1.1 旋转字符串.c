/**
 * 单词翻转。输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变，句子中单词以空格符隔开。
 * 为简单起见，标点符号和普通字母一样处理。例如，输入“I am a student.”，则输出“student. a am I”。
 */

#include <stdio.h>
#include <stdlib.h>

void ReverseWord(char *p, char *q)
{
	char c;
	while (p < q)
	{
		c = *p;
		*p++ = *q;
		*q-- = c;
	}
}

char* ReverseSentence(char *s)
{
	char *p, *q;
	p = q = s;

	while (*q != '\0')
	{
		if (*q == ' ')
		{
			ReverseWord(p, q -1);
			q++;
			p = q;
		}
		else
		{
			q++;
		}
	}
	ReverseWord(p, q - 1);
	ReverseWord(s, q -1);
	return s;
}

int main()
{
	char str[20] = "you am a student";

	printf(ReverseSentence(str));

	system("pause");
	return 0;
}
