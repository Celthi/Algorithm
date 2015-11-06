#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 110

int my_getline(char line[], int max_len);
int erase(char line[], char re[]);

int main(int argc, const char *argv[])
{
	int numofstr;
	char line[LEN];
	char re[LEN];
	int gg = 0;
	scanf("%d", &numofstr);
	int *out;
	out  = (int *) malloc(sizeof(int) * numofstr);
	/*numofstr++;    increment numofstr by 1, because after scanf numofstr, there is a newline remain, 
				  ** my_getline will read newline first */
	int length = 0;
	char temp[LEN];
	int onegoal = 0;
	int kk = 0;
	while (kk < numofstr){
		out[kk++] = 0;
	}
	kk = 0;
	/*getchar();  remove newline */
	while(numofstr--) {

		int pos, max = 0;
		/* read input the string */
		if ((scanf("%s",line)) == 1) {
			int num = 0;
			max = 0;
			strcpy(re, line);
			int choose = 0;
			length = strlen(re);
			char add_char[3] = {'A', 'B', 'C'};
			for (choose = 0; choose < 3; choose++){
				/* printf("--------------enter add mode\n"); */
				/* cha ru zifu bing jisuan zengjia de xiaoqu shu*/
				for (gg = 0; gg < length + 1; gg++) {
					num = 0;
					int index = 0;
					pos = gg;
					/* gou zao tian jia hou de zifuchuan
					 * yuanli shi zengjia mei yi ge zifu */
					while (index < pos) {
						line[index] = re[index];
						index++;
					}
					line[pos] = add_char[choose]; /* zeng jia di k ge zifu */
					/* zhan tie sheng xia de zifu dao xin de zifu shuzu li */
					while (re[index] != '\0') {
						line[++pos] = re[index++];
					}
					line[++pos] = '\0';
					  /* printf("str is\n%s\n", line);    */
					while ((onegoal = erase(line, temp)) > 0) { 
						num += onegoal; 
						/* printf("%s\n", temp);     */
						num += erase(temp,line);
						 /* printf("%s\n", line);    */
					} 
					max = num > max? num : max;
					 /* printf("%d==========\n", max);   */
				}
			}
			out[kk++] = max;
		} else kk++;
	}
	for (numofstr = 0; numofstr < kk; numofstr++) {
		printf("%d\n", out[numofstr]);

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
			/* while (j < len) */
				/* re[k++] = line[j++]; */
		   i = j; 
		} else {
			re[k++] = line[i++];
		}
	}
	re[k] = '\0';	/* remember to add '\0' to the new string array
					   in C, string in array must end with '\0'*/
	
	return goals;
}
