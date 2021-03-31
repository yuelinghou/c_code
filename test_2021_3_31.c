#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int arr[100][100] = { 0 };
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int flag = 0;
//	for (int i = 1; i < m-1; i++)
//	{
//		for (int j = 1; j < n-1; j++)
//		{
//			if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1])
//			{
//				printf("%d %d %d\n", arr[i][j], i + 1, j + 1);
//				flag = 1;
//			}
//		}
//	}
//	if (!flag)
//	{
//		printf("None %d %d", m, n);
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	int flag = 0;
//	scanf("%d/%d/%d", &year, &month, &day);
//	int get_month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int day_number = day;
//	for (int i = 1; i < month; i++)
//	{
//		day_number += get_month_day[i];
//	}
//	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month > 2)
//	{
//		flag = 1;
//	}
//	printf("%d\n", day_number + flag);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		int t = 0;
//		int arr[10][10] = { 0 };
//		int flag = 1;
//		scanf("%d", &t);
//		for (int j = 0; j < t; j++)
//		{
//			for (int k = 0; k < t; k++)
//			{
//				scanf("%d", &arr[j][k]);
//				if (j > k&&arr[j][k] != 0)
//				{
//					flag = 0;
//				}
//			}
//		}
//		if (!flag)
//		{
//			printf("NO\n");
//		}
//		else
//		{
//			printf("YES\n");
//		}
//	}
//	return 0;
//}
