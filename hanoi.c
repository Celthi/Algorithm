#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char src, char dest);
void mov(char src, char dest);
int main(int argc, const char *argv[])
{
    hanoi(5, 'B', 'C');
    return 0;
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
