#include <stdio.h>
#include <stdlib.h>

//3.1 ���ӳ���
// ѭ�����
void monkeyPeach() {
	// ���ƣ�10 �� 1 �оŸ�ʱ���
	int x = 2, sum, day = 9;
	// for (day = 9; day >= 1; day--) {����}
	while (day > 0) {
		x = (x + 2) * 2;
		day--;
	}
	printf("��һ����%d������\n", x);
}

#include <math.h>

//3.2 �˻ʺ�����
// ö�ٷ�
int checkSame(int a[], int n) {
	int i;
	// ��ǰ����ǰ 1~n-1 ����Ƚ�
	// �ж��Ƿ�ͬ�С�ͬ�Խ�
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
	// �����±�:�ǻʺ����� �У�����Ԫ��:�ǻʺ����� ��
	// �����ʺ󣬸��ݵ�һ���ʺ�ı�λ��
	// �ı����ݣ��Ƿ��������ʺ���ͬһ �Խ� / ��.
	// ͬ�Խǣ�a[i] +- i == a[j] -+ j
	// ͬ�У�a[i] == a[j];
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
											// ������ռλ
											y[x[i]] = 0;
										}
										// �ָ���������
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
	printf("һ����%d��\n", count);
}


//3.3 ����ٵ�
void selectHorse() {
	int a, b, c, sum = 0;
	for (a = 0; a <= 33; a++) {
		for (b = 50; b >= 0; b--) {
			c = 100 - a - b;
			sum = 3 * a + 2 * b + c / 2;
			if (c % 2 == 0 && sum == 100) {
				printf("������%dֻ��������%dֻ��С����%dֻ\n", a, b, c);
			}
		}
	}
}

//3.4 ������λ��
int check(int x) {
	int k = 0, s = 0;
	int arr[10] = { 0 };
	int temp = x;
	// �������λ���浽����
	while (temp) {
		k = temp % 10;
		s = s + k;  // �����λ���ֵĺ�
		arr[k]++;  // �����¼���ֳ��ָ���
		temp /= 10;
	}
	// �ж��ܷ񱻸���λ���ֺ͵�ƽ������
	//���Ѹ��ϸ����������ǰ��
	if (x % (s * s) != 0) {
		return 0;
	}
	// �ж��Ƿ����ظ�����
	for (int i = 0; i < 10; i++) {
		if (arr[i] >= 2) {
			return 0;
		}
	}
	return 1;
}
void fourNumber() {
	// ��Ϊ����ǧλ���ַ���
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