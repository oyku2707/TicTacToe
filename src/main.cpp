
#include <SFML/Graphics.hpp>

int main() {
    // SFML 3.0'da VideoMode kullanımı Vector2u ile değişti
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tic Tac Toe - SFML Calisiyor!");

    while (window.isOpen()) {
        // SFML 3.0'da event sistemi opsiyonel (std::optional) hale geldi
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);
        window.display();
    }

    return 0;
}