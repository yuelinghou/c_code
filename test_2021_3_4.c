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
////srcΪ������Ԫ�ص�ַ
////timeΪ��Ҫ�������ַ��ĸ���
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(src);//�����ַ������ַ��ĸ���
//	//�����ת�ַ�����Ҫ��תtime��
//	for (i = 0; i < time; i++)
//	{
//		char tmp = src[0];//�Ȱѵ�һ���ַ�������������Ȼ����Ų����ʱ��ᱻ����
//		//������Ԫ�ض���ǰŲһ��λ��
//		for (j = 0; j < len - 1; j++)
//		{
//			src[j] = src[j + 1];
//		}
//		//Ų����ǰ�汣��ĵ�һ���ַ��ŵ����һ��λ�ã����һ���ַ�����ת
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
//	assert(src != NULL);//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
//	int len = strlen(src)+1;//����и�'\0'��λ��ҲҪ����
//	char* tmp = malloc(len * sizeof(char));//������srcͬ�ȴ�С������
//	//�жϿռ��Ƿ񿪱ٳɹ�
//	if (tmp==NULL)
//	{
//		printf("%s\n",strerror(errno));
//		exit(-1);
//	}
//	//��һ��
//	strcpy(tmp, src + pos);
//	//�ڶ���
//	strncat(tmp, src, pos);
//	//������
//	strcpy(src, tmp);
//	//�ͷŶ�̬���ٵĿռ�
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
////����
//void Reverse_Part(char* start, char* end)
//{
//	char tmp = 0;//�м����������������ʱ���������������
//	//��ʼ����
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
////����
//void Left_Round(char* src, int time)
//{
//	assert(src != NULL);//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
//	int len = strlen(src);
//	//��һ������Ҫ�����Ĳ�������
//	Reverse_Part(src, src+time - 1);
//	//�ڶ����������������ǲ����ַ���
//	Reverse_Part(src+time, src+len-1);
//	//�����������������ַ���
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
//		printf("�ҵ���\n");
//	}
//	else
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}


