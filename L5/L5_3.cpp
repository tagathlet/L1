#include <stdio.h>

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

int main() {

	char string[STRING_SIZE] = {};
	char word[STRING_SIZE] = {};
	int start = 0;
	int end = 0;
	int word_length = 0;
	int count_word = 0;

	printf("Input string: ");
	fgets(string, sizeof(string), stdin);
	printf("Input word: ");
	fgets(word, sizeof(word), stdin);

	start = get_word_start(start, word);
	end = get_word_end(start, word);
	word_length = end - start + 1;
	start = 0;

	while (1) {
		start = get_word_start(start, string);
		if (start == -1) {
			break;
		}
		end = get_word_end(start, string);
		if (end - start + 1 == word_length) {
			count_word++;
		}
		start = end + 1;
	}

	printf("Result: %d", count_word);

	return 0;
}