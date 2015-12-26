#include <stdio.h>
#include <stdlib.h>

/*************************************
 * first version
 * second version using three spare arguments
 ************************************/
void hanoi(int n, char src, char dest);
void hanoi_2(int n, char src, char dest, char spare);
void mov(char src, char dest);
int main(int argc, const char *argv[])
{
    hanoi_2(3, 'B', 'C', 'A');
	printf("==============\n");
	hanoi(3, 'B', 'C');
    return 0;
}


void hanoi_2(int n, char src, char dest, char spare)
{
	if (n == 0) {
		return;
	}
	else {
		hanoi_2(n-1, src, spare, dest);
		mov(src, dest);
		hanoi_2(n-1, spare, dest, src);
	}
}
void hanoi(int n, char src, char dest)
{
    char temp;
	/* set the spare cylinder */
    if (src +  dest == 'B' + 'A')
        temp = 'C';
    if (src + dest == 'A' + 'C')
        temp = 'B';
    if (src + dest == 'B' + 'C')
        temp = 'A';
    
	/* if there is one plate, move it directly to the dest */
    if (n == 1) mov(src, dest);
    else {
		/* else recusive hanoi move the plates */
        hanoi(n-1, src, temp);
        mov(src, dest);
        hanoi(n-1, temp, dest);
    }
    return;
}

void mov(char src, char dest)
{
    printf("move %c to %c\n", src, dest);
	return;
}
/****************************/
