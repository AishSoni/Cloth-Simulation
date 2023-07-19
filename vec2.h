#pragma once

struct vec2{
    double x,y;

    vec2() : x(0), y(0) {}
    vec2(double x, double y) : x(x), y(y) {}
    ~vec2() = default;

    vec2 operator + (const struct vec2 &v) const{
        vec2 result;
        result.x = x + v.x;
        result.y = y + v.y;
        return result;
    }
    vec2 operator - (const struct vec2 &v) const{
        vec2 result;
        result.x = x - v.x;
        result.y = y - v.y;
        return result;
    }
    vec2 operator * (const double k) const{
        vec2 result;
        result.x = x * k;
        result.y = y * k;
        return result;
    }
    vec2 operator / (const double k) const{
        vec2 result;
        result.x = x / k;
        result.y = y / k;
        return result;
    }
};
