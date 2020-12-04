#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct {
    int min;
    int max;
    char chr;
    char * password;
} typedef PolicyAndPassword;

const int inputLength = 1000;
PolicyAndPassword input [1000];

PolicyAndPassword splitStringIntoPolicyAndPassword(char * str) {
    PolicyAndPassword result;
    // passwords are in the format "1-7 j: vrfjljjwbsv"
    //                               ^ ^ ^^           ^
    // split by '-' to get the min, ' ' to get the max,
    //  ': ' to get the char then whatever to get the password
    result.min = atoi(strtok(str, "-"));
    result.max = atoi(strtok(NULL, " "));
    char* c = strtok(NULL, ": ");
    result.chr = c[0];
    char * passwordTok = strtok(NULL, " ");
    result.password = malloc(strlen(passwordTok) + 1);
    strcpy(result.password, passwordTok);

    return result;
}

int countOccurrences(char chr, char * password) {
    int count = 0;

    for (int c = 0; c < strlen(password); c++) {
        if (password[c] == chr) {
            count++;
        }
    }

    return count > 0 ? count : count - 1;
}

int countValidPasswords() {
    int count = 0;

    for (int a = 0; a < inputLength; a++) {
        PolicyAndPassword pap = input[a];

        int occurrences = countOccurrences(pap.chr, pap.password);
        if (occurrences >= pap.min && occurrences <= pap.max) {
            count++;
        }

        //printf("Policy: %d-%d %c; Password: %s; Occurrences: %d\n", pap.min, pap.max, pap.chr, pap.password, occurrences);
    }

    return count;
}

int main(int argc, char ** args) {
    // read the input file
    FILE * file = fopen("input.txt", "r");
    if (file == NULL) { printf("Could not open input file."); return 1; }
    for (int l = 0; l < inputLength; l++) {
        char line[50] = "";
        fgets(line, 50, file);
        //printf("Line read from file: %s", line);
        input[l] = splitStringIntoPolicyAndPassword(line);
    }

    // solve the puzzle
    printf("Part 1: %d\n", countValidPasswords());
}
