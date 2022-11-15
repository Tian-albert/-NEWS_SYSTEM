#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include <conio.h>

void user_login(struct user_node* user_list, struct news_node* news_list) {
	char account[N];
	char password[N];
	int key = 0;

	while (1) {
		printf("Please enter an account number:\n");
		rewind(stdin);
		scanf("%s", account);
		printf("Please enter a password:\n");
		rewind(stdin);
		scanf("%s", password);
		key = check_user_account(account, password, user_list);
		if (key == 1) {
			printf("Login successful.\n");
			
			clrscr();
			user_function(user_list, news_list);
			break;
		}
		else {
			printf("The account number or password was entered incorrectly!");
			
			
			printf("Please enter 1 to re-enter it or enter 2 to Return to the previous level:");
			rewind(stdin);
			scanf("%d", &key);
			if (key == 2) { break; }
		}

	}
}

void user_function(struct user_node* user_list, struct news_node* news_list) {
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

		temp_user.account[0] = '\0';//初始化temp_user（准确地来说是赋值为0保证数据不会杂糅）
		temp_user.password[0] = '\0';

		a = 0;
		b = 0;
		c = 0;

		user_menu();
		rewind(stdin);
		scanf("%d", &key);
		switch (key)
		{
		case 0:
			printf("Sign out\n\n");
			return;
			break;
		case 1:
			printf("Read news\n\n");
			print_news_list(news_list);
			break;
		case 2:
			printf("Counts the number of times news is published in a certain time period.\n\n");
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
		case 3:
			printf("Search news\n\n");
			search_function(news_list);
			break;
		case 4:
			printf("Comment news\n\n");
			printf("Please enter the title of the news you want to comment on:\n");
			rewind(stdin);
			gets(temp_news.title);
			cur_news_node = search_news_by_title(news_list, temp_news.title);
			if (cur_news_node == NULL) {
				printf("The specified content could not be found!\n");
			}
			else {
				printf("Please enter the comment,for example(|*mary:it is a good news!*|)\n");
				printf("Be careful not to exceed 50 characters!\n");
				rewind(stdin);
				gets(temp_news.comment);
				strncat(cur_news_node->data.comment, temp_news.comment, 50);
				save_news_file("news.txt", news_list);
				printf("Comment successful!\n");
			}
			break;
		case 5:
			printf("Add news\n\n");
			printf("Please enter a title:\n");
			rewind(stdin);
			gets(temp_news.title);
			printf("Please enter your account:\n");
			rewind(stdin);
			gets(temp_news.user.account);
			printf("Please enter a news category(Notice,Announcement or Newsletter):\n");
			rewind(stdin);
			gets(temp_news.category);
			printf("Please enter a release date(Separated by commas in the middle->2022,1,2):\n");
			rewind(stdin);
			scanf("%d,%d,%d", &temp_news.date.year, &temp_news.date.month, &temp_news.date.day);//int类型记得加取地址符
			printf("Please enter the body text:\n");
			rewind(stdin);
			gets(temp_news.content);
			insert_news_node(news_list, temp_news);
			save_news_file("news.txt", news_list);
			printf("Added successfully!\n");
			break;
		case 6:
			printf("Sort news by time from ago to latese\n\n");
			sorting_from_ago_to_latest(news_list);
			print_news_list(news_list);
			break;
		case 7:
			printf("Sort news by time from latest to ago\n\n");
			sorting_from_latest_to_ago(news_list);
			print_news_list(news_list);
			break;
		default:
			printf("Input error, please re-enter：");
			break;
		}
		key = 0;
		
		clrscr();
	}
}

void search_function(struct news_node* news_list) {
	int key = 0;
	Date date_1 = { 0 }, date_2 = { 0 };
	User temp_user = { 0 };
	News temp_news = { 0 };
	struct user_node* cur_user_node = { 0 };
	struct news_node* cur_news_node = { 0 };

	while (1) {
		clrscr();
		temp_news.category[0] = 0;//初始化temp_news（准确地来说是赋值为0保证数据不会杂糅）
		temp_news.title[0] = 0;
		temp_news.user.account[0] = 0;
		temp_news.content[0] = 0;
		temp_news.comment[0] = 0;
		temp_news.date.year = 0;
		temp_news.date.month = 0;
		temp_news.date.day = 0;

		temp_user.account[0] = '\0';//初始化temp_user（准确地来说是赋值为0保证数据不会杂糅）
		temp_user.password[0] = '\0';

		search_menu();
		rewind(stdin);
		scanf("%d", &key);
		switch (key)
		{
		case 0:
			printf("Return\n\n");
			return;
			break;
		case 1:
			printf("Search_news_by_title\n\n");
			printf("Please enter the title of the news you want to read:\n");
			rewind(stdin);
			gets(temp_news.title);
			cur_news_node = search_news_by_title(news_list, temp_news.title);
			if (cur_news_node == NULL) {
				printf("The specified content could not be found!\n");
			}
			else {
				print_news_node(cur_news_node);
			}
			break;
		case 2:
			printf("Search_news_by_date\n\n");
			printf("Please enter the release date of the news you want to read(Separated by commas in the middle->2022,1,2):\n");
			rewind(stdin);
			scanf("%d,%d,%d", &temp_news.date.year, &temp_news.date.month, &temp_news.date.day);
			cur_news_node = search_news_by_date(news_list, temp_news);
			if (cur_news_node == NULL) {
				printf("The specified content could not be found!\n");
			}
			else {
				print_news_node(cur_news_node);
			}
			break;
		case 3:
			printf("Search_news_by_time\n\n");
			printf("Check out the news between date_2 and date_2.\n");
			printf("Please enter date_1:\n");
			rewind(stdin);
			scanf("%d,%d,%d", &date_1.year, &date_1.month, &date_1.day);
			printf("Please enter date_2:\n");
			rewind(stdin);
			scanf("%d,%d,%d", &date_2.year, &date_2.month, &date_2.day);
			search_news_by_time(news_list, date_1, date_2);
			break;
		case 4:
			printf("Search_news_by_category\n\n");
			printf("Please enter the category of the news you want to read:\n");
			rewind(stdin);
			gets(temp_news.category);
			search_news_by_category(news_list, temp_news.category);
			break;
		case 5:
			printf("Search news by keyword of title ,time and category.\n\n");
			printf("Check out the news between date_1 and date_2.\n");
			printf("Please enter date_1:\n");
			rewind(stdin);
			scanf("%d,%d,%d", &date_1.year, &date_1.month, &date_1.day);
			printf("Please enter date_2:\n");
			rewind(stdin);
			scanf("%d,%d,%d", &date_2.year, &date_2.month, &date_2.day);
			printf("Please enter the category of the news you want to read:\n");
			rewind(stdin);
			gets(temp_news.category);
			printf("Please enter the keyword of title:\n");
			rewind(stdin);
			gets(temp_news.title);
			combined_search(news_list, date_1, date_2, temp_news.title, temp_news.category);
			break;
		default:
			printf("Input error, please re-enter：");
			
			break;
		}
		key = 0;
		clrscr();
	}
}

int check_user_account(char account[N], char password[N], struct user_node* user_list) {//数组作为参数，定义式需要带方括号，使用时则不需要
	int key = 0;
	struct user_node* pMove = user_list;
	if (pMove == NULL || pMove->next == NULL) {
		printf("The account number or password was entered incorrectly!");
		return key;
	}
	while (pMove = pMove->next) {
		if (strcmp(pMove->data.account, account) == 0 && strcmp(pMove->data.password, password) == 0) {
			key = 1;
			return key;
		}

	}

}

struct news_node* search_news_by_date(struct news_node* head, News temp_news) {//通过日期查找特定新闻
	struct news_node* pMove = head;
	if (pMove == NULL || pMove->next == NULL) {
		printf("The specified content could not be found!\n");
		return pMove;
	}
	else {
		pMove = pMove->next;
		while (pMove) {
			if (pMove->data.date.year == temp_news.date.year && pMove->data.date.month == temp_news.date.month && pMove->data.date.day == temp_news.date.day) {
				print_news_node(pMove);
			}
			pMove = pMove->next;
		}
		return pMove;

	}
}

void search_news_by_time(struct news_node* head, Date date_1, Date date_2) {//通过时间段查找特定新闻
	struct news_node* pMove = head;
	if (pMove == NULL || pMove->next == NULL) {
		printf("The specified content could not be found!\n");
		return pMove;
	}
	else {
		pMove = pMove->next;
		while (pMove) {
			if ((pMove->data.date.year > date_1.year || (pMove->data.date.year == date_1.year && pMove->data.date.month > date_1.month) || (pMove->data.date.year == date_1.year && pMove->data.date.month == date_1.month && pMove->data.date.day >= date_1.day)) &&
				(pMove->data.date.year < date_2.year || (pMove->data.date.year == date_2.year && pMove->data.date.month < date_2.month) || (pMove->data.date.year == date_2.year && pMove->data.date.month == date_2.month && pMove->data.date.day <= date_2.day))) {
				print_news_node(pMove);
			}
			pMove = pMove->next;
		}
		return;

	}
}

void search_news_by_category(struct news_node* head, char* category) {//通过分类查找特定新闻
	struct news_node* pMove = head;
	if (pMove == NULL || pMove->next == NULL) {
		printf("The specified content could not be found!\n");
		return pMove;
	}
	else {
		pMove = pMove->next;
		while (pMove) {

			if (strcmp(pMove->data.category, category) == 0) {
				print_news_node(pMove);
			}
			pMove = pMove->next;
		}
		return;

	}
}

void combined_search(struct news_node* head, Date date_1, Date date_2, char* keyword, char* category) {
	struct news_node* pMove = head;
	if (pMove == NULL || pMove->next == NULL) {
		printf("The specified content could not be found!\n");
		return pMove;
	}
	else {
		pMove = pMove->next;
		while (pMove) {
			if (strcmp(pMove->data.category, category) == 0) {
				if ((pMove->data.date.year > date_1.year || (pMove->data.date.year == date_1.year && pMove->data.date.month > date_1.month) ||
					(pMove->data.date.year == date_1.year && pMove->data.date.month == date_1.month && pMove->data.date.day >= date_1.day)) &&
					(pMove->data.date.year < date_2.year || (pMove->data.date.year == date_2.year && pMove->data.date.month < date_2.month) ||
						(pMove->data.date.year == date_2.year && pMove->data.date.month == date_2.month && pMove->data.date.day <= date_2.day))) {
					if (strstr(pMove->data.title, keyword)) {
						print_news_node(pMove);
					}
				}
			}

			pMove = pMove->next;
		}
		printf("The end.\n");
		return;

	}
}

int Count(struct news_node* head, Date date_1, Date date_2, char* account, int* A, int* B, int* C) {
	int num = 0;
	struct news_node* pMove = head;
	if (pMove == NULL || pMove->next == NULL) {
		printf("The specified content could not be found!\n");
		return 0;
	}
	else {
		pMove = pMove->next;
		while (pMove) {
			if (strcmp(pMove->data.user.account, account) == 0) {
				if ((pMove->data.date.year > date_1.year || (pMove->data.date.year == date_1.year && pMove->data.date.month > date_1.month) ||
					(pMove->data.date.year == date_1.year && pMove->data.date.month == date_1.month && pMove->data.date.day >= date_1.day)) &&
					(pMove->data.date.year < date_2.year || (pMove->data.date.year == date_2.year && pMove->data.date.month < date_2.month) ||
						(pMove->data.date.year == date_2.year && pMove->data.date.month == date_2.month && pMove->data.date.day <= date_2.day))) {
					num++;
					if (strcmp(pMove->data.category, "Notice") == 0)(*A)++;
					if (strcmp(pMove->data.category, "Announcement") == 0)(*B)++;
					if (strcmp(pMove->data.category, "Newsletter") == 0)(*C)++;
				}
			}

			pMove = pMove->next;
		}
		return num;

	}

}

struct news_node* sorting_from_ago_to_latest(struct news_node* news_list)
{
	int i = 1;
	struct news_node* p1 = news_list;
	struct news_node* p2 = news_list->next;
	struct news_node* temp_p = { 0 };
	if (p1 == NULL || p2 == NULL)return NULL;
	if (p2->next == NULL)return news_list;
	temp_p = p1;
	p1 = p2;
	p2 = p2->next;
	while (i) {
		i = 0;
		while (p2) {
			if (p1->data.date.year > p2->data.date.year || (p1->data.date.year == p2->data.date.year && p1->data.date.month > p2->data.date.month) ||
				(p1->data.date.year == p2->data.date.year && p1->data.date.month == p2->data.date.month && p1->data.date.day > p2->data.date.day)) {
				temp_p->next = p2;
				p1->next = p2->next;
				p2->next = p1;
				//不能把指针也给交换了，只交换数据，否则进入死循环
				i = 1;
			}
			temp_p = p1;
			p1 = p2;
			p2 = p2->next;
		}
		temp_p = news_list;
		p1 = news_list->next;
		p2 = p1->next;
	}
	return news_list;
}

struct news_node* sorting_from_latest_to_ago(struct news_node* news_list)
{
	int i = 1;
	struct news_node* p1 = news_list;
	struct news_node* p2 = news_list->next;
	struct news_node* temp_p = { 0 };
	if (p1 == NULL || p2 == NULL)return NULL;
	if (p2->next == NULL)return p2;
	temp_p = p1;
	p1 = p2;
	p2 = p2->next;
	while (i) {
		i = 0;
		while (p2) {
			if (p1->data.date.year < p2->data.date.year || (p1->data.date.year == p2->data.date.year && p1->data.date.month < p2->data.date.month) ||
				(p1->data.date.year == p2->data.date.year && p1->data.date.month == p2->data.date.month && p1->data.date.day < p2->data.date.day)) {
				temp_p->next = p2;
				p1->next = p2->next;
				p2->next = p1;
				//不能把指针也给交换了，只交换数据，否则进入死循环
				i = 1;
			}
			temp_p = p1;
			p1 = p2;
			p2 = p2->next;
		}
		temp_p = news_list;
		p1 = news_list->next;
		p2 = p1->next;
	}
	return news_list;
}