#define _CRT_SECURE_NO_WARNINGS 1

#include"game2.h"

//菜单函数
void menu()
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}

//游戏函数
void game()
{
	//雷的信息储存
	//1.雷分布的棋盘
	char mine[ROWS][COLS] = { 0 };//玩家不能看
	//2.排查雷信息的棋盘
	char show[ROWS][COLS] = { 0 };//玩家进行游戏时候的棋盘

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);

	//扫雷
	FindMine(mine,show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}