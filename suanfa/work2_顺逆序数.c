#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2.5 输入五位数以内的正整数，判断它是几位数，顺序输出，逆序输出，循环解决
void number1(long x) {  //int 型数值取值范围是-32768~+32767，不能满足五位数以内的所有数
	long a = x;
	long b = x;
	int count = 0;
	while (x != 0) {
		x /= 10;
		count++;
	}
	printf("%d是%d位数", a, count);
	//
	printf("\n逆序输出：");
	while (a != 0) {
		printf("%d", a % 10);
		a /= 10;
	}
	//
	printf("\n顺序输出：");
	int k = 1;
	for (int i = 1; i < count - 1; i++) {
		k *= 10;
	}
	while (k != 0) {
		printf("%d", b / k);
		b %= k;
		k /= 10;
	}
	printf("\n");
}
// 模块化更方便管理
int getSize(long x) {
	int count = 0;
	while (x != 0) {
		x /= 10;
		count++;
	}
	return count;
}
void invert(int x) {
	printf("按逆序输出为：\n");
	while (x != 0) {
		printf("%d", x % 10);
		x /= 10;
	}
}
void sequence(int x) {
	int count = getSize(x);
	printf("\n按顺序输出为：\n");
	int k = 1;
	for (int i = 1; i < count - 1; i++) {
		k *= 10;
	}
	while (k != 0) {
		printf("%d", x / k);
		x %= k;
		k /= 10;
	}
}

// 用数组试试
void num(long x) {
	int arr[5] = { 0 };
	int i, j;
	// i 记录位数
	for (i = 0; i < 5 && x != 0; i++) {
		//数组存着逆序的数字
		arr[i] = x % 10;
		x /= 10;
	}

	printf("输入的是%d位数\n", i);
	printf("\n按逆序输出为：\n");
	for (j = 0; j < i; j++) {
		printf("%d", arr[j]);
	}
	printf("\n按顺序输出为：\n");
	for (j = i - 1; j >= 0; j--) {
		printf("%d", arr[j]);
	}
	printf("\n");
}





//2.6 输入五位数以内的正整数，判断它是几位数，顺序输出，逆序输出，递归解决【我太强了！！】
int count(int i) //位数计算函数
{
	if (i != 0) {
		return 1 + count(i / 10);
	}
	else {
		return 0;
	}
}
void nxdisp(int i) //逆序输出函数
{
	if (i != 0) {
		printf("%d", i % 10);
		return nxdisp(i / 10);
	}
}
void sxdisp(int i)//顺序输出函数
{
	int temp = count(i);
	if (temp != 0) {
		switch (temp) {
		case 5: printf("%d", i / 10000);
			return sxdisp(i % 10000);
			break;
		case 4: printf("%d", i / 1000);
			return sxdisp(i % 1000);
			break;
		case 3: printf("%d", i / 100);
			return sxdisp(i % 100);
			break;
		case 2: printf("%d", i / 10);
			return sxdisp(i % 10);
			break;
		case 1: printf("%d", i);
			break;
		}
	}
}

int main() {
	int n;//存放输入的正整数
	//循环
	num(n);
	//递归
	printf("请输入一个五位以内的正整数\n");
	scanf("%d", &n);
	printf("%d是%d位数\n", n, count(n));
	printf("逆序打印\n");
	nxdisp(n);
	printf("\n");
	printf("顺序打印\n");
	sxdisp(n);
	printf("\n");

	system("pause");
	return 0;
}