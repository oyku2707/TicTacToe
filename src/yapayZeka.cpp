#include "../include/yapayZeka.hpp"
#include "../include/oyunMekanigi.hpp"
#include <algorithm>
#include <climits>

bool hamleKaldiMi(int tahta[3][3]) {//minimax'ın durma şartı kontrolü için
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tahta[i][j] == 0) return true;
    return false;
}
int minimax(int tahta[3][3], int derinlik, bool enYuksekAl) {
    int skor = kazananiKontrolEt(tahta);

    if (skor == 2) return 10 - derinlik; 
    if (skor == 1) return derinlik - 10;  
    if (skor == 3 || !hamleKaldiMi(tahta)) return 0; 

    if (enYuksekAl) {//sıra yapayzekada 
        int enIyi = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tahta[i][j] == 0) {
                    tahta[i][j] = 2; // Hamleyi simüle et
                    enIyi = std::max(enIyi, minimax(tahta, derinlik + 1, false));
                    tahta[i][j] = 0; // Hamleyi geri al
                }
            }
        }
        return enIyi;
    } 
    else {//sıra oyuncuda
        int enIyi = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tahta[i][j] == 0) {
                    tahta[i][j] = 1; // Oyuncunun hamlesini simüle et
                    enIyi = std::min(enIyi, minimax(tahta, derinlik + 1, true));
                    tahta[i][j] = 0; // Hamleyi geri al
                }
            }
        }
        return enIyi;
    }
}
std::pair<int, int> enIyiHamleyiBul(int tahta[3][3], int bzYapayZeka) {
    int enIyiDeger = INT_MIN;
    std::pair<int, int> enIyiHamle = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tahta[i][j] == 0) {
                tahta[i][j] = bzYapayZeka; // Yapay zeka buraya oynasın

                // Sıradaki hamle insan oyuncunun olacağı için false gönderiyoruz
                int hamleDegeri = minimax(tahta, 0, false);
                
                tahta[i][j] = 0; // Tahtayı eski haline getir

                if (hamleDegeri > enIyiDeger) {//hamle en iyisiyse kaydet
                    enIyiHamle = {i, j};
                    enIyiDeger = hamleDegeri;
                }
            }
        }
    }
    return enIyiHamle;
}