//声明C库函数的头文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

//定义相关量的宏
//struct PeoInfo数组成员的默认大小 
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//初始化时，通讯录的默认容量大小
#define DEFAULT_SIZE 3

//枚举，作为case语句的执行常量表达式
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT,//6
	SAVE//7
};

//声明成员信息的结构体
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//声明通讯录信息的结构体
struct Contact
{
	struct PeoInfo* data;//存放所有成员的数据
	int size;//记录通讯录当前有多少人
	int capacity;//记录通讯录当前容量大小
};

//函数声明
void InitContact(struct Contact* p);
void AddContact(struct Contact* p);
void ShowContact(struct Contact* p);
void SearchContact(struct Contact* p);
void DelContact(struct Contact* p);
void ModifyContact(struct Contact* p);
void SortContact(struct Contact* p);
void DistroyContact(struct Contact* p);
void SaveContact(struct Contact* p);




