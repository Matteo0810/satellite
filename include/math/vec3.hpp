#pragma once
#include <cmath>
#include <iostream>

class Vec3 {
public:
    double x, y, z;

    Vec3(double x = 0, double y = 0, double z = 0);

    Vec3 operator+(const Vec3& o) const;
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator*(double s) const;
    Vec3 operator/(double s) const;

    Vec3& operator+=(const Vec3& o);
    Vec3& operator-=(const Vec3& o);
    Vec3& operator*=(double s);
    Vec3& operator/=(double s);

    double length2() const;
    double length() const;

    double dot(const Vec3& o) const;
    Vec3 cross(const Vec3& o) const;

    Vec3 normalized() const;
    void normalize();

    void print() const;

    static Vec3 zero();
    static Vec3 one();
};