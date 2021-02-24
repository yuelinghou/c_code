#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//�˵�����
void menu()
{
	printf("****************************************\n");
	printf("***** 1.add               2.del    *****\n");
	printf("***** 3.search            4.modify *****\n");
	printf("***** 5.show              6.sort   *****\n");
	printf("***** 7.save              0.exit   *****\n");
	printf("****************************************\n");
}

//������
int main()
{
	struct Contact con = {0};
	InitContact(&con);
	int input = 0;
	do
	{
		menu();//��ʾͨѶ¼����
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT://0
			SaveContact(&con);
			DistroyContact(&con);
			break;
		case ADD://1
			AddContact(&con);
			break;
		case DEL://2
			DelContact(&con);
			break;
		case SEARCH://3
			SearchContact(&con);
			break;
		case MODIFY://4
			ModifyContact(&con);
			break;
		case SHOW://5
			ShowContact(&con);
			break;
		case SORT://6
			SortContact(&con);
			ShowContact(&con);
			break;
		case SAVE://7
			SaveContact(&con);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}