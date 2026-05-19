#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include "../include/oyunMekanigi.hpp"
#include "../include/oyuncuSecimi.hpp"
#include "../include/oyunArayuzu.hpp"
#include "../include/oyunTahtasi.hpp"

enum OyunDurumu { secimAlani,oyunAlani};

int main() {
    // 1. Senin çalışan orijinal pencere satırın (Dokunmadık)
    sf::RenderWindow pencere(sf::VideoMode({600, 600}), "Tic Tac Toe");

    // 2. Açılır açılmaz kodla pencereyi 200x200'e küçültüyoruz
    pencere.setSize(sf::Vector2u(200, 200));
    pencere.setView(sf::View(sf::FloatRect({0.f, 0.f}, {200.f, 200.f})));
   
    OyunDurumu suan=secimAlani;
    int siraKimde=1;
    int tahta[3][3]={{0,0,0},{0,0,0},{0,0,0}};//Oyun tahtası bütün hücreler boş

    std::vector<sf::RectangleShape> cizgiler;
    std::vector<sf::CircleShape> daireler;
    std::vector<sf::RectangleShape> xCizgileri;// X çizgileri için vektör

    tahtaCizgileriniOlustur(cizgiler);

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
                   else if(suan==oyunAlani) {
                    //hangi hücreyi tıkladıgını anlamak için
                    int sutun=x/200;
                    int satir=y/200;

                    if (tahta[satir][sutun] == 0) {//sadece hücre boşsa hamle yapmasını sağla.
                       tahta[satir][sutun] = siraKimde;

                       if (siraKimde == 1) {
                         xCizgisiEkle(xCizgileri,satir,sutun);
                         siraKimde=2;
                      }  
                      else{
                         oDairesiEkle(daireler,satir,sutun);
                         siraKimde=1;
                         }      
                         int durum = kazananiKontrolEt(tahta);

                         if (durum == 1) {
                         std::cout << "TEBRİKLER! X OYUNCUSU KAZANDI!" << std::endl;
                         pencere.close(); 
                         } else if (durum == 2) {
                         std::cout << "TEBRİKLER! O OYUNCUSU KAZANDI!" << std::endl;
                         pencere.close();
                         } else if (durum == 3) {
                         std::cout << "OYUN BERABERE BİTTİ!" << std::endl;
                          pencere.close();
                         }
                     }
                  } 
                }
             }
        
        if(suan==secimAlani){
            secimEkraniniCiz(pencere);
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
    }
    return 0;
    }
