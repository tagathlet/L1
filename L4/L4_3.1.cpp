#include <stdio.h>
#include <Windows.h>

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
	if (c == 'а' || c == 'е' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я' || c == 'ё' || \
		c == 'А' || c == 'Е' || c == 'И' || c == 'О' || c == 'У' || c == 'Ы' || c == 'Э' || c == 'Ю' || c == 'Я' || c == 'Ё') {
		return true;
	}
	else {
		return false;
	}
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

int main() {

	char string[STRING_SIZE] = {};
	int result[STRING_SIZE / 2 * 3] = {0};
	int result_index = 0;
	int start = 0;
	int end = 0;
	int n = 0;
	int max_vowels = 0;
	int j = 0;

	for (int i = 0; i < STRING_SIZE / 2 * 3; i++) {
		result[i] = -1;
	}

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Input string: ");
	fgets(string, sizeof(string), stdin);

	while (1) {
		start = get_word_start(start, string);
		if (start == -1) {
			break;
		}
		end = get_word_end(start, string);
		n = number_of_vowels(start, end, string);
		if (n > max_vowels) {
			max_vowels = n;
		}
		result[result_index] = n;
		result[result_index + 1] = start;
		result[result_index + 2] = end;
		result_index += 3;
		start = end + 1;
	}

	for (int i = 0; i <= max_vowels; i++) {
		j = 0;
		while (result[j] != -1) {
			if (result[j] == i) {
				print_word(result[j + 1], result[j + 2], string);
			}
			j += 3;
		}
	}

	return 0;
}