#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int checkInput(char* input) {
    int i = 0;
    while (input[i] != '\0' && input[i] != '\n') {
        if (!((input[i] >= '0' && input[i] <= '9') || input[i] == ' ' || input[i] == '-')) {
            puts("Invalid enter");
            return 0;
        }
        i++;
    }
    return 1;
}

void fillFile(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char input[256];
    puts("Enter numbers through space");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        perror("Error");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    if (checkInput(input)) {
        char* next_token;
        char* token = strtok_s(input, " ", &next_token);
        while (token != NULL) {
            int num;
            if (sscanf_s(token, "%d", &num, 256) == 1) {
                fwrite(&num, sizeof(int), 1, file);
            }
            token = strtok_s(NULL, " ", &next_token);
        }
    }
    fclose(file);
}

void printFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int num;
    printf("Contents of '%s':\n", filename);
    while (fread(&num, sizeof(int), 1, file) == 1) {
        printf("%d ", num);
    }
    printf("\n");

    fclose(file);
}

void findMinMaxSum(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num, min, max;
    if (fread(&num, sizeof(int), 1, file) != 1) {
        printf("File is empty\n");
        fclose(file);
        return;
    }
    min = max = num;

    while (fread(&num, sizeof(int), 1, file) == 1) {
        if (num < min) min = num;
        if (num > max) max = num;
    }

    fclose(file);
    printf("Sum of min (%d) and max (%d): %d\n", min, max, min + max);
}

void zeroElements(const char* filename) {
    FILE* file = fopen(filename, "r+b");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num, pos;
    pos = 0;
    while (1) {
        fseek(file, pos * sizeof(int), SEEK_SET);
        if (fread(&num, sizeof(int), 1, file) != 1 || num == 0) break;
        fseek(file, pos * sizeof(int), SEEK_SET);
        int zero = 0;
        fwrite(&zero, sizeof(int), 1, file);
        pos += num;
    }
    fclose(file);
}

void removeZeros(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num;
    int* numbers = NULL;
    int count = 0;
    while (fread(&num, sizeof(int), 1, file) == 1) {
        if (num != 0) {
            numbers = realloc(numbers, (count + 1) * sizeof(int));
            numbers[count++] = num;
        }
    }
    fclose(file);


    file = fopen(filename, "wb");

    fwrite(numbers, sizeof(int), count, file);
    fclose(file);
    free(numbers);
}


