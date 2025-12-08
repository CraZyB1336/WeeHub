#pragma once

class ChannelGrid {
    public:
        ChannelGrid();

        void AddChannel(const ChannelData&& data);
        void Update(float deltaTime);
        void Render(Renderer& renderer);
        void MoveSelection(int dx, int dy);
        Channel* GetSelectedChannel();
        void ActivateSelected();

    private:
        std::vector<std::unique_ptr<Channel>> channels;
        int selectedX, selectedY;
        int gridWidth, gridHeight;

        void UpdateChannelPositions(float deltaTime);
};