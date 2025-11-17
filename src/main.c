#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "utils.h"

int main(int argc, char** argv) {
        if (argc <= 1) {
                printf("Not a command use `apm --help` to learn more\n");
                exit(0);
        }

        char mass_file[MAX_STRING];

        if (HOME == NULL) {
                printf("Failed to find environment\n");
                exit(0);
        }

        snprintf(mass_file, sizeof(mass_file), "%s/%s", HOME, MASS_PATH);

        if (access(mass_file, F_OK) != 0) {
                setMaster();
        }

        if (strcmp(argv[1], "--help") == 0) {
                printf(
                        "--help   => displays the help screen, this one actually\n"
                        "--create =>               creates and stores a password\n"
                        "--list   =>     list passwords that you have had stored\n"
                        "--delete =>          delete a password of your choosing\n"
                );
        } else if (strcmp(argv[1], "--create") == 0) {
                checkMaster();

                char path[MAX_STRING];
                char name[MAX_STRING];

                snprintf(path, sizeof(path), "%s/%s", HOME, PASS_PATH);
                printf("Input passwords name: ");
                scanf("%[^\n]", name);

                if (access(path, F_OK) == 0) {
                        if (findPassword(name)) {
                                printf("Password name already exists\n");
                                exit(0);
                        }
                }

                srand(time(NULL));

                char* password = createPassword();

                printf("%s\n", password);
                storePassword(name, password);
        } else if (strcmp(argv[1], "--list") == 0) {
                checkMaster();
                listPasswords();
        } else if (strcmp(argv[1], "--delete") == 0) {
                checkMaster();

                int num;
                char name[MAX_STRING];

                printf("Please input name of password you wish to search for: ");
                scanf("%[^\n]", name);

                num = findPassword(name);

                deletePassword(num);
        } else {
                printf("Not a command use `apm --help` to learn more\n");
                exit(0);
        }

        return 0;
}
