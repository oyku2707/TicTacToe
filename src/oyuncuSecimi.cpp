#include "../include/oyuncuSecimi.hpp"
//pop-up ve buton koordinatları
const float panelX = 150.f, panelY = 200.f;   
const float panelGenislik = 300.f, panelYukseklik = 200.f;

const float boyut = 70.f;                        
const float xButonX = 185.f, xButonY = 280.f;     
const float oButonX = 345.f, oButonY = 280.f;     

void secimEkraniniCiz(sf::RenderWindow& pencere) {
  
    sf::RectangleShape popUpKutu({panelGenislik,panelYukseklik});//pop-up kutusu
    popUpKutu.setPosition({panelX,panelY});
    popUpKutu.setFillColor(sf::Color(211,211,211,180));
    popUpKutu.setOutlineThickness(4.f);
    popUpKutu.setOutlineColor(sf::Color::Black);
    pencere.draw(popUpKutu);

    sf::RectangleShape xKutu({boyut, boyut});
    xKutu.setPosition({xButonX, xButonY});
    xKutu.setFillColor(sf::Color(50, 50, 50));
    xKutu.setOutlineThickness(3.f);
    xKutu.setOutlineColor(sf::Color::Red);
    pencere.draw(xKutu);

    sf::RectangleShape cizgi1({50.f,6.f});//X yazısı
    cizgi1.setFillColor(sf::Color::Red);
    cizgi1.setOrigin({25.f,3.f});
    cizgi1.setPosition({xButonX + 35.f, xButonY + 35.f});
    cizgi1.setRotation(sf::degrees(45.f));
    pencere.draw(cizgi1);

    sf::RectangleShape cizgi2 = cizgi1;
    cizgi2.setRotation(sf::degrees(135.f));
    pencere.draw(cizgi2);

    sf::RectangleShape oKutu({boyut, boyut});//o için buton
    oKutu.setPosition({oButonX, oButonY});
    oKutu.setFillColor(sf::Color(50, 50, 50));
    oKutu.setOutlineThickness(3.f);
    oKutu.setOutlineColor(sf::Color::Blue);
    pencere.draw(oKutu);

    sf::CircleShape daire(20.f);//O yazısı
    daire.setFillColor(sf::Color::Transparent);
    daire.setOutlineThickness(6.f);
    daire.setOutlineColor(sf::Color::Blue);
    daire.setOrigin({20.f,20.f});
    daire.setPosition({oButonX + 35.f, oButonY + 35.f});
    pencere.draw(daire);
}
int secimKontrolu(int x, int y) {
    if (x>= xButonX && x <= xButonX + boyut && y >= xButonY && y <= xButonY +boyut) {
        return 1; // X seçildi
    }
    if (x >= oButonX && x<= oButonX +boyut && y >= oButonY && y <= oButonY + boyut) {
        return 2; // O seçildi
    }
    return 0; //seçim yapılmadı
}