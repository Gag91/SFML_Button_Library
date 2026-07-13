#include <SFML/Graphics.hpp>
#include <iostream>
#include "bt_button.hpp"

int main()
{
    // Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game Menu");

    // Load font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        return -1;
    }

    // === CREATE BUTTONS ===

    // Button 1: Start Game
    bt::Button startBtn;
    bt::setColor(startBtn, bt::Green);
    bt::setColorHover(startBtn, sf::Color(100, 255, 100)); // Lighter green
    bt::setColorPressed(startBtn, sf::Color(0, 100, 0));   // Darker green
    bt::setSize(startBtn, 300, 80);
    bt::setFont(startBtn, font);
    bt::Text(startBtn, "Start Game");
    bt::setPosition(startBtn, 250, 100);

    // Button 2: Options
    bt::Button optionsBtn;
    bt::setColor(optionsBtn, sf::Color(255, 200, 0));        // Gold
    bt::setColorHover(optionsBtn, sf::Color(255, 220, 100)); // Light gold
    bt::setColorPressed(optionsBtn, sf::Color(150, 100, 0)); // Dark gold
    bt::setSize(optionsBtn, 300, 80);
    bt::setFont(optionsBtn, font);
    bt::Text(optionsBtn, "Options");
    bt::setPosition(optionsBtn, 250, 220);

    // Button 3: Exit
    bt::Button exitBtn;
    bt::setColor(exitBtn, bt::Red);
    bt::setColorHover(exitBtn, sf::Color(255, 100, 100)); // Light red
    bt::setColorPressed(exitBtn, sf::Color(100, 0, 0));   // Dark red
    bt::setSize(exitBtn, 300, 80);
    bt::setFont(exitBtn, font);
    bt::Text(exitBtn, "Exit");
    bt::setPosition(exitBtn, 250, 340);

    // Game state
    bool gameRunning = true;
    bool gameStarted = false;

    while (window.isOpen())
    {
        // === EVENT HANDLING ===
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // === UPDATE BUTTONS ===
        bt::update(startBtn, window);
        bt::update(optionsBtn, window);
        bt::update(exitBtn, window);

        // === KEYBOARD SHORTCUTS ===
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            bt::ButtonPress(startBtn); // Press Start with 'S' key
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        {
            bt::ButtonPress(optionsBtn); // Press Options with 'O' key
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            bt::ButtonPress(exitBtn); // Press Exit with Escape key
        }

        // === BUTTON ACTIONS ===

        // Start Game
        if (bt::ButtonIsPressed(startBtn))
        {
            std::cout << "🎮 Starting Game!" << std::endl;
            gameStarted = true;
            // Start your game logic here
        }

        // Options
        if (bt::ButtonIsPressed(optionsBtn))
        {
            std::cout << "⚙️ Opening Options..." << std::endl;
            // Open options menu
        }

        // Exit
        if (bt::ButtonIsPressed(exitBtn))
        {
            std::cout << "👋 Exiting Game..." << std::endl;
            window.close();
        }

        // === DRAW EVERYTHING ===
        window.clear(sf::Color(30, 30, 50)); // Dark blue background

        // Draw title
        sf::Text title("MY AWESOME GAME", font, 50);
        title.setFillColor(sf::Color::White);
        title.setPosition(200, 30);
        window.draw(title);

        // Draw buttons
        bt::draw(window, startBtn);
        bt::draw(window, optionsBtn);
        bt::draw(window, exitBtn);

        // Show game started message
        if (gameStarted)
        {
            sf::Text status("Game Running!", font, 30);
            status.setFillColor(sf::Color::Green);
            status.setPosition(300, 450);
            window.draw(status);
        }

        window.display();
    }

    return 0;
}