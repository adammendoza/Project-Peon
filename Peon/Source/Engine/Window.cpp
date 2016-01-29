#include "PCH.hpp"
#include "Window.hpp"

Window::Window(const int& width, const int& height, const std::string& title) :
    m_size(Vector2D(width, height)),
    m_title(title)
{
}

Window::~Window()
{
    SDL_DestroyWindow(m_SDLWindow);
}

int Window::Initialize()
{
    m_SDLWindow = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_size.GetX(), m_size.GetY(), SDL_WINDOW_SHOWN);
    if (m_SDLWindow == nullptr)
    {
        SDL_Log("Window could not initialize! SDL error: %s\n", SDL_GetError());
        return FAILURE;
    }

    return SUCCESS;
}

// Tyren Review: As said earlier, you should try to hide this.
// TODO: Figure out how to do this
SDL_Window* Window::GetSDLWindow() const
{
    return m_SDLWindow;
}

void Window::SetSize(const Vector2D& size)
{
    m_size = size;
    SDL_SetWindowSize(m_SDLWindow, size.GetX(), size.GetY());
}

Vector2D Window::GetSize() const
{
    return m_size;
}

std::string Window::GetTitle() const
{
    return m_title;
}

void Window::SetTitle(const std::string& title)
{
    m_title = title;
    SDL_SetWindowTitle(m_SDLWindow, title.c_str());
}
