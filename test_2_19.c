#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
////��leftָ������ߵ�Ԫ��,rightָ�����ұߵ�Ԫ��,��������λ��Ԫ�ص�ֵ֮��left++��right- -���𽥿�����ֱ��letf>=rightΪֹ��
//char* my_strrev(char* string)
//{
//	assert(string != NULL);//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
//	char* tmp1 = string;//��ס���ַ�������Ԫ�ص�ַ����󷵻�
//	char* left = string;//leftΪ�����Ԫ�ص�ַ
//	char* right = string + strlen(string) - 1;//rightΪ���ұ�Ԫ�ص�ַ��'\0'ǰ����Ǹ���
//	while (left < right)
//	{
//		//��ʼ������ͷ���ַ�
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
//	assert(base != NULL);//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
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
//void Bubble_Sort(void* base, int num, int width, int(*cmp)(void*, void*));//��ð�������㷨������������

//ʹ�����Զ���ıȽϺ����������Ƚ��������صĴ�С�������������صĲ�ֵ
//int cmp(const void* elem1, const void* elem2)
//{
//	return *(int*)elem1 - *(int*)elem2;
//}


//int main()
//{
//	int arr[] = { 9,8,7,6,5,4};
//	int sz = sizeof arr / sizeof arr[0];//��������Ԫ�ظ���
//	Bubble_Sort(arr, sz, sizeof arr[0], cmp);
//	//��ӡ����������
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

#include<stdio.h>

void Bubble_Sort(void* base, int num, int width, int(*cmp)(void*, void*));//��ð�������㷨������������

//�����ṹ������
struct S
{
	char name[20];
	int age;
};

//�ȽϽṹ���Ա�е�age��ͨ��age�Ĵ�С����������
int cmp(const void* s1, const void* s2)
{
	return (((struct S*)s1)->age) - ((struct S*)s2)->age;
}



int main()
{
	struct S s[4] = { {"zhangsan",20},{"lisi",28},{"wangwu",32},{"ergou",11} };//����struct S������͵Ľṹ������
	int sz = sizeof s / sizeof s[0];
	Bubble_Sort(s, sz, sizeof s[0], cmp);//ʹ��Bubble_Sort��ʼ����
	//��һ���������������������Ԫ�ص�ַ
	//�ڶ��������������������Ԫ�ظ���
	//����������������������ÿ��Ԫ�صĴ�С����λ���ֽڣ�
	//���ĸ�����������ָ�루�Ƚ�����Ԫ�����õĺ�����ַ��
	return 0;
}