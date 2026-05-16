#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>

int main() {
    // 600x600 boyutunda bir pencere oluşturuyoruz
    sf::RenderWindow pencere (sf::VideoMode({600, 600}), "Tic Tac Toe");

    int tahta[3][3]={{0,0,0},{0,0,0},{0,0,0}};//Oyun tahtası bütün hücreler boş
    int siraKimde=1;
    
    std::vector<sf::RectangleShape> cizgiler;

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
                         siraKimde = 2; }
                        else {
                         siraKimde = 1;}
                        
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
        // Çizilenleri ekrana yansıt
        pencere.display();
    
}
    return 0;
}
