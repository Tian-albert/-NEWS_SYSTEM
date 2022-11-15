#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main() {

	int key = 0;

	struct user_node* user_list = create_user_list();
	struct news_node* news_list = create_news_list();
	read_user_file("uesr.txt", user_list);
	read_news_file("news.txt", news_list);


	while (1) {
		login_interface();
		scanf("%d", &key);
		switch (key)
		{
		case 0:
			printf("Exit the system\n");
			exit(0);
			break;
		case 1:
			printf("Administrator login\n");
			admin_login(user_list, news_list);//管理员登录验证
			break;
		case 2:
			printf("User login\n");
			user_login(user_list, news_list);//用户登录验证
			break;
		case 3:
			printf("Visitor\n");
			print_news_list(news_list);
			printf("The end.\n");
			break;
		default:
			printf("Input error, please re-enter：");
			break;
		}
		clrscr();
	}
}