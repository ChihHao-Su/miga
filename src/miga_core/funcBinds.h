#pragma once
#include <functional>
using std::function;

struct funcBinds
{
    function<void()> addTestSprite;
    function<void (Actor &, const Actor::TweenRotation &, int, int)> addTweenRotation;
    function<void (Actor &, Tween &, const TweenOptions &)> addTween;
    function<void (Tween &)> letTweenDetachWhenAnimDone;

    function<Tween *()> createTween;
    function<ColorRectSprite *()> createColorRectSprite;
    function<TextField *()> createTextField;
    function<Box9Sprite *()> createBox9Sprite;
    function<Button *()> createButton;
    function<void *(size_t)> allocMemory;
}
};
