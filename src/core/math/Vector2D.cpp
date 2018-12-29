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

#include "Vector2D.h"


Vector2D::Vector2D()
		: x(0), y(0)
{}

Vector2D::Vector2D(float a, float b)
		: x(a), y(b)
{}

Vector2D::Vector2D(const Vector2D &v)
		: x(v.x), y(v.y)
{}

Vector2D &Vector2D::operator+=(const Vector2D &otherVector)
{
	x += otherVector.x;
	y += otherVector.y;
	return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &otherVector)
{
	x -= otherVector.x;
	y -= otherVector.y;
	return *this;
}

Vector2D &Vector2D::operator*=(const float &scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2D &Vector2D::operator/=(const float &scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;
}

float Vector2D::magnitude() const
{
	return (std::sqrt(x * x + y * y));
}
