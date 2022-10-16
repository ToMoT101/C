#pragma warning(disable:6031)//����scanf����
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 255
typedef struct String
{
	char str[Max + 1];
	int len;
}string;
string* init_string()
{
	string* str = (string*)malloc(sizeof(string));
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
string* string_assign(string* str1, char str2[])
{
	int i = 1;
	for (i; str2[i - 1] != '\0'; i++)
	{
		str1->str[i] = str2[i - 1];
	}
	str1->len = i - 1;
	return str1;
}
void string_print(string* str)
{
	for (int i = 1; i <= str->len; i++)
		printf("%c", str->str[i]);
	printf("\n");
}
//*************************************** next[] **************************************
int* GetNext(string *s)
{
	int* next = (int*)malloc(sizeof(int) * s->len + 1);
	if (next == NULL)
		exit(-1);
	*(next+1) = 0;  //��һ���ض�Ϊ0
	if (s->len == 1)
		return next;
	else if (s->len == 2)
	{
		*(next + 2) = 1;  //�ڶ����ض�Ϊ1
		return next;
	}
	else  //3���ַ�������
	{
		*(next + 2) = 1;
		for (int i = 3; i <= s->len; i++)
		{
			*(next + i) = 0;
		}
		for (int now = 3; now <= s->len; now++)
		{
			//�������ͬǰ��׺����,�������εݼ�
			int front = 1, back = 2, now_move = now;
			for (back; back != now_move; back++) //����(����)
			{
				int front_move = front, back_move = back;
				if (s->str[front] == s->str[back]) //ǰ׺�ͺ�׺�ĵ�һ���ַ���ͬ
				{
					while (back_move != now_move)//�Ƚϸó��ȵ�ǰ��׺�ġ������ַ����Ƿ����
					{
						if (++back_move == now_move) //���ú�ָ������ƶ�,�����ó��ȵĺ�׺������û��
						{
							//�ҵ��˸ó��ȵ���ͬǰ��׺
							*(next + now_move) = back_move - back;
							back = now_move - 1;  //�ҵ���next[]��ֵ���Ϳ��Ե��˳���															
						}
						else
						{
							front_move++;  //��ǰָ������ƶ����Ƚϵ�ǰ��Ӧ�ַ��Ƿ����
							if (s->str[back_move] != s->str[front_move]) //�����->�м����
								break;  //����whileѭ����back���ƣ�˵����ǰ���Ȳ�������ͬǰ��׺
						}
					}
				}
			}
		}
		for (int i = 3; i <= s->len; i++)
		{
			*(next + i) += 1;  //�����ͬǰ��׺+1
		}
		return next;
	}
}
//*************************************** KMP�㷨 **************************************
int KMP(string* main, string* son, int *next)
{
	/*for (int i = 1; i <= main->len; i++)
		printf("%c", main->str[i]);
	
	printf("\n");
	for (int i = 1; i <= son->len; i++)
		printf("%c", son->str[i]);

	printf("\n");
	for (int i = 1; i <= son->len; i++)
		printf("%d", next[i]);
	printf("\n");
	printf("main_len = %d,son_len = %d\n", main->len, son->len);*/
	int p_main = 1, p_son = 1;
	for (p_main; p_main <= main->len; p_main++ )
	{
		if (main->str[p_main] != son->str[p_son])
		{
			while (p_son > 1)
			{
				p_son = next[p_son - 1] + 1;
				if (main->str[p_main] == son->str[p_son])
				{
					p_son++;  //��ȣ����Ӵ�ָ����ƣ�������һ��ĶԱȣ������elseԭ��һ��
					break;    //��������ٻ���
				}
			}
			//���Ӵ���һ���ַ�ʼ����������Ӧ�ַ������ʱ���������ʣ����ַ�(������ǰ�ַ�)���ִ��ĳ���
		    //���ʱ����ʱ�Ӵ���һ���ַ����Ǻ͵�ǰ�ַ�����ȣ��򲻱ؼ����ƶ�����ָ�룬
			//��Ϊ�ƶ�����ָ�������ʣ���ַ���(������ǰ�ַ�) < �Ӵ��ĳ���
			//��Ҫ�ǳ��Ȳ�ͬ���ٱȽϾ��������ˣ���η�ֹ����ָ��Խ�磬���������ַ�һֱ��ͬ��
			//������ָ���һֱ���ƣ�ֱ���Ӵ�ָ��ָ�����һ���ַ���
			//��ʱ�����ܻ����Ӵ�ָ��ָ�����һ���ַ�ǰ������ָ���Ѿ�ָ�������һ���ַ������λ��
			//�ͻᷢ����Խ����Ϊ��
			if ((p_main == main->len - son->len + 1) && p_son == 1)
				return -1;
		}
		else
		{
			p_son++;
		}
		if (p_son == son->len + 1)
		{
			return p_main - p_son + 2;
		}
	}
	return -1;
}
void main()
{
	//*****************************************  KMPƥ��  ************************************
	
	//0.��ȡnext[]����
	string* test;
	test = init_string();
	char ch[] = "ababaab";
	string_assign(test, ch);
	int* next_test = GetNext(test);
	for (int i=1;i<=test->len;i++)
	{
		printf("%d", next_test[i]);
	}
	printf("\nnext[]���Խ���\n");
	//1.��ȡnext[]
	string* str_main, * str_son;
	char ch_main[] = "abababcaa";
	char ch_son[] =  "caa";
	str_main = init_string();
	str_son = init_string();
	string_assign(str_main, ch_main);
	string_assign(str_son, ch_son);
	int* next = GetNext(str_son);
	//2.ģʽƥ��
	printf("����:   ");
	string_print(str_main);
	printf("ģʽ��: ");
	string_print(str_son);
	printf("ƥ������");
	int pos;
	pos = KMP(str_main, str_son, next);
	printf("λ�� = %d\n", pos);

}