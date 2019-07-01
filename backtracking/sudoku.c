#include <stdio.h>

void printSudoku(int m[9][9]) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("|%d", m[i][j]);
        }
        printf("|\n");
    }
}

void initMatrixValues(int m[9][9]) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            m[i][j] = 0;
        }
    }
}

int canInsert(int m[9][9], int l, int c, int v) {
    int i, j, cel_l, cel_c;
    
    for (i = 0; i < 9; i++)
        if (m[l][i] == v)
            return 0;
    for (i = 0; i < 9; i++)
        if (m[i][c] == v)
            return 0;
    
    cel_l = 3 * (l / 3);
    cel_c = 3 * (c / 3);
    for (i = cel_l; i < cel_l + 3; i++)
        for (j = cel_c; j < cel_c + 3; j++)
            if (m[i][j] == v)
                return 0;
    return 1;
}

void nextPos(int l, int c, int *nl, int *nc) {
    if (c < 8) {
        *nl = l;
        *nc = c + 1;
    } else {
        *nl = l + 1;
        *nc = 0;
    }
}

int sudokuR(int m[9][9], int fixed[9][9], int l, int c) {
    int v, nl, nc;
    if (l == 9) {
        printSudoku(m);
        return 1;
    }

    nextPos(l, c, &nl, &nc);
    if (fixed[l][c])
        return sudokuR(m, fixed, nl, nc);
    
    for (v = 1; v <= 9; v++) {
        if (canInsert(m, l, c, v)) {
            m[l][c] = v;
            if (sudokuR(m, fixed, nl, nc))
                return 1;
        }
    }

    m[l][c] = 0;
    return 0;
}

int sudoku(int m[9][9]) {
    int i, j, fixed[9][9];
    
    initMatrixValues(fixed);

    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            fixed[i][j] = m[i][j];
    return sudokuR(m, fixed, 0, 0);
}

void receiveBaseElementsInput(int m[9][9], int nFixedElements) {
    int i;
    int l, c, v;

    printf("Please insert %d lines, indicating the line index, column index and value to be set in the sudoku table:\n", nFixedElements);

    for (i = 0; i < nFixedElements; i++) {
        scanf("%d %d %d", &l, &c, &v);
        m[l - 1][c - 1] = v;
    }
}

int main() {
    int nFixedElements;
    int m[9][9];

    initMatrixValues(m);

    printf("Please enter the number of fixed elements in the sudoku: ");
    scanf("%d", &nFixedElements);

    receiveBaseElementsInput(m, nFixedElements);
    sudoku(m);

    return 0;
}