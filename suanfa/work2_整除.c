#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2.3 �ж�����һ�����ܷ�4,7,9����������ָ������Щ������
void w2_3() {
	long n; //��ż��������ֵ
	printf("������һ��������");
	scanf("%d", &n); //��ȡ���������ֵ
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
	//����Ȧ���ӶȽϵ͵�д�����£�
	//sum = (n % 4 == 0) + (n % 7 == 0) + (n % 9 == 0);
	switch (sum) {
	case 0: printf("��������ܱ�4,7,9�е��κ�һ��������\n");
		break;
	case 1: printf("������ܱ�4����\n");
		break;
	case 2: printf("������ܱ�7����\n");
		break;
	case 3: printf("������ܱ�4��7����\n");
		break;
	case 4: printf("������ܱ�9����\n");
		break;
	case 5: printf("������ܱ�4��9����\n");
		break;
	case 6: printf("������ܱ�7��9����\n");
		break;
	case 7: printf("�������ͬʱ��4��7��9����\n");
		break;
	}
	system("pause");
}