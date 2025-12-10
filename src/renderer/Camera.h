#pragma once

class Camera{
    private:
        float* screenSize = new float[2];

    public:
        Camera(float width, float height);

        float* getScreenSize() {return screenSize;}
        float getWidth() {return screenSize[0];}
        float getHeight() {return screenSize[1];}
};