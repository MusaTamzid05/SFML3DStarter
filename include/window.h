#ifndef WINDOW_H
#define WINDOW_H


namespace sf {
    class Window;
};

#include <string>

struct Entity;

struct Window {
    Window(const std::string& title="Window");
    virtual ~Window();

    void run();

    void handle_event(float delta_time);
    void render();
    void update(float delta_time);


    sf::Window* m_window;
    Entity* m_rect;
    bool m_running;

    bool first_mouse_move;
    float last_mouse_x;
    float last_mouse_y;


};

#endif
