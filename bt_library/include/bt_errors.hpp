#pragma once
#include <string>
#include <exception>
#include <iostream>

namespace bt
{
    class ButtonError : public std::exception
    {
    private:
        std::string message;

    public:
        explicit ButtonError(const std::string &msg) : message(msg) {}
        const char *what() const noexcept override
        {
            return message.c_str();
        }
    };

    class FontError : public ButtonError
    {
    public:
        explicit FontError(const std::string &msg) : ButtonError("Font Error: " + msg) {}
    };

    class ButtonNotFoundError : public ButtonError
    {
    public:
        explicit ButtonNotFoundError(const std::string &msg) : ButtonError("Button Not Found: " + msg) {}
    };

    void logError(const std::string &error)
    {
        std::cerr << "[BT ERROR] " << error << std::endl;
    }

    void logWarning(const std::string &warning)
    {
        std::cerr << "[BT WARNING] " << warning << std::endl;
    }

    void logInfo(const std::string &info)
    {
        std::cout << "[BT INFO] " << info << std::endl;
    }

#ifdef _DEBUG
#define BT_DEBUG(x) std::cout << "[BT DEBUG] " << x << std::endl
#else
#define BT_DEBUG(x)
#endif
}