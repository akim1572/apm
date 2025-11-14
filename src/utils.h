#include <stdlib.h>

#define HOME getenv("HOME")
#define MASS_PATH ".config/.apmm"
#define PASS_PATH ".config/.apmp"
#define PWD_SIZE 16
#define MAX_STRING 64

char* createPassword();
int findPassword(char* name);
void listPasswords();
void storePassword(char* name, char* password);
