#include "basketball_game.h"

using finalproject::BasketballGame;

void prepareSettings(BasketballGame::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(BasketballGame, ci::app::RendererGl, prepareSettings);