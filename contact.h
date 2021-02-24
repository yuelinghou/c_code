//����C�⺯����ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

//����������ĺ�
//struct PeoInfo�����Ա��Ĭ�ϴ�С 
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//��ʼ��ʱ��ͨѶ¼��Ĭ��������С
#define DEFAULT_SIZE 3

//ö�٣���Ϊcase����ִ�г������ʽ
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

//������Ա��Ϣ�Ľṹ��
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//����ͨѶ¼��Ϣ�Ľṹ��
struct Contact
{
	struct PeoInfo* data;//������г�Ա������
	int size;//��¼ͨѶ¼��ǰ�ж�����
	int capacity;//��¼ͨѶ¼��ǰ������С
};

//��������
void InitContact(struct Contact* p);
void AddContact(struct Contact* p);
void ShowContact(struct Contact* p);
void SearchContact(struct Contact* p);
void DelContact(struct Contact* p);
void ModifyContact(struct Contact* p);
void SortContact(struct Contact* p);
void DistroyContact(struct Contact* p);
void SaveContact(struct Contact* p);




