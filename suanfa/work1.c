#include <stdio.h>
#include <stdlib.h>

//1.1 ���ξ���
void w1_1(){
	int i, j, n, k = 1, a[10][10];
	printf("������һ��������(1��n��10):");
	scanf("%d", &n);

	for (i = 0; i < (n + 1) / 2; i++)	/*����Ȧ��*/
	{
		for (j = i; j < n - i; j++)		/*�Ϸ�Ԫ��*/
			a[i][j] = k++;
		for (j = i + 1; j < n - i; j++)	/*�ҷ�Ԫ��*/
			a[j][n - i - 1] = k++;
		for (j = n - i - 2; j > i; j--)	/*�·�Ԫ��*/
			a[n - i - 1][j] = k++;
		for (j = n - i - 1; j > i; j--)	/*��Ԫ��*/
			a[j][i] = k++;
	}
	//�������
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
	system("pause");
}



//1.2 һ��������Ȼ����ˣ�������ж��ٸ�0
void w1_2(){
	int count = 0;
	int n = 0;
	printf("������n��ֵ��");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int m = i;  //ע�ⲻ��ֱ�Ӷ�i������һ������������iһֱ�޷�ͻ��5����������ѭ��
		while (m % 5 == 0) {
			m = m / 5;
			count++;
		}
	}
	printf("��1��%d��˵Ľ����,ĩβ0�ĸ���Ϊ%d��\n", n, count);
	system("pause");
}



//1.3 ��������
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
										printf("A�ǵ�%d��; \nB�ǵ�%d��; \nC�ǵ�%d��; \nD�ǵ�%d��; \nE�ǵ�%d����\n", a, b, c, d, e);
									}
								}
							}
	system("pause");
}



//1.4 ��ȫƽ����������������λ������ͬ����λ��
void w1_4() {
	printf("����ȫƽ����������������λ������ͬ����λ���У�\n");
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

