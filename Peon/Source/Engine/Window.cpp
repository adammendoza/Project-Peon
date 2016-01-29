#include "../PCH.hpp"
#include "Window.hpp"

Window::Window(const int& width, const int& height, const std::string& title) :
    m_width(width),
    m_height(height),
    m_title(title)
{
    m_SDLWindow = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN);
    if (m_SDLWindow == nullptr)
    {
        // Tyren Review: you can't fail in a constructor! That is really hard to handle
        // Instead create an Initialize method like you did with game?
        std::cerr << "Window could not be created! SDL error: " << SDL_GetError() << std::endl;
    }
}

Window::~Window()
{
    SDL_DestroyWindow(m_SDLWindow);
}

// Tyren Review: As said earlier, you should try to hide this.
SDL_Window* Window::GetSDLWindow() const
{
    return m_SDLWindow;
}

int Window::GetWidth() const
{
    return m_width;
}

// Tyren Review: Wait, does this work? You never apply this, or the other settings
void Window::SetWidth(const int& width)
{
    m_width = width;
}

int Window::GetHeight() const
{
    return m_height;
}

void Window::SetHeight(const int& height)
{
    m_height = height;
}

std::string Window::GetTitle() const
{
    return m_title;
}

void Window::SetTitle(const std::string& title)
{
    m_title = title;
}
