#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>

int main() {
    // 600x600 boyutunda bir pencere oluşturuyoruz
    sf::RenderWindow pencere(sf::VideoMode({600, 600}), "Tic Tac Toe");

    sf::ContextSettings ayarlar;
    ayarlar.antiAliasingLevel = 8;//8 kat kenar yumuşatma

    pencere.create(sf::VideoMode({600, 600}), "Tic Tac Toe", sf::State::Windowed, ayarlar);

    int tahta[3][3]={{0,0,0},{0,0,0},{0,0,0}};//Oyun tahtası bütün hücreler boş
    int siraKimde=1;
    
    std::vector<sf::RectangleShape> cizgiler;
    std::vector<sf::CircleShape> daireler;
    std::vector<sf::RectangleShape> xCizgileri;// X çizgileri için vektör

    for(int i=0;i<2;i++){
        // Dikey Çizgiler
        sf::RectangleShape dikey;
        dikey.setSize(sf::Vector2f(10.f, 600.f));
        dikey.setFillColor(sf::Color::Black);
        dikey.setPosition(sf::Vector2f(200.f * (i + 1), 0.f));
        cizgiler.push_back(dikey);

        // Yatay Çizgiler
        sf::RectangleShape yatay;
        yatay.setSize(sf::Vector2f(600.f, 10.f));
        yatay.setFillColor(sf::Color::Black);
        yatay.setPosition(sf::Vector2f(0.f, 200.f * (i + 1)));
        cizgiler.push_back(yatay);
    }

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
                    
                    //hangi hücreyi tıkladıgını anlamak için
                    int sutun=x/200;
                    int satir=y/200;

                    if (tahta[satir][sutun] == 0) {//sadece hücre boşsa hamle yapmasını sağla.
                       tahta[satir][sutun] = siraKimde;

                       if (siraKimde == 1) {
                    
                         float solUstX = sutun * 200.f;
                         float solUstY = satir * 200.f;
                         float kalinlik = 15.f;

                         sf::RectangleShape cizgi1;// X'in birinci çizgisi
                         cizgi1.setSize({170.f, kalinlik}); 
                         cizgi1.setFillColor(sf::Color::Red); 
                         cizgi1.setOrigin({85.f, kalinlik / 2.f}); //Dönme merkezi çizginin ortası
                         cizgi1.setPosition({solUstX + 100.f, solUstY + 100.f});
                         cizgi1.setRotation(sf::degrees(45.f)); //45 derece sağa döndür
                         xCizgileri.push_back(cizgi1);

                         sf::RectangleShape cizgi2;// X'in ikinci çizgisi
                         cizgi2.setSize({170.f, kalinlik});
                         cizgi2.setFillColor(sf::Color::Red);
                         cizgi2.setOrigin({85.f, kalinlik / 2.f});
                         cizgi2.setPosition({solUstX + 100.f, solUstY + 100.f});
                         cizgi2.setRotation(sf::degrees(135.f));//135 derece döndür
                         xCizgileri.push_back(cizgi2);

                         siraKimde=2;//sıra O'ya geçer
                      }  
                      else{

                         //O için görsel kısım
                         sf::CircleShape daire(50.f);
                         daire.setPointCount(150);//Daireyi daha pürüzsüz göstermek için
                         daire.setFillColor(sf::Color::Transparent); 
                         daire.setOutlineThickness(16.f); 
                         daire.setOutlineColor(sf::Color::Blue); 

                         daire.setOrigin({50.f, 50.f});//Dairenin merkezini kendi ortası yapıyoruz kareye tam oturması için
 
                         float merkezX = sutun * 200.f + 100.f;//karenin merkez koordinatı 
                         float merkezY = satir * 200.f + 100.f;
                         daire.setPosition({merkezX, merkezY});
                         daireler.push_back(daire);

                         siraKimde=1;//sıra x'e geçer
                      }      
                  }
                    //kontrol için terminale yazdırma
                    std::cout << "\n--- TIKLAMA SONRASI TAHTA ---" << std::endl;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            std::cout << tahta[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << "-----------------------------" << std::endl;
                    std::cout << "Siradaki Oyuncu: " << (siraKimde == 1 ? "X" : "O") << std::endl;
                    
                }
            }
        }
        
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
    return 0;
}
