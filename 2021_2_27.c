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



//�ο���(�����ɲ鿴)
//���ѭ��ʹ�������1�Σ�Ȼ������ִ��n����һ����򵥵�˼·��
//
//
//
//void leftRound(char * src, int time)
//{
//	int i, j, tmp;
//	int len = strlen(src);
//	time %= len; //����Ϊ5������£���ת6��11��16...���൱��1�Σ�7��12��17...���൱��2�Σ��Դ����ơ�
//	for (i = 0; i < time; i++) //ִ��k�εĵ���ƽ��
//	{
//		tmp = src[0];
//		for (j = 0; j < len - 1; j++) //����ƽ��
//		{
//			src[j] = src[j + 1];
//		}
//		src[j] = tmp;
//	}