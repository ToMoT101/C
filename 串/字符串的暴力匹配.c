#pragma warning(disable:6031)//屏蔽scanf报错
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define Max 255
typedef struct String
{
	char str[Max+1];
	int len;
}string;
string* init_string()
{
	string* str=(string*)malloc(sizeof(string));
	if (str == NULL)
		exit(-1);
	str->len = 0;
	return str;
}
int string_len(string* str)
{
	int len = str->len;
	return len;
}
string* string_assign(string* str1,char str2[])
{
	int i = 1;
	for ( i; str2[i-1] != '\0'; i++)
	{
		str1->str[i] = str2[i - 1];
	}
	str1->len = i-1;
	return str1;
}
void string_print(string *str)
{
	for (int i = 1; i <= str->len; i++)
		printf("%c", str->str[i]);
	printf("\n");
}
int string_match(string*main, string*son)
{
	int match_time = main->len - son->len + 1;
	bool flag = false;
	for (int i = 1; i <= match_time; i++)
	{
		for (int j = 1; j <= son->len; j++)
		{
			if (main->str[i + j - 1] == son->str[j])
				flag = true;
			else
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			return i;
		}
	}
	printf("不存在匹配的字符串\n");
	return -1;
}
void main()
{
	string* s_1;
	string* s_2;
	char a[] = "abcdefgh";
	char b[] = "cc";
	int len_1, len_2;
	s_1 = init_string();
	s_2 = init_string();
	string_assign(s_1, a);
	string_assign(s_2, b);
	//主串
	printf("主串为： ");
	string_print(s_1);
	len_1 = string_len(s_1);
	printf("字符串长度为：  %d\n", len_1);
	//子串
	printf("子串为： ");
	string_print(s_2);
	len_2 = string_len(s_2);
	printf("字符串长度为：  %d\n", len_2);

	int pos;
	pos = string_match(s_1, s_2);
	if (pos != -1)
		printf("字串位置在-> %d\n", pos);




}