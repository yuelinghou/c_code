#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//���ͨѶ¼���������ڴ�ռ䣩�Ƿ��㹻
//�������ڿ���������Ա�ռ�
//���˾�ʲô������
static void CheckCapacity(struct Contact* p)
{
	//�жϵ�ǰͨѶ¼�����Ƿ�����
	if (p->size == p->capacity)//��ǰͨѶ¼��Ա�����Ƿ�����������
	{
		//���ٿռ�
		struct PeoInfo* tmp = (struct PeoInfo*)realloc(p->data, (2 + p->capacity) * sizeof(struct PeoInfo));
		if (tmp != NULL)//���ٳɹ�
		{
			p->data = tmp;
			p->capacity += 2;
		}
		else//����ʧ��
		{
			printf("CheckCapacity::%s\n", strerror(errno));
			return;
		}
	}
}

//�ϴ��ϴ�д���ļ���ĳ�Ա��Ϣ
static void LoadContact(struct Contact* p)
{
	//��ֻ���ķ�ʽ���ļ�
	FILE* pf = fopen("contactinformation", "rb");
	if (pf == NULL)//����Ƿ��
	{
		printf("LoadContact::%s\n", strerror(errno));
	}
	struct PeoInfo tmp = { 0 };//����һ����ʱ�Ľṹ�����
	//��ʼ������ȡpf�ģ���Ա��Ϣ�����ݷŵ��м����tmp��
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pf))
	{
		CheckCapacity(p);//��鵱ǰ�Ľṹ�������Ƿ���Էŵ�������֮ǰ�ĳ�Ա��Ϣ
		*(p->data + p->size) = tmp;
		p->size++;//ÿ��һ����Ա����¼��Ա������size�ͼ�һ
	}
	//�ļ���ȡ��ϣ��ر��ļ�
	fclose(pf);
	pf = NULL;
}

//��ʼ��ͨѶ¼��Ϣ
void InitContact(struct Contact* p)
{
	//ΪͨѶ¼DEFAULT_SIZE����Ա�Ŀռ�
	p->data = (struct PeoInfo*)malloc(DEFAULT_SIZE * sizeof(struct PeoInfo));
	if (p->data == NULL)//����Ƿ񿪱ٳɹ�
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	p->size = 0;
	p->capacity= DEFAULT_SIZE;
	LoadContact(p);//��ʼ��֮�����ǰд���ļ���ĳ�Ա��Ϣ�ϴε���γ����ͨѶ¼��
}


//���ӳ�Ա��Ϣ
void AddContact(struct Contact* p)
{
	void CheckCapacity(p);//��鵱ǰͨѶ¼�����Ƿ��㹻�������Ļ��Ϳ��ٿռ䣬���˾�ʲô������

	printf("����������:>");
	scanf("%s",(*((p->data)+(p->size))).name);

	printf("�������Ա�:>");
	scanf("%s", (*((p->data) + (p->size))).sex);

	printf("����������:>");
	scanf("%d", &(*((p->data) + (p->size))).age);

	printf("������绰����:>");
	scanf("%s", (*((p->data) + (p->size))).tele);

	printf("������סַ:>");
	scanf("%s", (*((p->data) + (p->size))).addr);

	printf("��ӳɹ�\n");

	p->size++;//������֮���¼��ǰͨѶ¼��Ա������size������һ
}


//�鿴ͨѶ¼�����г�Ա��Ϣ
void ShowContact(struct Contact* p)
{
	//�ȼ�鵱ǰͨѶ¼�Ƿ��г�Ա��Ϣ
	if (p->size == 0)//û�г�Ա
	{
		printf("ͨѶ¼����Ϊ��\n");
	}
	else//�г�Ա�����δ�ӡÿ����Ա����Ϣ
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
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

//ʵ�ֲ��ҳ�Ա���ֹ��ܵĺ���
//�ҵ��˾ͷ��س�Ա���±�
//�Ҳ����ͷ���-1
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

//����ָ����Ա
void SearchContact(struct Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	//�жϸó�Ա�Ƿ����
	int flag = Search_By_Name(p, name);
	if (flag == -1)//������
	{
		printf("Ҫ�����˵���Ϣ������\n");
	}
	else//���ڣ���ӡ�ó�Ա����Ϣ
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");

		printf("%-20s\t%-4s\t%-5d\t%-12s\t%-20s\n",
			(*((p->data) + flag)).name,
			(*((p->data) + flag)).sex,
			(*((p->data) + flag)).age,
			(*((p->data) + flag)).tele,
			(*((p->data) + flag)).addr);
	}
}

//���ͨѶ¼��ָ����Ա��Ϣ
void DelContact(struct Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//�жϸó�Ա�Ƿ����
	int flag = Search_By_Name(p, name);
	if (flag == -1)//������
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else//���ڣ��Ѻ����Ա��λ����ǰŲһλ
	{
		int i = 0;
		for (i = flag; i < p->size-1; i++)
		{
			*(p->data + i) = *(p->data + i + 1);
		}
		printf("ɾ���ɹ�\n");
		p->size--;//���¼��ǰͨѶ¼��Ա������size��һ
	}
}

//�޸�ͨѶ¼��ָ����Ա��Ϣ
void ModifyContact(struct Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	//�жϸó�Ա�Ƿ����
	int flag=Search_By_Name(p, name);
	if (flag == -1)//������
	{
		printf("Ҫ�޸��˵���Ϣ������\n");
	}
	else//���ڣ�ͨ�����ʽṹ���Աֱ���޸���Ϣ
	{
		printf("����������:>");
		scanf("%s", (*((p->data) + flag)).name);

		printf("�������Ա�:>");
		scanf("%s", (*((p->data) + flag)).sex);

		printf("����������:>");
		scanf("%d", &(*((p->data) + flag)).age);

		printf("������绰����:>");
		scanf("%s", (*((p->data) + flag)).tele);

		printf("������סַ:>");
		scanf("%s", (*((p->data) + flag)).addr);

		printf("�޸ĳɹ�\n");
	}
}

//�ָ����ڶ���ʵ��(ͨ������)�����ܵ���غ���

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//�Զ���ıȽϺ�����ͨ���������Ƚ�����Ԫ�صĴ�С��
//�Ƚ�����Ԫ��
//p1>p2���ش����������
//p1=p2����0
//p1<p2����С���������
static int Cmp_Struct(void* p1, void* p2)
{
	return strcmp(((struct PeoInfo*)p1)->name , ((struct PeoInfo*)p2)->name);
}

//��������Ԫ�ص����ݣ�width����һ��Ԫ����ռ�ڴ�ռ�Ĵ�С����λ���ֽڣ�
static void Swap(void* p1, void* p2, int width)
{
	//һ���ֽ�һ���ֽڵĽ���
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

//ͨ�õ�ð������ʲô���͵����ݶ������ţ�
static void My_Bubble_Sort(void* p, int sz, int width, int(*cmp)(void*, void*))
{
	int i = 0;
	int j = 0;
	int flag = 1;//flagΪ1�����Ѿ��ź���Ϊ0���ǻ�û�ź�����Ĭ����Ϊ1
	//ð������
	for (i = 0; i < sz - 1; i++)//sz��Ԫ�أ�һ��Ҫ�Ƚ�sz-1�ˣ�ÿһ�������һ��Ԫ��
	{
		for (j = 0; j < sz - 1 - i; j++)//ÿ��Ҫ�����Ƚϵ�ǰδ�ź����Ԫ�ظ���-1��
		{
			if (cmp((char*)p + (j*width), (char*)p + ((j + 1)*width)) > 0)//�ж��Ƿ�Ҫ��������Ԫ�أ����ж�ǰһ��Ԫ�ص������Ƿ���ں�һ��Ԫ�ص����֣�
			{
				Swap((char*)p + (j*width), (char*)p + ((j + 1)*width), width);//����������Ա��λ��
				flag = 0;//�Ѿ��ж�����������ˣ�����flag=0
			}
		}
		if (flag == 1)//��һ�������Ƚ�����flag��Ȼ=1��������϶������ˣ�����ð������
		{
			break;
		}
	}
}

void SortContact(struct Contact* p)
{
	//����֮ǰ�Ĵ���
	My_Bubble_Sort(p->data,p->size,sizeof(p->data[0]),Cmp_Struct);
	//p->data����Ա��Ϣ�������Ԫ�ص�ַ
	//p->size����ǰ��Ա����
	//sizeof(p->data[0])��һ����Ա��ռ�ڴ�ռ�Ĵ�С����λ���ֽ�
	//Cmp_Struct���Զ���ıȽ�����Ԫ�ع��ܵĺ���
	printf("�������\n");
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//�ͷ�֮ǰmalloc���ٵĿռ�
void DistroyContact(struct Contact* p)
{
	free(p->data);
	p->data = NULL;
	printf("�˳�ͨѶ¼\n");
}

//���浱ǰͨѶ¼�ĳ�Ա��Ϣ��contactinformation����ļ���
void SaveContact(struct Contact* p)
{
	//��ֻд�ķ�ʽ���ļ�
	FILE* pf = fopen("contactinformation", "wb");
	//�ж��ļ��Ƿ��
	if (pf == NULL)//��ʧ�ܵ����
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//��ʼ������ȡ��Ա��Ϣ�ŵ�contactinformation�ļ���
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		fwrite(p->data + i, sizeof(struct PeoInfo), 1, pf);
	}
	printf("����ɹ�\n");
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}
