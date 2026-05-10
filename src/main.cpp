#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    // 600x600 boyutunda bir pencere oluşturuyoruz
    sf::RenderWindow pencere (sf::VideoMode({600, 600}), "Tic Tac Toe");

    while (pencere.isOpen()) {
        while (const std::optional event =pencere.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                pencere.close();
            }
        }
        //pencereyi temizle(beyaz yap)
        pencere.clear(sf::Color::White);

        // Çizilenleri ekrana yansıt
        pencere.display();
    }

    return 0;
}