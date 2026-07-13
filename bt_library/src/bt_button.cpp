#include "bt_button.hpp"
#include <cmath>
#include <iostream>

namespace bt
{

    // ==================== BASIC FUNCTIONS ====================

    void setColor(Button &btn, sf::Color color)
    {
        btn.normalColor = color;
        if (!btn.disabled)
        {
            btn.shape.setFillColor(btn.normalColor);
            if (btn.currentShape == CIRCLE)
            {
                btn.circleShape.setFillColor(btn.normalColor);
            }
            if (btn.currentShape == TRIANGLE)
            {
                btn.triangleShape.setFillColor(btn.normalColor);
            }
        }
        btn.shadow.setFillColor(btn.shadowColor);
    }

    void setColorPressed(Button &btn, sf::Color color)
    {
        btn.pressedColor = color;
    }

    void setColorHover(Button &btn, sf::Color color)
    {
        btn.hoverColor = color;
    }

    void setDisabledColor(Button &btn, sf::Color color)
    {
        btn.disabledColor = color;
    }

    void setTextColor(Button &btn, sf::Color color)
    {
        btn.textNormalColor = color;
        btn.text.setFillColor(btn.textNormalColor);
    }

    void setTextColorHover(Button &btn, sf::Color color)
    {
        btn.textHoverColor = color;
    }

    void setTextColorPressed(Button &btn, sf::Color color)
    {
        btn.textPressedColor = color;
    }

    void setOpacity(Button &btn, float opacity)
    {
        btn.opacity = std::max(0.0f, std::min(1.0f, opacity));
        sf::Color color = btn.shape.getFillColor();
        color.a = static_cast<sf::Uint8>(btn.opacity * 255);
        btn.shape.setFillColor(color);
        btn.shadow.setFillColor(sf::Color(40, 40, 40, static_cast<sf::Uint8>(btn.opacity * 180)));
    }

    void setSize(Button &btn, float width, float height)
    {
        btn.size = sf::Vector2f(width, height);
        btn.shape.setSize(sf::Vector2f(width, height));
        btn.shadow.setSize(sf::Vector2f(width, height));
        btn.circleShape.setRadius(std::min(width, height) / 2.0f);
        btn.triangleShape.setPointCount(3);
        btn.triangleShape.setPoint(0, sf::Vector2f(width / 2, 0));
        btn.triangleShape.setPoint(1, sf::Vector2f(0, height));
        btn.triangleShape.setPoint(2, sf::Vector2f(width, height));
    }

    void setPosition(Button &btn, float x, float y)
    {
        btn.basePosition = sf::Vector2f(x, y);
        btn.shape.setPosition(x, y);
        btn.shadow.setPosition(x + btn.shadowOffset.x, y + btn.shadowOffset.y);
        btn.circleShape.setPosition(x, y);
        btn.triangleShape.setPosition(x, y);

        sf::FloatRect textRect = btn.text.getLocalBounds();
        btn.text.setOrigin(textRect.left + textRect.width / 2.0f,
                           textRect.top + textRect.height / 2.0f);
        btn.text.setPosition(x + btn.size.x / 2.0f, y + btn.size.y / 2.0f);

        if (btn.hasIcon)
        {
            btn.icon.setPosition(x + btn.iconPosition.x, y + btn.iconPosition.y);
        }
    }

    void setPositionCentered(Button &btn, const sf::RenderWindow &window)
    {
        sf::Vector2u windowSize = window.getSize();
        float x = (windowSize.x - btn.size.x) / 2.0f;
        float y = (windowSize.y - btn.size.y) / 2.0f;
        setPosition(btn, x, y);
    }

    void setPositionCentered(Button &btn, float x, float y)
    {
        float posX = x - btn.size.x / 2.0f;
        float posY = y - btn.size.y / 2.0f;
        setPosition(btn, posX, posY);
    }

    void setPadding(Button &btn, float padding)
    {
        btn.padding = padding;
    }

    void autoSize(Button &btn)
    {
        if (!btn.hasFont)
            return;
        sf::FloatRect textRect = btn.text.getLocalBounds();
        float width = textRect.width + btn.padding * 2;
        float height = textRect.height + btn.padding * 2;
        setSize(btn, width, height);
    }

    void setShape(Button &btn, ButtonShape shape)
    {
        btn.currentShape = shape;
    }

    void setCornerRadius(Button &btn, float radius)
    {
        btn.cornerRadius = radius;
        // Note: sf::RectangleShape doesn't support rounded corners natively
    }

    void setOutline(Button &btn, float thickness, sf::Color color)
    {
        btn.outlineThickness = thickness;
        btn.outlineColor = color;
        btn.shape.setOutlineThickness(thickness);
        btn.shape.setOutlineColor(color);
    }

    void setOutlineHover(Button &btn, float thickness, sf::Color color)
    {
        btn.outlineHoverColor = color;
    }

    void setOutlinePressed(Button &btn, float thickness, sf::Color color)
    {
        btn.outlinePressedColor = color;
    }

    void setShadowOffset(Button &btn, float x, float y)
    {
        btn.shadowOffset = sf::Vector2f(x, y);
        btn.shadow.setPosition(btn.basePosition.x + x, btn.basePosition.y + y);
    }

    void setShadowColor(Button &btn, sf::Color color)
    {
        btn.shadowColor = color;
        btn.shadow.setFillColor(color);
    }

    void setShadowEnabled(Button &btn, bool enabled)
    {
        btn.shadowEnabled = enabled;
    }

    void setFont(Button &btn, const sf::Font &font)
    {
        btn.text.setFont(font);
        btn.hasFont = true;
        btn.text.setCharacterSize(btn.textSize);
        btn.text.setFillColor(btn.textNormalColor);
    }

    void setText(Button &btn, const std::string &str)
    {
        if (!btn.hasFont)
        {
            throw ButtonError("Attempted to set text without loading a font first.");
        }
        btn.text.setString(str);
        setPosition(btn, btn.basePosition.x, btn.basePosition.y);
    }

    void setTextSize(Button &btn, unsigned int size)
    {
        btn.textSize = size;
        btn.text.setCharacterSize(size);
        setPosition(btn, btn.basePosition.x, btn.basePosition.y);
    }

    void setTextStyle(Button &btn, sf::Text::Style style)
    {
        btn.text.setStyle(style);
    }

    void setTextPadding(Button &btn, float padding)
    {
        btn.padding = padding;
    }

    // ==================== GRID FUNCTIONS ====================

    void setGrid(Button &btn, int rows, int cols, float spacingX, float spacingY)
    {
        btn.useGrid = true;
        btn.gridRows = rows;
        btn.gridCols = cols;
        btn.gridSpacingX = spacingX;
        btn.gridSpacingY = spacingY;
        btn.gridStartX = 0;
        btn.gridStartY = 0;
    }

    void setGrid(Button &btn, int rows, int cols, float spacingX, float spacingY, float startX, float startY)
    {
        btn.useGrid = true;
        btn.gridRows = rows;
        btn.gridCols = cols;
        btn.gridSpacingX = spacingX;
        btn.gridSpacingY = spacingY;
        btn.gridStartX = startX;
        btn.gridStartY = startY;
    }

    void setGridPosition(Button &btn, int row, int col)
    {
        if (!btn.useGrid)
            return;

        float x = btn.gridStartX + col * (btn.size.x + btn.gridSpacingX);
        float y = btn.gridStartY + row * (btn.size.y + btn.gridSpacingY);
        bt::setPosition(btn, x, y);
    }

    void setRow(Button &btn, int index, int total, float spacing)
    {
        float width = btn.size.x;
        float totalWidth = total * width + (total - 1) * spacing;
        float startX = btn.basePosition.x - totalWidth / 2.0f + index * (width + spacing);
        bt::setPosition(btn, startX, btn.basePosition.y);
    }

    void setColumn(Button &btn, int index, int total, float spacing)
    {
        float height = btn.size.y;
        float totalHeight = total * height + (total - 1) * spacing;
        float startY = btn.basePosition.y - totalHeight / 2.0f + index * (height + spacing);
        bt::setPosition(btn, btn.basePosition.x, startY);
    }

    // ==================== INTERACTIVE FUNCTIONS ====================

    void setDisabled(Button &btn, bool disabled)
    {
        btn.disabled = disabled;
        if (disabled)
        {
            btn.shape.setFillColor(btn.disabledColor);
            btn.text.setFillColor(sf::Color(100, 100, 100));
        }
        else
        {
            btn.shape.setFillColor(btn.normalColor);
            btn.text.setFillColor(btn.textNormalColor);
        }
    }

    bool isDisabled(const Button &btn)
    {
        return btn.disabled;
    }

    void setToggle(Button &btn, bool enabled)
    {
        btn.toggleEnabled = true;
        btn.toggled = enabled;
    }

    bool isToggled(const Button &btn)
    {
        return btn.toggled;
    }

    void toggle(Button &btn)
    {
        if (!btn.toggleEnabled)
            return;
        btn.toggled = !btn.toggled;
        if (btn.onToggle)
        {
            btn.onToggle();
        }
    }

    bool ButtonIsPressed(Button &btn)
    {
        if (btn.simulatedPress)
        {
            btn.simulatedPress = false;
            return true;
        }
        return btn.isPressed && !btn.wasPressed;
    }

    void ButtonPress(Button &btn)
    {
        btn.simulatedPress = true;
    }

    bool ButtonIsHovered(const Button &btn)
    {
        return btn.isHovered;
    }

    void setOnClick(Button &btn, std::function<void()> callback)
    {
        btn.onClick = callback;
    }

    void setOnHover(Button &btn, std::function<void()> callback)
    {
        btn.onHover = callback;
    }

    void setOnPress(Button &btn, std::function<void()> callback)
    {
        btn.onPress = callback;
    }

    void setOnRelease(Button &btn, std::function<void()> callback)
    {
        btn.onRelease = callback;
    }

    void setOnToggle(Button &btn, std::function<void()> callback)
    {
        btn.onToggle = callback;
    }

    void setShortcut(Button &btn, sf::Keyboard::Key key)
    {
        btn.shortcutKey = key;
        btn.shortcutCtrl = false;
        btn.shortcutShift = false;
        btn.shortcutAlt = false;
    }

    void setShortcut(Button &btn, sf::Keyboard::Key key, bool ctrl, bool shift, bool alt)
    {
        btn.shortcutKey = key;
        btn.shortcutCtrl = ctrl;
        btn.shortcutShift = shift;
        btn.shortcutAlt = alt;
    }

    void setShortcutKey(Button &btn, sf::Keyboard::Key key)
    {
        btn.shortcutKey = key;
    }

    bool checkShortcut(const Button &btn)
    {
        if (btn.shortcutKey == sf::Keyboard::Unknown)
            return false;
        if (!sf::Keyboard::isKeyPressed(btn.shortcutKey))
            return false;

        bool ctrl = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
                    sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
        bool shift = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
        bool alt = sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) ||
                   sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt);

        if (btn.shortcutCtrl && !ctrl)
            return false;
        if (btn.shortcutShift && !shift)
            return false;
        if (btn.shortcutAlt && !alt)
            return false;

        return true;
    }

    // ==================== TOOLTIP FUNCTIONS ====================

    void setTooltip(Button &btn, const std::string &text)
    {
        btn.tooltipText = text;
        btn.tooltip.setString(text);
        btn.hasTooltip = true;
    }

    void setTooltipFont(Button &btn, const sf::Font &font)
    {
        btn.tooltip.setFont(font);
    }

    void setTooltipColor(Button &btn, sf::Color color)
    {
        btn.tooltip.setFillColor(color);
    }

    void setTooltipSize(Button &btn, unsigned int size)
    {
        btn.tooltip.setCharacterSize(size);
    }

    // ==================== ICON FUNCTIONS ====================

    void setIcon(Button &btn, const sf::Texture &texture)
    {
        btn.icon.setTexture(texture);
        btn.hasIcon = true;
        sf::FloatRect bounds = btn.icon.getLocalBounds();
        btn.iconSize = sf::Vector2f(bounds.width, bounds.height);
        btn.iconPosition = sf::Vector2f(10.0f, (btn.size.y - bounds.height) / 2.0f);
        btn.icon.setPosition(btn.basePosition.x + btn.iconPosition.x,
                             btn.basePosition.y + btn.iconPosition.y);
    }

    void setIcon(Button &btn, const sf::Texture &texture, float width, float height)
    {
        btn.icon.setTexture(texture);
        btn.hasIcon = true;
        btn.iconSize = sf::Vector2f(width, height);
        btn.icon.setScale(width / btn.icon.getLocalBounds().width,
                          height / btn.icon.getLocalBounds().height);
        btn.iconPosition = sf::Vector2f(10.0f, (btn.size.y - height) / 2.0f);
        btn.icon.setPosition(btn.basePosition.x + btn.iconPosition.x,
                             btn.basePosition.y + btn.iconPosition.y);
    }

    void setIconPosition(Button &btn, float x, float y)
    {
        btn.iconPosition = sf::Vector2f(x, y);
        btn.icon.setPosition(btn.basePosition.x + x, btn.basePosition.y + y);
    }

    void setIconSize(Button &btn, float width, float height)
    {
        btn.iconSize = sf::Vector2f(width, height);
        btn.icon.setScale(width / btn.icon.getLocalBounds().width,
                          height / btn.icon.getLocalBounds().height);
    }

    void setIconColor(Button &btn, sf::Color color)
    {
        btn.icon.setColor(color);
    }

    // ==================== ANIMATION FUNCTIONS ====================

    void setAnimation(Button &btn, AnimationType type, float duration)
    {
        btn.currentAnimation = type;
        btn.animationDuration = duration;
        btn.animationTimer = 0.0f;
        btn.animating = true;
        btn.animationProgress = 0.0f;
    }

    void setAnimationDuration(Button &btn, float duration)
    {
        btn.animationDuration = duration;
    }

    void playAnimation(Button &btn, AnimationType type)
    {
        btn.currentAnimation = type;
        btn.animationTimer = 0.0f;
        btn.animating = true;
        btn.animationProgress = 0.0f;
    }

    void stopAnimation(Button &btn)
    {
        btn.animating = false;
        btn.animationProgress = 0.0f;
        btn.animationTimer = 0.0f;
    }

    void resetAnimation(Button &btn)
    {
        btn.animationProgress = 0.0f;
        btn.animationTimer = 0.0f;
    }

    bool isAnimating(const Button &btn)
    {
        return btn.animating;
    }

    // ==================== UPDATE & DRAW ====================

    void update(Button &btn, const sf::RenderWindow &window)
    {
        update(btn, window, 0.016f);
    }

    void update(Button &btn, const sf::RenderWindow &window, float deltaTime)
    {
        if (btn.disabled)
            return;

        if (checkShortcut(btn))
        {
            ButtonPress(btn);
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x),
                               static_cast<float>(mousePos.y));

        sf::FloatRect bounds(btn.basePosition, btn.size);
        btn.isHovered = bounds.contains(mousePosF);

        btn.wasPressed = btn.isPressed;

        if (btn.animating)
        {
            btn.animationTimer += deltaTime;
            btn.animationProgress = std::min(1.0f, btn.animationTimer / btn.animationDuration);

            if (btn.animationProgress >= 1.0f)
            {
                btn.animating = false;
                btn.animationProgress = 1.0f;
            }
        }

        if (btn.animating)
        {
            float scale = 1.0f;
            float progress = btn.animationProgress;

            switch (btn.currentAnimation)
            {
            case BOUNCE:
                scale = 1.0f + 0.1f * std::sin(progress * 3.14159f * 4) * (1.0f - progress);
                break;
            case PULSE:
                scale = 1.0f + 0.05f * std::sin(progress * 3.14159f * 4);
                break;
            case FADE_IN:
                setOpacity(btn, progress);
                break;
            case FADE_OUT:
                setOpacity(btn, 1.0f - progress);
                break;
            default:
                break;
            }

            if (btn.currentAnimation == BOUNCE || btn.currentAnimation == PULSE)
            {
                btn.shape.setScale(scale, scale);
                btn.text.setScale(scale, scale);
            }
        }
        else
        {
            btn.shape.setScale(1.0f, 1.0f);
            btn.text.setScale(1.0f, 1.0f);
        }

        if (btn.isHovered || btn.simulatedPress)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || btn.simulatedPress)
            {
                btn.shape.setFillColor(btn.pressedColor);
                btn.shape.setOutlineColor(btn.outlinePressedColor);
                btn.text.setFillColor(btn.textPressedColor);
                btn.shape.setPosition(btn.basePosition.x + 4.0f, btn.basePosition.y + 4.0f);
                btn.shadow.setPosition(btn.basePosition.x + 4.0f + btn.shadowOffset.x,
                                       btn.basePosition.y + 4.0f + btn.shadowOffset.y);
                btn.text.setPosition(btn.basePosition.x + 4.0f + btn.size.x / 2.0f,
                                     btn.basePosition.y + 4.0f + btn.size.y / 2.0f);
                if (btn.hasIcon)
                {
                    btn.icon.setPosition(btn.basePosition.x + 4.0f + btn.iconPosition.x,
                                         btn.basePosition.y + 4.0f + btn.iconPosition.y);
                }
                btn.isPressed = true;
                if (btn.onPress && !btn.wasPressed)
                {
                    btn.onPress();
                }
            }
            else
            {
                btn.shape.setFillColor(btn.hoverColor);
                btn.shape.setOutlineColor(btn.outlineHoverColor);
                btn.text.setFillColor(btn.textHoverColor);
                btn.shape.setPosition(btn.basePosition.x, btn.basePosition.y);
                btn.shadow.setPosition(btn.basePosition.x + btn.shadowOffset.x,
                                       btn.basePosition.y + btn.shadowOffset.y);
                btn.text.setPosition(btn.basePosition.x + btn.size.x / 2.0f,
                                     btn.basePosition.y + btn.size.y / 2.0f);
                if (btn.hasIcon)
                {
                    btn.icon.setPosition(btn.basePosition.x + btn.iconPosition.x,
                                         btn.basePosition.y + btn.iconPosition.y);
                }
                btn.isPressed = false;
                if (btn.onHover && !btn.wasPressed)
                {
                    btn.onHover();
                }
            }
        }
        else
        {
            btn.shape.setFillColor(btn.normalColor);
            btn.shape.setOutlineColor(btn.outlineColor);
            btn.text.setFillColor(btn.textNormalColor);
            btn.shape.setPosition(btn.basePosition.x, btn.basePosition.y);
            btn.shadow.setPosition(btn.basePosition.x + btn.shadowOffset.x,
                                   btn.basePosition.y + btn.shadowOffset.y);
            btn.text.setPosition(btn.basePosition.x + btn.size.x / 2.0f,
                                 btn.basePosition.y + btn.size.y / 2.0f);
            if (btn.hasIcon)
            {
                btn.icon.setPosition(btn.basePosition.x + btn.iconPosition.x,
                                     btn.basePosition.y + btn.iconPosition.y);
            }
            btn.isPressed = false;
        }

        if (btn.isPressed && !btn.wasPressed)
        {
            if (btn.toggleEnabled)
            {
                toggle(btn);
            }
            if (btn.onClick)
            {
                btn.onClick();
            }
        }

        if (!btn.isPressed && btn.wasPressed)
        {
            if (btn.onRelease)
            {
                btn.onRelease();
            }
        }
    }

    void draw(sf::RenderWindow &window, const Button &btn)
    {
        if (btn.shadowEnabled)
        {
            window.draw(btn.shadow);
        }

        switch (btn.currentShape)
        {
        case RECTANGLE:
            window.draw(btn.shape);
            break;
        case CIRCLE:
            window.draw(btn.circleShape);
            break;
        case ROUNDED:
            window.draw(btn.shape);
            break;
        case TRIANGLE:
            window.draw(btn.triangleShape);
            break;
        }

        if (btn.hasIcon)
        {
            window.draw(btn.icon);
        }

        if (btn.hasFont && !btn.text.getString().isEmpty())
        {
            window.draw(btn.text);
        }

        if (btn.hasTooltip && btn.isHovered && !btn.isPressed)
        {
            window.draw(btn.tooltip);
        }

        if (btn.debugMode)
        {
            drawDebug(window, btn);
        }
    }

    void drawDebug(sf::RenderWindow &window, const Button &btn)
    {
        sf::RectangleShape debugRect(btn.size);
        debugRect.setPosition(btn.basePosition);
        debugRect.setFillColor(sf::Color::Transparent);
        debugRect.setOutlineThickness(1);
        debugRect.setOutlineColor(sf::Color::Red);
        window.draw(debugRect);
    }

    // ==================== UTILITY FUNCTIONS ====================

    void setDebugMode(Button &btn, bool enabled)
    {
        btn.debugMode = enabled;
    }

    bool isPointInButton(const Button &btn, sf::Vector2f point)
    {
        sf::FloatRect bounds(btn.basePosition, btn.size);
        return bounds.contains(point);
    }

    sf::FloatRect getGlobalBounds(const Button &btn)
    {
        return sf::FloatRect(btn.basePosition, btn.size);
    }

    sf::Vector2f getCenter(const Button &btn)
    {
        return sf::Vector2f(btn.basePosition.x + btn.size.x / 2.0f,
                            btn.basePosition.y + btn.size.y / 2.0f);
    }

    // ==================== BUTTON GROUP ====================

    void ButtonGroup::addButton(Button &btn)
    {
        buttons.push_back(&btn);
        if (selectedIndex == -1)
        {
            selectedIndex = 0;
        }
    }

    void ButtonGroup::removeButton(Button &btn)
    {
        for (size_t i = 0; i < buttons.size(); ++i)
        {
            if (buttons[i] == &btn)
            {
                buttons.erase(buttons.begin() + i);
                if (selectedIndex == (int)i)
                {
                    selectedIndex = -1;
                }
                break;
            }
        }
    }

    void ButtonGroup::clear()
    {
        buttons.clear();
        selectedIndex = -1;
    }

    void ButtonGroup::selectButton(int index)
    {
        if (index >= 0 && index < (int)buttons.size())
        {
            selectedIndex = index;
        }
    }

    void ButtonGroup::selectButton(Button &btn)
    {
        for (size_t i = 0; i < buttons.size(); ++i)
        {
            if (buttons[i] == &btn)
            {
                selectedIndex = i;
                break;
            }
        }
    }

    int ButtonGroup::getSelectedIndex() const
    {
        return selectedIndex;
    }

    Button *ButtonGroup::getSelectedButton() const
    {
        if (selectedIndex >= 0 && selectedIndex < (int)buttons.size())
        {
            return buttons[selectedIndex];
        }
        return nullptr;
    }

    size_t ButtonGroup::getButtonCount() const
    {
        return buttons.size();
    }

    void ButtonGroup::updateAll(const sf::RenderWindow &window)
    {
        for (Button *btn : buttons)
        {
            update(*btn, window);
        }
    }

    void ButtonGroup::drawAll(sf::RenderWindow &window)
    {
        for (Button *btn : buttons)
        {
            draw(window, *btn);
        }
    }

    // ==================== BUTTON CONTAINER ====================

    void ButtonContainer::addButton(Button &btn)
    {
        buttons.push_back(&btn);
        if (autoArrange)
        {
            arrange();
        }
    }

    void ButtonContainer::removeButton(Button &btn)
    {
        for (size_t i = 0; i < buttons.size(); ++i)
        {
            if (buttons[i] == &btn)
            {
                buttons.erase(buttons.begin() + i);
                break;
            }
        }
        if (autoArrange)
        {
            arrange();
        }
    }

    void ButtonContainer::clear()
    {
        buttons.clear();
    }

    void ButtonContainer::setSpacing(float horizontal, float vertical)
    {
        horizontalSpacing = horizontal;
        verticalSpacing = vertical;
        if (autoArrange)
        {
            arrange();
        }
    }

    void ButtonContainer::setAlignment(Alignment horizontal, Alignment vertical)
    {
        horizontalAlignment = horizontal;
        verticalAlignment = vertical;
        if (autoArrange)
        {
            arrange();
        }
    }

    void ButtonContainer::setPosition(float x, float y)
    {
        position = sf::Vector2f(x, y);
        if (autoArrange)
        {
            arrange();
        }
    }

    void ButtonContainer::setSize(float width, float height)
    {
        size = sf::Vector2f(width, height);
        if (autoArrange)
        {
            arrange();
        }
    }

    void ButtonContainer::setLayout(LayoutDirection dir)
    {
        layoutDirection = dir;
        if (autoArrange)
        {
            arrange();
        }
    }

    void ButtonContainer::setGridLayout(int cols)
    {
        gridCols = cols;
        layoutDirection = GRID;
        if (autoArrange)
        {
            arrange();
        }
    }

    void ButtonContainer::arrange()
    {
        if (buttons.empty())
            return;

        float currentX = position.x;
        float currentY = position.y;

        if (layoutDirection == HORIZONTAL)
        {
            for (Button *btn : buttons)
            {
                bt::setPosition(*btn, currentX, currentY);
                currentX += btn->size.x + horizontalSpacing;
            }
        }
        else if (layoutDirection == VERTICAL)
        {
            for (Button *btn : buttons)
            {
                bt::setPosition(*btn, currentX, currentY);
                currentY += btn->size.y + verticalSpacing;
            }
        }
        else if (layoutDirection == GRID)
        {
            int col = 0, row = 0;
            for (Button *btn : buttons)
            {
                float x = position.x + col * (btn->size.x + horizontalSpacing);
                float y = position.y + row * (btn->size.y + verticalSpacing);
                bt::setPosition(*btn, x, y);
                col++;
                if (col >= gridCols)
                {
                    col = 0;
                    row++;
                }
            }
        }
    }

    void ButtonContainer::updateAll(const sf::RenderWindow &window)
    {
        for (Button *btn : buttons)
        {
            update(*btn, window);
        }
    }

    void ButtonContainer::drawAll(sf::RenderWindow &window)
    {
        for (Button *btn : buttons)
        {
            draw(window, *btn);
        }
    }

    size_t ButtonContainer::getButtonCount() const
    {
        return buttons.size();
    }

    void ButtonContainer::setAutoArrange(bool enabled)
    {
        autoArrange = enabled;
        if (enabled)
        {
            arrange();
        }
    }

} // namespace bt