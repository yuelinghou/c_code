#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
////令left指向最左边的元素,right指向最右边的元素,交换两个位置元素的值之后left++，right- -，逐渐靠近，直到letf>=right为止。
//char* my_strrev(char* string)
//{
//	assert(string != NULL);//断言，保证指针的有效性，防止野指针
//	char* tmp1 = string;//记住该字符串的首元素地址，最后返回
//	char* left = string;//left为最左边元素地址
//	char* right = string + strlen(string) - 1;//right为最右边元素地址（'\0'前面的那个）
//	while (left < right)
//	{
//		//开始交换两头的字符
//		char tmp2 = *left;
//		*left = *right;
//		*right = tmp2;
//		left++;
//		right--;
//	}
//	return tmp1;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", my_strrev(arr));
//	return 0;
//}

//#include<stdio.h>
////#include<assert.h>
//
//int cmp(const void* elem1, const void* elem2)
//{
//	return *(int*)elem1 - *(int*)elem2;
//}

//void Swap(char* buf1, char* buf2, int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void Bubble_Sort(void* base, int num, int width, int(*cmp)(void*, void*))
//{
//	assert(base != NULL);//断言，保证指针的有效性，防止野指针
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (1 + j)*width) >0)
//			{
//				flag = 0;
//				Swap((char*)base + j * width, (char*)base + (1 + j)*width, width);
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//#include<stdio.h>
//
//void Bubble_Sort(void* base, int num, int width, int(*cmp)(void*, void*));//对冒泡排序算法函数进行声明

//使用者自定义的比较函数，用来比较两个因素的大小，返回两个因素的差值
//int cmp(const void* elem1, const void* elem2)
//{
//	return *(int*)elem1 - *(int*)elem2;
//}


//int main()
//{
//	int arr[] = { 9,8,7,6,5,4};
//	int sz = sizeof arr / sizeof arr[0];//计算数组元素个数
//	Bubble_Sort(arr, sz, sizeof arr[0], cmp);
//	//打印排序后的数组
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

#include<stdio.h>

void Bubble_Sort(void* base, int num, int width, int(*cmp)(void*, void*));//对冒泡排序算法函数进行声明

//声明结构体类型
struct S
{
	char name[20];
	int age;
};

//比较结构体成员中的age（通过age的大小来进行排序）
int cmp(const void* s1, const void* s2)
{
	return (((struct S*)s1)->age) - ((struct S*)s2)->age;
}



int main()
{
	struct S s[4] = { {"zhangsan",20},{"lisi",28},{"wangwu",32},{"ergou",11} };//创建struct S这个类型的结构体数组
	int sz = sizeof s / sizeof s[0];
	Bubble_Sort(s, sz, sizeof s[0], cmp);//使用Bubble_Sort开始排序
	//第一个参数：待排序数组的首元素地址
	//第二个参数：待排序数组的元素个数
	//第三个参数：待排序数组每个元素的大小（单位是字节）
	//第四个参数：函数指针（比较两个元素所用的函数地址）
	return 0;
}