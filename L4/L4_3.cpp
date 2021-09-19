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
}

int get_word_end(int i, char* string) {
	while (string) {
		if (string[i] == ' ' || string[i] == '\n') {
			return i - 1;
		}
		i++;
	}
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

int copy_word(int start, int end, char* string_in, char string_out[], int n) {
	int len = end - start;
	if (len >= STRING_SIZE) {
		return 0;
	}
	else {
		int index_line = n * STRING_SIZE;
		int j = 0;
		while (string_out[index_line + j]) {
			j++;
		}
		if (j != 0) {
			string_out[index_line + j] = ' ';
			j++;
		}
		for (int i = start; i <= end; i++) {
			string_out[index_line + j] = string_in[i];
			j++;
		}
		return 1;
	}
}

int main() {

	char string[STRING_SIZE] = {};
	char res[STRING_SIZE][STRING_SIZE] = { 0 };
	int start = 0;
	int end = 0;
	int c = 0;
	int n = 0;

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
		copy_word(start, end, string, &res[0][0], n);
		start = end + 1;
	}

	for (int i = 0; i < STRING_SIZE; i++) {
		if (res[i][0]) {
			c = 0;
			//printf("%d vowels in word: ", i);
			while (res[i][c]) {
				putc(res[i][c], stdout);
				c++;
			}
			putc(' ', stdout);
		}
	}

	return 0;
}