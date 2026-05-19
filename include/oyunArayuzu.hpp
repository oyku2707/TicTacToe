#ifndef OYUN_ARAYUZU_HPP
#define OYUN_ARAYUZU_HPP

#include <SFML/Graphics.hpp>
#include <vector>

void xCizgisiEkle(std::vector<sf::RectangleShape>& xCizgileri, int satir, int sutun);//x'i ekleyen fonksiyon
void oDairesiEkle(std::vector<sf::CircleShape>& daireler, int satir, int sutun);//o'yu ekleyen fonksiyon

#endif