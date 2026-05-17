#include "../include/oyuncuSecimi.hpp"
#include <iostream>

using namespace std;

int oyuncuSecimiAl() {
    char secim;
    int baslangicSirasi = 1; 
    
    cout << "TIC-TAC-TOE OYUNCU SECIMI\n";
   
    while (true) {
        cout << "Hangi sembolle baslamak istersiniz? (X / O): ";
        cin >> secim;
        
        if (secim == 'X' || secim == 'x') {
            baslangicSirasi = 1; // X için 1
            cout << "Oyuna X olarak basliyorsunuz.\n";
            break;
        } 
        else if (secim == 'O' || secim == 'o' || secim == '0') {
            baslangicSirasi = 2; // O için 2
            cout << "Oyuna O olarak basliyorsunuz.\n";
            break;
        } 
        else {
            cout << "Gecersiz secim! Lutfen sadece 'X' veya 'O' giriniz.\n";
        }
    } 
    return baslangicSirasi;
}