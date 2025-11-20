#include "enigma.h"

char plugboard(char c) {
        switch (c) {
        // forwards
        case 'e':
                c = 'z';
                break;
        case 't':
                c = 'q';
                break;
        case 'a':
                c = 'j';
                break;
        case 'o':
                c = 'x';
                break;
        case 'i':
                c = 'k';
                break;
        case 'n':
                c = 'v';
                break;
        case 's':
                c = 'b';
                break;
        case 'r':
                c = 'y';
                break;
        case 'h':
                c = 'w';
                break;
        case 'l':
                c = 'g';
                break;
        case 7:
                c = 10;
                break;
        case 6:
                c = 1;
                break;
        case 4:
                c = 9;
                break;
        case '&':
                c = ')';
                break;
        case '^':
                c = '!';
                break;
        case '$':
                c = '(';
                break;
        // backwards
        case 'z':
                c = 'e';
                break;
        case 'q':
                c = 't';
                break;
        case 'j':
                c = 'a';
                break;
        case 'x':
                c = 'o';
                break;
        case 'k':
                c = 'i';
                break;
        case 'v':
                c = 'n';
                break;
        case 'b':
                c = 's';
                break;
        case 'y':
                c = 'r';
                break;
        case 'w':
                c = 'h';
                break;
        case 'g':
                c = 'l';
                break;
        case 10:
                c = 7;
                break;
        case 1:
                c = 6;
                break;
        case 9:
                c = 4;
                break;
        case ')':
                c = '&';
                break;
        case '!':
                c = '^';
                break;
        case '(':
                c = '$';
                break;
        }

        return c;
}
