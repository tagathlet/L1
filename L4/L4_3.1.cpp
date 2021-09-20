#include <stdio.h>
#include <string.h>

#define STRING_SIZE 255

int get_word_start(int i, char* string) {
	while (i < STRING_SIZE) {
		while (string[i] == ' ') {
			i++;
		}
		if (string[i] != '\n') {
			return i;
		}
		else {
			return -1;
		}
	}
	return -1;
}

int get_word_end(int i, char* string) {
	while (string) {
		if (string[i] == ' ' || string[i] == '\n') {
			return i - 1;
		}
		i++;
	}
	return -1;
}

bool is_vowels(char c) {
	return strchr("aeiouyAEIOUY", c) != NULL;
}

int number_of_vowels(int start, int end, char* string) {
	int count = 0;
	for (int i = start; i <= end; i++) {
		if (is_vowels(string[i])) {
			count++;
		}
	}
	return count;
}

void print_word(int start, int end, char* string) {
	for (int i = start; i <= end; i++) {
		putc(string[i], stdout);
	}
	putc(' ', stdout);
}

struct word_struct {
	int vowels;
	int start;
	int end;
};

void bubble_sort(word_struct* word, int n) {
	struct word_struct tmp;
	bool swap = false;
	for (int i = 1; i < n; i++) {
		swap = false;
		for (int j = 1; j < n; j++) {
			if (word[j].vowels < word[j - 1].vowels) {
				tmp = word[j];
				word[j] = word[j - 1];
				word[j - 1] = tmp;
				swap = true;
			}
		}
		if (!swap) {
			break;
		}
	}
}

void insertion_sort(word_struct* word, int n) {
	struct word_struct tmp;
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (word[j].vowels > word[j - 1].vowels) {
				tmp = word[j];
				word[j] = word[j - 1];
				word[j - 1] = tmp;
				continue;
			}
		}
	}
}

void selection_sort(word_struct* word, int n) {
	struct word_struct tmp;
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (word[j].vowels < word[min].vowels) {
				min = j;
			}
		}
		if (min != i) {
			tmp = word[i];
			word[i] = word[min];
			word[min] = tmp;
		}
	}
}

int main() {

	struct word_struct word[STRING_SIZE / 2] = { 0 };
	char string[STRING_SIZE] = {};
	int start = 0;
	int end = 0;
	int count_word = 0;

	printf("Input string: ");
	fgets(string, sizeof(string), stdin);

	while (1) {
		start = get_word_start(start, string);
		if (start == -1) {
			break;
		}
		end = get_word_end(start, string);
		word[count_word].vowels = number_of_vowels(start, end, string);
		word[count_word].start = start;
		word[count_word].end = end;
		count_word++;
		start = end + 1;
	}

	selection_sort(word, count_word);
	for (int i = 0; i < count_word; i++) {
		print_word(word[i].start, word[i].end, string);
	}

	return 0;
}