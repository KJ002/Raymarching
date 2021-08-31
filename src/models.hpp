#pragma once
#include <raylib.h>
#include <cmath>

struct Vec2 : public Vector2{
  Vector2 expose() const{
    return (Vector2){x, y};
  }

  Vec2 operator+(const Vec2& other) const{
    return (Vec2){x+other.x, y+other.y};
  }

  Vec2 operator-(const Vec2& other) const{
    return (Vec2){x-other.x, y-other.y};
  }

  Vec2 operator*(const Vec2& other) const{
    return (Vec2){x*other.x, y*other.y};
  }

  Vec2 operator/(const Vec2& other) const{
    return (Vec2){x/other.x, y/other.y};
  }

  bool operator>(const Vec2& other) const{
    if ((x*y) > (other.x*other.y))
      return true;
    return false;
  }

  bool operator<(const Vec2& other) const{
    return !operator>(other);
  }

  double dotProduct(const Vec2& other) const{
    return x*other.x+y*other.y;
  }

  double crossProduct(const Vec2& other) const{
    return x+other.x*y+other.y;
  }

  Vec2 rotate(const double th) const{
    Vec2 result;

    result.x = cos(th) * this->x - sin(th) * this->y;
    result.y = sin(th) * this->x + sin(th) * this->y;

    return result;
  }

  Vec2 rotate(const double th, const Vec2& origin) const{
    Vec2 newPoint = *this - origin;

    return newPoint.rotate(th);
  }
};


struct Circle{
  Vec2 position;
  Vec2 radius;
}