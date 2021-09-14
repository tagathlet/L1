#include <stdio.h>

#define BUF_SIZE 255


int last_char_index(int i, char *string) {
	for (i; i < BUF_SIZE; i++) {
		if (string[i] == ' ' || string[i] == '\n') {
			return i - 1;
		}
	}
}

bool symmetrical(int first, int last, char *word) {
	int current_index = first;
	for (first - current_index; (first - current_index) < (last - current_index) / 2; first++) {
		if (word[first] != word[last - first + current_index]) {
			return false;
		}
	}
	return true;
}

void print_word(int i, int last, char *string) {
	for (i; i <= last; i++) {
		putc(string[i], stdout);
	}
	putc(' ', stdout);
}

int main() {
	
	char string[BUF_SIZE] = {};
	int i = 0;
	int last = 0;
	bool not_found = true;

	printf("Input string: ");
	fgets(string, sizeof(string), stdin);
	printf("Symmetrical words: ");

	for (i = 0; i < sizeof(string); i++) {
		if (string[i] == ' ') {
			continue;
		}
		else if (string[i] == '\n') {
			break;
		}
		else {
			last = last_char_index(i, string);
			if (symmetrical(i, last, string)) {
				not_found = false;
				print_word(i, last, string);
			}
			i = last + 1;
		}
	}

	if (not_found) {
		printf("No symmetric words found");
	}

	return 0;
}