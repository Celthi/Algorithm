#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 100

int my_getline(char line[], int max_len);
int erase(char line[]);

int main(int argc, const char *argv[])
{
	int times;
	char line[100];
	int goals = 0;
	scanf("%d", &times);
	times++;    /*increment times by 1, because after scanf times, there is a newline remain, 
				  ** my_getline will read newline first */
	while(times--) {
		if (my_getline(line, LEN) > 1) {
			goals = erase(line);
			printf("%d\n", goals);
		}
	}
	return 0;
}

int my_getline(char line[], int max_len)
{
	int i = 0;
	char c;
	while ((c = getchar()) != EOF && c != '\n' && i < max_len - 1)
		line[i++] = c;
	if (c == '\n') {
		line[i++] = '\n';
	}
	line[i] = '\0';
	return i;
}

int erase(char line[])
{
	int len = strlen(line);
	char temp = line[0];
	int goals = 0;
	int i, j;

	for (i = 0, j = 0; i < len - 1, j < len; ) {
		while (line[i] == line[j]) {
			j++;
		}
		if (j - i > 1){
			goals += j - i;
		}
		i = j;
	}
	
	return goals;
}
