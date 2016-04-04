#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void reverse(char *s, int i, int j)
{
	j--;
	while (i < j) {
		char temp;
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

int main(int argc, const char *argv[])
{
	char s[100];
	// char *s;
	scanf("%[^\n]", s);
	// fgets(s, MAX, stdin);
	int l = strlen(s);
	// s[l-1] = '\0';  /* remove the \n */
	// reverse(s);
	int i, j;
	char state = 0;
	i = 0;
	while (i < l) {
		j = i;
		while (s[i] == ' ' && s[i] != '\0') {
			i++;
			j = i;
		}
		while (s[j] != ' ' && s[j] != '\0') {
			j++;
			state = 1;
		}
		if (state) {
			reverse(s, i, j);
			state = 0;
			i = j;
		}


	}
	reverse(s, 0, l);
	printf("%s", s);
	return 0;
}
