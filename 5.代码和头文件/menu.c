#include <stdio.h>

void search_menu() {
	printf("---------------------Search----------------------------------\n");
	printf("\t|0.return                                               |\n");
	printf("\t|1.search news by title.                               |\n");
	printf("\t|2.search news by date.                                |\n");
	printf("\t|3.search news by time.                                |\n");
	printf("\t|4.search news by category.                            |\n");
	printf("\t|5.search news by keyword of title ,time and category. |\n");
	printf("-------------------------------------------------------------\n\n");
	printf("Please enter a number 0~5：");
}

void user_menu() {
	printf("-------------------User-------------------------\n");
	printf("|\t0.Sign out                             |\n");
	printf("|\t1.read news                            |\n");
	printf("|\t2.Count your own news releases         |\n");
	printf("|\t3.search news                          |\n");
	printf("|\t4.comment news                         |\n");
	printf("|\t5.add news                             |\n");
	printf("|\t6.sort news by time from ago to latese |\n");
	printf("|\t7.sort news by time from latest to ago |\n");
	printf("------------------------------------------------\n\n");
	printf("Please enter a number 0~7：");
}

void administrator_menu() {                          //管理员菜单
	printf("-------------------Administrator--------------------------\n");
	printf("|\t0.Sign out                                        |\n");
	printf("|\t1.add news                                        |\n");
	printf("|\t2.delete news                                     |\n");
	printf("|\t3.modify news                                     |\n");
	printf("|\t4.read news                                       |\n");
	printf("|\t5.sort news by time from ago to latese            |\n");
	printf("|\t6.sort news by time from latest to ago            |\n");
	printf("|\t7.modify user                                     |\n");
	printf("|\t8.add user                                        |\n");
	printf("|\t9.delete user                                     |\n");
	printf("|\t10.read user                                      |\n");
	printf("|\t11.search news                                    |\n");
	printf("|\t12.Counts news published in a certain time period.|\n");
	printf("----------------------------------------------------------\n\n");
	printf("Please enter a number 0~12：");
}

void login_interface() {                                         //登录菜单
	printf("-------------Login---------------\n");
	printf("|\t0.Exit the system    \t|\n");
	printf("|\t1.administrator login\t|\n");
	printf("|\t2.user login         \t|\n");
	printf("|\t3.visitor            \t|\n");
	printf("---------------------------------\n\n");
	printf("Please enter a number 0~3：");
}