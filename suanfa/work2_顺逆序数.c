#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2.5 ������λ�����ڵ����������ж����Ǽ�λ����˳����������������ѭ�����
void number1(long x) {  //int ����ֵȡֵ��Χ��-32768~+32767������������λ�����ڵ�������
	long a = x;
	long b = x;
	int count = 0;
	while (x != 0) {
		x /= 10;
		count++;
	}
	printf("%d��%dλ��", a, count);
	//
	printf("\n���������");
	while (a != 0) {
		printf("%d", a % 10);
		a /= 10;
	}
	//
	printf("\n˳�������");
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
// ģ�黯���������
int getSize(long x) {
	int count = 0;
	while (x != 0) {
		x /= 10;
		count++;
	}
	return count;
}
void invert(int x) {
	printf("���������Ϊ��\n");
	while (x != 0) {
		printf("%d", x % 10);
		x /= 10;
	}
}
void sequence(int x) {
	int count = getSize(x);
	printf("\n��˳�����Ϊ��\n");
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

// ����������
void num(long x) {
	int arr[5] = { 0 };
	int i, j;
	// i ��¼λ��
	for (i = 0; i < 5 && x != 0; i++) {
		//����������������
		arr[i] = x % 10;
		x /= 10;
	}

	printf("�������%dλ��\n", i);
	printf("\n���������Ϊ��\n");
	for (j = 0; j < i; j++) {
		printf("%d", arr[j]);
	}
	printf("\n��˳�����Ϊ��\n");
	for (j = i - 1; j >= 0; j--) {
		printf("%d", arr[j]);
	}
	printf("\n");
}





//2.6 ������λ�����ڵ����������ж����Ǽ�λ����˳�����������������ݹ�������̫ǿ�ˣ�����
int count(int i) //λ�����㺯��
{
	if (i != 0) {
		return 1 + count(i / 10);
	}
	else {
		return 0;
	}
}
void nxdisp(int i) //�����������
{
	if (i != 0) {
		printf("%d", i % 10);
		return nxdisp(i / 10);
	}
}
void sxdisp(int i)//˳���������
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
	int n;//��������������
	//ѭ��
	num(n);
	//�ݹ�
	printf("������һ����λ���ڵ�������\n");
	scanf("%d", &n);
	printf("%d��%dλ��\n", n, count(n));
	printf("�����ӡ\n");
	nxdisp(n);
	printf("\n");
	printf("˳���ӡ\n");
	sxdisp(n);
	printf("\n");

	system("pause");
	return 0;
}