#include "../include/oyunMekanigi.hpp"

int kazananiKontrolEt(const int tahta[3][3]) {
    for (int i = 0; i < 3; i++) {//Satir kontrolü
        if (tahta[i][0] != 0 && tahta[i][0] == tahta[i][1] && tahta[i][1] == tahta[i][2]) {
            return tahta[i][0];
        }
    }
    for (int j = 0; j < 3; j++) {//sütun kontrolü
        if (tahta[0][j] != 0 && tahta[0][j] == tahta[1][j] && tahta[1][j] == tahta[2][j]) {
            return tahta[0][j];
        }
    }
    if (tahta[0][0] != 0 && tahta[0][0] == tahta[1][1] && tahta[1][1] == tahta[2][2]) {//çapraz kontrolü 
        return tahta[0][0];
    }
    if (tahta[0][2] != 0 && tahta[0][2] == tahta[1][1] && tahta[1][1] == tahta[2][0]) {//çapraz kontrolü
        return tahta[0][2];
    }
    bool bosHucreVarMi = false;//Beraberlik için bos hücre kontrolü
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tahta[i][j] == 0) bosHucreVarMi = true;
        }
    }
    if (!bosHucreVarMi) return 3;//3=berabelik

    return 0;//0=oyun devam ediyor
}