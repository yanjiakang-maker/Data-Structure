#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>



int test() {
	char s1[50], s2[50];
	int i;
	gets(s1);
	gets(s2);
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] > s2[i])
			break;
	}
	int tmp = strcmp(s1, s2);
	printf("两字符串比较的结果为:%d\n", tmp);


	return 0;
}


#define N 6

int test2() {

	int a[N+1][N+1] = { 0 }, i, j;
	for (i = 1; i < N+1; i++) {
		a[i][1] = 1;
		for (j = 2; j <= i; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	for (i = 1; i < N+1; i++) {
		for (j = 1; j <= i; j++) 
			printf("%4d", a[i][j]);
		printf("\n");
	}

	return 0;
}


//int f(int x)
//{
//	int i, j, m;
//	if (x <= 0)
//	{
//		printf("sorry error");
//		return NULL;
//	}
//
//	i = x;
//	while (1)
//	{
//		for (j = 2; j < x; ++j)
//		{
//			if (i % j == 0)
//				continue;
//		}
//		i++;
//		if (j = x)
//			return i;
//	}
//}


int f(int x)
{
	int i, j, m;
	if (x <= 0) {
		printf("sorry error");
		return 0;
	}

	for (i = x + 1;; ++i)
	{
		//m = x + i;
		for (j = 2; j < x; ++j)
		{
			if (i % j != 0)
				if (j <= 2)
				{
					return i;
				}
		}
	}

}



int f(int x)
{
	int i, j, m;
	if (x <= 0) {
		printf("sorry error");
		return 0;
	}

	for (i = x + 1;; ++i)
	{
		//m = x + i;
		for (j = 1; (x - j) >= 2; ++j)
		{
			if (i % (x - j) != 0)
				if ((x - j) <= 2)
				{
					return i; 
				}
		}
	}
	
}



int main()
{
	int f(int x);
	int m, n;
	printf("please input a number:\n");
	scanf("%d", &m);
	n = f(m);
	printf("outcome is %d", n);
}
