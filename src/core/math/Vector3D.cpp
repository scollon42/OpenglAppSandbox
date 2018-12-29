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
#include "Vector3D.h"

Vector3D::Vector3D()
		: x(0), y(0), z(0)
{}

Vector3D::Vector3D(float a, float b, float c)
		: x(a), y(b), z(c)
{}

Vector3D::Vector3D(const Vector3D &v)
		: x(v.x), y(v.y), z(v.z)
{}

Vector3D &Vector3D::operator+=(const Vector3D &otherVector)
{
	x += otherVector.x;
	y += otherVector.y;
	z += otherVector.z;
	return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &otherVector)
{
	x -= otherVector.x;
	y -= otherVector.y;
	z -= otherVector.z;
	return *this;
}

Vector3D &Vector3D::operator*=(const float &scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3D &Vector3D::operator/=(const float &scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

float Vector3D::magnitude() const
{
	return (std::sqrt(x * x + y * y + z * z));
}

Vector3D &Vector3D::cross(const Vector3D &other)
{
	float nx, ny, nz;

	nx = y * other.z - z * other.y;
	ny = z * other.x - x * other.z;
	nz = x * other.y - y * other.x;

	x = nx;
	y = ny;
	z = nz;

	return *this;
}
