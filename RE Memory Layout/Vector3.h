#pragma once
#include <cassert>
#include <cmath>

struct Vector3
{
	float x, y, z;

	float magnitude() const { return sqrtf(x*x + y*y); }
};

//Dot Product
inline float dot(const Vector3 &ls, const Vector3 &rs)
{
	return ls.x * rs.x + ls.y * rs.y;
}

//Addition and Subtraction
inline Vector3 operator+(const Vector3 &ls, const Vector3 &rs)
{
	return Vector3(ls + rs);
}

inline Vector3 operator-(const Vector3 &ls, const Vector3 &rs)
{
	return Vector3(ls - rs);
}

inline Vector3 operator+=(const Vector3 &ls, const Vector3 &rs)
{
	return Vector3(ls += rs);
}

inline Vector3 operator-=(const Vector3 &ls, const Vector3 &rs)
{
	return Vector3(ls -= rs);
}

//Scalar
inline Vector3 operator*(const Vector3 &ls, const Vector3 &rs)
{
	return Vector3(ls * rs);
}

inline Vector3 operator/(const Vector3 &ls, const Vector3 &rs)
{
	return Vector3(ls / rs);
}

inline Vector3 operator*=(const Vector3 &ls, float rs)
{
	return Vector3(ls *= rs);
}

inline Vector3 operator/=(const Vector3 &ls, float rs)
{
	return Vector3(ls /= rs);
}

//Relational
inline bool operator==(const Vector3 &ls, const Vector3 &rs)
{
	return ls.x == rs.x && ls.y == rs.y && ls.z == rs.z;
}

inline bool operator!=(const Vector3 &ls, const Vector3 &rs)
{
	return ls.x != rs.x && ls.y != rs.y && ls.z != rs.z;
}

inline bool operator<(const Vector3 &ls, const Vector3 &rs)
{
	return ls.x < rs.x && ls.y < rs.y && ls.z < rs.z;
}

inline bool operator<=(const Vector3 &ls, const Vector3 &rs)
{
	return ls.x <= rs.x && ls.y <= rs.y && ls.z <= rs.z;
}

inline bool operator>(const Vector3 &ls, const Vector3 &rs)
{
	return ls.x > rs.x && ls.y > rs.y && ls.z > rs.z;
}

inline bool operator>=(const Vector3 &ls, const Vector3 &rs)
{
	return ls.x >= rs.x && ls.y >= rs.y && ls.z >= rs.z;
}

//Unary Negation
//Interpolation
//Reflection
//Length
//Normal
inline Vector3 normal(const Vector3 &a)
{
	return a / a.magnitude;
}
//Cross Product 3D only