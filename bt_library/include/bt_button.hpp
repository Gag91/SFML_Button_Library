#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>
#include <functional>
#include <vector>

namespace bt
{

    // ==================== ERRORS ====================
    class ButtonError : public std::runtime_error
    {
    public:
        explicit ButtonError(const std::string &message) : std::runtime_error("Button Error: " + message) {}
    };

    // ==================== ENUMS ====================
    enum ButtonShape
    {
        RECTANGLE,
        CIRCLE,
        ROUNDED,
        TRIANGLE
    };

    enum LayoutDirection
    {
        HORIZONTAL,
        VERTICAL,
        GRID
    };

    enum GradientDirection
    {
        GRADIENT_VERTICAL,
        GRADIENT_HORIZONTAL,
        GRADIENT_DIAGONAL
    };

    enum AnimationType
    {
        FADE_IN,
        FADE_OUT,
        SLIDE_IN,
        SLIDE_OUT,
        BOUNCE,
        PULSE,
        SHAKE
    };

    enum Alignment
    {
        ALIGN_LEFT,
        ALIGN_CENTER,
        ALIGN_RIGHT,
        ALIGN_TOP,
        ALIGN_BOTTOM
    };

    // ==================== COLORS ====================
    const sf::Color Blue = sf::Color::Blue;
    const sf::Color Red = sf::Color::Red;
    const sf::Color Black = sf::Color::Black;
    const sf::Color White = sf::Color::White;
    const sf::Color Green = sf::Color::Green;
    const sf::Color Yellow = sf::Color::Yellow;
    const sf::Color Cyan = sf::Color::Cyan;
    const sf::Color Magenta = sf::Color::Magenta;

    // ==================== BUTTON STRUCT ====================
    struct Button
    {
        // ===== Shape =====
        sf::RectangleShape shape;
        sf::RectangleShape shadow;
        sf::CircleShape circleShape;
        sf::ConvexShape triangleShape;
        ButtonShape currentShape = RECTANGLE;

        // ===== Text =====
        sf::Text text;
        bool hasFont = false;
        unsigned int textSize = 30;
        sf::Color textColor = sf::Color::Black;

        // ===== Colors =====
        sf::Color normalColor = White;
        sf::Color hoverColor = White;
        sf::Color pressedColor = White;
        sf::Color disabledColor = sf::Color(150, 150, 150);
        sf::Color textNormalColor = sf::Color::Black;
        sf::Color textHoverColor = sf::Color::Black;
        sf::Color textPressedColor = sf::Color::Black;

        // ===== Position & Size =====
        sf::Vector2f basePosition;
        sf::Vector2f size;
        float cornerRadius = 10.0f;
        float padding = 10.0f;

        // ===== Shadow =====
        sf::Vector2f shadowOffset = sf::Vector2f(6.0f, 6.0f);
        sf::Color shadowColor = sf::Color(40, 40, 40, 180);
        bool shadowEnabled = true;

        // ===== Outline =====
        float outlineThickness = 0.0f;
        sf::Color outlineColor = sf::Color::Black;
        sf::Color outlineHoverColor = sf::Color::Black;
        sf::Color outlinePressedColor = sf::Color::Black;

        // ===== State =====
        bool isPressed = false;
        bool wasPressed = false;
        bool simulatedPress = false;
        bool isHovered = false;
        bool disabled = false;
        bool toggled = false;
        bool toggleEnabled = false;

        // ===== Opacity =====
        float opacity = 1.0f;

        // ===== Animation =====
        float animationDuration = 0.3f;
        float animationTimer = 0.0f;
        AnimationType currentAnimation = FADE_IN;
        bool animating = false;
        float animationProgress = 0.0f;

        // ===== Callbacks =====
        std::function<void()> onClick;
        std::function<void()> onHover;
        std::function<void()> onPress;
        std::function<void()> onRelease;
        std::function<void()> onToggle;

        // ===== Keyboard Shortcut =====
        sf::Keyboard::Key shortcutKey = sf::Keyboard::Unknown;
        bool shortcutCtrl = false;
        bool shortcutShift = false;
        bool shortcutAlt = false;

        // ===== Tooltip =====
        std::string tooltipText;
        sf::Text tooltip;
        bool hasTooltip = false;

        // ===== Icon =====
        sf::Sprite icon;
        bool hasIcon = false;
        sf::Vector2f iconPosition;
        sf::Vector2f iconSize;

        // ===== Debug =====
        bool debugMode = false;

        // ===== GRID LAYOUT SETTINGS =====
        bool useGrid = false;
        int gridRows = 1;
        int gridCols = 1;
        int gridRow = 0;
        int gridCol = 0;
        float gridSpacingX = 10.0f;
        float gridSpacingY = 10.0f;
        float gridStartX = 0.0f;
        float gridStartY = 0.0f;
    };

    // ==================== BASIC FUNCTIONS ====================

    // Color Functions
    void setColor(Button &btn, sf::Color color);
    void setColorPressed(Button &btn, sf::Color color);
    void setColorHover(Button &btn, sf::Color color);
    void setDisabledColor(Button &btn, sf::Color color);
    void setTextColor(Button &btn, sf::Color color);
    void setTextColorHover(Button &btn, sf::Color color);
    void setTextColorPressed(Button &btn, sf::Color color);
    void setOpacity(Button &btn, float opacity);

    // Size & Position
    void setSize(Button &btn, float width, float height);
    void setPosition(Button &btn, float x, float y);
    void setPositionCentered(Button &btn, const sf::RenderWindow &window);
    void setPositionCentered(Button &btn, float x, float y);
    void setPadding(Button &btn, float padding);
    void autoSize(Button &btn);

    // Shape Functions
    void setShape(Button &btn, ButtonShape shape);
    void setCornerRadius(Button &btn, float radius);
    void setOutline(Button &btn, float thickness, sf::Color color);
    void setOutlineHover(Button &btn, float thickness, sf::Color color);
    void setOutlinePressed(Button &btn, float thickness, sf::Color color);

    // Shadow Functions
    void setShadowOffset(Button &btn, float x, float y);
    void setShadowColor(Button &btn, sf::Color color);
    void setShadowEnabled(Button &btn, bool enabled);

    // Text Functions
    void setFont(Button &btn, const sf::Font &font);
    void setText(Button &btn, const std::string &str);
    void setTextSize(Button &btn, unsigned int size);
    void setTextStyle(Button &btn, sf::Text::Style style);
    void setTextPadding(Button &btn, float padding);

    // Grid Layout Functions
    void setGrid(Button &btn, int rows, int cols, float spacingX = 10, float spacingY = 10);
    void setGrid(Button &btn, int rows, int cols, float spacingX, float spacingY, float startX, float startY);
    void setGridPosition(Button &btn, int row, int col);
    void setRow(Button &btn, int index, int total, float spacing = 10);
    void setColumn(Button &btn, int index, int total, float spacing = 10);

    // ==================== INTERACTIVE FUNCTIONS ====================

    // State Functions
    void setDisabled(Button &btn, bool disabled);
    bool isDisabled(const Button &btn);
    void setToggle(Button &btn, bool enabled);
    bool isToggled(const Button &btn);
    void toggle(Button &btn);
    bool ButtonIsPressed(Button &btn);
    void ButtonPress(Button &btn);
    bool ButtonIsHovered(const Button &btn);

    // Callback Functions
    void setOnClick(Button &btn, std::function<void()> callback);
    void setOnHover(Button &btn, std::function<void()> callback);
    void setOnPress(Button &btn, std::function<void()> callback);
    void setOnRelease(Button &btn, std::function<void()> callback);
    void setOnToggle(Button &btn, std::function<void()> callback);

    // Keyboard Shortcuts
    void setShortcut(Button &btn, sf::Keyboard::Key key);
    void setShortcut(Button &btn, sf::Keyboard::Key key, bool ctrl, bool shift, bool alt);
    void setShortcutKey(Button &btn, sf::Keyboard::Key key);
    bool checkShortcut(const Button &btn);

    // ==================== TOOLTIP FUNCTIONS ====================
    void setTooltip(Button &btn, const std::string &text);
    void setTooltipFont(Button &btn, const sf::Font &font);
    void setTooltipColor(Button &btn, sf::Color color);
    void setTooltipSize(Button &btn, unsigned int size);

    // ==================== ICON FUNCTIONS ====================
    void setIcon(Button &btn, const sf::Texture &texture);
    void setIcon(Button &btn, const sf::Texture &texture, float width, float height);
    void setIconPosition(Button &btn, float x, float y);
    void setIconSize(Button &btn, float width, float height);
    void setIconColor(Button &btn, sf::Color color);

    // ==================== ANIMATION FUNCTIONS ====================
    void setAnimation(Button &btn, AnimationType type, float duration);
    void setAnimationDuration(Button &btn, float duration);
    void playAnimation(Button &btn, AnimationType type);
    void stopAnimation(Button &btn);
    void resetAnimation(Button &btn);
    bool isAnimating(const Button &btn);

    // ==================== UPDATE & DRAW ====================
    void update(Button &btn, const sf::RenderWindow &window);
    void update(Button &btn, const sf::RenderWindow &window, float deltaTime);
    void draw(sf::RenderWindow &window, const Button &btn);
    void drawDebug(sf::RenderWindow &window, const Button &btn);

    // ==================== UTILITY FUNCTIONS ====================
    void setDebugMode(Button &btn, bool enabled);
    bool isPointInButton(const Button &btn, sf::Vector2f point);
    sf::FloatRect getGlobalBounds(const Button &btn);
    sf::Vector2f getCenter(const Button &btn);

    // ==================== BUTTON GROUP ====================
    class ButtonGroup
    {
    private:
        std::vector<Button *> buttons;
        int selectedIndex = -1;

    public:
        void addButton(Button &btn);
        void removeButton(Button &btn);
        void clear();
        void selectButton(int index);
        void selectButton(Button &btn);
        int getSelectedIndex() const;
        Button *getSelectedButton() const;
        size_t getButtonCount() const;
        void updateAll(const sf::RenderWindow &window);
        void drawAll(sf::RenderWindow &window);
    };

    // ==================== BUTTON CONTAINER ====================
    class ButtonContainer
    {
    private:
        std::vector<Button *> buttons;
        Alignment horizontalAlignment = ALIGN_CENTER;
        Alignment verticalAlignment = ALIGN_CENTER;
        float horizontalSpacing = 20.0f;
        float verticalSpacing = 20.0f;
        sf::Vector2f position;
        sf::Vector2f size;
        bool autoArrange = true;

        // Layout settings
        LayoutDirection layoutDirection = HORIZONTAL;
        int gridCols = 2;

    public:
        void addButton(Button &btn);
        void removeButton(Button &btn);
        void clear();
        void setSpacing(float horizontal, float vertical);
        void setAlignment(Alignment horizontal, Alignment vertical);
        void setPosition(float x, float y);
        void setSize(float width, float height);
        void arrange();
        void updateAll(const sf::RenderWindow &window);
        void drawAll(sf::RenderWindow &window);
        size_t getButtonCount() const;
        void setAutoArrange(bool enabled);

        // New layout methods
        void setLayout(LayoutDirection dir);
        void setGridLayout(int cols);
    };

} // namespace bt