#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"

int main(int argc, char** argv) {
        if (argc <= 1) {
                printf("Not a command use `apm --help` to learn more\n");
                exit(0);
        }

        if (strcmp(argv[1], "--help") == 0) {
                printf(
                        "--help => displays the help screen, this one actually\n"
                        "--change => changes master password that has already been set\n"
                        "--create => creates and stores a password\n"
                        "--list => list passwords that you have had stored\n"
                        "--delete => delete a password of your choosing\n"
                );
        } else if (strcmp(argv[1], "--change") == 0) {
                // change master pass
        } else if (strcmp(argv[1], "--create") == 0) {
                char name[MAX_STRING];

                printf("Input passwords name: ");
                scanf("%s", name);

                srand(time(NULL));

                char* password = createPassword();

                printf("%s\n", password);
                storePassword(name, password);
        } else if (strcmp(argv[1], "--list") == 0) {
                listPasswords();
        } else if (strcmp(argv[1], "--delete") == 0) {
                int num;
                char name[MAX_STRING];

                printf("Please input name of password you wish to search for: ");
                scanf("%s", name);

                num = findPassword(name);

                printf("Line num: %d\n", num);
        } else {
                printf("Not a command use `apm --help` to learn more\n");
                exit(0);
        }

        return 0;
}
