#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(const Velocity& velocity, const Point& center, const Color& color, const double radius, const bool callidable);
    ~Ball() = default;
    void draw(Painter& painter) const;    
    Point getCenter() const;
    double getMass() const;
    double getRadius() const;
    Velocity getVelocity() const;
    bool isCallidable() const;
    void setCenter(const Point& center);
    void setVelocity(const Velocity& velocity);

private:
    bool callidable;
    Point center;
    Color color;
    double mass, radius;
    Velocity velocity;    
};
