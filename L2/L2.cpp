#include <stdio.h>

#define BUF_SIZE 255


int main() {
	
	char string[BUF_SIZE] = {};
	char c = '0';
	int word[BUF_SIZE] = {};
	int i = 0;
	bool symmetrical = true;

	while (string) {
		c = getc(stdin);

		if (c == ' ') {
			symmetrical = true;
			for (int j = 0; j < i/2; j++) {
				if (word[j] != word[i - j - 1]) {
					symmetrical = false;
					break;
				}
			}
			if (symmetrical) {
				for (int j = 0; j < i; j++) {
					putc(word[j], stdout);
					if (j == i - 1) {
						putc(' ', stdout);
					}
				}
			}
			i = 0;
			continue;
		}
		else if (c == '\n') {
			symmetrical = true;
			for (int j = 0; j < i / 2; j++) {
				if (word[j] != word[i - j - 1]) {
					symmetrical = false;
					break;
				}
			}
			if (symmetrical) {
				for (int j = 0; j < i; j++) {
					putc(word[j], stdout);
				}
			}
			i = 0;
			break;
		}
		else {
			word[i] = c;
			i++;
		}
			

	}

	return 0;
}