#pragma once
#include <cmath>
#include <iostream>

class Vec3 {
public:
    float x, y, z;

    Vec3(float x = 0, float y = 0, float z = 0);

    Vec3 operator+(const Vec3& o) const;
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator*(float s) const;
    Vec3 operator/(float s) const;

    Vec3& operator+=(const Vec3& o);
    Vec3& operator-=(const Vec3& o);
    Vec3& operator*=(float s);
    Vec3& operator/=(float s);

    float length2() const;
    float length() const;

    float dot(const Vec3& o) const;
    Vec3 cross(const Vec3& o) const;

    Vec3 normalized() const;
    void normalize();

    void print() const;

    static Vec3 zero();
    static Vec3 one();
};