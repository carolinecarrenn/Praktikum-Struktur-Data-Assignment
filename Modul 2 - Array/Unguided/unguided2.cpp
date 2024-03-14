#include <stdio.h>

int main() {
    // Deklarasi variable
    int x, y, z;
    // Input ukuran array 3D
    printf("Masukkan ukuran array 3D (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    // Deklarasi array 3D
    int arr[x][y][z];

    // Mengambil input dan menampilkan array 3D
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("Masukkan nilai untuk arr[%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\nArray 3D adalah:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    // Kembali ke titik awal
    return 0;
}