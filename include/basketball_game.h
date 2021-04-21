#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <field.h>

namespace finalproject {

class BasketballGame : public ci::app::App {
    public:
        BasketballGame();

        void draw() override;

        void update() override;

       void mouseDrag(ci::app::MouseEvent event) override;

       void keyDown(ci::app::KeyEvent event) override;

    const int kWindowSize = 1000;
    const int kMargin = 100;

  private:
    Field field_ = Field();
    };
}
