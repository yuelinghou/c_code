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
//count������
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
//�ݹ鷨
//size_t my_strlen(const char* string)
//{
//	if (*string)
//		return 1 + my_strlen(string + 1);
//	else
//		return 0;
//}
//
//ָ��-ָ�뷨
//unsigned int my_strlen(const char* string)
//{
//	//const���εİ�ȫ��ָ�뽻��һ������ȫ��char*��ָ����Ҫǿ������ת��
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
//	//�ȱ����Ŀ�ĵ��ַ�����Ԫ�ص�ַ����󷵻���
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
//	//�ȱ����Ŀ�ĵ��ַ�����Ԫ�ص�ַ�����Ҫ������
//	char* tmp = dest;
//	//���ԣ���ָ֤�����Ч��
//	assert(dest != NULL);
//	assert(src != NULL);
//	//�ҵ�dest�ַ�����'\0'�ĵ�ַ
//	while (*dest)
//	{
//		dest++;
//	}
//	//��ʼƴ��(����)
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
//	//���ԣ��ж�ָ�����Ч�ԣ���ֹҰָ��
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1==*str2)
//	{
//		if (*str1 == '\0')//��ȵ����
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
//char* my_strstr(const char* str1, const char* str2)//const���εİ�ȫ��ָ�룬�ڸ�ֵ������ȫ��ָ���������Ϊ����ֵʱҪ������Ӧ��ǿ������ת��
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	char* cur = (char*)str1;
//	//����Ҫ���ҵ��ַ���Ϊ���ַ���ʱ������������ַ���
//	if (*str2 == '\0')
//	{
//		return (char*)str2;
//	}
//	while (*cur)
//	{
//		//��¼ƥ���λ��
//		char* s1 = cur;
//		char* s2 = (char*)str2;
//		//��ʼƥ��
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//ƥ��ɹ������
//		{
//			return cur;
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;//ƥ��ʧ�ܵ�һ������������˳�������abc  abcdef��
//		}
//		cur++;
//	}
//	return NULL;//ƥ��ʧ�ܣ��Ҳ����Ӵ�
//}
//
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bbc";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret != NULL)
//		printf("�ҵ��ˣ�%s\n", ret);
//	else
//		printf("�Ӵ�������\n");
//	return 0;
//}
