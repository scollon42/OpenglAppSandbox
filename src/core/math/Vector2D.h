/*
** Copyright © 18/12/18 scollon
**
** Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
** associated documentation files (the “Software”), to deal in the Software without restriction,
** including without limitation the rights to use, copy, modify, merge, publish, distribute,
** sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all copies or substantial
** portions of the Software.
**
** The Software is provided “as is”, without warranty of any kind, express or implied,
** including but not limited to the warranties of merchantability, fitness for a particular
** purpose and noninfringement. In no event shall the authors or copyright holders X be liable for
** any claim, damages or other liability, whether in an input_action of contract, tort or otherwise, arising
** from, out of or in connection with the software or the use or other dealings in the Software.
** Except as contained in this notice, the name of the scollon shall not be used in advertising or
** otherwise to promote the sale, use or other dealings in this Software without prior written
** authorization from the scollon.
*/
#ifndef OPENGGLAPP_VECTOR2D_H
#define OPENGGLAPP_VECTOR2D_H

#include <iosfwd>
#include <sstream>
#include <cmath>

struct Vector2D
{
	Vector2D();
	Vector2D(float a, float b);
	Vector2D(const Vector2D &vector3d);

	Vector2D &operator+=(const Vector2D &otherVector);

	Vector2D &operator-=(const Vector2D &otherVector);

	Vector2D &operator*=(const float &scalar);

	Vector2D &operator/=(const float &scalar);

	float magnitude() const;
	Vector2D &cross(const Vector2D &other);

	friend std::ostream &operator<<(std::ostream &, const Vector2D &);

	float x;
	float y;
};

inline bool operator==(const Vector2D &a, const Vector2D &b)
{
	return (a.x == b.x && a.y == b.y);
}

inline Vector2D operator+(const Vector2D &a, const Vector2D &b)
{
	return (Vector2D(a.x + b.x, a.y + b.y));
}

inline Vector2D operator-(const Vector2D &a, const Vector2D &b)
{
	return (Vector2D(a.x - b.x, a.y - b.y));
}

inline Vector2D operator*(const Vector2D &vector, const float &scalar)
{
	return (Vector2D(vector.x * scalar, vector.y * scalar));
}

inline Vector2D operator/(const Vector2D &vector, const float &scalar)
{
	return (Vector2D(vector.x / scalar, vector.y / scalar));
}

inline Vector2D operator-(const Vector2D &v)
{
	return (Vector2D(-v.x, -v.y));
}

inline float Magnitude(const Vector2D &v)
{
	return std::sqrt(v.x * v.x + v.y * v.y);
}

inline Vector2D Normalize(const Vector2D &v)
{
	return (v / v.magnitude());
}

inline float  Dot(const Vector2D &a, const Vector2D &b)
{
	return (a.x * b.x + a.y * b.y);
}

inline Vector2D Project(const Vector2D &a, const Vector2D &b)
{
	return (b * (Dot(a, b) / Dot(b, b)));
}

inline Vector2D Reject(const Vector2D &a, const Vector2D &b)
{
	return (a - Project(a, b));
}

inline std::ostream &operator<<(std::ostream &stream, const Vector2D &v)
{
	return stream << "Vector2D(x: " << v.x << ", y: " << v.y << ", z: " << 0 << ");";
}


#endif //OPENGGLAPP_VECTOR2D_H
