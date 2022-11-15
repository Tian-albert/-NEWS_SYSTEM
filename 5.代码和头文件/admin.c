#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include <conio.h>




void admin_login(struct user_node* user_list, struct news_node* news_list) {
	int key = 0;
	char admin_account[10] = { "admin" };
	char admin_password[10] = { "123456" };
	char account[10];
	char password[10];

	while (1) {
		printf("Please enter an account number:\n");
		rewind(stdin);
		scanf("%s", account);
		printf("Please enter a password:\n");
		rewind(stdin);
		scanf("%s", password);
		if (strcmp(admin_account, account) == 0 && strcmp(admin_password, password) == 0) {
			printf("Login successful.\n");

			clrscr();
			admid_function(user_list, news_list);
			break;
		}
		else {
			printf("The account number or password was entered incorrectly!\n");
			
			printf("Please enter 1 to re-enter it or enter 2 to Return to the previous level:");
			rewind(stdin);
			scanf("%d", &key);
			if (key == 2) { break; }

		}
	}

}


void admid_function(struct user_node* user_list, struct news_node* news_list) {
	int key = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int* A = &a;
	int* B = &b;
	int* C = &c;
	Date date_1 = { 0 };
	Date date_2 = { 0 };
	User temp_user = { 0 };
	News temp_news = { 0 };
	struct user_node* cur_user_node = { 0 };
	struct news_node* cur_news_node = { 0 };
	struct news_node* deleted_news_list = create_news_list();
	read_news_file("news_del.txt", deleted_news_list);

	while (1) {
		temp_news.category[0] = 0;//初始化temp_news（准确地来说是赋值为0保证数据不会杂糅）
		temp_news.title[0] = 0;
		temp_news.user.account[0] = 0;
		temp_news.user.password[0] = 0;
		temp_news.content[0] = 0;
		temp_news.comment[0] = 0;
		temp_news.date.year = 0;
		temp_news.date.month = 0;
		temp_news.date.day = 0;

		temp_user.account[0] = '0';//初始化temp_user（准确地来说是赋值为0保证数据不会杂糅）
		temp_user.password[0] = '0';



		administrator_menu();
		rewind(stdin);
		scanf("%d", &key);
		switch (key)
		{
		case 0:
			printf("Sign out\n");
			return;

		case 1:
			printf("Add news\n\n");
			printf("Please enter a title:\n");
			rewind(stdin);  /*此函数把键盘输入指针移到开头，起到和清除缓冲区同样的作用
							  fflush(stdin);该函数并不能很好地清空缓冲区，比如回车,且通用性差
							  getchar();该函数可以，但是一次只能清理一个*/
			gets(temp_news.title);
			printf("\nPlease enter the publisher name:\n");
			rewind(stdin);
			gets(temp_news.user.account);
			printf("Please enter a news category(Notice,Announcement or Newsletter):\n");
			rewind(stdin);
			gets(temp_news.category);
			printf("Please enter a release date(Separated by commas in the middle->2022,1,7):\n");
			rewind(stdin);
			scanf("%d,%d,%d", &temp_news.date.year, &temp_news.date.month, &temp_news.date.day);//int类型记得加取地址符
			printf("Please enter the body text:\n");
			rewind(stdin);
			gets(temp_news.content);
			insert_news_node(news_list, temp_news);
			save_news_file("news.txt", news_list);
			printf("Added successfully!\n");
			break;
		case 2:
			printf("Delete news\n");
			printf("\nPlease enter the title of the news you want to delete:\n");
			rewind(stdin);
			gets(temp_news.title);
			delete_news_node_by_title(news_list, temp_news.title, deleted_news_list);
			save_news_file("news.txt", news_list);
			break;
		case 3:
			printf("Modify news\n");
			printf("\nPlease enter the title of the news you want to modify:\n");
			rewind(stdin);
			gets(temp_news.title);
			cur_news_node = search_news_by_title(news_list, temp_news.title);
			if (cur_news_node == NULL) {
				printf("The specified content could not be found!\n");
			}
			else {
				print_news_node(cur_news_node);
				printf("Please enter a revised title:\n");
				rewind(stdin);
				gets(cur_news_node->data.title);
				printf("Please enter the revised publisher name:\n");
				rewind(stdin);
				gets(cur_news_node->data.user.account);
				printf("Please enter a revised news category(Notice,Announcement or Newsletter):\n");
				rewind(stdin);
				gets(cur_news_node->data.category);
				printf("Please enter a revised release date(Separated by commas in the middle):\n");
				rewind(stdin);
				scanf("%d,%d,%d", &cur_news_node->data.date.year, &cur_news_node->data.date.month, &cur_news_node->data.date.day);//int类型记得加取地址符
				printf("Please enter the revised body text:\n");
				rewind(stdin);
				gets(cur_news_node->data.content);
				printf("Please enter the comment:\n");
				rewind(stdin);
				gets(cur_news_node->data.comment);
				save_news_file("news.txt", news_list);
				printf("Modification successful!\n");

			}
			break;
		case 4:
			printf("Read news\n");
			print_news_list(news_list);
			printf("The end.\n");
			break;
		case 5:
			printf("Sort news by time from ago to latese\n\n");
			sorting_from_ago_to_latest(news_list);
			print_news_list(news_list);
			break;
		case 6:
			printf("Sort news by time from latest to ago\n\n");
			sorting_from_latest_to_ago(news_list);
			print_news_list(news_list);
			break;
		case 7:
			printf("Modify user\n\n");
			printf("Please enter the user account number you want to modify:\n");
			scanf("%s", &temp_user.account);
			cur_user_node = search_user_by_account(user_list, temp_user.account);
			if (cur_user_node == NULL) {
				printf("The specified content could not be found!\n");
			}
			else {
				print_user_node(cur_user_node);
				printf("Please enter an account number:\n");
				scanf("%s", cur_user_node->data.account);
				printf("Please enter password:\n");
				scanf("%s", cur_user_node->data.password);
				save_user_file("uesr", user_list);
				printf("Modification successful!\n");
			}

			break;
		case 8:
			printf("\tAdd user\n");
			printf("Please enter an account number:\n\n");
			scanf("%s", temp_user.account);
			rewind(stdin);
			printf("Please enter password:\n");
			scanf("%s", temp_user.password);

			insert_user_node(user_list, temp_user);
			save_user_file("uesr.txt", user_list);
			printf("Added successfully!\n");
			break;
		case 9:
			printf("Delete user\n\n");
			printf("Please enter the account number of the user you want to delete:\n");
			scanf("%s", temp_user.account);
			delete_user_node_by_account(user_list, temp_user.account);
			save_user_file("uesr.txt", user_list);
			break;
		case 10:
			printf("Read user\n\n");
			print_user_list(user_list);
			printf("The end.\n");
			break;
		case 11:
			printf("\t11.search news\n");
			search_function(news_list);
			break;
		case 12:
			printf("\t12.Counts the number of times news is published in a certain time period.\n");
			printf("Please enter the account you want to view:\n");
			rewind(stdin);
			gets(temp_news.user.account);
			printf("Check out the news between date_1 and date_2.\n");
			printf("Please enter date_1:\n");
			rewind(stdin);
			scanf("%d,%d,%d", &date_1.year, &date_1.month, &date_1.day);
			printf("Please enter date_2:\n");
			rewind(stdin);
			scanf("%d,%d,%d", &date_2.year, &date_2.month, &date_2.day);
			key = Count(news_list, date_1, date_2, temp_news.user.account, A, B, C);
			printf("-Between %d,%d,%d and %d,%d,%d\n", date_1.year, date_1.month, date_1.day, date_2.year, date_2.month, date_2.day);
			printf("-User %s posted a total of %d news.\n", temp_news.user.account, key);
			printf("-Notice:%d\n-Announcement:%d\n-Newsletter:%d\n", a, b, c);
			break;
		default:
			printf("Input error, please re-enter：");
			break;
		}
		key = 0;
		clrscr();
	}
}

struct user_node* create_user_list() {              //创建用户数据链表表头
	struct user_node* head = (struct user_node*)malloc(sizeof(struct user_node));
	head->next = NULL;
	return head;
}

struct user_node* create_user_node(User data) {//   增加用户数据类型结点
	struct user_node* new_node = (struct user_node*)malloc(sizeof(struct user_node));
	new_node->next = NULL;
	new_node->data = data;
	return new_node;
}

void insert_user_node(struct user_node* head, User data) {//将新增的用户数据类型结点链接在表头与第二个结点之间
	struct user_node* new_node = create_user_node(data);
	new_node->next = head->next;
	head->next = new_node;
}

struct news_node* create_news_list() {//创造新闻数据类型链表表头
	struct news_node* head = (struct news_node*)malloc(sizeof(struct news_node));
	head->next = NULL;
	return head;
}

struct news_node* create_news_node(News data) {//增加新闻数据类型结点
	struct news_node* new_news_node = (struct news_node*)malloc(sizeof(struct news_node));
	new_news_node->next = NULL;
	new_news_node->data = data;
	return new_news_node;
}

void insert_news_node(struct news_node* head, News data) {//将新增的新闻数据类型结点链接在表头与第二个结点之间
	struct news_node* new_news_node = create_news_node(data);
	new_news_node->next = head->next;
	head->next = new_news_node;
}

void print_user_list(struct user_node* head) {//打印全部用户数据
	struct user_node* pMove = head->next;
	printf("  account\t\t\t     password\n\n");

	while (pMove) {
		printf("%12s\t\t%12s\n", pMove->data.account, pMove->data.password);
		pMove = pMove->next;
	}
	printf("\n");

}

void print_news_list(struct news_node* head) {//打印全部新闻数据
	struct news_node* pMove=head->next;
	if (head == NULL || head->next == NULL) {
		printf("There is no data！");
		return;
	}



	while (pMove) {

		printf("\nTitle:%s\n\nPublisher:%s\n%s\nTime:%d,%d,%d\n", pMove->data.title, pMove->data.user.account, pMove->data.category, pMove->data.date.year, pMove->data.date.month, pMove->data.date.day);
		puts(pMove->data.content);
		printf("\n");
		puts(pMove->data.comment);
		pMove = pMove->next;
		printf("\n------------------------\n");
	}
  return;

}

void print_news_node(struct news_node* cur_news_node) {//打印特定新闻数据
	if (cur_news_node == NULL) {
		printf("There is no data！");
		return;
	}
	printf("%s\n%s\n%s\n%d,%d,%d\n", cur_news_node->data.title, cur_news_node->data.user.account, cur_news_node->data.category, cur_news_node->data.date.year, cur_news_node->data.date.month, cur_news_node->data.date.day);
	puts(cur_news_node->data.content);
	printf("\n");
	puts(cur_news_node->data.comment);
	printf("\n");

}

void print_user_node(struct user_node* cur_user_node) {//打印特定用户数据
	printf("account\t\tpassword\n");
	printf("%s\t\t%s\n", cur_user_node->data.account, cur_user_node->data.password);
}

void delete_user_node_by_account(struct user_node* head, char* account) {//删除特定用户数据
	struct user_node* posFrontNode = head;
	struct user_node* posNode = head->next;
	if (posNode == NULL) {
		printf("The specified content could not be found!\n");
		return;
	}
	else {
		while (strcmp(posNode->data.account, account)) {
			posFrontNode = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("The specified content could not be found!\n");
				return;
			}
		}
		posFrontNode->next = posNode->next;
		free(posNode);
	}
	printf("Delete successful!\n");
}

void delete_news_node_by_title(struct news_node* head, char* title, struct news_node* deleted_news_list) {//删除特定新闻数据
	News temp_news;
	struct news_node* posFrontNode = head;//把删除用户数据的函数搬过来，居然忘记改数据类型！引以为戒！
	struct news_node* posNode = head->next;
	if (posNode == NULL) {
		printf("The specified content could not be found!\n");
		return;
	}
	else {
		while (strcmp(posNode->data.title, title)) {
			posFrontNode = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("The specified content could not be found!\n");
				return;
			}
		}
		posFrontNode->next = posNode->next;
		temp_news = posNode->data;
		insert_news_node(deleted_news_list, temp_news);
		save_news_file("news_del.txt", deleted_news_list);
		free(posNode);
	}
	printf("Delete successful!\n");
}

struct user_node* search_user_by_account(struct user_node* head, char* account) {//查找特定用户
	struct user_node* pMove = head->next;
	if (pMove == NULL) {
		return pMove;
	}
	else {
		while (strcmp(pMove->data.account, account)) {
			pMove = pMove->next;
			if (pMove == NULL) {
				printf("The specified content could not be found!\n");
				break;
			}
		}
		return pMove;

	}
}

struct news_node* search_news_by_title(struct news_node* head, char* title) {//查找特定新闻
	struct news_node* pMove = head->next;
	if (pMove == NULL) {
		return pMove;
	}
	else {
		while (strcmp(pMove->data.title, title)) {
			pMove = pMove->next;
			if (pMove == NULL) {
				printf("The specified content could not be found!\n");
				break;
			}
		}
		return pMove;

	}
}

void save_user_file(char* user_file_name, struct user_node* user_list) {
	struct user_node* pMove = user_list->next;
	User* p;
	FILE* fp = fopen(user_file_name, "wb");

	while (pMove) {
		p = &pMove->data;
		if (fwrite(p, sizeof(User), 1, fp) != 1) {
			printf("File write error!\n");
			fclose(fp);
		}
		pMove = pMove->next;
	}
	rewind(fp);
	fclose(fp);
	fp = NULL;
}

//保存和读取文件的数据类型不一样导致乱码！

void read_user_file(char* user_file_name, struct user_node* user_list) {
	User temp_user_data;

	FILE* fp = fopen(user_file_name, "rb");
	if (fp == NULL) {

		printf("Failed to read data.\n");
		return;
	}

	while (fread(&temp_user_data, sizeof(User), 1, fp) == 1) {
		insert_user_node(user_list, temp_user_data);
		memset(&temp_user_data, 0, sizeof(temp_user_data));
	}
	rewind(fp);
	fclose(fp);
	fp = NULL;
}

void save_news_file(char* news_file_name, struct news_node* news_list) {
	struct news_node* pMove = news_list->next;
	News* p;
	FILE* fp = fopen(news_file_name, "wb");

	while (pMove) {
		p = &pMove->data;
		if (fwrite(p, sizeof(News), 1, fp) != 1) {
			printf("File write error!\n");
			fclose(fp);
		}
		pMove = pMove->next;
	}
	rewind(fp);
	fclose(fp);
	fp = NULL;
}

void read_news_file(char* news_file_name, struct news_node* news_list) {
	News temp_news_data;

	FILE* fp = fopen(news_file_name, "rb");
	if (fp == NULL) {

		printf("Failed to read data.\n");
		return;
	}

	while (fread(&temp_news_data, sizeof(News), 1, fp) == 1) {
		insert_news_node(news_list, temp_news_data);
		memset(&temp_news_data, 0, sizeof(temp_news_data));
	}
	rewind(fp);
	fclose(fp);
	fp = NULL;
}



