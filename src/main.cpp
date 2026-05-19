#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include "../include/oyunMekanigi.hpp"
#include "../include/oyuncuSecimi.hpp"
#include "../include/oyunArayuzu.hpp"
#include "../include/oyunTahtasi.hpp"
#include "../include/yapayZeka.hpp"

enum OyunDurumu { secimAlani,oyunAlani};

int main() {
    sf::RenderWindow pencere(sf::VideoMode({600, 600}), "Tic Tac Toe");

    pencere.setSize(sf::Vector2u(200, 200));
    pencere.setView(sf::View(sf::FloatRect({0.f, 0.f}, {200.f, 200.f})));
   
    OyunDurumu suan=secimAlani;
    int siraKimde=1;
    int tahta[3][3]={{0,0,0},{0,0,0},{0,0,0}};//Oyun tahtası bütün hücreler boş

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
                            siraKimde = secim; 
                            suan = oyunAlani;  
                            pencere.setSize(sf::Vector2u(600, 600));
                            pencere.setView(sf::View(sf::FloatRect({0.f, 0.f}, {600.f, 600.f})));   
                    }}
                     else if(suan==oyunAlani && siraKimde == 1) { //sadece sıra insandaysa
                         int sutun=x/200;//hangi hücreyi tıkladığını anlamak için
                         int satir=y/200;

                         if (tahta[satir][sutun] == 0) {//hücre boşsa hamle yap
                         tahta[satir][sutun] = siraKimde;
                    
                         xCizgisiEkle(xCizgileri, satir, sutun);
                         siraKimde = 2; 

                         yzSaati.restart();
                         yzZamanlayiciBasladi = true;
                         
                         int durum = kazananiKontrolEt(tahta);
                         if (durum != 0) {
                           if (durum == 1) std::cout << "TEBRİKLER! KAZANDIN!" << std::endl;
                           else if (durum == 3) std::cout << "OYUN BERABERE BİTTİ!" << std::endl;
                           pencere.close(); 
                       }
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
                tahta[yzSatir][yzSutun] = 2;
                oDairesiEkle(daireler, yzSatir, yzSutun);
                siraKimde = 1; 
                yzZamanlayiciBasladi = false;//sayacı sıfırla
                
                int durum = kazananiKontrolEt(tahta);
                if (durum != 0) {
                    if (durum == 2) std::cout << "YAPAY ZEKA KAZANDI! DAHA ÇOK ÇALIŞMALISIN." << std::endl;
                    else if (durum == 3) std::cout << "OYUN BERABERE BİTTİ!" << std::endl;
                    pencere.close();
                }
            }
        }
    }   
        if(suan==secimAlani){
            pencere.clear(sf::Color(211,211,211));
            secimEkraniniCiz(pencere);
            pencere.display();
        }
        else if(suan==oyunAlani){
        //pencereyi temizle(acık gri yap)
        pencere.clear(sf::Color(211,211,211));

        for(const auto& cizgi:cizgiler){
            pencere.draw(cizgi);
        }
        for(const auto& daire : daireler){//daireyi çiz
            pencere.draw(daire);
        }
        for(const auto& xCizgi : xCizgileri){//X çiz
            pencere.draw(xCizgi);
        }
        // Çizilenleri ekrana yansıt
        pencere.display();
    }
}
    return 0;
    }
