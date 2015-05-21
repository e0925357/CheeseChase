#include "Vec2i.hpp"
#include "math.h"

namespace cheesechase {

    Vec2i::Vec2i() : x(0), y(0) {

    }

    Vec2i::Vec2i(int x, int y) : x(x), y(y) {

    }

    int Vec2i::getX() const {
        return x;
    }

    int Vec2i::getY() const {
        return y;
    }

    double Vec2i::lenght() const {
        return sqrt(lenghtSqrd());
    }

    int Vec2i::lenghtSqrd() const {
        return x * x + y * y;
    }

    void Vec2i::setX(int x) {
        this->x = x;
    }

    void Vec2i::setY(int y) {
        this->y = y;
    }

    void Vec2i::add(Vec2i const &rhs) {
        x += rhs.getX();
        y += rhs.getY();
    }

    void Vec2i::add(int rhs) {
        x += rhs;
        y += rhs;
    }

    void Vec2i::sub(Vec2i const &rhs) {
        x -= rhs.getX();
        y -= rhs.getY();
    }

    void Vec2i::sub(int rhs) {
        x -= rhs;
        y -= rhs;
    }

    void Vec2i::div(Vec2i const &rhs) {
        x /= rhs.getX();
        y /= rhs.getY();
    }

    void Vec2i::div(int rhs) {
        x /= rhs;
        y /= rhs;
    }

    void Vec2i::mult(Vec2i const &rhs) {
        x *= rhs.getX();
        y *= rhs.getY();
    }

    void Vec2i::mult(int rhs) {
        x *= rhs;
        y *= rhs;
    }

    int Vec2i::point(Vec2i const &rhs) {
        return x * rhs.getX() + y * rhs.getY();
    }


    Vec2i operator+(Vec2i const &lhs, Vec2i const &rhs) {
        return Vec2i(lhs.getX() + rhs.getX(),
                     lhs.getY() + rhs.getY());
    }

    Vec2i operator+(Vec2i const &lhs, int rhs) {
        return Vec2i(lhs.getX() + rhs,
                     lhs.getY() + rhs);
    }

    Vec2i operator+(int lhs, Vec2i const &rhs) {
        return Vec2i(lhs + rhs.getX(),
                     lhs + rhs.getY());
    }

    Vec2i operator-(Vec2i const &lhs, Vec2i const &rhs) {
        return Vec2i(lhs.getX() - rhs.getX(),
                     lhs.getY() - rhs.getY());
    }

    Vec2i operator-(Vec2i const &lhs, int rhs) {
        return Vec2i(lhs.getX() - rhs,
                     lhs.getY() - rhs);
    }

    Vec2i operator-(int lhs, Vec2i const &rhs) {
        return Vec2i(lhs - rhs.getX(),
                     lhs - rhs.getY());
    }

    Vec2i operator*(Vec2i const &lhs, Vec2i const &rhs) {
        return Vec2i(lhs.getX() * rhs.getX(),
                     lhs.getY() * rhs.getY());
    }

    Vec2i operator*(int lhs, Vec2i const &rhs) {
        return Vec2i(lhs * rhs.getX(),
                     lhs * rhs.getY());
    }

    Vec2i operator*(Vec2i const &lhs, int rhs) {
        return Vec2i(lhs.getX() * rhs,
                     lhs.getY() * rhs);
    }

    Vec2i operator/(Vec2i const &lhs, Vec2i const &rhs) {
        return Vec2i(lhs.getX() / rhs.getX(),
                     lhs.getY() / rhs.getY());
    }

    Vec2i operator/(int lhs, Vec2i const &rhs) {
        return Vec2i(lhs / rhs.getX(),
                     lhs / rhs.getY());
    }

    Vec2i operator/(Vec2i const &lhs, int rhs) {
        return Vec2i(lhs.getX() / rhs,
                     lhs.getY() / rhs);
    }

    int point(Vec2i const &lhs, Vec2i const &rhs) {
        return lhs.getX() * rhs.getX() +
               lhs.getY() * rhs.getY();
    }
}