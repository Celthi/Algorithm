#include <stdio.h>
#include <stdlib.h>

typedef int item_type;
int binary_search(item_type data[], int low, int high, item_type item_to_find);
int main(int argc, const char *argv[])
{
	
	item_type input[10] = {
		1, 2, 3, 3, 4, 4, 5, 6, 7,10
	};
	printf("%d\n", binary_search(input, 0, 9, 8));
	return 0;
}

int binary_search(item_type data[], int low, int high, item_type item_to_find)
{
	int middle;

	while (low <= high) {
		middle = (low + high) / 2;
		if (data[middle] > item_to_find) {
			high = middle - 1;
		}
		else if (data[middle] < item_to_find) {
			low = middle + 1;
		}
		else break;
	}
	if (data[middle] == item_to_find)
		return middle;
	return -1;


}
