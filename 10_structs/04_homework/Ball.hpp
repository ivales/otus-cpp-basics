#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(const Velocity& velocity, const Point& center, const Color& color, const double radius);
    ~Ball() = default;
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
private:
    const double PI = 3.14159265358979323846;
    double radius;
    Color color;
    Point center;
    Velocity velocity;
};
