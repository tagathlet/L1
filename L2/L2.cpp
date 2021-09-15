#include <stdio.h>

#define BUF_SIZE 255


int get_word_start(int i, char *string) {
	while (i < BUF_SIZE) {
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

bool check_next_word(int i) {
	if (i == -1) {
		return false;
	}
	else {
		return true;
	}
}

bool check_empty_string(char* string) {
	int start = get_word_start(0, string);
	if (check_next_word(start)) {
		return true;
	}
	else {
		return false;
	}
}

bool check_symmetrical(int first, int last, char *word) {
	int centre = (last - first) / 2 + first;
	int end = last + first;
	for (int i = first; i < centre; i++) {
		if (word[i] != word[end - i]) {
			return false;
		}
	}
	return true;
}

void print_word(int i, int last, char *string) {
	while(i <= last) {
		putc(string[i], stdout);
		i++;
	}
	putc(' ', stdout);
}

int main() {
	
	char string[BUF_SIZE] = {};
	int start = 0;
	int end = 0;
	bool next_word = true;
	bool not_found = true;

	printf("Input string: ");
	fgets(string, sizeof(string), stdin);
	printf("Symmetrical words: ");

	
	next_word = check_empty_string(string);

	while (next_word) {
		start = get_word_start(start, string);
		end = get_word_end(start, string);
		if (check_symmetrical(start, end, string)) {
			not_found = false;
			print_word(start, end, string);
		}
		start = get_word_start(end + 1, string);
		next_word = check_next_word(start);
	}

	if (not_found) {
		printf("No symmetric words found");
	}
	
	printf("\n");

	return 0;
}