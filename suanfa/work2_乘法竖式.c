#include<stdio.h> 

#define NUM 5 /*需要穷举的变量数目*/ 
#define C_NUM 4 /*每个变量的值的变化范围*/ 

int a[NUM + 1]; /*为需要穷举的变量开辟的数组*/
/*a[1]:被乘数的百位，a[2]：十位,aa[3]:个位 a[4]:被乘数的十位 a[5]:个位*/
int b[] = { 0,2,3,5,7 }; /*存放质数数字的数组，不使用第0号元素*/
int f(long sum);

int main()
{
	int i, not_finish = 1;
	i = 2; /*i:将要进行处理的元素的指针下标。设置初始值*/
	a[1] = 1; /*为第1号元素设置初始值*/
	while (not_finish) /*not_finish:程序运行没结束标记*/
	{
		while (not_finish && i <= NUM) /*处理包括第i个元素在内的后续元素，找出当前条件下的一种各个变量的一种可能的取值方法*/
			if (a[i] >= C_NUM) /*当要处理的元素取超过规定的C_NUM时*/
				if (i == 1 && a[1] == C_NUM)
					not_finish = 0; /*若1号元素已经到C_NUM，则处理全部结束*/
				else a[i--] = 0; /*将要处理的元素置0，下标-1(回退一个元素)*/
			else a[i++]++; /*当前元素值加1后下标指针加1*/
		if (not_finish)
		{
			long int sum1, sum2, sum3, sum4; /*定义临时变量*/
			sum1 = b[a[1]] * 100 + b[a[2]] * 10 + b[a[3]]; /*计算被乘数*/ /*利用数组的下标与质数的对应关系完成序号1到4向质数的转换*/
			sum2 = sum1 * b[a[5]]; /*计算乘数个位与被乘数的部分积*/
			sum3 = sum1 * b[a[4]]; /*计算乘数十位与被乘数的部分积*/
			if (sum2 >= 2222 && sum2 <= 7777 && f(sum2) && sum3 >= 2222 && sum3 <= 7777 && f(sum3)) /*判断两部分积是否满足题目条件*/
				if ((sum4 = sum2 + sum3 * 10) >= 22222 && sum4 <= 77777 && f(sum4)) /*判断乘式的积是否满足题目条件*/
				{
					printf("  %d\n", sum1); /*若满足题意，则打印结果*/
					printf("× %d%d\n", b[a[4]], b[a[5]]);
					printf("-----------\n");
					printf(" %d\n", sum2);
					printf("%d\n", sum3);
					printf("-----------\n");
					printf("%d\n", sum4);
				}
			i = NUM; /*为穷举下一个可能取值作准备*/
		}
	}
}

int f(long sum) /*判断sum的每一位数字是否是质数，若不是返回0，若是返回1*/
{
	int i, k, flag; /*flag=1:数字是质数的标记*/
	while (sum > 0)
	{
		i = sum % 10; /*取个位的数字*/
		for (flag = 0, k = 1; !flag && k <= C_NUM; k++) if (b[k] == i)
		{
			flag = 1; break;
		}
		if (!flag)
			return 0;
		else sum = sum / 10;
	}
	return 1;
}