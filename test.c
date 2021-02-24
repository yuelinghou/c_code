#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//菜单函数
void menu()
{
	printf("****************************************\n");
	printf("***** 1.add               2.del    *****\n");
	printf("***** 3.search            4.modify *****\n");
	printf("***** 5.show              6.sort   *****\n");
	printf("***** 7.save              0.exit   *****\n");
	printf("****************************************\n");
}

//主函数
int main()
{
	struct Contact con = {0};
	InitContact(&con);
	int input = 0;
	do
	{
		menu();//显示通讯录功能
		printf("请选择:>");
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
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}