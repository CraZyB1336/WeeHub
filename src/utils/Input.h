#pragma once

class Input{
    public:
        void Update();

        bool IsKeyPressed(SDL_Keycode key) const;
        bool IsKeyJustPressed(SDL_Keycode key) const;
        bool IsKeyReleased(SDL_Keycode key) const;

        Vector GetMousePosition() const;
        bool IsMouseButtonPressed(int button) const;

    private:
        std::unordered_set<SDL_Keycode> currentKeys;
        std::unordered_set<SDL_Keycode> previousKeys;
        Vector2 mousePos;
};