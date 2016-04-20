#pragma once

namespace grim
{

namespace graphics
{

class SDLWindow : public IWindow
{
public:
    SDLWindow(const uint16_t& width, const uint16_t& height, const std::string& title, bool isFullScreen, bool isOpenGL);
    ~SDLWindow();

    virtual bool Initialize();
    virtual void Terminate();
    virtual void SwapWindow();

    virtual void SetSize(const glm::vec2& size);
    virtual void SetTitle(const std::string& title);
    virtual glm::vec2 GetSize() const;
    virtual std::string GetTitle() const;

private:
    SDL_Window* m_SDLWindow;
    SDL_GLContext m_glContext;
    glm::vec2 m_size;
    std::string m_title;
    bool m_isFullScreen;
    bool m_isOpenGL;
};

}

}