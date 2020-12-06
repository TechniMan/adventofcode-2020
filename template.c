#include <string.h>
#include <stdio.h>
#include <stdlib.h>

long solve() {
    return 0L;
}

int main(int argc, char ** args) {
    // read the input file
    FILE * file = fopen("input.txt", "r");
    if (file == NULL) { printf("Could not open input file."); return 1; }

    char c;
    while ((c = fgetc(file)) != EOF) {
        // PROCESS INPUT HERE
    }
    fclose(file);

    printf("%ld\n", solve());
}
