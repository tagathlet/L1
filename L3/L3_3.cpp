#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 20

int absolute_min_of(int i, int j) {
	if (i < 0) {
		int absolute_i = i *= -1;
	}
	if (j < 0) {
		int absolute_j = j *= -1;
	}
	if (i <= j) {
		return i;
	}
	else {
		return j;
	}
}

int find_smallest_absolute_number(int *arr_number) {
	int min = absolute_min_of(arr_number[0], arr_number[1]);
	for (int i = 2; i < ARR_SIZE; i++) {
		min = absolute_min_of(min, arr_number[i]);
	}
	return min;
}

int main() {

	int arr_number[ARR_SIZE];

	srand(time(NULL));
	for (int i = 0; i < ARR_SIZE; i++) {
		arr_number[i] = rand()%100 - 50;
		printf("%d ", arr_number[i]);
	}
	printf("\n");

	printf("Absolute minimum number = %d \n", find_smallest_absolute_number(arr_number));

	return 0;
}