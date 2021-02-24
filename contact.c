#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//检查通讯录的容量（内存空间）是否足够
//不够就在开辟两个成员空间
//够了就什么都不做
static void CheckCapacity(struct Contact* p)
{
	//判断当前通讯录容量是否满了
	if (p->size == p->capacity)//当前通讯录成员人数是否等于最大容量
	{
		//开辟空间
		struct PeoInfo* tmp = (struct PeoInfo*)realloc(p->data, (2 + p->capacity) * sizeof(struct PeoInfo));
		if (tmp != NULL)//开辟成功
		{
			p->data = tmp;
			p->capacity += 2;
		}
		else//开辟失败
		{
			printf("CheckCapacity::%s\n", strerror(errno));
			return;
		}
	}
}

//上传上次写在文件里的成员信息
static void LoadContact(struct Contact* p)
{
	//以只读的方式打开文件
	FILE* pf = fopen("contactinformation", "rb");
	if (pf == NULL)//检查是否打开
	{
		printf("LoadContact::%s\n", strerror(errno));
	}
	struct PeoInfo tmp = { 0 };//创建一个临时的结构体变量
	//开始逐条读取pf的（成员信息）内容放到中间变量tmp里
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pf))
	{
		CheckCapacity(p);//检查当前的结构体容量是否可以放得下所有之前的成员信息
		*(p->data + p->size) = tmp;
		p->size++;//每放一个成员，记录成员人数的size就加一
	}
	//文件读取完毕，关闭文件
	fclose(pf);
	pf = NULL;
}

//初始化通讯录信息
void InitContact(struct Contact* p)
{
	//为通讯录DEFAULT_SIZE个成员的空间
	p->data = (struct PeoInfo*)malloc(DEFAULT_SIZE * sizeof(struct PeoInfo));
	if (p->data == NULL)//检查是否开辟成功
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	p->size = 0;
	p->capacity= DEFAULT_SIZE;
	LoadContact(p);//初始化之后把以前写在文件里的成员信息上次到这次程序的通讯录里
}


//增加成员信息
void AddContact(struct Contact* p)
{
	void CheckCapacity(p);//检查当前通讯录容量是否足够，不够的话就开辟空间，够了就什么都不干

	printf("请输入名字:>");
	scanf("%s",(*((p->data)+(p->size))).name);

	printf("请输入性别:>");
	scanf("%s", (*((p->data) + (p->size))).sex);

	printf("请输入年龄:>");
	scanf("%d", &(*((p->data) + (p->size))).age);

	printf("请输入电话号码:>");
	scanf("%s", (*((p->data) + (p->size))).tele);

	printf("请输入住址:>");
	scanf("%s", (*((p->data) + (p->size))).addr);

	printf("添加成功\n");

	p->size++;//添加完成之后记录当前通讯录成员个数的size变量加一
}


//查看通讯录中所有成员信息
void ShowContact(struct Contact* p)
{
	//先检查当前通讯录是否有成员信息
	if (p->size == 0)//没有成员
	{
		printf("通讯录内容为空\n");
	}
	else//有成员，依次打印每个成员的信息
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "性别", "年龄", "电话", "住址");
		int i = 0;
		for (i = 0; i < p->size; i++)
		{
			printf("%-20s\t%-4s\t%-5d\t%-12s\t%-20s\n",
				(*((p->data) + i)).name,
				(*((p->data) + i)).sex,
				(*((p->data) + i)).age,
				(*((p->data) + i)).tele,
				(*((p->data) + i)).addr);
		}
	}
}

//实现查找成员名字功能的函数
//找到了就返回成员的下标
//找不到就返回-1
static int Search_By_Name(struct Contact* p,char* pc)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (strcmp((*((p->data) + i)).name, pc) == 0)
		{
			return i;
		}
	}
	return -1;
}

//查找指定成员
void SearchContact(struct Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的姓名:>");
	scanf("%s", name);
	//判断该成员是否存在
	int flag = Search_By_Name(p, name);
	if (flag == -1)//不存在
	{
		printf("要查找人的信息不存在\n");
	}
	else//存在，打印该成员的信息
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "性别", "年龄", "电话", "住址");

		printf("%-20s\t%-4s\t%-5d\t%-12s\t%-20s\n",
			(*((p->data) + flag)).name,
			(*((p->data) + flag)).sex,
			(*((p->data) + flag)).age,
			(*((p->data) + flag)).tele,
			(*((p->data) + flag)).addr);
	}
}

//输出通讯录中指定成员信息
void DelContact(struct Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//判断该成员是否存在
	int flag = Search_By_Name(p, name);
	if (flag == -1)//不存在
	{
		printf("要删除的人不存在\n");
	}
	else//存在，把后面成员的位置往前挪一位
	{
		int i = 0;
		for (i = flag; i < p->size-1; i++)
		{
			*(p->data + i) = *(p->data + i + 1);
		}
		printf("删除成功\n");
		p->size--;//令记录当前通讯录成员个数的size减一
	}
}

//修改通讯录中指定成员信息
void ModifyContact(struct Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	//判断该成员是否存在
	int flag=Search_By_Name(p, name);
	if (flag == -1)//不存在
	{
		printf("要修改人的信息不存在\n");
	}
	else//存在，通过访问结构体成员直接修改信息
	{
		printf("请输入名字:>");
		scanf("%s", (*((p->data) + flag)).name);

		printf("请输入性别:>");
		scanf("%s", (*((p->data) + flag)).sex);

		printf("请输入年龄:>");
		scanf("%d", &(*((p->data) + flag)).age);

		printf("请输入电话号码:>");
		scanf("%s", (*((p->data) + flag)).tele);

		printf("请输入住址:>");
		scanf("%s", (*((p->data) + flag)).addr);

		printf("修改成功\n");
	}
}

//分隔行内都是实现(通过名字)排序功能的相关函数

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//自定义的比较函数（通过名字来比较两个元素的大小）
//比较两个元素
//p1>p2返回大于零的数字
//p1=p2返回0
//p1<p2返回小于零的数字
static int Cmp_Struct(void* p1, void* p2)
{
	return strcmp(((struct PeoInfo*)p1)->name , ((struct PeoInfo*)p2)->name);
}

//交换两个元素的内容（width，是一个元素所占内存空间的大小，单位是字节）
static void Swap(void* p1, void* p2, int width)
{
	//一个字节一个字节的交换
	while (width)
	{
		char tmp = *(char*)p1;
		*(char*)p1 = *(char*)p2;
		*(char*)p2 = tmp;
		++(char*)p1;
		++(char*)p2;
		width--;
	}
}

//通用的冒泡排序（什么类型的数据都可以排）
static void My_Bubble_Sort(void* p, int sz, int width, int(*cmp)(void*, void*))
{
	int i = 0;
	int j = 0;
	int flag = 1;//flag为1是是已经排好序，为0是是还没排好序，先默认它为1
	//冒泡排序
	for (i = 0; i < sz - 1; i++)//sz个元素，一共要比较sz-1趟，每一趟排序好一个元素
	{
		for (j = 0; j < sz - 1 - i; j++)//每趟要两两比较当前未排好序的元素个数-1次
		{
			if (cmp((char*)p + (j*width), (char*)p + ((j + 1)*width)) > 0)//判断是否要交换两个元素（既判断前一个元素的名字是否大于后一个元素的名字）
			{
				Swap((char*)p + (j*width), (char*)p + ((j + 1)*width), width);//交换两个成员的位置
				flag = 0;//已经判断这次是无序了，所以flag=0
			}
		}
		if (flag == 1)//若一趟两两比较下来flag仍然=1，则数组肯定有序了，跳出冒泡排序
		{
			break;
		}
	}
}

void SortContact(struct Contact* p)
{
	//排序之前的传参
	My_Bubble_Sort(p->data,p->size,sizeof(p->data[0]),Cmp_Struct);
	//p->data：成员信息数组的首元素地址
	//p->size：当前成员个数
	//sizeof(p->data[0])：一个成员所占内存空间的大小，单位是字节
	//Cmp_Struct：自定义的比较两个元素功能的函数
	printf("排序完成\n");
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//释放之前malloc开辟的空间
void DistroyContact(struct Contact* p)
{
	free(p->data);
	p->data = NULL;
	printf("退出通讯录\n");
}

//保存当前通讯录的成员信息到contactinformation这个文件里
void SaveContact(struct Contact* p)
{
	//以只写的方式打开文件
	FILE* pf = fopen("contactinformation", "wb");
	//判断文件是否打开
	if (pf == NULL)//打开失败的情况
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//开始逐条读取成员信息放到contactinformation文件里
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		fwrite(p->data + i, sizeof(struct PeoInfo), 1, pf);
	}
	printf("保存成功\n");
	//关闭文件
	fclose(pf);
	pf = NULL;
}
