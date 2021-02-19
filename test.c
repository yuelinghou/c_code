#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//void bubble_sort(int* p, int n)
//{
//	int i = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - 1 - i;j++)
//		{
//			if (p[j] > p[j + 1])
//			{
//				int tmp = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 5,9,7,3,16,55,79,11,17,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//
//void init(int* p, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		*(p + i) = 0;
//	}
//}
//
//int main()
//{
//	int arr[] = {1,88,15,47,69,3,15,67};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	init(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//
//void print(int* p, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,88,15,47,69,3,15,67 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}
//#include<stdio.h>
//
//void reverse(int* p, int n)
//{
//	int left = 0;
//	int right = n - 1;
//	while (left < right)
//	{
//		int tmp = p[left];
//		p[left] = p[right];
//		p[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,88,15,47,69,3,15,67 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	printf("逆序前：");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%-2d ", arr[i]);
//	}
//	printf("\n");
//	reverse(arr, sz);
//	printf("逆序后：");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%-2d ", arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//
//void exchange(int* p1, int* p2, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int tmp = *(p1 + i);
//		*(p1 + i) = *(p2 + i);
//		*(p2 + i) = tmp;
//	}
//}
//
//int main()
//{
//	int arr1[] = { 147,258,369 };
//	int arr2[] = { 123,456,789 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	//交换前的打印
//	printf("交换前：\n");
//	int i = 0;
//	int j = 0;
//	printf("arr1:");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\narr2:");
//	for (j = 0; j < sz; j++)
//	{
//		printf("%d ", arr2[j]);
//	}
//	//交换
//	exchange(arr1, arr2, sz);
//	//交换后的打印
//	printf("\n交换后：\n");
//	printf("arr1:");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\narr2:");
//	for (j = 0; j < sz; j++)
//	{
//		printf("%d ", arr2[j]);
//	}
//	return 0;
//}
//#include<stdio.h>
//
//int count_bit_one(int num)
//{
//	int count = 0;
//	while (num)
//	{
//		count++;
//		num = num & (num - 1);
//	}
//	return count;
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	printf("%d\n", count_bit_one(num));
//	return 0;
//}
//#include<stdio.h>
//
//int count_diff_bit(int num1, int num2)
//{
//	int num = num1 ^ num2;
//	int count = 0;
//	while (num)
//	{
//		count++;
//		num = num & (num - 1);
//	}
//	return count;
//}
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d%d", &num1, &num2);
//	printf("%d\n", count_diff_bit(num1, num2));
//	return 0;
//}
//#include<stdio.h>
//
//void PrintBit(int num)
//{
//	printf("奇数位：");
//	int i = 0;
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n偶数位：");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	PrintBit(num);
//	return 0;
//}
//#include<stdio.h>
//
//void exchange(int* num1, int* num2)
//{
//	*num1 = (*num1) ^ (*num2);
//	*num2 = (*num1) ^ (*num2);
//	*num1 = (*num1) ^ (*num2);
//}
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d%d", &num1, &num2);
//	printf("num1=%d num2=%d\n", num1, num2);
//	exchange(&num1, &num2);
//	printf("num1=%d num2=%d\n", num1, num2);
//	return 0;
//}