#include <stdio.h>

void papan_catur(int size, int chessBoard[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            chessBoard[i][j] = 0;
        }
    }
}

void KoboImaginaryChess(int i, int j, int size, int chessBoard[size][size]) {
    int gerak[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                       {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

    for (int k = 0; k < 8; k++) {
        int i_baru = i + gerak[k][0];
        int j_baru = j + gerak[k][1];

        if (i_baru >= 1 && i_baru <= size && j_baru >= 1 && j_baru <= size) {
            chessBoard[i_baru - 1][j_baru - 1] = 1;
        }
    }
}

int main() {
    int i, j;
    int size = 8;
    int catur[size][size];

    papan_catur(size, catur);

    printf("Papan catur awal:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", catur[i][j]);
        }
        printf("\n");
    }

    printf("Masukkan posisi bidak kuda : ");
    scanf("%d %d", &i, &j);

    KoboImaginaryChess(i, j, size, catur);

    printf("Hasil papan catur setelah pergerakan kuda:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", catur[i][j]);
        }
        printf("\n");
    }

    return 0;
}
