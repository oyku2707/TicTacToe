#include "../include/oyunArayuzu.hpp"

void xCizgisiEkle(std::vector<sf::RectangleShape>& xCizgileri, int satir, int sutun) {
    float solUstX = sutun * 200.f;
    float solUstY = satir * 200.f;
    float kalinlik = 15.f;

    sf::RectangleShape cizgi1;
    cizgi1.setSize({170.f, kalinlik});// x'in birinci çizgisi
    cizgi1.setFillColor(sf::Color::Red); 
    cizgi1.setOrigin({85.f, kalinlik / 2.f});//Dönme merkezi çizginin ortası
    cizgi1.setPosition({solUstX + 100.f, solUstY + 100.f});
    cizgi1.setRotation(sf::degrees(45.f)); 
    xCizgileri.push_back(cizgi1);

    sf::RectangleShape cizgi2 = cizgi1;//x'in ikinci çizgisi
    cizgi2.setRotation(sf::degrees(135.f));
    xCizgileri.push_back(cizgi2);
}
void oDairesiEkle(std::vector<sf::CircleShape>& daireler, int satir, int sutun) {
    sf::CircleShape daire(50.f);//o için çizim
    daire.setPointCount(150);
    daire.setFillColor(sf::Color::Transparent); 
    daire.setOutlineThickness(16.f); 
    daire.setOutlineColor(sf::Color::Blue); 
    daire.setOrigin({50.f, 50.f});
 
    float merkezX = sutun * 200.f + 100.f; 
    float merkezY = satir * 200.f + 100.f;
    daire.setPosition({merkezX, merkezY});
    daireler.push_back(daire);
}