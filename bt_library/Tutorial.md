// ====================================================================
// bt::Button - Complete Usage Guide
// ====================================================================
// This file contains EVERYTHING you need to use the bt::Button library
// Copy this entire file and use it as your main.cpp
// ====================================================================

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "bt_button.hpp"

// ====================================================================
// SECTION 1: BASIC SETUP
// ====================================================================

void basicSetupExample() {
    std::cout << "\n=== BASIC SETUP ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Basic Setup");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    // 1. Create a button
    bt::Button myButton;
    
    // 2. Set size (width, height)
    bt::setSize(myButton, 200, 50);
    
    // 3. Set font and text
    bt::setFont(myButton, font);
    bt::setText(myButton, "Click Me!");
    bt::setTextSize(myButton, 24);
    
    // 4. Set position (x, y)
    bt::setPosition(myButton, 300, 275);
    
    // 5. Set colors
    bt::setColor(myButton, bt::Blue);
    bt::setColorHover(myButton, sf::Color::Cyan);
    bt::setColorPressed(myButton, bt::Red);
    
    // 6. Add action
    bt::setOnClick(myButton, []() {
        std::cout << "Button Clicked!" << std::endl;
    });
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(myButton, window);
        
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, myButton);
        window.display();
    }
}

// ====================================================================
// SECTION 2: COLORS & STYLING
// ====================================================================

void colorsStylingExample() {
    std::cout << "\n=== COLORS & STYLING ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Colors & Styling");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    bt::Button btn;
    bt::setSize(btn, 250, 60);
    bt::setFont(btn, font);
    bt::setText(btn, "Styled Button");
    bt::setTextSize(btn, 24);
    bt::setPosition(btn, 275, 270);
    
    // Colors
    bt::setColor(btn, sf::Color(50, 150, 255));           // Normal
    bt::setColorHover(btn, sf::Color(100, 200, 255));     // Hover
    bt::setColorPressed(btn, sf::Color(0, 100, 200));     // Pressed
    
    // Text Colors
    bt::setTextColor(btn, sf::Color::White);
    bt::setTextColorHover(btn, sf::Color::Yellow);
    bt::setTextColorPressed(btn, sf::Color::Gray);
    
    // Outline
    bt::setOutline(btn, 2, sf::Color::White);
    bt::setOutlineHover(btn, 4, sf::Color::Yellow);
    bt::setOutlinePressed(btn, 3, sf::Color::Red);
    
    // Shadow
    bt::setShadowEnabled(btn, true);
    bt::setShadowOffset(btn, 6, 6);
    bt::setShadowColor(btn, sf::Color(40, 40, 40, 180));
    
    // Opacity
    bt::setOpacity(btn, 0.9f);
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(btn, window);
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, btn);
        window.display();
    }
}

// ====================================================================
// SECTION 3: SHAPES
// ====================================================================

void shapesExample() {
    std::cout << "\n=== SHAPES ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    // Rectangle (Default)
    bt::Button rectBtn;
    bt::setSize(rectBtn, 200, 50);
    bt::setShape(rectBtn, bt::RECTANGLE);
    bt::setFont(rectBtn, font);
    bt::setText(rectBtn, "Rectangle");
    bt::setPosition(rectBtn, 50, 50);
    bt::setColor(rectBtn, sf::Color(50, 150, 255));
    
    // Circle
    bt::Button circleBtn;
    bt::setSize(circleBtn, 100, 100);
    bt::setShape(circleBtn, bt::CIRCLE);
    bt::setFont(circleBtn, font);
    bt::setText(circleBtn, "Circle");
    bt::setTextSize(circleBtn, 18);
    bt::setPosition(circleBtn, 300, 50);
    bt::setColor(circleBtn, sf::Color(50, 255, 150));
    
    // Rounded Rectangle
    bt::Button roundBtn;
    bt::setSize(roundBtn, 200, 50);
    bt::setShape(roundBtn, bt::ROUNDED);
    bt::setCornerRadius(roundBtn, 10);
    bt::setFont(roundBtn, font);
    bt::setText(roundBtn, "Rounded");
    bt::setPosition(roundBtn, 450, 50);
    bt::setColor(roundBtn, sf::Color(255, 150, 50));
    
    // Triangle
    bt::Button triBtn;
    bt::setSize(triBtn, 100, 80);
    bt::setShape(triBtn, bt::TRIANGLE);
    bt::setFont(triBtn, font);
    bt::setText(triBtn, "Triangle");
    bt::setTextSize(triBtn, 16);
    bt::setPosition(triBtn, 700, 50);
    bt::setColor(triBtn, sf::Color(255, 50, 150));
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(rectBtn, window);
        bt::update(circleBtn, window);
        bt::update(roundBtn, window);
        bt::update(triBtn, window);
        
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, rectBtn);
        bt::draw(window, circleBtn);
        bt::draw(window, roundBtn);
        bt::draw(window, triBtn);
        window.display();
    }
}

// ====================================================================
// SECTION 4: GRID LAYOUT
// ====================================================================

void gridLayoutExample() {
    std::cout << "\n=== GRID LAYOUT ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Grid Layout");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    // Create 4 buttons
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
    
    bt::setText(btn1, "Row 0, Col 0");
    bt::setText(btn2, "Row 0, Col 1");
    bt::setText(btn3, "Row 1, Col 0");
    bt::setText(btn4, "Row 1, Col 1");
    
    bt::setColor(btn1, sf::Color(50, 150, 255));
    bt::setColor(btn2, sf::Color(50, 255, 150));
    bt::setColor(btn3, sf::Color(255, 150, 50));
    bt::setColor(btn4, sf::Color(255, 50, 150));
    
    // Use grid layout - 2 rows, 2 columns, 20px spacing, start at (150, 150)
    bt::setGrid(btn1, 2, 2, 20, 20, 150, 150);
    bt::setGrid(btn2, 2, 2, 20, 20, 150, 150);
    bt::setGrid(btn3, 2, 2, 20, 20, 150, 150);
    bt::setGrid(btn4, 2, 2, 20, 20, 150, 150);
    
    // Position each button
    bt::setGridPosition(btn1, 0, 0);  // Row 0, Column 0
    bt::setGridPosition(btn2, 0, 1);  // Row 0, Column 1
    bt::setGridPosition(btn3, 1, 0);  // Row 1, Column 0
    bt::setGridPosition(btn4, 1, 1);  // Row 1, Column 1
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
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
}

// ====================================================================
// SECTION 5: CALLBACKS
// ====================================================================

void callbacksExample() {
    std::cout << "\n=== CALLBACKS ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Callbacks");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    bt::Button btn;
    bt::setSize(btn, 250, 60);
    bt::setFont(btn, font);
    bt::setText(btn, "Test Callbacks");
    bt::setPosition(btn, 275, 270);
    bt::setColor(btn, sf::Color(50, 150, 255));
    
    // All callbacks
    bt::setOnClick(btn, []() {
        std::cout << "✅ CLICKED!" << std::endl;
    });
    
    bt::setOnHover(btn, []() {
        std::cout << "🔄 HOVERING!" << std::endl;
    });
    
    bt::setOnPress(btn, []() {
        std::cout << "⬇️  PRESSED!" << std::endl;
    });
    
    bt::setOnRelease(btn, []() {
        std::cout << "⬆️  RELEASED!" << std::endl;
    });
    
    // Capture variables
    int clickCount = 0;
    bt::setOnClick(btn, [&]() {
        clickCount++;
        std::cout << "Clicked " << clickCount << " times!" << std::endl;
    });
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(btn, window);
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, btn);
        window.display();
    }
}

// ====================================================================
// SECTION 6: TOGGLE BUTTONS
// ====================================================================

void toggleButtonExample() {
    std::cout << "\n=== TOGGLE BUTTONS ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Toggle Buttons");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    bt::Button toggleBtn;
    bt::setSize(toggleBtn, 250, 60);
    bt::setFont(toggleBtn, font);
    bt::setText(toggleBtn, "OFF");
    bt::setPosition(toggleBtn, 275, 270);
    bt::setToggle(toggleBtn, true);
    
    // Toggle callback
    bt::setOnToggle(toggleBtn, [&]() {
        if (bt::isToggled(toggleBtn)) {
            bt::setText(toggleBtn, "ON");
            bt::setColor(toggleBtn, bt::Green);
            bt::setColorHover(toggleBtn, sf::Color(100, 255, 100));
            std::cout << "Toggle: ON" << std::endl;
        } else {
            bt::setText(toggleBtn, "OFF");
            bt::setColor(toggleBtn, bt::Red);
            bt::setColorHover(toggleBtn, sf::Color(255, 100, 100));
            std::cout << "Toggle: OFF" << std::endl;
        }
    });
    
    // Check toggle state
    bt::setOnClick(toggleBtn, [&]() {
        std::cout << "Toggle state: " << (bt::isToggled(toggleBtn) ? "ON" : "OFF") << std::endl;
    });
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(toggleBtn, window);
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, toggleBtn);
        window.display();
    }
}

// ====================================================================
// SECTION 7: KEYBOARD SHORTCUTS
// ====================================================================

void keyboardShortcutsExample() {
    std::cout << "\n=== KEYBOARD SHORTCUTS ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Keyboard Shortcuts");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    // Space button
    bt::Button spaceBtn;
    bt::setSize(spaceBtn, 200, 50);
    bt::setFont(spaceBtn, font);
    bt::setText(spaceBtn, "Press SPACE");
    bt::setPosition(spaceBtn, 300, 150);
    bt::setColor(spaceBtn, sf::Color(50, 150, 255));
    bt::setShortcut(spaceBtn, sf::Keyboard::Space);
    bt::setOnClick(spaceBtn, []() {
        std::cout << "✅ SPACE pressed!" << std::endl;
    });
    
    // Ctrl+S button
    bt::Button saveBtn;
    bt::setSize(saveBtn, 200, 50);
    bt::setFont(saveBtn, font);
    bt::setText(saveBtn, "Ctrl+S to Save");
    bt::setPosition(saveBtn, 300, 250);
    bt::setColor(saveBtn, sf::Color(50, 255, 150));
    bt::setShortcut(saveBtn, sf::Keyboard::S, true, false, false);
    bt::setOnClick(saveBtn, []() {
        std::cout << "💾 SAVED! (Ctrl+S)" << std::endl;
    });
    
    // Escape button
    bt::Button exitBtn;
    bt::setSize(exitBtn, 200, 50);
    bt::setFont(exitBtn, font);
    bt::setText(exitBtn, "ESC to Exit");
    bt::setPosition(exitBtn, 300, 350);
    bt::setColor(exitBtn, sf::Color(255, 50, 50));
    bt::setShortcut(exitBtn, sf::Keyboard::Escape);
    bt::setOnClick(exitBtn, [&]() {
        std::cout << "👋 Exiting!" << std::endl;
        window.close();
    });
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(spaceBtn, window);
        bt::update(saveBtn, window);
        bt::update(exitBtn, window);
        
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, spaceBtn);
        bt::draw(window, saveBtn);
        bt::draw(window, exitBtn);
        window.display();
    }
}

// ====================================================================
// SECTION 8: TOOLTIPS
// ====================================================================

void tooltipsExample() {
    std::cout << "\n=== TOOLTIPS ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tooltips");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    bt::Button btn;
    bt::setSize(btn, 250, 60);
    bt::setFont(btn, font);
    bt::setText(btn, "Hover Me!");
    bt::setPosition(btn, 275, 270);
    bt::setColor(btn, sf::Color(50, 150, 255));
    
    // Add tooltip
    bt::setTooltip(btn, "This is a helpful tooltip!\nIt can have multiple lines.");
    bt::setTooltipFont(btn, font);
    bt::setTooltipColor(btn, sf::Color::Yellow);
    bt::setTooltipSize(btn, 16);
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(btn, window);
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, btn);
        window.display();
    }
}

// ====================================================================
// SECTION 9: ICONS
// ====================================================================

void iconsExample() {
    std::cout << "\n=== ICONS ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Icons");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    // Note: You need an icon.png file in your project folder
    sf::Texture iconTexture;
    if (!iconTexture.loadFromFile("icon.png")) {
        std::cout << "Warning: icon.png not found! Creating a simple shape instead.\n";
        // Create a simple shape as fallback
        sf::Image img;
        img.create(32, 32, sf::Color::Yellow);
        iconTexture.loadFromImage(img);
    }
    
    bt::Button btn;
    bt::setSize(btn, 250, 60);
    bt::setFont(btn, font);
    bt::setText(btn, "With Icon");
    bt::setPosition(btn, 275, 270);
    bt::setColor(btn, sf::Color(50, 150, 255));
    
    // Add icon
    bt::setIcon(btn, iconTexture, 32, 32);
    bt::setIconPosition(btn, 15, 14);
    bt::setIconColor(btn, sf::Color::White);
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(btn, window);
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, btn);
        window.display();
    }
}

// ====================================================================
// SECTION 10: ANIMATIONS
// ====================================================================

void animationsExample() {
    std::cout << "\n=== ANIMATIONS ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Animations");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    bt::Button btn;
    bt::setSize(btn, 250, 60);
    bt::setFont(btn, font);
    bt::setText(btn, "Animate Me!");
    bt::setPosition(btn, 275, 270);
    bt::setColor(btn, sf::Color(50, 150, 255));
    
    // Play different animations
    bt::setOnClick(btn, [&]() {
        static int animIndex = 0;
        std::vector<bt::AnimationType> anims = {
            bt::BOUNCE, bt::PULSE, bt::FADE_IN, bt::FADE_OUT, bt::SHAKE
        };
        
        bt::playAnimation(btn, anims[animIndex % anims.size()]);
        animIndex++;
        
        std::cout << "Playing animation " << animIndex << std::endl;
    });
    
    bt::setAnimationDuration(btn, 0.5f);
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(btn, window);
        window.clear(sf::Color(30, 30, 50));
        bt::draw(window, btn);
        window.display();
    }
}

// ====================================================================
// SECTION 11: BUTTON GROUPS (Radio Buttons)
// ====================================================================

void buttonGroupsExample() {
    std::cout << "\n=== BUTTON GROUPS ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Button Groups");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    // Create 3 buttons
    bt::Button btn1, btn2, btn3;
    
    bt::setSize(btn1, 120, 40);
    bt::setSize(btn2, 120, 40);
    bt::setSize(btn3, 120, 40);
    
    bt::setFont(btn1, font);
    bt::setFont(btn2, font);
    bt::setFont(btn3, font);
    
    bt::setText(btn1, "Option 1");
    bt::setText(btn2, "Option 2");
    bt::setText(btn3, "Option 3");
    
    bt::setPosition(btn1, 340, 100);
    bt::setPosition(btn2, 340, 180);
    bt::setPosition(btn3, 340, 260);
    
    // Create group
    bt::ButtonGroup group;
    group.addButton(btn1);
    group.addButton(btn2);
    group.addButton(btn3);
    group.selectButton(0);
    
    // Show selection
    bt::setOnClick(btn1, [&]() {
        std::cout << "Selected: Option 1" << std::endl;
    });
    bt::setOnClick(btn2, [&]() {
        std::cout << "Selected: Option 2" << std::endl;
    });
    bt::setOnClick(btn3, [&]() {
        std::cout << "Selected: Option 3" << std::endl;
    });
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        group.updateAll(window);
        
        window.clear(sf::Color(30, 30, 50));
        group.drawAll(window);
        window.display();
    }
}

// ====================================================================
// SECTION 12: BUTTON CONTAINER
// ====================================================================

void buttonContainerExample() {
    std::cout << "\n=== BUTTON CONTAINER ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Button Container");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    // Create 6 buttons
    bt::Button btn1, btn2, btn3, btn4, btn5, btn6;
    
    std::vector<bt::Button*> btns = {&btn1, &btn2, &btn3, &btn4, &btn5, &btn6};
    
    // Setup all buttons
    for (int i = 0; i < 6; i++) {
        bt::setSize(*btns[i], 100, 40);
        bt::setFont(*btns[i], font);
        bt::setText(*btns[i], "Btn " + std::to_string(i+1));
        bt::setColor(*btns[i], sf::Color(50 + i*30, 100, 255 - i*20));
        
        bt::setOnClick(*btns[i], [i]() {
            std::cout << "Button " << i+1 << " clicked!" << std::endl;
        });
    }
    
    // Create container
    bt::ButtonContainer container;
    container.setPosition(200, 100);
    container.setSpacing(15, 15);
    container.setLayout(bt::GRID);
    container.setGridLayout(3);  // 3 columns
    
    // Add buttons to container
    container.addButton(btn1);
    container.addButton(btn2);
    container.addButton(btn3);
    container.addButton(btn4);
    container.addButton(btn5);
    container.addButton(btn6);
    
    container.arrange();
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
            
            // Toggle layout with 'L' key
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::L) {
                    static int layout = 0;
                    layout = (layout + 1) % 3;
                    if (layout == 0) {
                        container.setLayout(bt::HORIZONTAL);
                        std::cout << "Layout: HORIZONTAL" << std::endl;
                    } else if (layout == 1) {
                        container.setLayout(bt::VERTICAL);
                        std::cout << "Layout: VERTICAL" << std::endl;
                    } else {
                        container.setLayout(bt::GRID);
                        container.setGridLayout(3);
                        std::cout << "Layout: GRID (3 columns)" << std::endl;
                    }
                    container.arrange();
                }
            }
        }
        
        container.updateAll(window);
        
        window.clear(sf::Color(30, 30, 50));
        container.drawAll(window);
        window.display();
    }
}

// ====================================================================
// SECTION 13: COMPLETE GAME MENU EXAMPLE
// ====================================================================

void completeGameMenuExample() {
    std::cout << "\n=== COMPLETE GAME MENU ===\n";
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Complete Game Menu");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    // Create menu buttons
    bt::Button startBtn, optionsBtn, creditsBtn, exitBtn;
    
    // Start Button
    bt::setSize(startBtn, 250, 60);
    bt::setFont(startBtn, font);
    bt::setText(startBtn, "Start Game");
    bt::setTextSize(startBtn, 28);
    bt::setPosition(startBtn, 275, 120);
    bt::setColor(startBtn, bt::Green);
    bt::setColorHover(startBtn, sf::Color(100, 255, 100));
    bt::setColorPressed(startBtn, sf::Color(0, 150, 0));
    bt::setShortcut(startBtn, sf::Keyboard::Enter);
    bt::setTooltip(startBtn, "Start a new game");
    bt::setTooltipFont(startBtn, font);
    
    // Options Button
    bt::setSize(optionsBtn, 250, 60);
    bt::setFont(optionsBtn, font);
    bt::setText(optionsBtn, "Options");
    bt::setTextSize(optionsBtn, 28);
    bt::setPosition(optionsBtn, 275, 210);
    bt::setColor(optionsBtn, sf::Color(255, 200, 0));
    bt::setColorHover(optionsBtn, sf::Color(255, 220, 100));
    bt::setColorPressed(optionsBtn, sf::Color(150, 100, 0));
    bt::setShortcut(optionsBtn, sf::Keyboard::O);
    bt::setTooltip(optionsBtn, "Change game settings");
    bt::setTooltipFont(optionsBtn, font);
    
    // Credits Button
    bt::setSize(creditsBtn, 250, 60);
    bt::setFont(creditsBtn, font);
    bt::setText(creditsBtn, "Credits");
    bt::setTextSize(creditsBtn, 28);
    bt::setPosition(creditsBtn, 275, 300);
    bt::setColor(creditsBtn, sf::Color(50, 200, 255));
    bt::setColorHover(creditsBtn, sf::Color(100, 220, 255));
    bt::setColorPressed(creditsBtn, sf::Color(0, 100, 200));
    bt::setShortcut(creditsBtn, sf::Keyboard::C);
    bt::setTooltip(creditsBtn, "See who made this");
    bt::setTooltipFont(creditsBtn, font);
    
    // Exit Button
    bt::setSize(exitBtn, 250, 60);
    bt::setFont(exitBtn, font);
    bt::setText(exitBtn, "Exit");
    bt::setTextSize(exitBtn, 28);
    bt::setPosition(exitBtn, 275, 390);
    bt::setColor(exitBtn, bt::Red);
    bt::setColorHover(exitBtn, sf::Color(255, 100, 100));
    bt::setColorPressed(exitBtn, sf::Color(150, 0, 0));
    bt::setShortcut(exitBtn, sf::Keyboard::Escape);
    bt::setTooltip(exitBtn, "Quit the game");
    bt::setTooltipFont(exitBtn, font);
    
    // Callbacks
    bt::setOnClick(startBtn, []() {
        std::cout << "🎮 Starting game..." << std::endl;
    });
    
    bt::setOnClick(optionsBtn, []() {
        std::cout << "⚙️ Opening options..." << std::endl;
    });
    
    bt::setOnClick(creditsBtn, []() {
        std::cout << "📝 Credits: Made with bt::Button!" << std::endl;
    });
    
    bt::setOnClick(exitBtn, [&]() {
        std::cout << "👋 Exiting game..." << std::endl;
        window.close();
    });
    
    // Status text
    sf::Text status;
    status.setFont(font);
    status.setCharacterSize(20);
    status.setFillColor(sf::Color::White);
    status.setPosition(300, 500);
    status.setString("Press Enter, O, C, or Escape for shortcuts");
    
    bool running = true;
    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                running = false;
        }
        
        bt::update(startBtn, window);
        bt::update(optionsBtn, window);
        bt::update(creditsBtn, window);
        bt::update(exitBtn, window);
        
        window.clear(sf::Color(30, 30, 50));
        
        // Draw title
        sf::Text title("MAIN MENU", font, 40);
        title.setFillColor(sf::Color::White);
        title.setPosition(300, 40);
        window.draw(title);
        
        bt::draw(window, startBtn);
        bt::draw(window, optionsBtn);
        bt::draw(window, creditsBtn);
        bt::draw(window, exitBtn);
        window.draw(status);
        window.display();
    }
}

// ====================================================================
// SECTION 14: MAIN - RUN ALL EXAMPLES
// ====================================================================

int main() {
    std::cout << "========================================\n";
    std::cout << "   bt::Button - Complete Usage Guide\n";
    std::cout << "========================================\n\n";
    
    std::cout << "Select an example to run:\n";
    std::cout << "1.  Basic Setup\n";
    std::cout << "2.  Colors & Styling\n";
    std::cout << "3.  Shapes\n";
    std::cout << "4.  Grid Layout\n";
    std::cout << "5.  Callbacks\n";
    std::cout << "6.  Toggle Buttons\n";
    std::cout << "7.  Keyboard Shortcuts\n";
    std::cout << "8.  Tooltips\n";
    std::cout << "9.  Icons\n";
    std::cout << "10. Animations\n";
    std::cout << "11. Button Groups\n";
    std::cout << "12. Button Container\n";
    std::cout << "13. Complete Game Menu\n";
    std::cout << "14. Exit\n";
    std::cout << "\nEnter your choice: ";
    
    int choice;
    std::cin >> choice;
    
    switch(choice) {
        case 1:  basicSetupExample(); break;
        case 2:  colorsStylingExample(); break;
        case 3:  shapesExample(); break;
        case 4:  gridLayoutExample(); break;
        case 5:  callbacksExample(); break;
        case 6:  toggleButtonExample(); break;
        case 7:  keyboardShortcutsExample(); break;
        case 8:  tooltipsExample(); break;
        case 9:  iconsExample(); break;
        case 10: animationsExample(); break;
        case 11: buttonGroupsExample(); break;
        case 12: buttonContainerExample(); break;
        case 13: completeGameMenuExample(); break;
        case 14: std::cout << "Goodbye!\n"; break;
        default: std::cout << "Invalid choice!\n";
    }
    
    return 0;
}
