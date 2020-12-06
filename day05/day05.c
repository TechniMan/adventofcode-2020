#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int * seatIds;
int lines = 0;
char * seatsTaken;

const int rowSize = 128;
const int colSize = 8;
int seatIdForBoardingPass(char * boardingPass) {
    // find the row
    int base = 0, range = rowSize, row = 0, column = 0;
    // iter through the first 7 chars of the pass
    for (int c = 0; c < 7; c++) {
        if (boardingPass[c] == 'F') {
            range /= 2;
        }
        else if (boardingPass[c] == 'B') {
            range /= 2;
            base += range;
        }
    }
    row = base;

    // find the column
    base = 0, range = colSize;
    // iter through the last 3 chars of the pass
    for (int c = 7; c < 10; c++) {
        if (boardingPass[c] == 'L') {
            range /= 2;
        }
        else if (boardingPass[c] == 'R') {
            range /= 2;
            base += range;
        }
    }
    column = base;

    return (row * 8) + column;
}

// fill up the seatsTaken array with whether or not that id of seat has been taken
void sortSeats(int highestSeatId) {
    seatsTaken = (char *)calloc(highestSeatId, sizeof(char));
    for (int s = 0; s < lines; s++) {
        seatsTaken[seatIds[s]] = 1;
    }
}

// Your seat wasn't at the very front or back, though; the seats with IDs +1 and -1 from yours will be in your list.
// What is the ID of your seat?
int mySeatId(int highestSeatId) {
    for (int guess = rowSize; guess < highestSeatId; guess++) {
        if (!seatsTaken[guess] && seatsTaken[guess - 1] && seatsTaken[guess + 1]) {
            return guess;
        }
    }
    return 0;
}

int main(int argc, char ** args) {
    // read the input file
    FILE * file = fopen("input.txt", "r");
    if (file == NULL) { printf("Could not open input file."); return 1; }

    // initialise the seatIds; there are 757 lines of input
    seatIds = (int *)calloc(757, sizeof(int));

    // each boarding pass is 10 chars + \n
    char * line = (char *)calloc(11, sizeof(char));
    // fgets reads n - 1 chars (no idea why)
    fgets(line, 12, file);
    int l;
    for (l = 0; !feof(file); l++, fgets(line, 12, file)) {
        seatIds[l] = seatIdForBoardingPass(line);
        //printf("l: %d, boardingPass: %s, seatId: %d\n", l, line, seatIds[l]);

        // set up for next iter
        free(line);
        line = (char *)calloc(11, sizeof(char));
    }
    free(line);
    lines = l;
    fclose(file);

    int highestSeatId = 0;
    for (int s = 0; s < lines; s++) {
        if (seatIds[s] > highestSeatId) {
            highestSeatId = seatIds[s];
        }
    }

    sortSeats(highestSeatId);

    printf("Part 1: %d\n", highestSeatId);
    printf("Part 2: %d\n", mySeatId(highestSeatId));

    free(seatsTaken);
    free(seatIds);
}
