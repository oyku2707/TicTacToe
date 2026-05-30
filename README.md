# 🎮 SFML Tic-Tac-Toe (Yapay Zeka Destekli)

Bu proje, Kocaeli Üniversitesi Yazılım Mühendisliği bölümü kapsamında C++ ve SFML (Simple and Fast Multimedia Library) kütüphanesi kullanılarak geliştirilmiştir. Modern katmanlı grafik kullanıcı arayüzüne ve yenilmez Minimax algoritmasına sahip akıllı bir Tic-Tac-Toe oyunudur. Proje, Nesne Yönelimli Programlama (OOP) prensiplerine ve tam modüler bir mimari tasarıma sadık kalınarak geliştirilmiştir.

# Geliştirici:
* Ad-Soyad:Öykü Ertuna
* Öğrenci Numarası:240229036
* Bölüm:Yazılım Mühendisliği

## 🛠️ Kullanılan Teknolojiler ve Mimari Standartlar

* **Programlama Dili:** C++17 Standartları
* **Grafik Kütüphanesi:** SFML (Simple and Fast Multimedia Library)
* **Tasarım Deseni:** Durum Makinesi (State Machine - `secimAlani`, `oyunAlani`, `oyunBitti` aşamaları)
* **Derleme Otomasyonu:** GNU Make (Makefile mimarisi)


## ✨ Öne Çıkan Teknik Özellikler

* **Katmanlı Pop-Up Sistemi:** Oyun, tek bir 600x600 çözünürlüğündeki pencere içinde çalışır. Başlangıçtaki karakter seçim ekranı (`PLAYER CHOICE`) ve oyun sonu sonuç ekranları, arkadaki ana oyun tahtasını silmeden veya yeni pencere açmadan birer arayüz katmanı olarak ekrana çizilir.
* **Gelişmiş Minimax Yapay Zekası:** Bilgisayar rakibi, oyun ağacındaki tüm olasılıkları hesaplayan ve en kötü senaryoda bile beraberliği garanti eden Minimax algoritmasını kullanır. Kullanıcı deneyimini doğallaştırmak adına, yapay zeka hamle yapmadan önce asenkron bir şekilde 1.5 saniyelik (`1500 ms`) gerçekçi bir düşünme gecikmesi simüle eder.
* **Dinamik Grafik Döngüsü:** Oyun tamamen terminal (konsol) bağımlılığından kurtarılmıştır. Oyuncular oyun bittikten sonra doğrudan arayüz üzerindeki grafik butonları (`RESTART` ve `QUIT`) kullanarak oyunu baştan başlatabilir veya kapatabilirler.
* **Tam Modüler Yapı:** Sorumlulukların ayrılması ilkesine uygun olarak kod tabanı `src/` ve `include/` dizinleri altında tamamen bağımsız modüllere bölünmüştür.

## 🛠️ Kurulum ve Çalıştırma Adımları

Bu projenin başka bir bilgisayarda sorunsuz çalışabilmesi için bilgisayarda **C++17 destekleyen bir derleyici** ve **SFML 3.0** kütüphanesinin kurulu olması gerekmektedir.

### 1. Bağımlılıkların Kurulması (Eğer yüklü değilse)
* **Windows (MinGW/MSYS2):** MSYS2 terminali üzerinden `mingw-w64-x86_64-sfml` paketi kurulmalıdır.
* **macOS (M serisi veya Intel):** Terminalden Homebrew kullanılarak şu komutla kurulabilir:
  brew install sfml

### 2. Projenin Derlenmesi
Terminali (Konsolu) projenin ana klasörünün içinde açın ve sırasıyla şu komutları çalıştırın:
make clean
make
### 3. Projenin Çalıştırılması
Derleme işlemi bittikten sonra klasörde oluşan çalıştırılabilir dosyayı işletim sisteminize göre terminalden başlatın:
* macOS / Linux için:
./main
* Windows için:
main.exe

⚠️ Başka Bilgisayarda Çalıştırırken Dikkat Edilmesi Gerekenler 
Font Dosyası Eksikliği: Projedeki yazıların (PLAYER CHOICE, YOU WIN vb.) ekrana düzgün çizilebilmesi için font.ttf dosyasının, çalıştırılabilir dosya (main / main.exe) ile kesinlikle aynı klasörde bulunması gerekir. Klasör değiştirilirse oyun fontu bulamaz ve çöker.


## 📂 Proje Dosya Yapısı

```text
TicTacToe/
├── include/
│   ├── oyunMekanigi.hpp 
│   ├── oyunArayuzu.hpp  
│   ├── oyunTahtasi.hpp  
│   ├── oyuncuSecimi.hpp 
│   ├── yapayZeka.hpp    
│   └── oyunSonu.hpp     
├── src/
│   ├── main.cpp         
│   ├── oyunMekanigi.cpp
│   ├── oyunArayuzu.cpp
│   ├── oyunTahtasi.cpp
│   ├── oyuncuSecimi.cpp
│   ├── yapayZeka.cpp
│   └── oyunSonu.cpp     
├── font.ttf            
├── Makefile             
└── README.md


## 🎬 Proje Demo Videosu

Projeyi canlı olarak çalışırken izlemek için aşağıdaki bağlantıdan demo videosuna ulaşabilirsiniz:

▶️ [Google Drive üzerinden Proje Demo Videosunu İzle](https://drive.google.com/file/d/1l1m9jMpucW7VrKc_lFX-yWU55KxSqk3X/view?usp=sharing)



