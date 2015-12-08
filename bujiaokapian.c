#include <stdio.h>
#include <stdlib.h>

#define DAY 100

int sum_of_days(int from, int cards);

int main(int argc, const char *argv[])
{
	int *miss;	/* dynamic array to store the missing days*/
	int days[DAY]; /* array to store the days, 1 for done, 0 for missing submittion*/

	int groups; /* how many groups data to process*/
	scanf("%d", &groups);

	while (groups--) {
		/* read the days of missing and the number of cards*/
		int missing, cards;
		scanf("%d %d", &missing, &cards);

		/* malloc meme for store the missing days*/
		miss = (int *) malloc(missing * sizeof(int)); 
		int i = 0;
		while (i < missing) {
			scanf("%d", (miss + i));
			i++;
		}

		/*printf("%d", miss[0]); */
		/*init the days[DAY], 1 for good day, 0 for the missing day */
		int k;
		for (k = 0; k < DAY; k++){
			days[k] = 1;
		}
		for (k = 0; k < missing; k++) {
			days[miss[k]-1] = 0;
		}

		int sum;
		int max = 0;
		int start = 0;
		int from;
		int cards_try = 0;
		k = 0;
		while (start < DAY) {
			from = start;
			cards_try = cards;
			sum = 0;
		
			while (from < DAY && (days[from] != 0 || cards_try != 0)) {
				sum += days[from];
				if (days[from] == 0 && cards_try != 0) {
					cards_try--;
					sum += 1;
				}
				from++;
			}
			max = max > sum ? max : sum;

			/* calc next try start point */
			start = miss[k++];
		}
		printf("%d\n", max);


	}

	return 0;
}

int sum_of_days(int from, int cards)
{
	/* int sum = 0;
	while (from < DAY && (days[from] != 0 || cards != 0)) {
		sum += day[from++];
		if (days[from] == 0) {
			cards--;
			sum += 1;
		}

	}
	return sum;
	*/
}
