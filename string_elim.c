#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 110

int my_getline(char line[], int max_len);
int erase(char line[], char re[]);

int main(int argc, const char *argv[])
{
	int times;
	char line[LEN];
	char re[LEN];
	int goals = 0;
	scanf("%d", &times);
	times++;    /*increment times by 1, because after scanf times, there is a newline remain, 
				  ** my_getline will read newline first */
	int length = 0;
	char temp[LEN];
	int onegoal = 0;
	while(times--) {
		/* read input the string */
		if ((my_getline(line, LEN)) >= 1) {
			goals = 0;
			/* xiao qu ke yi xiao qu de zifu */
			while ((onegoal = erase(line, re)) > 0) {
				goals += onegoal;
				printf("%s\n", re);
				goals += erase(re, line);
			}
				printf("%s\n", re);

			int k, max = 1;
			int num = 0;
			length = strlen(re);

            /* cha ru zifu bing jisuan zengjia de xiaoqu shu*/
			for (k = 0; k < length; k++) {
			 	num = 0;
				int index = 0;
				/* gou zao tian jia hou de zifuchuan
				 * yuanli shi zengjia mei yi ge zifu */
				while (index <= k) {
					line[index] = re[index];
					index++;
				}
				line[index] = re[k]; /* zeng jia di k ge zifu */

				/* zhan tie sheng xia de zifu dao xin de zifu shuzu li */
				while (re[index++] != '\0') {
					line[index] = re[index-1];
				}
                line[index] = '\0';
				while ((onegoal = erase(line, temp)) > 0) {
					num += onegoal;
					num += erase(temp, line);
				}
				max = num > max? num : max;
			}

			goals += max;
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
	/* if (c == '\n') {
		line[i++] = '\n';
	}  in this program we don't need to add a newline to the string */
	line[i] = '\0';
	return i;
}

int erase(char line[], char re[])
{
	int len = strlen(line);
	int goals = 0;
	int i, j, k;

	k = 0;
	for (i = 0, j = 0; i < len; ) {
		while (line[i] == line[j]) {
			j++;
		}
		if (j - i > 1){
			goals += j - i;
		} else {
			re[k++] = line[i];
		}
		i = j;
	}
	re[k] = '\0';	/* remember to add '\0' to the new string array
					   in C, string in array must end with '\0'*/
	
	return goals;
}
