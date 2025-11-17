#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"

char* createPassword() {
        const char LETTERS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const char NUMBERS[] = "1f234567890";
        const char SPECIALS[] = "!@#$%^&*()";
        char* password = (char*)malloc(PWD_SIZE + 1 * sizeof(char));
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

        password[PWD_SIZE] = '\0';
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

void checkMaster() {
        char c;
        char mass_file[MAX_STRING];
        char pass[MAX_STRING];
        char test[MAX_STRING];

        printf("Enter master password: ");
        scanf("%s", test);

        if (HOME == NULL) {
                printf("Failed init environment\n");
                exit(0);
        }

        snprintf(mass_file, sizeof(mass_file), "%s/%s", HOME, MASS_PATH);

        FILE* mass = fopen(mass_file, "r");

        fgets(pass, sizeof(pass), mass);

        if (strcmp(test, pass) != 0) {
                printf("Wrong password\n");
                exit(0);
        }

        c = getc(stdin);
}

void deletePassword(int line_num) {
        char cur_line[MAX_STRING];
        char path[MAX_STRING];
        char path2[MAX_STRING];
        int line = 0;

        if (HOME == NULL) {
                printf("Could not find environment\n");
                exit(0);
        }

        snprintf(path, sizeof(path), "%s/%s",  HOME, PASS_PATH);
        snprintf(path2, sizeof(path2), "%s/.config/.apm2", HOME);

        FILE* passes;
        FILE* passes2;
        passes = fopen(path, "r");
        passes2 = fopen(path2, "w");

        testFile(passes);
        testFile(passes2);

        while (fgets(cur_line, MAX_STRING, passes) != NULL) {
                line++;

                if (line == line_num) {
                        continue;
                }

                fputs(cur_line, passes2);
        }

        fclose(passes);
        fclose(passes2);
        remove(path);
        rename(path2, path);
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

void setMaster() {
        char mass[MAX_STRING];
        char path[MAX_STRING];

        printf(
                "Put in one word password that only you know\n"
                "You only get one chance at this so make sure you remember: "
        );
        scanf("%s", mass);

        if (HOME == NULL) {
                printf("Could not find environment\n");
                exit(0);
        }

        snprintf(path, sizeof(path), "%s/%s", HOME, MASS_PATH);

        FILE* mass_file = fopen(path, "w");

        testFile(mass_file);

        fputs(mass, mass_file);
        fclose(mass_file);
}

void storePassword(char* name, char* password) {
        char path[MAX_STRING];
        char storage[MAX_STRING];

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

