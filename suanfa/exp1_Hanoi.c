#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char start, char buffer, char end) {
	if (n == 1) {
		printf("Move dish %d from %c to %c \n", n, start, end);
	}
	else {
		Hanoi(n - 1, start, end, buffer);   //�����ݹ�ʱ����ż����ԣ�end��buffer����
		printf("Move dish %d from %c to %c \n", n, start, end);  //�����ĵݹ�ִ�����Ž���ִ��
		Hanoi(n - 1, buffer, start, end);   //������������Ŀ����ʼ�ղ���	
	}
}


