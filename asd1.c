#include <stdio.h> 
#include <string.h>

int huruf(char kartu) {
    if (kartu == 'J') {
        return 11; 
    } else if (kartu == 'Q') {
        return 12; 
    } else if (kartu == 'K') {
        return 13; 
    } else if (kartu == '1') {
        return 10; 
    } else {
        return (kartu - '0');
    }
}

int selection_sort(char kartu[], int n) {
    int tukar = 0;
    
    for (int i = 0; i < n; i++) {
        int minim = i;
        
        for (int j = i + 1; j < n; j++) {
            if (huruf(kartu[j]) < huruf(kartu[minim])) {
                minim = j;
            }
        }
        if (minim != i) {
            char temp = kartu[i]; 
            kartu[i] = kartu[minim]; 
            kartu[minim] = temp; 
            
            printf("pertukaran %d: ",tukar + 1);
            for (int k = 0; k < n; k++) {
                printf("%c ", kartu[k]);
            }
            printf("\n");
            
            tukar++;
        } 
    } return tukar;
}

int main() {
    int n;
    int swap = 0; 
    char remi[1000]; 
    
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &n);
    
    printf("Masukkan nilai kartu: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &remi[i]);
    }
    
    swap = selection_sort(remi, n);
    
    printf("Jumlah minimum iterasi pertukaran kartu: %d\n", swap);
    
    return 0;
}
