#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2.1 �ǵݹ�ʵ���ж��ַ�������
void w2_1() {
	//����һ��
	char* str = "";
	printf("����һ���ַ��ж��Ƿ�Ϊ���ģ�\n");
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
		printf("������ǻ��ģ�\n");
	}
	else {
		printf("����Ĳ��ǻ��ģ�\n");
	}

	//��������
	char ch[100] = "";   //��ż�����ַ���
	printf("����һ���ַ��ж��Ƿ�Ϊ���ģ�\n");
	scanf("%s", ch); //���ܼ�����ַ���
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
		printf("������ǻ��ģ�\n");
	}
	else {
		printf("����Ĳ��ǻ��ģ�\n");
	}
}


//2.2 �ݹ�ʵ���ж��ַ�������
int isPalindrome(char str[], int i)  //�����жϺ���
{
	if (i == 0 || i == 1) {
		return 1;
	}
	else if (str[0] == str[i - 1]) {
		return isPalindrome(str + 1, i - 2); //���±�(i - 1) - 1
	}
	else {
		return 0;
	}
}


int main2_2() {
	//�����жϣ��ݹ飩
	int str[] = { "" };
	printf("����һ���ַ��ж��Ƿ�Ϊ���ģ�\n");
	scanf("%s", str);
	int i = strlen(str);
	if (isPalindrome(str, i)) {
		printf("������ǻ��ģ�\n");
	}
	else {
		printf("����Ĳ��ǻ��ģ�\n");
	}
	system("pause");
	return 0;
}