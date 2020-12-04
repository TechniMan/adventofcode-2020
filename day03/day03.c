#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const int mapHeight = 323;
const int mapWidth = 31;
const int mapSize = 10013;
char map [323][31];

long solve(int xOffset, int yOffset) {
    long trees = 0L;

    for (int y = 0, x = 0; y < mapHeight; y += yOffset, x += xOffset) {
        trees += map[y][x % mapWidth] == '#';
    }

    return trees;
}

int main(int argc, char ** args) {
    // read the input file
    FILE * file = fopen("input.txt", "r");
    if (file == NULL) { printf("Could not open input file."); return 1; }

    char c;
    int i = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c != '\n') {
            map[i / mapWidth][i % mapWidth] = c;
            i += 1;
        }
    }

    // solve the puzzle
    printf("Part 1: %ld\n", solve(3, 1));
    printf("Part 2: %ld\n", solve(1, 1) * solve(3, 1) * solve(5, 1) * solve(7, 1) * solve(1, 2));
}
