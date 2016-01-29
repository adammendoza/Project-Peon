#pragma once

class Window
{
    public:
        Window(const int& width, const int& height, const std::string& title);
        ~Window();

        SDL_Window* GetSDLWindow() const;
        void SetSize(const Vector2D& size);
        Vector2D GetSize() const;
        void SetTitle(const std::string& title);
        std::string GetTitle() const;

        int Initialize();

    private:
        SDL_Window* m_SDLWindow;
        Vector2D m_size;
        std::string m_title;
};
