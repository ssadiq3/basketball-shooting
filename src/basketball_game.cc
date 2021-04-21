#include <basketball_game.h>

namespace finalproject {

    BasketballGame::BasketballGame() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void BasketballGame::draw() {
        ci::gl::clear();
        field_.Display();
    }

    void BasketballGame::update() {
        field_.AdvanceOneFrame();
    }

    void BasketballGame::mouseDrag(ci::app::MouseEvent event) {

    }

    void BasketballGame::keyDown(ci::app::KeyEvent event) {
        switch(event.getCode()) {
            case ci::app::KeyEvent::KEY_RETURN:
                field_.SetShooting(true);
            case ci::app::KeyEvent::KEY_RIGHT:
                field_.SetMovingRight(true);
            case ci::app::KeyEvent::KEY_LEFT:
                field_.SetMovingLeft(true);
        }
    }
}

