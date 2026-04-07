#include "math/vec3.hpp"
#include <cmath>

Vec3::Vec3(double x, double y, double z)
    : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& o) const {
    return Vec3(x + o.x, y + o.y, z + o.z);
}

Vec3 Vec3::operator-(const Vec3& o) const {
    return Vec3(x - o.x, y - o.y, z - o.z);
}

Vec3 Vec3::operator*(double s) const {
    return Vec3(x * s, y * s, z * s);
}

Vec3 Vec3::operator/(double s) const {
    return Vec3(x / s, y / s, z / s);
}

Vec3& Vec3::operator+=(const Vec3& o) {
    x += o.x; y += o.y; z += o.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& o) {
    x -= o.x; y -= o.y; z -= o.z;
    return *this;
}

Vec3& Vec3::operator*=(double s) {
    x *= s; y *= s; z *= s;
    return *this;
}

Vec3& Vec3::operator/=(double s) {
    x /= s; y /= s; z /= s;
    return *this;
}

double Vec3::length2() const {
    return x*x + y*y + z*z;
}

double Vec3::length() const {
    return std::sqrt(length2());
}

double Vec3::dot(const Vec3& o) const {
    return x*o.x + y*o.y + z*o.z;
}

Vec3 Vec3::cross(const Vec3& o) const {
    return Vec3(
        y*o.z - z*o.y,
        z*o.x - x*o.z,
        x*o.y - y*o.x
    );
}

Vec3 Vec3::normalized() const {
    double len = length();
    if (len > 0.0) return (*this) / len;
    return Vec3(0,0,0);
}

void Vec3::normalize() {
    double len = length();
    if (len > 0.0) {
        x /= len;
        y /= len;
        z /= len;
    }
}

void Vec3::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")\n";
}

Vec3 Vec3::zero() {
    return Vec3(0,0,0);
}

Vec3 Vec3::one() {
    return Vec3(1,1,1);
}