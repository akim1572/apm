#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"

char* createPassword() {
        const char LETTERS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const char NUMBERS[] = "1f234567890";
        const char SPECIALS[] = "!@#$%^&*()";
        char* password = (char*)malloc(PWD_SIZE * sizeof(char));
        int random = rand() % 3;

        if (password == NULL) {
                printf("Could not create password\n");
                exit(0);
        }

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

void listPasswords() {
        char* home = getenv("HOME");
        char cur_line[MAX_STRING];
        char path[MAX_STRING];

        if (home == NULL) {
                printf("Could not read password file\n");
                exit(0);
        }

        snprintf(path, sizeof(path), "%s/.config/.apmp", home);

        if (access(path, F_OK) != 0) {
                printf("You don't have any passwords to list\n");
                exit(0);
        }

        FILE* passes = fopen(path, "r");

        if (passes == NULL) {
                printf("Could not read from password fiel\n");
                exit(0);
        };

        while (fgets(cur_line, sizeof(cur_line), passes) != NULL) {
                printf("%s", cur_line);
        }
}

void storePassword(char* name, char* password) {
        char* home = getenv("HOME");
        char path[MAX_STRING];
        char storage[MAX_STRING];

        if (home == NULL) {
                printf("Could not find environment\n");
                exit(0);
        }

        snprintf(path, sizeof(path), "%s/.config/.apmp", home);
        snprintf(storage, sizeof(storage), "%s - %s\n", name, password);

        FILE* passes = fopen(path, "a");

        if (passes == NULL) {
                printf("Could not open file for storage\n");
                exit(0);
        }

        fputs(storage, passes);
        fclose(passes);
        free(password);
}
