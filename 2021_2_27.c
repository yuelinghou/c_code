#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
//int Search_Substring(const char* sou,const char* str)
//{
//	assert(sou != NULL);
//	assert(str != NULL);
//	char tmp[100] = { 0 };
//	strcpy(tmp, sou);
//	strcat(tmp, sou);
//	if (strstr(tmp, str) != NULL)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	char arr1[] = "AABCD";
//	char arr2[] = "BCDAA";
//	if (Search_Substring(arr1, arr2))
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//char* Left_Rotate_String(char* str, int n,int sz)
//{
//	
//}
//
//int main()
//{
//	char arr[] = "ABCD";
//	int k = 2;
//	int sz = strlen(arr);
//	printf("%s\n", Left_Rotate_String(arr, k,sz));
//	return 0;
//}



//参考答案(答题后可查看)
//设计循环使其可以旋1次，然后让他执行n次是一个最简单的思路：
//
//
//
//void leftRound(char * src, int time)
//{
//	int i, j, tmp;
//	int len = strlen(src);
//	time %= len; //长度为5的情况下，旋转6、11、16...次相当于1次，7、12、17...次相当于2次，以此类推。
//	for (i = 0; i < time; i++) //执行k次的单次平移
//	{
//		tmp = src[0];
//		for (j = 0; j < len - 1; j++) //单次平移
//		{
//			src[j] = src[j + 1];
//		}
//		src[j] = tmp;
//	}