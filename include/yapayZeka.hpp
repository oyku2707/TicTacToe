#ifndef YAPAY_ZEKA_HPP
#define YAPAY_ZEKA_HPP

#include <vector>
//minimax algoritmasını tahtayı puanladığı ana matematik fonksiyonu
int minimax(int tahta[3][3], int derinlik, bool enYuksekAl);

// Bilgisayarın en iyi hamleyi bulup tahtaya yazdığı fonksiyon
std::pair<int, int> enIyiHamleyiBul(int tahta[3][3], int bzYapayZeka);

#endif