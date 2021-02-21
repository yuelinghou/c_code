//引用库函数的头文件
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//声明表示棋盘大小的量
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define MAX_MINE 10

//声明函数
void InitBoard(char(*p)[COLS], int row, int col, char set);
void DisplayBoard(char(*ps)[COLS], int row, int col);
void SetMine(char(*pm)[COLS], int row, int col);
void FindMine(char(*pm)[COLS], char(*ps)[COLS], int row, int col);

