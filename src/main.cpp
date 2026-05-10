#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    // 600x600 boyutunda bir pencere oluşturuyoruz
    sf::RenderWindow pencere (sf::VideoMode({600, 600}), "Tic Tac Toe");
    
    //Ilk dikey cizgi nesnesi olustur.mak
    sf::RectangleShape dikeyCizgi1;
    dikeyCizgi1.setSize(sf::Vector2f(10.f,600.f));
    dikeyCizgi1.setFillColor(sf::Color::Black);
    dikeyCizgi1.setPosition(sf::Vector2(200.f,0.f));


    while (pencere.isOpen()) {
        while (const std::optional event =pencere.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                pencere.close();
            }
        }
        //pencereyi temizle(beyaz yap)
        pencere.clear(sf::Color::White);

        pencere.draw(dikeyCizgi1);

        // Çizilenleri ekrana yansıt
        pencere.display();
    }

    return 0;
}
