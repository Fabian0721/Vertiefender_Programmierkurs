#include "Wall.h"
#include "Vec2D.h"
#include "Terminal.h"
#include "Snake.h"
#include "Nachtwache.h"
#include "Weiswanderer.h"

Wall::Wall(const Vec2D& start, const Vec2D& end) :
    _start(start), _end(end)
{
}

void Wall::draw(Terminal& term)
{
    if (is_vertical_wall()) {
        for (int y = _start.y; y <= _end.y; ++y) {
            term.set_cell(_start.x, y, 'x');
        }
    }
    else if (is_horizontal_wall())
    {
        for (int x = _start.x; x <= _end.x; ++x) {
            term.set_cell(x, _start.y, 'x');
        }
    }
}

bool Wall::collides_with( Nachtwache& nacht)
{
    Vec2D vec = nacht.get_segments();

    if (is_vertical_wall()) {
        if (vec.x == _start.x) {
            return true;
        }
    }
    else if (is_horizontal_wall()) {
        if (vec.y == _start.y) {
            return true;
        }
    }

    return false;
}

bool Wall::collides_with( Weiswanderer& weis)
{
    Vec2D vec = weis.get_segments();

    if (is_vertical_wall()) {
        if (vec.x == _start.x) {
            return true;
        }
    }
    else if (is_horizontal_wall()) {
        if (vec.y == _start.y) {
            return true;
        }
    }

    return false;
}

bool Wall::is_vertical_wall() const
{
    if (_start.x == _end.x && _start.y != _end.y) {
        return true;
    }

    return false;
}

bool Wall::is_horizontal_wall() const
{
    if (_start.y == _end.y && _start.x != _end.x) {
        return true;
    }

    return false;
}
