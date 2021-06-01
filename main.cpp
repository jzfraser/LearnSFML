#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>
#include <iostream>

const uint32_t WIN_WIDTH = 900;
const uint32_t WIN_HEIGHT = 480;
const uint32_t NUM_BARS = 100;
const uint32_t BAR_WIDTH = WIN_WIDTH / NUM_BARS;

sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "SFML is EZPZ!");
int bars[NUM_BARS];

void getBars() {
    for (int i = 0; i < NUM_BARS; i++) {
        bars[i] = rand() % WIN_HEIGHT - 1;
    }
}

// void printBars() {
//     for (int i = 0; i < NUM_BARS; i++) {
//         std::cout << bars[i] << " ";
//     }
//     std::cout << "\n";
// }

void drawBars(int current = -2) {
    window.clear();
    for (int i = 0; i < NUM_BARS; i++) {
            sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH, bars[i]));
            bar.setPosition(i * BAR_WIDTH, WIN_HEIGHT - bars[i]);
            if (i == current || i == current + 1) {
                bar.setFillColor(sf::Color::Magenta);
            } else {
                bar.setFillColor(sf::Color::White);
            }
            window.draw(bar);
        }
    window.display();
}

void swap(int a[], int i, int j) {
    // std::cout << "Swapping " << bars[i] << " and " << bars[j] << "\n";
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main() {
    getBars();
    int i = 0;
    int j = 0;
    int n = NUM_BARS;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (i < n) {
            for (int j = 0; j < n - i - 1; j++) {
                if (bars[j] > bars[j + 1]) {
                    swap(bars, j, j + 1);
                    drawBars(j);
                    sf::sleep(sf::seconds(0.001f));
                }
            }
            i++;
        } else {
            drawBars();
        }
    }

    return 0;
}