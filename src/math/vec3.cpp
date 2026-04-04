#include "math/vec3.h"
#include <cmath>

Vec3::Vec3(float x, float y, float z)
    : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& o) const {
    return Vec3(x + o.x, y + o.y, z + o.z);
}

Vec3 Vec3::operator-(const Vec3& o) const {
    return Vec3(x - o.x, y - o.y, z - o.z);
}

Vec3 Vec3::operator*(float s) const {
    return Vec3(x * s, y * s, z * s);
}

Vec3 Vec3::operator/(float s) const {
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

Vec3& Vec3::operator*=(float s) {
    x *= s; y *= s; z *= s;
    return *this;
}

Vec3& Vec3::operator/=(float s) {
    x /= s; y /= s; z /= s;
    return *this;
}

float Vec3::length2() const {
    return x*x + y*y + z*z;
}

float Vec3::length() const {
    return std::sqrt(length2());
}

float Vec3::dot(const Vec3& o) const {
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
    float len = length();
    if (len > 0.0f) return (*this) / len;
    return Vec3(0,0,0);
}

void Vec3::normalize() {
    float len = length();
    if (len > 0.0f) {
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