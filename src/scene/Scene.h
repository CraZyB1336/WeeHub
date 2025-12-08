#pragma once

class Scene{
    public:
        virtual ~Scene() = default;

        virtual void OnEnter() = 0;
        virtual void OnExit() = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Render(Renderer& renderer) = 0;
        virtual void HandleInput(const Input& input) = 0;
};

class 