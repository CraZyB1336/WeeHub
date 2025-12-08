#pragma once

struct ChannelData{
    std::string id;
    std::string title;
    std::string texturePath;
    // Could be function pointer or command pattern
    std::function<void()> onActivate;
};

class Channel {
    public:
        Channel(const ChannelData& data, int gridX, int gridY);

        void Update(float deltaTime);
        void Render(Renderer& renderer);
        void SetSelected(bool selected);
        void Activate();

        Vector3 GetPosition() const;

    private:
        ChannelData data;
        Vector3 position;
        Vector targetPosition;
        float rotation;
        float scale;
        bool isSelected;

        // Animation state
        float wobbleTime;
        float hoverOffset;
};