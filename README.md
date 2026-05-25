# 🎮 SFML Tic-Tac-Toe (Yapay Zeka Destekli)

Kocaeli Üniversitesi Yazılım Mühendisliği dönemi kapsamında C++ ve SFML (Simple and Fast Multimedia Library) kullanılarak geliştirilmiş, modern kullanıcı arayüzüne (UI) ve Minimax algoritmalı Yapay Zekaya sahip akıllı bir Tic-Tac-Toe oyunudur.

---

## ✨ Öne Çıkan Özellikler

* **Katmanlı Pop-Up Sistemi (Overlay):** Oyun, tek bir 600x600 pencere içinde başlar. Karakter seçimi ve oyun sonu ekranları, arkadaki oyun tahtasını silmeden "sekme içinde sekme" mantığıyla akıcı bir şekilde açılır.
* **Gelişmiş Yapay Zeka:** Minimax algoritması sayesinde yenilmez bir rakibe karşı oynarsınız. Yapay zeka hamleleri öncesinde 1.5 saniyelik gerçekçi bir düşünme gecikmesi simüle edilir.
* **Dinamik Oyun Döngüsü:** Oyun bittiğinde terminale bağımlı kalmadan GUI üzerinden doğrudan "Yeniden Başlat" veya "Çıkış" aksiyonları alınabilir.
* **Tam Modüler Mimari:** Temiz kod prensiplerine uygun, sorumlulukların tamamen ayrıldığı (`src/` ve `include/`) nesne yönelimli dosya yapısı.

---

## 📂 Proje Dosya Yapısı

TicTacToe/
├── include/
│   ├── oyunMekanigi.hpp  # Kazanma ve beraberlik kontrol lojistiği
│   ├── oyunArayuzu.hpp   # Genel arayüz tanımlamaları
│   ├── oyunTahtasi.hpp   # 3x3 ızgara çizgilerinin oluşturulması
│   ├── oyuncuSecimi.hpp  # Başlangıç X/O panel çizimi ve kontrolü
│   ├── yapayZeka.hpp     # Minimax yapay zeka algoritması
│   └── oyunSonu.hpp      # Sonuç ekranı ve buton lojistiği
├── src/
│   ├── main.cpp          # Ana oyun döngüsü ve katmanlı çizim yönetimi
│   ├── oyunMekanigi.cpp
│   ├── oyunArayuzu.cpp
│   ├── oyunTahtasi.cpp
│   ├── oyuncuSecimi.cpp
│   ├── yapayZeka.cpp
│   └── oyunSonu.cpp      # Sonuç metinleri ve Restart/Quit buton mekanizmaları
├── font.ttf              # Oyun içi metinlerin çizilmesi için gerekli font dosyası
├── Makefile              # Kolay derleme otomasyonu
└── README.md

🛠️ Kurulum ve Çalıştırma
Gereksinimler:
1.C++17 destekleyen bir derleyici (GCC/Clang)
2.SFML Kütüphanesi 
Derleme Adımları:
1.Projenin ana dizininde terminali açın.
2.Eski derleme kalıntılarını temizlemek ve projeyi sıfırdan derlemek için şu komutu çalıştırın:
make clean && make
3.Derleme tamamlandıktan sonra oluşan çalıştırılabilir dosyayı başlatın:
./main
