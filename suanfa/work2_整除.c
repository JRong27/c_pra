#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2.3 判断输入一个数能否被4,7,9整除，具体指出被哪些个整除
void w2_3() {
	long n; //存放键入的整数值
	printf("请输入一个整数：");
	scanf("%d", &n); //获取键入的整数值
	long sum = 0;

	if (n % 4 == 0) {
		sum += 1;
	}
	else if (n % 7 == 0) {
		sum += 2;
	}
	else if (n % 9 == 0) {
		sum += 4;
	}
	//简便的圈复杂度较低的写法如下：
	//sum = (n % 4 == 0) + (n % 7 == 0) + (n % 9 == 0);
	switch (sum) {
	case 0: printf("这个数不能被4,7,9中的任何一个数整除\n");
		break;
	case 1: printf("这个数能被4整除\n");
		break;
	case 2: printf("这个数能被7整除\n");
		break;
	case 3: printf("这个数能被4，7整除\n");
		break;
	case 4: printf("这个数能被9整除\n");
		break;
	case 5: printf("这个数能被4，9整除\n");
		break;
	case 6: printf("这个数能被7，9整除\n");
		break;
	case 7: printf("这个数能同时被4，7，9整除\n");
		break;
	}
	system("pause");
}