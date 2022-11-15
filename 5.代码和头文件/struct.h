#pragma once

#define N 50


//定义发布时间结构体，包含年、月、日
typedef struct _date {
	int year;
	int month;
	int day;
}Date;


//定义用户结构体，包含账号、密码
typedef struct _user {
	char account[N];   //此50是数组大小，此后的方括号是下标。注意在定义时初始化的方式和定义后初始化方式是不一样的！
	char password[N];
}User;

//定义用户数据结点
struct user_node {
	User data;
	struct user_node* next;
};


/*//定义评论结构体，包含账号、密码
typedef struct _comment {
	char comment[N];
	User user;
}Comment;*/

//定义新闻结构体，包含标题、发布者、发布时间、正文、评论、分类
typedef struct _news {
	char title[500];
	User user;
	Date date;
	char content[10000];
	char comment[1000];
	char category[N];      //1.通知Notice，2.公告Announcement，3.简讯Newsletter
}News;

struct news_node {
	News data;
	struct news_node* next;
};




void administrator_menu();//管理员菜单界面
void visitor_menu();//访客菜单界面
void user_menu();//用户菜单界面
void admid_function(struct user_node* uesr_list, struct news_node* news_list);//管理员功能界面
void login_interface();//登录界面
void search_menu();//搜索界面


void admin_login(struct user_node* uesr_list, struct news_node* news_list);//判断管理员登录函数
void insert_user_node(struct user_node* head, User data);//将新增用户数据结点插在链表头后面
struct user_node* create_user_node(User data);//创造新的用户数据结点
struct user_node* create_user_list();//创造用户数据链表表头
struct news_node* create_news_list();//创造新闻数据链表表头
struct news_node* create_news_node(News data);//创造新的新闻数据结点
void insert_news_node(struct news_node* head, News data);//将新增新闻数据结点插在链表表头后面
void print_user_list(struct user_node* head);//打印用户链表数据
void delete_user_node_by_account(struct user_node* head, char* account);//通过搜索用户账号删除该用户数据
struct user_node* search_user_by_account(struct user_node* head, char* account);//通过用户账号搜索用户
void print_user_node(struct user_node* cur_user_node);//打印当前用户数据
void print_news_list(struct news_node* head);//打印全部新闻数据
void delete_news_node_by_title(struct news_node* head, char* title,struct news_node* deleted_news_list);//通过搜索新闻标题删除新闻数据
void print_news_node(struct news_node* cur_news_node);//打印特定新闻
struct news_node* search_news_by_title(struct news_node* head, char* title);//通过新闻标题搜索特定新闻数据

void read_user_file(char* user_file_name, struct user_node* user_list);
void save_user_file(char* user_file_name, struct user_node* user_list);
void read_news_file(char* news_file_name, struct news_node* news_list);
void save_news_file(char* news_file_name, struct news_node* news_list);
void user_login(struct user_node* user_list, struct news_node* news_list);
int check_user_account(char account[N], char password[N], struct user_node* user_list);
void user_function(struct user_node* user_list, struct news_node* news_list);

void search_function(struct news_node* news_list);
struct news_node* search_news_by_date(struct news_node* head, News temp_news);
void search_news_by_time(struct news_node* head, Date date_1, Date date_2);
void search_news_by_category(struct news_node* head, char* category);
void combined_search(struct news_node* head, Date date_1, Date date_2, char* keyword, char* category);
int Count(struct news_node* head, Date date_1, Date date_2, char* account, int* A, int* B, int* C);

struct news_node* sorting_from_ago_to_latest(struct news_node* news_list);
struct news_node* sorting_from_latest_to_ago(struct news_node* news_list);