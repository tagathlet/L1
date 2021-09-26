#include <stdio.h>
#include <stdlib.h>

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
struct list {
	char* word;
	struct list* next;
};

struct list* init(int start, int end, char* string) {
	struct list* tmp;
	int j = 0;
	tmp = (struct list*)malloc(sizeof(struct list));
	tmp->word = (char*)malloc(sizeof(char)*(end-start+3));
	for (int i = start; i <= end; i++) {
		tmp->word[j++] = string[i];
	}
	tmp->word[j++] = '\0';
	tmp->next = NULL; 
	return tmp;
};

struct list* add_note(struct list* ptr, int start, int end, char* string) {
	struct list* tmp;
	int j = 0;
	tmp = (struct list*)malloc(sizeof(struct list));
	tmp->word = (char*)malloc(sizeof(char) * (end - start + 3));
	ptr->next = tmp;
	for (int i = start; i <= end; i++) {
		tmp->word[j++] = string[i];
	}
	tmp->word[j++] = '\0';
	tmp->next = NULL;
	return tmp;
}

void print_list(struct list* p) {
	int i = 0;
	while (p != NULL) {
		while (p->word[i] != '\0') {
			putc(p->word[i], stdout);
			i++;
		}
		putc(' ', stdout);
		p = p->next;
		i = 0;
	}
	putc('\n', stdout);
}

struct list* minimal_alphabetically(struct list* p1, struct list* p2) {
	int i = 0;
	struct list* p = NULL;
	while (p1->word[i] != '\0' && p2->word[i] != '\0') {
		if (p1->word[i] < p2->word[i]) {
			return p1;
		}
		else if (p1->word[i] > p2->word[i]) {
			return p2;
		}
		else {
			i++;
		}
	}
	if (p1->word[i] == '\0') {
		return p1;
	}
	else {
		return p2;
	}
}


struct list* merge(struct list* head1, struct list* head2) {
	struct list* p1 = head1;
	struct list* p2 = head2;
	struct list* p = head2;
	struct list* head = NULL;

	head = minimal_alphabetically(head1, head2);
	p = head;
	if (p == head1) {
		p1 = p1->next;
	}
	else {
		p2 = p2->next;
	}

	while (p1 != NULL && p2 != NULL) {
		p->next = minimal_alphabetically(p1, p2);
		p = p->next;
		if (p == p1) {
			p1 = p1->next;
		}
		else {
			p2 = p2->next;
		}
	}
	if (p1 == NULL) {
		p->next = p2;
	}
	else {
		p->next = p1;
	}
	return head;
}

int main(){

	int x = 0;
	struct list* head = NULL;
	struct list* head1 = NULL;
	struct list* head2 = NULL;
	struct list* p = head1;
	char string1[STRING_SIZE] = {};
	char string2[STRING_SIZE] = {};
	int start = 0;
	int end = 0;

	printf("Input 1 string: ");
	fgets(string1, sizeof(string1), stdin);

	while (1) {
		start = get_word_start(start, string1);
		if (start == -1) {
			break;
		}
		end = get_word_end(start, string1);
		if (!head1) {
			head1 = init(start, end, string1);
			p = head1;
			start = end + 1;
			continue;
		}
		p = add_note(p, start, end, string1);
		start = end + 1;
	}
	
	printf("Input 2 string: ");
	fgets(string2, sizeof(string2), stdin);
	start = end = 0;

	while (1) {
		start = get_word_start(start, string2);
		if (start == -1) {
			break;
		}
		end = get_word_end(start, string2);
		if (!head2) {
			head2 = init(start, end, string2);
			p = head2;
			start = end + 1;
			continue;
		}
		p = add_note(p, start, end, string2);
		start = end + 1;
	}

	print_list(head1);
	print_list(head2);

	head = merge(head1, head2);

	print_list(head);

	return 0;
}