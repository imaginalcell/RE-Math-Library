#pragma once
#include <cassert>
#include <cmath>

struct Vector3
{
	union 
	{
		struct { float x, y, z; };
	};
	
	float magnitude() const { return sqrtf(x*x + y*y + z*z); }
};

//Dot Product
inline float dot(const Vector3 &ls, const Vector3 &rs)
{
	return ls.x * rs.x + ls.y * rs.y + ls.z*rs.z;
}

//Addition and Subtraction
inline Vector3 operator+(const Vector3 &ls, const Vector3 &rs)
{
	return Vector3{ ls.x + rs.x, ls.y+rs.y, ls.z+rs.z };
}

inline Vector3 operator-(const Vector3 &ls, const Vector3 &rs)
{
	return Vector3{ ls.x + rs.x, ls.y - rs.y, ls.z - rs.z };
}

inline Vector3 &operator+=(Vector3 &ls, const Vector3 &rs)
{
	return ls = ls + rs;
}

inline Vector3 &operator-=(Vector3 &ls, const Vector3 &rs)
{
	return ls = ls - rs;
}

//Scalar
inline Vector3 operator*(const Vector3 &ls, float rs)
{
	return Vector3{ ls.x * rs, ls.y * rs, ls.z * rs };
}

inline Vector3 operator/(const Vector3 &ls, float rs)
{
	return Vector3{ ls.x / rs, ls.y / rs, ls.z / rs };
}

inline Vector3 &operator*=(Vector3 &ls, float rs)
{
	return ls = ls * rs;
}


inline Vector3 &operator/=(Vector3 &ls, float rs)
{
	return ls = ls / rs;
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
	return a / a.magnitude();
}

//Cross Product 3D only
inline float cross(const Vector3 &a,const Vector3 &b)
{
	return a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x;
}