#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//void* my_memcpy(void* dest, const void* src, unsigned int num)//传入数据可能是各种类型的，所以用void*接收
//{
//	//void*
//	//可以接收所有类型的指针
//	//不可以进行解引用和加减整数的操作，但可以比较大小
//	void* tmp = dest;
//	while (num--)
//	{
//		//把指针类型转化为char*在解引用和+1/-1时可以访问一个字节
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
//	printf("arr1=%s\n", (char*)my_memcpy(arr1, arr2, 3));//把arr2的前三个字节内容拷贝到arr1里
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//
//void* my_memmove(void* dest, const void* src, unsigned int num)
//{
//	//断言，判断指针的有效性，防止野指针
//	assert(dest != NULL);
//	assert(src != NULL);
//	//对于重叠拷贝
//	//若dest<src,src从前向后拷贝
//	//若dest>=src&&dest<=src+num，src从后向前拷贝
//	//若dest>src,src从前和从后都可以拷贝
//	void* tmp = dest;
//	while (num--)
//	{
//		if (dest < src)//从前向后拷贝
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//		else//从后向前拷贝
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
//	int* ret=(int*)(my_memmove(arr, arr + 2, 20));//把34567拷贝到12345上
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *ret);
//		ret++;
//	}
//	return 0;
//}