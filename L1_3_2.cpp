#include <stdio.h>

#define BUF_SIZE 255

int main()
{
    int x = -1;
    int max = 0;
    int count = 0;
    int max_N = -1;
    int correct = 1;
    char line[BUF_SIZE];
    char result[BUF_SIZE];

    while (x) {
        printf("Enter a natural number (0 to end): ");
        fgets(line, sizeof(line), stdin);
        for (int i = 0; i < sizeof(line); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                correct = 1;
            }
            else if (line[i] == '\n') {
                if (i == 0) {
                    correct = 0;
                }
                break;
            }
            else {
                correct = 0;
                break;
            }
        }
        if (correct) {
            sscanf_s(line, "%d", &x);
            if (x) {
                printf("Accepted %d\n", x);
            }
            else {
                printf("End enter\n");
            }
            if (x > max) {
                max = x;
                max_N = count;
            }
            result[count++] = x;
        }
        else {
            puts("Incorrect input");
        }
    }

    printf("Result: ");
    for (int i = 0; i < count - 1; i++) {
        printf("%d ", result[i]);
    }

    printf("\nMax number index: %d", max_N + 1);

    return 0;