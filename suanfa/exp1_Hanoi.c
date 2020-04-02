#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char start, char buffer, char end) {
	if (n == 1) {
		printf("Move dish %d from %c to %c \n", n, start, end);
	}
	else {
		Hanoi(n - 1, start, end, buffer);   //该语句递归时有奇偶相关性，end和buffer互换
		printf("Move dish %d from %c to %c \n", n, start, end);  //更深层的递归执行完后才接着执行
		Hanoi(n - 1, buffer, start, end);   //缓冲柱更换，目标柱始终不变	
	}
}


