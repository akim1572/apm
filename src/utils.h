#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HOME getenv("HOME")
#define MASS_PATH ".config/.apmm"
#define PASS_PATH ".config/.apmp"
#define PWD_SIZE 16
#define MAX_STRING 64

char* createPassword();
void checkMaster();
uint8_t findPassword(char* name);
void decrypt(char* name);
void deletePassword(int line_num);
void encrypt(char* pass);
void listPasswords();
void setMaster();
void storePassword(char* name, char* password);
void testAccess(char* filename);
void testAllocation(char* p);
void testFile(FILE* fp);
void testHome();
