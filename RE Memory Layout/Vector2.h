#pragma once
#include <cassert>
#include <cmath>
#include <cfloat>

struct Vector2
{
	union
	{
		struct { float x, y; };
	};
	Vector2(float a_x, float a_y) : x(a_x), y(a_y) {}
	
	float magnitude() const {return sqrtf(x*x + y*y);}

	//Angle 2D only
};

//Dot Product
inline float dot(const Vector2 &ls, const Vector2 &rs)
{
	return ls.x * rs.x + ls.y * rs.y;
}

//Addition and Subtraction
inline Vector2 operator+(const Vector2 &ls, const Vector2 &rs)
{
	return Vector2(ls + rs);
}

inline Vector2 operator-(const Vector2 &ls, const Vector2 &rs)
{
	return Vector2(ls - rs);
}

inline Vector2 operator+=(const Vector2 &ls, const Vector2 &rs)
{
	return Vector2(ls += rs);
}

inline Vector2 operator-=(const Vector2 &ls, const Vector2 &rs)
{
	return Vector2(ls -= rs);
}

//Scalar
inline Vector2 operator*(const Vector2 &ls, const Vector2 &rs)
{
	return Vector2(ls * rs);
}

inline Vector2 operator/(const Vector2 &ls, const Vector2 &rs)
{
	return Vector2(ls / rs);
}

inline Vector2 operator*=(const Vector2 &ls, float rs)
{
	return Vector2(ls *= rs);
}

inline Vector2 operator/=(const Vector2 &ls, float rs)
{
	return Vector2(ls /= rs);
}

//Relational
inline bool operator==(const Vector2 &ls, const Vector2 &rs)
{
	return ls.x == rs.x && ls.y == rs.y;
}

inline bool operator!=(const Vector2 &ls, const Vector2 &rs)
{
	return ls.x != rs.x && ls.y != rs.y;
}

inline bool operator<(const Vector2 &ls, const Vector2 &rs)
{
	return ls.x < rs.x && ls.y < rs.y;
}

inline bool operator<=(const Vector2 &ls, const Vector2 &rs)
{
	return ls.x <= rs.x && ls.y <= rs.y;
}

inline bool operator>(const Vector2 &ls, const Vector2 &rs)
{
	return ls.x > rs.x && ls.y > rs.y;
}

inline bool operator>=(const Vector2 &ls, const Vector2 &rs)
{
	return ls.x >= rs.x && ls.y >= rs.y;
}

//Unary Negation
//Interpolation
//Reflection
//Length

//Normal
inline Vector2 normal(const Vector2 &a)
{
	return a / a.magnitude;
}

//Perpendicular 2D only
inline Vector2 perp(const Vector2 &a)
{
	return Vector2(-a.y, a.x);
}