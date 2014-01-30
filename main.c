#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int matriks[MAX][MAX];
    int jumlah_kota, rute[MAX];
    int jarak_minimum;
    int i, j;
    
    printf("Jumlah Kota: "); scanf("%i", &jumlah_kota);
    
    printf("Masukan Jarak:\n");
    for(i = 0;i < jumlah_kota;i++)
        for(j = 0;j < jumlah_kota;j++)
            scanf("%i", &matriks[i][j]);

    for(i = 0;i < jumlah_kota;i++)
        rute[i] = i;

    jarak_minimum = 0;

    /*
        Proses TSP
    */

    printf("Jarak Minimum: %i\n", jarak_minimum);

    printf("Rute: ");
    for(i = 0;i < jumlah_kota;i++)
        printf("%i ", rute[i] + 1);
    printf("1\n");
    
    system("PAUSE");
    return 0;
}
