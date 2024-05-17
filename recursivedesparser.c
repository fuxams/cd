#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[10];
int i, error;

void e();
void t();
void eprime();
void tprime();
void f();

int main() {
    i = 0;
    error = 0;

    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    e();

    if (strlen(input) - 1 == i && error == 0) {
        printf("\nAccepted!\n");
    } else {
        printf("\nRejected\n");
    }

    return 0;
    
}

void e() {
    t();
    eprime();
}

void eprime() {
    if (input[i] == '+') {
        i++;
        t();
        eprime();
    }
}

void t() {
    if (input[i] == '*') {
        i++;
        f();
        tprime();
    } else {
        f();
        tprime();
    }
}

void tprime() {
    if (input[i] == '*') {
        i++;
        f();
        tprime();
    }
}

void f() {
    if (isalnum(input[i])) {
        i++;
    } else if (input[i] == '(') {
        i++;
        e();
        if (input[i] == ')') {
            i++;
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
}
// a*b=c
