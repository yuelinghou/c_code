//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 4) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if (a*b*c*d*e == 120)
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//
//count计数法
//size_t my_strlen(const char* string)
//{
//	size_t count = 0;
//	while(*string)
//	{
//		count++;
//		string++;
//	}
//	return count;
//}
//
//递归法
//size_t my_strlen(const char* string)
//{
//	if (*string)
//		return 1 + my_strlen(string + 1);
//	else
//		return 0;
//}
//
//指针-指针法
//unsigned int my_strlen(const char* string)
//{
//	//const修饰的安全的指针交给一个不安全的char*的指针是要强制类型转换
//	char* tmp = (char*)string;
//	while (*string)
//	{
//		string++;
//	}
//	return string - tmp;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	//先保存好目的地字符串首元素地址，最后返回它
//	char* tmp = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return tmp;
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "hijklmn";
//	printf("arr1=%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	//先保存好目的地字符串首元素地址，最后要返回它
//	char* tmp = dest;
//	//断言，保证指针的有效性
//	assert(dest != NULL);
//	assert(src != NULL);
//	//找到dest字符串中'\0'的地址
//	while (*dest)
//	{
//		dest++;
//	}
//	//开始拼接(拷贝)
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return tmp;
//}
//
//int main()
//{
//	char arr1[30] = "abcdefg";
//	char arr2[] = "hijklmn";
//	printf("arr1=%s\n", my_strcat(arr1, arr2));
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	//断言，判断指针的有效性，防止野指针
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1==*str2)
//	{
//		if (*str1 == '\0')//相等的情况
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = "abcz";
//	printf("%d\n", my_strcmp(arr1, arr2));
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//
//char* my_strstr(const char* str1, const char* str2)//const修饰的安全的指针，在赋值给不安全的指针变量和作为返回值时要进行相应的强制类型转换
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	char* cur = (char*)str1;
//	//当需要查找的字符串为空字符串时，返回这个空字符串
//	if (*str2 == '\0')
//	{
//		return (char*)str2;
//	}
//	while (*cur)
//	{
//		//记录匹配的位置
//		char* s1 = cur;
//		char* s2 = (char*)str2;
//		//开始匹配
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//匹配成功的情况
//		{
//			return cur;
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;//匹配失败的一种情况，尽早退出（例如abc  abcdef）
//		}
//		cur++;
//	}
//	return NULL;//匹配失败，找不到子串
//}
//
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bbc";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret != NULL)
//		printf("找到了：%s\n", ret);
//	else
//		printf("子串不存在\n");
//	return 0;
//}
