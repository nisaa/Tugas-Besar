#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define INF 999

int Random(int range)
{
    return rand() % range + 1;    
}

int TSP(int n, int matriks[][MAX], int rute[], int awal)
{
    int temp[MAX], rute_minimum[MAX]; 
    int jarak_terpendek, jarak;
    int i, j, k;
    
    if(awal == n - 2)
        return matriks[rute[n - 2]][rute[n - 1]] + matriks[rute[n - 1]][0];
 
    jarak_terpendek = INF;
    
    for(i = awal + 1;i < n;i++)
    {
        for(j = 0;j < n;j++)
            temp[j] = rute[j];
 
        temp[awal + 1] = rute[i];
        temp[i] = rute[awal + 1];

        if(matriks[rute[awal]][rute[i]] + (jarak = TSP(n, matriks, temp, awal + 1)) < jarak_terpendek) 
        {
            jarak_terpendek = matriks[rute[awal]][rute[i]] + jarak;
            for(k = 0;k < n;k++)
                rute_minimum[k] = temp[k];
        }
    }

    for(i = 0;i < n;i++)
        rute[i] = rute_minimum[i];

    return jarak_terpendek;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int matriks[MAX][MAX];
    int jumlah_kota, rute[MAX];
    int jarak_minimum;
    int i, j;
    
    printf("Jumlah Kota: "); scanf("%i", &jumlah_kota);
    printf("\n");
    for(i = 0;i < jumlah_kota;i++)
    { 
        for(j = 0;j < jumlah_kota;j++)
        {
            matriks[i][j] = Random(25);
            printf("Matriks[%i][%i]: %i\n", i + 1, j + 1, matriks[i][j]);
        }
        printf("\n");
    }
    for(i = 0;i < jumlah_kota;i++)
        rute[i] = i;

    jarak_minimum = TSP(jumlah_kota, matriks, rute, 0);

    printf("Jarak Minimum: %i\n", jarak_minimum);

    printf("Rute: ");
    for(i = 0;i < jumlah_kota;i++)
        printf("%i ", rute[i] + 1);
    printf("1\n");
    
    system("PAUSE");
    return 0;
}
