#include <stdio.h>

int key(int bulan, int tahun);

int main() {
    int tanggal, bulan, tahun;
    printf("Tanggal: ");
    scanf("%d %d %d",&tanggal, &bulan, &tahun);
    
    if (tahun < 1753) {
        printf("tidak valid");
        return 0;
    }
    
    int year = tahun % 100;
    int qyear = year / 4;
    int month = key(bulan, tahun);
    int sum = year + qyear + month + tanggal;
    
    if (tahun >= 2000 && tahun <= 2099) {
        sum -= 1;
    } else if (tahun >= 1800 && tahun <= 1899) {
        sum +=2;
    } else if (tahun >= 1753 && tahun <=1799) {
        sum += 4;
    }
    
    int mod = sum % 7;
    switch (mod) {
        case 0: printf("Sabtu"); break;
        case 1: printf("Minggu"); break;
        case 2: printf("Senin"); break;
        case 3: printf("Selasa"); break;
        case 4: printf("Rabu"); break;
        case 5: printf("Kamis"); break;
        case 6: printf("Jum'at"); break;
    }
    return 0;
}

int key(int bulan, int tahun) {
    // Cek tahun kabisat
    int kab = 0;
    if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)) {
        kab = 1;
    }
    
    switch (bulan) {
        case 1: // Januari
            return (kab) ? 0 : 1;
        case 2: // Februari
            return (kab) ? 3 : 4;
        case 3: return 4;
        case 4: return 0;
        case 5: return 2;
        case 6: return 5;
        case 7: return 0;
        case 8: return 3;
        case 9: return 6;
        case 10: return 1;
        case 11: return 4;
        case 12: return 6;
        default: return 0;
    }
}
