#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include "../include/oyunMekanigi.hpp"
#include "../include/oyuncuSecimi.hpp"
#include "../include/oyunArayuzu.hpp"
#include "../include/oyunTahtasi.hpp"
#include "../include/yapayZeka.hpp"
#include "../include/oyunSonu.hpp"

enum OyunDurumu { secimAlani,oyunAlani,oyunBitti};

int main() {
    sf::RenderWindow pencere(sf::VideoMode({600, 600}), "Tic Tac Toe");
    pencere.setFramerateLimit(60);
    
    OyunDurumu suan=secimAlani;
    int siraKimde=1;
    int tahta[3][3]={{0,0,0},{0,0,0},{0,0,0}};//Oyun tahtası bütün hücreler boş

    int insanTasi=1;
    int yapayZekaTasi=2;
    int oyunSonucu=0;

    std::vector<sf::RectangleShape> cizgiler;
    std::vector<sf::CircleShape> daireler;
    std::vector<sf::RectangleShape> xCizgileri;// X çizgileri için vektör

    tahtaCizgileriniOlustur(cizgiler);

    sf::Clock yzSaati;
    bool yzZamanlayiciBasladi = false;

    while (pencere.isOpen()) {
        while (const std::optional event =pencere.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                pencere.close();
            }
            // Fare tıklamasını algılama
            if (const auto* fareTiklamasi = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (fareTiklamasi->button == sf::Mouse::Button::Left) { //Solu tıkladıgını anlamak icin

                    // Tıklanan koordinatları algılama
                    int x = fareTiklamasi->position.x;
                    int y = fareTiklamasi->position.y;

                    if (suan == secimAlani) {
                        int secim = secimKontrolu(x,y);
                        if (secim != 0) {
                            if(secim==1){//oyuncu x'i seçerse
                                insanTasi=1;
                                yapayZekaTasi=2;
                                siraKimde=1;
                            }
                            else if(secim==2){//oyuncu o'yu seçerse
                                insanTasi=2;
                                yapayZekaTasi=1;
                                siraKimde=2;
                                yzSaati.restart();
                                yzZamanlayiciBasladi=true;
                            }  
                            suan=oyunAlani; 
                    }}
                     else if(suan==oyunAlani && siraKimde == 1) { //sadece sıra insandaysa
                         int sutun=x/200;//hangi hücreyi tıkladığını anlamak için
                         int satir=y/200;

                         if (tahta[satir][sutun] == 0) {//hücre boşsa hamle yap
                         tahta[satir][sutun] = insanTasi;

                         if(insanTasi==1){
                            xCizgisiEkle(xCizgileri, satir, sutun); 
                         }
                         else{
                            oDairesiEkle(daireler, satir, sutun);
                         }
                         siraKimde = 2; 
                         yzSaati.restart();
                         yzZamanlayiciBasladi = true;
                         
                         int durum = kazananiKontrolEt(tahta);
                         if (durum != 0) {
                           oyunSonucu=durum;
                           suan=oyunBitti; 
                       }
                     }
                  }
                  else if (suan == oyunBitti) {
                        int sonucSecim = sonucKontrolu(x, y);
                        if (sonucSecim == 1) { //yeniden başlatmak için
                            for(int i = 0; i < 3; i++) {
                                for(int j = 0; j < 3; j++) tahta[i][j] = 0;
                            }
                            xCizgileri.clear();
                            daireler.clear();
                            
                            suan = secimAlani;//oyunu sıfırlamak ve seçim ekranına dönmek için
                            oyunSonucu = 0;
                            yzZamanlayiciBasladi = false;
                        } 
                        else if (sonucSecim == 2) { //çıkış butonu
                            pencere.close();
                        }
                    }
                }
             }   
         }
             if (suan == oyunAlani && siraKimde == 2 && yzZamanlayiciBasladi) {

               if (yzSaati.getElapsedTime() >= sf::milliseconds(1500)) {//1.5 saniye bekleme
             
                std::pair<int, int> yzHamle = enIyiHamleyiBul(tahta, 2);//en iyi hamleyi bul
                int yzSatir = yzHamle.first;
                int yzSutun = yzHamle.second;

                if (yzSatir != -1 && yzSutun != -1) {//yapay zeka hamlesi
                tahta[yzSatir][yzSutun] = yapayZekaTasi;
                
                if(yapayZekaTasi==1){
                   xCizgisiEkle(xCizgileri, yzSatir, yzSutun); 
                }
                else{
                   oDairesiEkle(daireler, yzSatir, yzSutun); 
                }
                siraKimde = 1; 
                yzZamanlayiciBasladi = false;//sayacı sıfırla
                
                int durum = kazananiKontrolEt(tahta);
                if (durum != 0) {
                    oyunSonucu=durum;
                    suan=oyunBitti;
                }
            }
        }
    }   
        pencere.clear(sf::Color(32,34,54));

        for(const auto& cizgi:cizgiler){
            pencere.draw(cizgi);
        }
        for(const auto& daire : daireler){//daireyi çiz
            pencere.draw(daire);
        }
        for(const auto& xCizgi : xCizgileri){//X çiz
            pencere.draw(xCizgi);
        }
        if(suan==secimAlani){
            secimEkraniniCiz(pencere);
        }
        if(suan==oyunBitti){
            sonucEkraniniCiz(pencere,oyunSonucu,insanTasi);
        }
        // Çizilenleri ekrana yansıt
        pencere.display();
    }

    return 0;
    }
