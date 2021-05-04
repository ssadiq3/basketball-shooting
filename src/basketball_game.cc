#include <basketball_game.h>
#include "cinder/Text.h"

namespace finalproject {

    BasketballGame::BasketballGame() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void BasketballGame::setup() {
        //ci::gl::Texture texture = cinder::loadImage("cropped.jpg");
        /*auto image = cinder::loadImage(loadAsset("cropped.jpg"));
        background_ = ci::gl::Texture2d::create(image);*/
    }

    void BasketballGame::draw() {
        ci::gl::clear();
        field_.Display();
    }

    void BasketballGame::update() {
        field_.AdvanceOneFrame();
    }

    void BasketballGame::mouseDown(ci::app::MouseEvent event) {
        field_.SetDirection(event.getPos());
    }

    void BasketballGame::mouseDrag(ci::app::MouseEvent event) {
        field_.SetDirection(event.getPos());
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

