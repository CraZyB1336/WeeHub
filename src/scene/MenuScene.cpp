#include "MenuScene.h"

MenuScene::MenuScene(){

}

void MenuScene::Render(Renderer& renderer){
    renderer.Clear();
    renderer.DrawQuad(-0.5f, -0.1f, 1.0f, 0.2f, {1.0f, 0.0f, 0.0f, 1.0f});
    renderer.Present();
}