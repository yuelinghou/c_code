#define _CRT_SECURE_NO_WARNINGS 1

#include"game2.h"

//�˵�����
void menu()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}

//��Ϸ����
void game()
{
	//�׵���Ϣ����
	//1.�׷ֲ�������
	char mine[ROWS][COLS] = { 0 };//��Ҳ��ܿ�
	//2.�Ų�����Ϣ������
	char show[ROWS][COLS] = { 0 };//��ҽ�����Ϸʱ�������

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);

	//ɨ��
	FindMine(mine,show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));//������������������
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}