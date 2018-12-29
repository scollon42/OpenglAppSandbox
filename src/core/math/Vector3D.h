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

#ifndef OPENGGLAPP_VECTOR3D_H
#define OPENGGLAPP_VECTOR3D_H

#include <iosfwd>
#include <sstream>
#include <cmath>

struct Vector3D
{
	Vector3D();
	Vector3D(float a, float b, float c);
	Vector3D(const Vector3D &vector3d);

	Vector3D &operator+=(const Vector3D &otherVector);

	Vector3D &operator-=(const Vector3D &otherVector);

	Vector3D &operator*=(const float &scalar);

	Vector3D &operator/=(const float &scalar);

	float magnitude() const;
	Vector3D &cross(const Vector3D &other);

	friend std::ostream &operator<<(std::ostream &, const Vector3D &);

	float x;
	float y;
	float z;
};

inline bool operator==(const Vector3D &a, const Vector3D &b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

inline Vector3D operator+(const Vector3D &a, const Vector3D &b)
{
	return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator-(const Vector3D &a, const Vector3D &b)
{
	return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline Vector3D operator*(const Vector3D &vector, const float &scalar)
{
	return (Vector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar));
}

inline Vector3D operator/(const Vector3D &vector, const float &scalar)
{
	return (Vector3D(vector.x / scalar, vector.y / scalar, vector.z / scalar));
}

inline Vector3D operator-(const Vector3D &v)
{
	return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude(const Vector3D &v)
{
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3D Normalize(const Vector3D &v)
{
	return (v / v.magnitude());
}

inline float  Dot(const Vector3D &a, const Vector3D &b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3D Cross(const Vector3D &a, const Vector3D &b)
{
	return Vector3D(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
	);
}

inline Vector3D Project(const Vector3D &a, const Vector3D &b)
{
	return (b * (Dot(a, b) / Dot(b, b)));
}

inline Vector3D Reject(const Vector3D &a, const Vector3D &b)
{
	return (a - Project(a, b));
}

inline std::ostream &operator<<(std::ostream &stream, const Vector3D &v)
{
	return stream << "Vector3D(x: " << v.x << ", y: " << v.y << ", z: " << v.z << ");";
}

#endif //OPENGGLAPP_VECTOR3D_H
