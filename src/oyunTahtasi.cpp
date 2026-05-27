#include "../include/oyunTahtasi.hpp"

void tahtaCizgileriniOlustur(std::vector<sf::RectangleShape>& cizgiler) {
    for (int i = 0; i < 2; i++) {
        // Dikey Çizgiler
        sf::RectangleShape dikey;
        dikey.setSize(sf::Vector2f(5.f, 600.f));
        dikey.setFillColor({90,95,130});
        dikey.setPosition(sf::Vector2f(200.f * (i + 1), 0.f));
        cizgiler.push_back(dikey);

        // Yatay Çizgiler
        sf::RectangleShape yatay;
        yatay.setSize(sf::Vector2f(600.f, 5.f));
        yatay.setFillColor({90,95,130});
        yatay.setPosition(sf::Vector2f(0.f, 200.f * (i + 1)));
        cizgiler.push_back(yatay);
    }
}