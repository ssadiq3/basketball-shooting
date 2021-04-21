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
        if (field_.IsShooting()) {
            field_.ShootBall();
        }

    }

    void BasketballGame::mouseDrag(ci::app::MouseEvent event) {

    }

    void BasketballGame::keyDown(ci::app::KeyEvent event) {
        if (ci::app::KeyEvent::KEY_RETURN) {
            field_.SetShooting(true);
        }
    }
}

