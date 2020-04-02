#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2.1 非递归实现判断字符串回文
void w2_1() {
	//方法一：
	char* str = "";
	printf("输入一串字符判断是否为回文：\n");
	scanf("%s", str);
	int length = strlen(str);
	char* low = str;
	char* high = str + length - 1;
	int i = 1, flag = 1;
	while (i <= length / 2) {
		if (*low == *high) {
			low++;
			high--;
			i++;
			continue;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		printf("输入的是回文！\n");
	}
	else {
		printf("输入的不是回文！\n");
	}

	//方法二：
	char ch[100] = "";   //存放键入的字符串
	printf("输入一串字符判断是否为回文：\n");
	scanf("%s", ch); //接受键入的字符串
	int len = strlen(ch);
	int i = 0, j = len - 1;
	int flag = 1;
	while (i <= len / 2) {
		if (ch[i] == ch[j]) {
			i++;
			j--;
			continue;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("输入的是回文！\n");
	}
	else {
		printf("输入的不是回文！\n");
	}
}


//2.2 递归实现判断字符串回文
int isPalindrome(char str[], int i)  //回文判断函数
{
	if (i == 0 || i == 1) {
		return 1;
	}
	else if (str[0] == str[i - 1]) {
		return isPalindrome(str + 1, i - 2); //即下标(i - 1) - 1
	}
	else {
		return 0;
	}
}


int main2_2() {
	//回文判断（递归）
	int str[] = { "" };
	printf("输入一串字符判断是否为回文：\n");
	scanf("%s", str);
	int i = strlen(str);
	if (isPalindrome(str, i)) {
		printf("输入的是回文！\n");
	}
	else {
		printf("输入的不是回文！\n");
	}
	system("pause");
	return 0;
}