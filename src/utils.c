#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"

char* createPassword() {
        const char LETTERS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const char NUMBERS[] = "1f234567890";
        const char SPECIALS[] = "!@#$%^&*()";
        char* password = (char*)malloc(PWD_SIZE * sizeof(char));
        int random = rand() % 3;

        for (int i = 0; i < PWD_SIZE; i++) {
                switch (random) {
                case 0:
                        password[i] = LETTERS[rand() % 52];
                        random = rand() % 3;
                        break;
                case 1:
                        password[i] = NUMBERS[rand() % 10];
                        random = rand() % 3;
                        break;
                case 2:
                        password[i] = SPECIALS[rand() % 10];
                        random = rand() % 3;
                        break;
                }
        }

        return password;
}

int findPassword(char* name) {
        char cur_line[MAX_STRING];
        char buffer[strlen(name)];
        char path[MAX_STRING];
        int line_num = 0;

        if (HOME == NULL) {
                printf("Could not find environment\n");
                exit(0);
        }

        snprintf(path, sizeof(path), "%s/%s",  HOME, PASS_PATH);

        if (access(path, F_OK) != 0) {
                printf("No passwords to search for\n");
                exit(0);
        }

        FILE* passes = fopen(path, "r");

        testFile(passes);

        while (fgets(cur_line, MAX_STRING, passes) != NULL) {
                line_num++;

                for (size_t i = 0; i < strlen(name); i++) {
                        buffer[i] = cur_line[i];
                }

                buffer[strlen(name)] = '\0';

                if (strcmp(buffer, name) == 0) {
                        fclose(passes);
                        return line_num;
                }
        }

        fclose(passes);
        return 0;
}

void testAllocation(char* p) {
        if (p == NULL) {
                exit(0);
        }
}

void testFile(FILE* fp) {
        if (fp == NULL) {
                exit(0);
        }
}

void listPasswords() {
        char cur_line[MAX_STRING];
        char path[MAX_STRING];

        if (HOME == NULL) {
                printf("Could not find environment\n");
                exit(0);
        }

        snprintf(path, sizeof(path), "%s/%s", HOME, PASS_PATH);

        if (access(path, F_OK) != 0) {
                printf("You don't have any passwords to list\n");
                exit(0);
        }

        FILE* passes = fopen(path, "r");

        testFile(passes);

        while (fgets(cur_line, sizeof(cur_line), passes) != NULL) {
                printf("%s", cur_line);
        }
}

void storePassword(char* name, char* password) {
        const int STORAGE_SIZE = ((int)strlen(name) + (int)strlen(password)) + 5;
        char path[MAX_STRING];
        char storage[STORAGE_SIZE];

        if (HOME == NULL) {
                printf("Could not find environment\n");
                exit(0);
        }

        snprintf(path, sizeof(path), "%s/%s", HOME, PASS_PATH);
        snprintf(storage, sizeof(storage), "%s - %s\n", name, password);

        FILE* passes = fopen(path, "a");

        testFile(passes);
        fputs(storage, passes);
        fclose(passes);
        free(password);
}
