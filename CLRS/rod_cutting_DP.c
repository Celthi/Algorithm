#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int price[LEN] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int rev[LEN];

void rod_cutting(int n, int price[])
{
	int rtemp = 0;
	int i = 0;
	int k;
	for (i = 0; i < n; i++){
		rev[i] = price[i];
		for (k = 0; k < i; k++) {
			//CLRS begin with 1, but in C, index begin with 0, So, index + 1 is the real rod length.
			rev[i] = (rev[i] > (price[k] + rev[i-k-1])) ? rev[i] : (price[k] + rev[i-k-1]);
		}
	}
	for ( i = 0; i < n; i++) {
		printf("%d\t", rev[i]);

	}
}
int main(void)
{
	rod_cutting(LEN, price);
	return 0;
}
