#include <stdio.h>
#include <stdlib.h>

//1.1 回形矩阵
void w1_1(){
	int i, j, n, k = 1, a[10][10];
	printf("请输入一个正整数(1≤n≤10):");
	scanf("%d", &n);

	for (i = 0; i < (n + 1) / 2; i++)	/*控制圈数*/
	{
		for (j = i; j < n - i; j++)		/*上方元素*/
			a[i][j] = k++;
		for (j = i + 1; j < n - i; j++)	/*右方元素*/
			a[j][n - i - 1] = k++;
		for (j = n - i - 2; j > i; j--)	/*下方元素*/
			a[n - i - 1][j] = k++;
		for (j = n - i - 1; j > i; j--)	/*左方元素*/
			a[j][i] = k++;
	}
	//矩阵输出
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
	system("pause");
}



//1.2 一串连续自然数相乘，结果中有多少个0
void w1_2(){
	int count = 0;
	int n = 0;
	printf("请输入n的值：");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int m = i;  //注意不能直接对i进行下一步操作，否则i一直无法突破5，会陷入死循环
		while (m % 5 == 0) {
			m = m / 5;
			count++;
		}
	}
	printf("从1到%d相乘的结果中,末尾0的个数为%d个\n", n, count);
	system("pause");
}



//1.3 竞猜排名
void w1_3(){
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++) 
		for (b = 1; b <= 5; b++)
			if (a != b)
				for (c = 1; c <= 5; c++)
					if (c != a && c != b)
						for (d = 1; d <= 5; d ++)
							if (d != a && d != b && d != c) {
								e = 15 - a - b - c - d;
								if (e != a && e != b && e != c && e != d) {
									if (((b == 3) + (c == 5) == 1) &&
										((d == 2) + (e == 4) == 1) &&
										((b == 1) + (e == 4) == 1) &&
										((c == 1) + (b == 2) == 1) &&
										((d == 2) + (a == 3) == 1)) {
										printf("A是第%d名; \nB是第%d名; \nC是第%d名; \nD是第%d名; \nE是第%d名。\n", a, b, c, d, e);
									}
								}
							}
	system("pause");
}



//1.4 完全平方数，其中又有两位数字相同的三位数
void w1_4() {
	printf("是完全平方数，其中又有两位数字相同的三位数有：\n");
	int a, b, c;
	int n = 10;
	for (int num = 0; num <= 1000; n++) {
		num = n * n;
		a = num / 100;
		b = num / 10 % 10;
		c = num % 10;
		if (a == b || a == c || b == c) {
			printf("%d\t", num);
		}
	}
	system("pause");
}

