#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//void* my_memcpy(void* dest, const void* src, unsigned int num)//�������ݿ����Ǹ������͵ģ�������void*����
//{
//	//void*
//	//���Խ����������͵�ָ��
//	//�����Խ��н����úͼӼ������Ĳ����������ԱȽϴ�С
//	void* tmp = dest;
//	while (num--)
//	{
//		//��ָ������ת��Ϊchar*�ڽ����ú�+1/-1ʱ���Է���һ���ֽ�
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//	}
//	return tmp;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "123456";
//	printf("arr1=%s\n", (char*)my_memcpy(arr1, arr2, 3));//��arr2��ǰ�����ֽ����ݿ�����arr1��
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//
//void* my_memmove(void* dest, const void* src, unsigned int num)
//{
//	//���ԣ��ж�ָ�����Ч�ԣ���ֹҰָ��
//	assert(dest != NULL);
//	assert(src != NULL);
//	//�����ص�����
//	//��dest<src,src��ǰ��󿽱�
//	//��dest>=src&&dest<=src+num��src�Ӻ���ǰ����
//	//��dest>src,src��ǰ�ʹӺ󶼿��Կ���
//	void* tmp = dest;
//	while (num--)
//	{
//		if (dest < src)//��ǰ��󿽱�
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//		else//�Ӻ���ǰ����
//		{
//			*((char*)dest + num) = *((char*)src + num);
//			--(char*)dest;
//			--(char*)src;
//		}
//	}
//	return tmp;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = sizeof arr/sizeof arr[0];
//	int* ret=(int*)(my_memmove(arr, arr + 2, 20));//��34567������12345��
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *ret);
//		ret++;
//	}
//	return 0;
//}