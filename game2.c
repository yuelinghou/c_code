#define _CRT_SECURE_NO_WARNINGS 1

#include"game2.h"

//��mine���̣�һ��ʼȫ��ʼ��Ϊ'0'��������׵�����λ�ø�Ϊ'1'
//��show���̣�һ��ʼȫ��ʼ��Ϊ'*'������ɨ��ʱ���ѡ�������λ�ø�Ϊ��Χ�׵ĸ���
void InitBoard(char(*p)[COLS], int row, int col, char set)//setΪ��Ҫ��ʼ�����ַ�
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			*(*(p + i) + j) = set;
		}
	}
}

void DisplayBoard(char(*ps)[COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ������һ�е���������ͷָ���
	printf("   ");
	for (i = 1; i <= 9; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("   ");
	for (i = 1; i <= 9; i++)
	{
		printf("--");
	}
	printf("\n");
	//��ӡ����ߵ���������ͷָ����Լ���Ӧ����������
	for (i = 1; i <= row; i++)
	{
		printf("%d |", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", *(*(ps + i) + j));
		}
		printf("\n");
	}
}

void SetMine(char(*pm)[COLS], int row, int col)
{
		int count = MAX_MINE;//count��¼��Ҫ�ŵ��׵ĸ���
		while (count)
		{
			int x = rand() % row + 1;//1-9������
			int y = rand() % col + 1;//1-9������
			//�ж���������������Ѿ�����
			if (*(*(pm + x) + y) == '0')
			{
				*(*(pm + x) + y) = '1';
				count--;
			}
		}
}

//��������Χ8��λ�õ��ַ�����ټ�ȥ8 * '0'��ASCLL����Ĳ�ֵ������Χ�׵ĸ���
static int Find_Mine_Count(char(*pm)[COLS], int x, int y)
{
	return
		(*(*(pm+x + 1) - 1+y) +
			*(*(pm+x + 1)+y) +
			*(*(pm+x + 1) + 1+y) +
			*(*(pm+x)- 1+y) +
			*(*(pm+x)+1+y) +
			*(*(pm+x - 1) - 1+y) +
			*(*(pm+x - 1)+y) +
			*(*(pm+x - 1) + 1+y)) - 8 * '0';
}

void FindMine(char(*pm)[COLS], char(*ps)[COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row*col - MAX_MINE)//�����з���λ�ö���ȷ��ʱ��win=row*col - MAX_MINE
	{
		printf("���������꣨�ÿո�ָ���:>");
		scanf("%d%d", &x, &y);
		//1.�ж����������Ƿ���ȷ
		if (x >= 1 && x <= row && y >= 1 && y <= col)//������ȷ�����
		{
			//2.�ж����������Ƿ��ظ�
			if (*(*(ps + x) + y) != '*')//�����ظ������
			{
				printf("�������ѱ�����\n");
			}
			else//���겻�ظ������
			{
				//3.�ж��Ƿ����
				if (*(*(pm + x) + y) == '1')//���׵����
				{
					printf("���ź����㱻ը����\n");
					break;
				}
				else//û���׵����
				{
					int count = Find_Mine_Count(pm, x, y);
					*(*(ps + x) + y) = count + '0';
					DisplayBoard(ps, row, col);
				}
			}
		}
		else//�����������
		{
			printf("�������\n");
		}
	}
	//����ж�ѭ����������Ϊ����֮��break�����Ļ���ɨ�׳ɹ�����ѭ����
	
    if(win == row * col - MAX_MINE)
	{
		printf("��ϲ�㣬ɨ�׳ɹ���\n");
	}
}
