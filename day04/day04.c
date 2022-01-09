#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct PASSPORT {
    char * byr;
    char * cid;
    char * ecl;
    char * eyr;
    char * hcl;
    char * hgt;
    char * iyr;
    char * pid;
    // ptr to next passport in list
    struct PASSPORT * next;
} Passport;
// ptr to most recent passport in list; FIFO/LILO
Passport * ppHead = NULL;
Passport * ppCurrent = NULL;

void AddToPassport(char * str) {
    char * fieldKey = strtok(str, ":");
    char * fieldValue = strtok(NULL, ":");

    switch (fieldKey[0])
    {
    case 'b':
        ppCurrent->byr = fieldValue; break;
    case 'c':
        ppCurrent->cid = fieldValue; break;
    case 'e':
        if (fieldKey[1] == 'c') {
            ppCurrent->ecl = fieldValue;
        }
        else {
            ppCurrent->eyr = fieldValue;
        }
        break;
    case 'h':
        if (fieldKey[1] == 'c') {
            ppCurrent->hcl = fieldValue;
        } else {
            ppCurrent->hgt;
        }
        break;
    case 'i':
        ppCurrent->iyr = fieldValue; break;
    case 'p':
        ppCurrent->pid = fieldValue; break;
    default:
        break;
    }
}

// insert ppCurrent into the list
void CompletePassport() {
    // set the head to the next of the current
    ppCurrent->next = ppHead;
    // then set the head as the current
    ppHead = ppCurrent;

    // initialise the next passport
    ppCurrent = malloc(sizeof(Passport));
    ppCurrent->byr = NULL;
    ppCurrent->cid = NULL;
    ppCurrent->ecl = NULL;
    ppCurrent->eyr = NULL;
    ppCurrent->hcl = NULL;
    ppCurrent->hgt = NULL;
    ppCurrent->iyr = NULL;
    ppCurrent->pid = NULL;
    ppCurrent->next = NULL;
}

long solve() {
    ppCurrent = ppHead;
    while (ppCurrent != NULL) {
        // count the valid fields in the passport

        // move the pointer on
        ppCurrent = ppCurrent->next;
    }
    return 0L;
}

int main(int argc, char ** args) {
    // read the input file
    FILE * file = fopen("testinput.txt", "r");
    if (file == NULL) { printf("Could not open input file."); return 1; }

    char c;
    char * lines [8];
    // for each passport in file
    while (fgets(lines[0], 100, file) != NULL) {
        // for each line in passport until blank line

        int l = 1;
        lines[1] = malloc(100);
        fgets(lines[1], 100, file);
        while (lines[l-1] != "\n" && lines[l] != NULL) {
            lines[l++] = malloc(100);
            fgets(lines[l], 100, file);
        }

        // process lines as a passport; a line might contain multiple segments
        // for each line
        for (int i = 0; i < l; i++) {
            // for each part in the line
            char * token = strtok(lines[i], " ");
            while (token != NULL) {
                // add the passport part to the passport
                AddToPassport(token);

                // try to get the next token from this line
                token = strtok(NULL, " ");
            }
        }
        CompletePassport();

        lines[0] = malloc(100);
    }
    fclose(file);

    printf("%ld\n", solve());
}
