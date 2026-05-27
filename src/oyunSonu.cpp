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
    panel.setFillColor(sf::Color(40,44,68)); 
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
        metin.setString("DRAW!");
        metin.setFillColor(sf::Color(140,160,190));
        metin.setPosition({245.f, 200.f}); 
    } 
    else if (durum == insanTasi) {
        metin.setString("YOU WIN!");
        metin.setFillColor(sf::Color(120,255,170));
        metin.setPosition({235.f, 200.f});
    } 
    else {
        metin.setString("YOU LOSE!");
        metin.setFillColor(sf::Color(255,70,150));
        metin.setPosition({220.f, 200.f}); 
    }
    pencere.draw(metin);

    sf::RectangleShape resButon({bBoyutX, bBoyutY});//yeniden başlatma butonu
    resButon.setPosition({restartX, restartY});
    resButon.setFillColor(sf::Color(50,120,220)); 
    pencere.draw(resButon);

    sf::Text resMetin(font, "RESTART", 16);//yeniden başlat yazısı
    resMetin.setFillColor(sf::Color(240,240,240));
    resMetin.setPosition({260.f, 333.f});
    pencere.draw(resMetin);

    sf::RectangleShape qButon({bBoyutX, bBoyutY});//çıkış butonu
    qButon.setPosition({quitX, quitY});
    qButon.setFillColor(sf::Color(180,60,80)); 
    pencere.draw(qButon);

    sf::Text qMetin(font, "QUIT", 16);//çıkış yazısı
    qMetin.setFillColor(sf::Color(245,245,245));
    qMetin.setPosition({280.f, 393.f});
    pencere.draw(qMetin);
}
int sonucKontrolu(int x, int y) {
    if (x >= restartX && x <= restartX + bBoyutX && y >= restartY && y <= restartY + bBoyutY) return 1;
    if (x >= quitX && x <= quitX + bBoyutX && y >= quitY && y <= quitY + bBoyutY) return 2;
    return 0;
}