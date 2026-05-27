# 🎮 SFML Tic-Tac-Toe (Yapay Zeka Destekli)

Bu proje, Kocaeli Üniversitesi Yazılım Mühendisliği bölümü kapsamında C++ ve SFML (Simple and Fast Multimedia Library) kütüphanesi kullanılarak geliştirilmiştir. Modern katmanlı grafik kullanıcı arayüzüne (UI Overlay) ve yenilmez Minimax algoritmasına sahip akıllı bir Tic-Tac-Toe oyunudur. Proje, Nesne Yönelimli Programlama (OOP) prensiplerine ve tam modüler bir mimari tasarıma sadık kalınarak temiz kod (clean code) standartlarında geliştirilmiştir.

---

## 🛠️ Kullanılan Teknolojiler ve Mimari Standartlar

* **Programlama Dili:** C++17 Standartları (Akıllı yapılar, vektörler ve bellek optimizasyonları)
* **Grafik Kütüphanesi:** SFML (Simple and Fast Multimedia Library)
* **Tasarım Deseni:** Durum Makinesi (State Machine - `secimAlani`, `oyunAlani`, `oyunBitti` aşamaları)
* **Derleme Otomasyonu:** GNU Make (Makefile mimarisi)

---

## ✨ Öne Çıkan Teknik Özellikler

* **Katmanlı Pop-Up Sistemi (UI Overlay):** Oyun, tek bir 600x600 çözünürlüğündeki pencere içinde çalışır. Başlangıçtaki karakter seçim ekranı (`PLAYER CHOICE`) ve oyun sonu sonuç ekranları, arkadaki ana oyun tahtasını silmeden veya yeni pencere açmadan yarı saydam birer arayüz katmanı olarak ekrana çizilir.
* **Gelişmiş Minimax Yapay Zekası:** Bilgisayar rakibi, oyun ağacındaki tüm olasılıkları hesaplayan ve en kötü senaryoda bile beraberliği garanti eden Minimax algoritmasını kullanır. Kullanıcı deneyimini doğallaştırmak adına, yapay zeka hamle yapmadan önce asenkron bir şekilde 1.5 saniyelik (`1500 ms`) gerçekçi bir düşünme gecikmesi simüle eder.
* **Küresel İngilizce Arayüz Bütünlüğü:** Projede dil bütünlüğü kurallarına tam uyum sağlanmıştır. Açılışta `PLAYER CHOICE`, oyun bitiminde ise dinamik olarak `YOU WIN!`, `YOU LOSE!` veya `DRAW!` ekranları modern arcade estetiğiyle sunulur.
* **Dinamik Grafik Döngüsü:** Oyun tamamen terminal (konsol) bağımlılığından kurtarılmıştır. Oyuncular oyun bittikten sonra doğrudan arayüz üzerindeki grafik butonları (`RESTART` ve `QUIT`) kullanarak oyunu baştan başlatabilir veya kapatabilirler.
* **Tam Modüler Yapı:** Sorumlulukların ayrılması (Separation of Concerns) ilkesine uygun olarak kod tabanı `src/` ve `include/` dizinleri altında tamamen bağımsız modüllere bölünmüştür.

---

## 📂 Proje Dosya Yapısı

```text
TicTacToe/
├── include/
│   ├── oyunMekanigi.hpp  # Kazanma durumları ve beraberlik kontrol lojistiği
│   ├── oyunArayuzu.hpp   # Genel arayüz yapılandırmaları ve ekran sabitleri
│   ├── oyunTahtasi.hpp   # 3x3 oyun ızgarasının çizgi sınırları
│   ├── oyuncuSecimi.hpp  # Başlangıç karakter seçim paneli (PLAYER CHOICE)
│   ├── yapayZeka.hpp     # Minimax karar ağacı algoritması hesaplamaları
│   └── oyunSonu.hpp      # Oyun sonu pop-up çizimi ve aksiyon yönetimi
├── src/
│   ├── main.cpp          # Ana oyun döngüsü, durum makinesi ve katmanlı render yönetimi
│   ├── oyunMekanigi.cpp
│   ├── oyunArayuzu.cpp
│   ├── oyunTahtasi.cpp
│   ├── oyuncuSecimi.cpp
│   ├── yapayZeka.cpp
│   └── oyunSonu.cpp      # RESTART ve QUIT buton lojistikleri ve tıklama alanları
├── font.ttf              # Yazıların ekrana çizilebilmesi için gerekli TrueType Font dosyası
├── Makefile              # Projenin tek komutla derlenmesini sağlayan otomasyon scripti
└── README.md

### Derleme ve Çalıştırma Adımları

1. Terminali (Konsolu) projenin ana kök dizininde açın.
2. Eski derleme kalıntılarını temizlemek ve projeyi sıfırdan hatasız derlemek için şu komutu çalıştırın:
   make clean && make
3.Derleme başarılı bir şekilde tamamlandıktan sonra oluşan çalıştırılabilir dosyayı sisteminize göre başlatın:
macOS / Linux:./main  # (Veya Makefile içinde tanımladığınız çıktı adı, örn: ./TicTacToe)
Windows (MinGW/MSYS2):main.exe