# 🕹️ SFML ile Yapay Zeka Destekli Tic-Tac-Toe Oyunu

Bu proje, C++ ve **SFML (Simple and Fast Multimedia Library)** kütüphanesi kullanılarak nesne yönelimli ve modüler bir mimariyle geliştirilmiş bir Tic-Tac-Toe (X-O-X) oyunudur. Oyunda, oyuncunun karşısında asla hata yapmayan ve en iyi hamleyi hesaplayan bir yapay zeka yer almaktadır.

---

## 🚀 Özellikler

* **Minimax Yapay Zeka Algoritması:** Bilgisayarın hamlelerini yöneten, oyunun tüm olasılık ağacını tarayarak her zaman en optimal kararı veren yenilmez yapay zeka mekanizması.
* **Doğal Oyun Deneyimi (Gecikme Sistemi):** Yapay zekanın hamlelerini anında yapmak yerine, gerçek bir rakip gibi "düşünüyormuş" hissi yaratması için eklenmiş zaman ayarlı (1.5 saniye) gecikme mekanizması.
* **Gelişmiş Grafik Kalitesi:** Donanımsal `8x Anti-Aliasing (Kenar Yumuşatma)` desteği ile pürüzsüz ve piksellenmeyen nesne çizimleri.
* **Modüler Mimari:** Proje, nesne yönelimli ve modüler programlama prensiplerine uygun olarak temiz ve sürdürülebilir bir `include/` ve `src/` yapısına ayrılmıştır.
* **Akıllı Çizim Sistemi:** Dinamik `sf::RectangleShape` ve `sf::CircleShape` manipülasyonları ile simetrik X ve O harfi konumlandırması.
* **Oyun Mekaniği:** Her hamle sonrası matris taraması yapan, zaman karmaşıklığı optimize edilmiş kazanma/beraberlik kontrol algoritması.

---

## 📂 Proje Yapısı

```text
TicTacToe/
├── Makefile             # Derleme otomasyonu ayarları
├── README.md            # Proje dokümantasyonu
├── include/
│   ├── oyunArayuzu.hpp  # Seçim ve çizim ekranı arayüz başlıkları
│   ├── oyunMekanigi.hpp # Kazanma kontrolü algoritması başlık dosyası
│   ├── oyunTahtasi.hpp  # Izgara ve şekil çizim fonksiyonları başlıkları
│   ├── oyuncuSecimi.hpp # Oyuncu seçimi mantığı başlık dosyası
│   └── yapayZeka.hpp    # Minimax yapay zeka fonksiyon başlıkları
└── src/
    ├── main.cpp         # SFML Grafik döngüsü ve ana event yönetimi
    ├── oyunArayuzu.cpp  # Seçim ekranı ve oyun içi görsel çizimler
    ├── oyunMekanigi.cpp # Oyun lojistiği ve matris kontrol mantığı
    ├── oyunTahtasi.cpp  # Tahta çizgileri ve X/O figürlerinin oluşturulması
    ├── oyuncuSecimi.cpp # Seçim ekranı koordinat kontrol mantığı
    └── yapayZeka.cpp    # Minimax algoritması hesaplama gövdesi