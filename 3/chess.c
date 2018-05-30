#include "stdio.h"
#include "stdlib.h"

int chessboard[19][19];

void findwinner(int i, int j, char direction[12]) {
    if (chessboard[i][j] == 0)
        return;
    if (!strcmp(direction, "left")) {
        if (j - 4 < 0) {

        } else if ((chessboard[i][j] == chessboard[i][j - 1]) && chessboard[i][j] == chessboard[i][j - 2] &&
                   chessboard[i][j] == chessboard[i][j - 3]) {
            if (chessboard[i][j - 4] == 0) {
                printf("%d:%d,%d", chessboard[i][j], i + 1, j + 1);
                return;
            }
        }
        findwinner(i, j, "lefttop");
    }
    if (!strcmp(direction, "lefttop")) {
        if (j - 4 < 0 || i - 4 < 0) {

        } else if (chessboard[i][j] == chessboard[i - 1][j - 1] && chessboard[i][j] == chessboard[i - 2][j - 2] &&
                   chessboard[i][j] == chessboard[i - 3][j - 3]) {
            if (chessboard[i - 4][j - 4] == 0) {
                printf("%d:%d,%d", chessboard[i][j], i + 1, j + 1);
                return;
            }
        }
        findwinner(i, j, "top");
    }
    if (!strcmp(direction, "top")) {
        if (i - 4 < 0) {

        } else if (chessboard[i][j] == chessboard[i - 1][j] && chessboard[i][j] == chessboard[i - 2][j] &&
                   chessboard[i][j] == chessboard[i - 3][j]) {
            if (chessboard[i - 4][j] == 0) {
                printf("%d:%d,%d", chessboard[i][j], i + 1, j + 1);
                return;
            }
        }
        findwinner(i, j, "righttop");
    }
    if (!strcmp(direction, "righttop")) {
        if (j + 4 > 18 || i - 4 < 0) {

        } else if (chessboard[i][j] == chessboard[i - 1][j + 1] && chessboard[i][j] == chessboard[i - 2][j + 2] &&
                   chessboard[i][j] == chessboard[i - 3][j + 3]) {
            if (chessboard[i - 4][j + 4] == 0) {
                printf("%d:%d,%d", chessboard[i][j], i + 1, j + 1);
                return;
            }
        }
        findwinner(i, j, "right");
    }
    if (!strcmp(direction, "right")) {
        if (j + 4 > 18) {

        } else if (chessboard[i][j] == chessboard[i][j + 1] && chessboard[i][j] == chessboard[i][j + 2] &&
                   chessboard[i][j] == chessboard[i][j + 3]) {
            if (chessboard[i][j + 4] == 0) {
                printf("%d:%d,%d", chessboard[i][j], i + 1, j + 1);
                return;
            }
        }
        findwinner(i, j, "rightbottom");
    }
    if (!strcmp(direction, "rightbottom")) {
        if (j + 4 > 18 || i + 4 > 18) {

        } else if (chessboard[i][j] == chessboard[i + 1][j + 1] && chessboard[i][j] == chessboard[i + 2][j + 2] &&
                   chessboard[i][j] == chessboard[i + 3][j + 3]) {
            if (chessboard[i + 4][j + 4] == 0) {
                printf("%d:%d,%d", chessboard[i][j], i + 1, j + 1);
                return;
            }
        }
        findwinner(i, j, "bottom");
    }
    if (!strcmp(direction, "bottom")) {
        if (i + 4 > 18) {

        } else if (chessboard[i][j] == chessboard[i + 1][j] && chessboard[i][j] == chessboard[i + 2][j] &&
                   chessboard[i][j] == chessboard[i + 3][j]) {
            if (chessboard[i + 4][j] == 0) {
                printf("%d:%d,%d", chessboard[i][j], i + 1, j + 1);
                return;
            }
        }
        findwinner(i, j, "leftbottom");
    }
    if (!strcmp(direction, "leftbottom")) {
        if (j - 4 < 0 || i + 4 > 18) {

        } else if (chessboard[i][j] == chessboard[i + 1][j - 1] && chessboard[i][j] == chessboard[i + 2][j - 2] &&
                   chessboard[i][j] == chessboard[i + 3][j - 3]) {
            if (chessboard[i + 4][j - 4] == 0) {
                printf("%d:%d,%d", chessboard[i][j], i + 1, j + 1);
                return;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int i, j;
    for (i = 0; i < 19; ++i) {
        for (j = 0; j < 19; ++j) {
            scanf("%d", &chessboard[i][j]);
        }
    }
    for (i = 0; i < 18; ++i) {
        for (j = 0; j < 18; ++j) {
            findwinner(i, j, "left");
        }
    }
    return 0;
}