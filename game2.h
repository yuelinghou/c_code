//���ÿ⺯����ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//������ʾ���̴�С����
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define MAX_MINE 10

//��������
void InitBoard(char(*p)[COLS], int row, int col, char set);
void DisplayBoard(char(*ps)[COLS], int row, int col);
void SetMine(char(*pm)[COLS], int row, int col);
void FindMine(char(*pm)[COLS], char(*ps)[COLS], int row, int col);

