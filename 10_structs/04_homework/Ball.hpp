#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(const Velocity& velocity, const Point& center, const Color& color);
    ~Ball() = default;
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    void setColor(const Color& color);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
private:
    const double PI = 3.14159265358979323846;
    const double radius = 3.;
    Color color;
    Point center;
    Velocity velocity;
};
