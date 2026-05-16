# C++ SFML ile Tic-Tac-Toe Oyunu

Bu proje, Kocaeli University Software Engineering bünyesinde, modern C++17 standartları ve SFML (Simple and Fast Multimedia Library) 3 grafik kütüphanesi kullanılarak geliştirilmiş iki oyunculu senkron bir Tic-Tac-Toe oyunudur.

## 🚀 Özellikler
* **Gelişmiş Grafik Kalitesi:** Donanımsal **8x Anti-Aliasing (Kenar Yumuşatma)** desteği ile pürüzsüz ve piksellenmeyen nesne çizimleri.
* **Modüler Mimari:** Proje, nesne yönelimli ve modüler programlama prensiplerine uygun olarak `include/` ve `src/` mimarisine ayrılmıştır.
* **Akıllı Çizim Sistemi:** Dinamik `sf::RectangleShape` ve `sf::CircleShape` manipülasyonları ile simetrik X ve O harfi konumlandırması.
* **Oyun Mekaniği:** Her hamle sonrası matris taraması yapan, zaman karmaşıklığı optimize edilmiş kazanma/beraberlik kontrol algoritması.

## 📂 Proje Yapısı
```text
TicTacToe/
├── Makefile            # Derleme otomasyonu ayarları
├── README.md           # Proje dokümantasyonu
├── include/
│   └── OyunMekanigi.hpp # Algoritma başlık (header) dosyası
└── src/
    ├── main.cpp        # SFML Grafik döngüsü ve event yönetimi
    └── OyunMekanigi.cpp # Oyun lojistiği ve kazanma kontrolü mantığı