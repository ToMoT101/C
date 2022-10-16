#pragma warning(disable:6031)//����scanf����
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
typedef char string;

int* GetNext(string str[])
{
	//    "ababaa"-> a(x) -> ab(x) -> aba -> abab -> ababa -> ababaa
	int* next = (int*)malloc(sizeof(int) * 8);
	if (next == NULL)
		exit(-1);
	next[1] = 0;  //��һ���ض�Ϊ0
	if (strlen(str)-1 == 1)
		return next;
	else if (strlen(str)-1 == 2)
	{
		next[2] = 1; 
		return next;
	}
	else  //3����3���ַ�����  
	{
		next[2] = 1;
		for (int i = 3; i <= 7; i++)
		{
			next[i] = 0;
		}
		for (int now = 3; now <= 7; now++)
		{
			//�������ͬǰ��׺����,�������εݼ�
			int front = 1, back = 2, now_move = now;
			for (back; back != now_move; back++) //����(����)
			{
				int front_move = front, back_move = back;
				if (str[front] == str[back]) //ǰ׺�ͺ�׺�ĵ�һ���ַ���ͬ
				{
					while (back_move != now_move)//�Ƚϸó��ȵ�ǰ��׺�ġ������ַ����Ƿ����
					{
						if (++back_move == now_move) //���ú�ָ������ƶ�,�����ó��ȵĺ�׺������û��
						{
							//�ҵ��˸ó��ȵ���ͬǰ��׺
							next[now_move] = back_move - back;//��ָ���ƶ��ľ���-1�������ͬǰ��׺  
							back = now_move - 1;  //�ҵ���next[]��ֵ���Ϳ��Ե��˳���
							//��ʱ��back_move == now_move����back <= now_move
							//Ϊ�˷�ֹback�������ƣ�Ҫ��back==now_move�������˳�ѭ��
							//����������for(back)ѭ����back+1
							//�����back = now_move - 1��ѭ����back + 1������back == now_move
							//�����˳�ѭ����																
						}
						else
						{
							front_move++;  //��ǰָ������ƶ����Ƚϵ�ǰ��Ӧ�ַ��Ƿ����
							if (str[back_move] != str[front_move]) //�����->�м����
								break;  //����whileѭ����back���ƣ�˵����ǰ���Ȳ�������ͬǰ��׺
						}
					}
				}
				//str[front] != str[back]   ->   �ó���������ͬǰ��׺������-1�ٿ����Ƿ������ͬǰ��׺
				//->ֱ����back_move����ƶ�
			}
		}
		for (int i = 3; i <= 7; i++)
		{
			next[i] += 1;
		}
		return next;
	}
}
void main()
{
	string str[] = "0ababaaa"; //  
	//printf("%d", strlen(str));
	int * next = GetNext(str);
	for (int i=1;i<=7;i++)
	{
		printf("%d", next[i]);
	}
}

