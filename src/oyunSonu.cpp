#include "../include/oyunSonu.hpp"
#include <iostream>

const float sonucPanelX = 150.f, sonucPanelY = 150.f;
const float sonucPanelGen = 300.f, sonucPanelYuk = 300.f;

const float bBoyutX = 220.f, bBoyutY = 50.f;
const float restartX = 190.f, restartY = 320.f;
const float quitX = 190.f, quitY = 380.f;

void sonucEkraniniCiz(sf::RenderWindow& pencere, int durum, int insanTasi) {
    sf::RectangleShape panel({sonucPanelGen, sonucPanelYuk});//arka plan paneli
    panel.setPosition({sonucPanelX, sonucPanelY});
    panel.setFillColor(sf::Color(211,211,211,180)); 
    panel.setOutlineThickness(4.f);
    panel.setOutlineColor(sf::Color::Black);
    pencere.draw(panel);

    sf::Font font;//font yükleme
    if (!font.openFromFile("font.ttf")) {
    std::cout << "Font dosyasi ana dizinde bulunamadi!" << std::endl;
    }
    sf::Text metin(font);
    metin.setCharacterSize(30);
    metin.setStyle(sf::Text::Bold);

    if (durum == 3) {
        metin.setString("BERABERE!");
        metin.setFillColor(sf::Color(253, 203, 110)); 
    } 
    else if (durum == insanTasi) {
        metin.setString("KAZANDIN!");
        metin.setFillColor(sf::Color(46, 204, 113));
    } 
    else {
        metin.setString("KAYBETTIN!");
        metin.setFillColor(sf::Color(231, 76, 60)); 
    }
    metin.setPosition({210.f, 200.f});//yazıyı pop-p ekranına yazdırma
    pencere.draw(metin);

    sf::RectangleShape resButon({bBoyutX, bBoyutY});//yeniden başlatma butonu
    resButon.setPosition({restartX, restartY});
    resButon.setFillColor(sf::Color(0, 184, 148)); 
    pencere.draw(resButon);

    sf::Text resMetin(font, "YENIDEN BASLAT", 16);//yeniden başlat yazısı
    resMetin.setFillColor(sf::Color::White);
    resMetin.setPosition({235.f, 333.f});
    pencere.draw(resMetin);

    sf::RectangleShape qButon({bBoyutX, bBoyutY});//çıkış butonu
    qButon.setPosition({quitX, quitY});
    qButon.setFillColor(sf::Color(214, 48, 49)); 
    pencere.draw(qButon);

    sf::Text qMetin(font, "CIKIS", 16);//çıkış yazısı
    qMetin.setFillColor(sf::Color::White);
    qMetin.setPosition({275.f, 393.f});
    pencere.draw(qMetin);
}
int sonucKontrolu(int x, int y) {
    if (x >= restartX && x <= restartX + bBoyutX && y >= restartY && y <= restartY + bBoyutY) return 1;
    if (x >= quitX && x <= quitX + bBoyutX && y >= quitY && y <= quitY + bBoyutY) return 2;
    return 0;
}