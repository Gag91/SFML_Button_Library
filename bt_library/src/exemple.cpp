#include <SFML/Graphics.hpp>
#include "bt_button.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Grid Test");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    bt::Button btn1, btn2, btn3, btn4;

    // Setup all buttons
    bt::setSize(btn1, 120, 40);
    bt::setSize(btn2, 120, 40);
    bt::setSize(btn3, 120, 40);
    bt::setSize(btn4, 120, 40);

    bt::setFont(btn1, font);
    bt::setFont(btn2, font);
    bt::setFont(btn3, font);
    bt::setFont(btn4, font);

    bt::setText(btn1, "1,1");
    bt::setText(btn2, "1,2");
    bt::setText(btn3, "2,1");
    bt::setText(btn4, "2,2");

    bt::setColor(btn1, sf::Color::Blue);
    bt::setColor(btn2, sf::Color::Green);
    bt::setColor(btn3, sf::Color::Red);
    bt::setColor(btn4, sf::Color::Yellow);

    // Use grid layout
    bt::setGrid(btn1, 2, 2, 20, 20, 100, 100);
    bt::setGrid(btn2, 2, 2, 20, 20, 100, 100);
    bt::setGrid(btn3, 2, 2, 20, 20, 100, 100);
    bt::setGrid(btn4, 2, 2, 20, 20, 100, 100);

    bt::setGridPosition(btn1, 0, 0);
    bt::setGridPosition(btn2, 0, 1);
    bt::setGridPosition(btn3, 1, 0);
    bt::setGridPosition(btn4, 1, 1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bt::update(btn1, window);
        bt::update(btn2, window);
        bt::update(btn3, window);
        bt::update(btn4, window);

        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, btn1);
        bt::draw(window, btn2);
        bt::draw(window, btn3);
        bt::draw(window, btn4);
        window.display();
    }

    return 0;
}