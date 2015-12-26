#include <stdio.h>
#define MAXLENGTH 100

int my_getline(char s[], int lim);
int main(int argc, char *argv[])
{
	unsigned char  a, b;
	int len = MAXLENGTH;
	char line[MAXLENGTH];
	while (my_getline(line, MAXLENGTH) > 1) {
		sscanf(line, "%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}
int my_getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
