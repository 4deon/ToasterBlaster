#include "TweenManager.h"
#include "Drawing/DisplayManager.h"

TweenManager::TweenManager(DisplayManager* displayManager, u8 initialLimit)
    : displayManager(displayManager) {
    tweens.reserve(initialLimit);
}

void TweenManager::add(ITweenable* t) {
    tweens.push_back(t);
}

void TweenManager::clearAll() {
    for(ITweenable* t : tweens) {
        t->finish();
        delete t;
    }
    tweens.clear();
}

void TweenManager::clearInterruptable() {
    for(i32 i = tweens.size() - 1; i >= 0; i--) {
        if(tweens[i]->interruptable) {
            tweens[i]->finish();
            delete tweens[i];
            tweens.erase(tweens.begin() + i);
        }
    }
}

void TweenManager::update() {
    if(tweens.size() == 0) return;

    for(i32 i = tweens.size() - 1; i >= 0; i--) {
        if(tweens[i]->apply()) {
            delete tweens[i];
            tweens.erase(tweens.begin() + i);
        }
    }

    displayManager->requestRedraw();
}