#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//int main()
//{
//	printf("\a");
//	printf("\a");
//	printf("\a");
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//void Left_Round(char* src, int time)
////src为数组首元素地址
////time为需要左旋的字符的个数
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(src);//计算字符串中字符的个数
//	//逐个旋转字符，需要旋转time次
//	for (i = 0; i < time; i++)
//	{
//		char tmp = src[0];//先把第一个字符保存起来，不然后面挪动的时候会被覆盖
//		//把数组元素都往前挪一个位置
//		for (j = 0; j < len - 1; j++)
//		{
//			src[j] = src[j + 1];
//		}
//		//挪完后把前面保存的第一个字符放到最后一个位置，完成一个字符的旋转
//		src[j] = tmp;
//	}
//}

//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//#include<assert.h>
//#include<stdlib.h>
//
//void Left_Round(char* src, int pos)
//{
//	assert(src != NULL);//断言，保证指针的有效性，防止野指针
//	int len = strlen(src)+1;//最后有个'\0'的位置也要开辟
//	char* tmp = malloc(len * sizeof(char));//开辟与src同等大小的数组
//	//判断空间是否开辟成功
//	if (tmp==NULL)
//	{
//		printf("%s\n",strerror(errno));
//		exit(-1);
//	}
//	//第一步
//	strcpy(tmp, src + pos);
//	//第二步
//	strncat(tmp, src, pos);
//	//第三步
//	strcpy(src, tmp);
//	//释放动态开辟的空间
//	free(tmp);
//	tmp = NULL;
//}
//
//int main()
//{
//	char arr[] = "ABCD";
//	Left_Round(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//
////逆序
//void Reverse_Part(char* start, char* end)
//{
//	char tmp = 0;//中间变量，逆序两个数时保存你需求的数据
//	//开始逆序
//	while (start < end)
//	{
//		tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//
////左旋
//void Left_Round(char* src, int time)
//{
//	assert(src != NULL);//断言，保证指针的有效性，防止野指针
//	int len = strlen(src);
//	//第一步：把要左旋的部分逆序
//	Reverse_Part(src, src+time - 1);
//	//第二步：逆序不左旋的那部分字符串
//	Reverse_Part(src+time, src+len-1);
//	//第三步：逆序整个字符串
//	Reverse_Part(src, src + len - 1);
//}
//
//int main()
//{
//	char arr[] = "ABCD";
//	Left_Round(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//
//int Find_Num(int(*p)[3], int row, int col, int num)
//{
//	int r = 0;
//	int c = col - 1;
//	while (r < 3 && c >= 0)
//	{
//		if (*(*(p + r) + c) > num)
//		{
//			c--;
//		}
//		else if (*(*(p + r) + c) < num)
//		{
//			r++;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int num = 3;
//	int arr[][3] = { {1, 2, 3},
//				  {4, 5, 6},
//				  {7, 8, 9} };
//	if (Find_Num(arr, 3, 3, 10))
//	{
//		printf("找到了\n");
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


