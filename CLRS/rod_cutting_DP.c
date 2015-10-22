#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN 10

int price[LEN] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int s[LEN] ;//= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int rev[LEN];

void rod_cutting(int n, int price[])
{
	int rtemp = 0;
	int i = 0;
	int k;
	char flag = 0;
	for (i = 0; i < n; i++){
		rev[i] = price[i];
		s[i] = i + 1;
		for (k = 0; k < i; k++) {
			//CLRS begin with 1, but in C, index begin with 0, So, index + 1 is the real rod length.
			//Watch out in the condition move must using < not >, because when use > it is hard to
			//record the optimal solution.
			rev[i] = (flag = (rev[i] < (price[k] + rev[i-k-1]))) ? (price[k] + rev[i-k-1]) : rev[i];
			if(flag)
				s[i] = k + 1;
		}
	}
	for ( i = 1; i <= n; i++) {
		printf("%d\t", i);
	}
	printf("\n------------------------------------------------------------------------\n");
	for ( i = 0; i < n; i++) {
		printf("%d\t", rev[i]);
	}
	printf("\n");
	for ( i = 0; i < n; i++) {
		printf("%d\t", s[i]);
	}
}
int main(void)
{
	rod_cutting(LEN, price);
	return 0;
}
