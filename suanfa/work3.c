#include <stdio.h>
#include <stdlib.h>

//3.1 猴子吃桃
// 循环求解
void monkeyPeach() {
	// 倒推，10 到 1 有九个时间段
	int x = 2, sum, day = 9;
	// for (day = 9; day >= 1; day--) {……}
	while (day > 0) {
		x = (x + 2) * 2;
		day--;
	}
	printf("第一天有%d个桃子\n", x);
}

#include <math.h>

//3.2 八皇后问题
// 枚举法
int checkSame(int a[], int n) {
	int i;
	// 当前行与前 1~n-1 行相比较
	// 判断是否同列、同对角
	for (i = 1; i < n; i++) {
		if (abs(a[i] - a[n]) == abs(i - n) || a[i] == a[n]) {
			return 0;
		}
	}
	return 1;
}
void eightQueens() {
	int i, k;
	int count = 0;
	int x[9] = { 0 }, y[9] = { 0 };
	// 数组下标:是皇后所在 行，数组元素:是皇后所在 列
	// 其他皇后，根据第一个皇后改变位置
	// 改变依据：是否与其他皇后在同一 对角 / 列.
	// 同对角：a[i] +- i == a[j] -+ j
	// 同列：a[i] == a[j];
	for (x[1] = 1; x[1] <= 8; x[1]++) {
		for (x[2] = 1; x[2] <= 8; x[2]++) {
			if (checkSame(x, 2) == 0) {
				continue;
			}
			for (x[3] = 1; x[3] <= 8; x[3]++) {
				if (checkSame(x, 3) == 0) {
					continue;
				}
				for (x[4] = 1; x[4] <= 8; x[4]++) {
					if (checkSame(x, 4) == 0) {
						continue;
					}
					for (x[5] = 1; x[5] <= 8; x[5]++) {
						if (checkSame(x, 5) == 0) {
							continue;
						}
						for (x[6] = 1; x[6] <= 8; x[6]++) {
							if (checkSame(x, 6) == 0) {
								continue;
							}
							for (x[7] = 1; x[7] <= 8; x[7]++) {
								if (checkSame(x, 7) == 0) {
									continue;
								}
								for (x[8] = 1; x[8] <= 8; x[8]++) {
									if (checkSame(x, 8) == 0) {
										continue;
									}
									else {
										for (i = 1; i <= 8; i++) {
											y[x[i]] = 1;
											for (k = 1; k <= 8; k++) {
												printf("%d ", y[k]);
											}
											printf("\n");
											// 清理标记占位
											y[x[i]] = 0;
										}
										// 分隔相邻棋盘
										printf("\n");
									}
									count++;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("一共有%d种\n", count);
}


//3.3 百马百担
void selectHorse() {
	int a, b, c, sum = 0;
	for (a = 0; a <= 33; a++) {
		for (b = 50; b >= 0; b--) {
			c = 100 - a - b;
			sum = 3 * a + 2 * b + c / 2;
			if (c % 2 == 0 && sum == 100) {
				printf("大马有%d只，中马有%d只，小马有%d只\n", a, b, c);
			}
		}
	}
}

//3.4 条件四位数
int check(int x) {
	int k = 0, s = 0;
	int arr[10] = { 0 };
	int temp = x;
	// 分离各个位数存到数组
	while (temp) {
		k = temp % 10;
		s = s + k;  // 求个各位数字的和
		arr[k]++;  // 数组记录数字出现个数
		temp /= 10;
	}
	// 判断能否被各个位数字和的平方整除
	//（把更严格的条件放在前）
	if (x % (s * s) != 0) {
		return 0;
	}
	// 判断是否有重复数字
	for (int i = 0; i < 10; i++) {
		if (arr[i] >= 2) {
			return 0;
		}
	}
	return 1;
}
void fourNumber() {
	// 人为限制千位数字非零
	for (int i = 1023; i <= 9876; i++) {
		if (check(i)) {
			printf("%d\n", i);
		}
	}
}

int main() {
	//selectHorse();
	//eightQueens();
	//monkeyPeach();
	//fourNumber();
	return 0;
}