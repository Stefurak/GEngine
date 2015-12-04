#include "Error.h"
#include "Vector2.h"
#include <math.h>

#pragma region Constructors & Deconstructors

Vector2::Vector2(void)
{}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}
Vector2::Vector2(Vector2 _paramOne, Vector2 _paramTwo)
{
	x = _paramTwo.x - _paramOne.x;
	y = _paramTwo.y - _paramOne.y;
}
Vector2::~Vector2(void)
{}

#pragma endregion

#pragma region Operators
Vector2 Vector2::operator + (Vector2 &param)
{
	Vector2 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}
Vector2 Vector2::operator += (Vector2 &param)
{
	Vector2 temp;
	temp.x = x += param.x;
	temp.y = y += param.y;
	return temp;
}
Vector2 Vector2::operator + (float param)
{
	Vector2 temp;
	temp.x = x + param;
	temp.y = y + param;
	return temp;
}
Vector2 Vector2::operator += (float param)
{
	Vector2 temp;
	temp.x = x += param;
	temp.y = y += param;
	return temp;
}
Vector2 Vector2::operator - (Vector2 &param)
{
	Vector2 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	return temp;
}
Vector2 Vector2::operator -= (Vector2 &param)
{
	Vector2 temp;
	temp.x = x -= param.x;
	temp.y = y -= param.y;
	return temp;
}
Vector2 Vector2::operator * (Vector2 &param)
{
	Vector2 temp;
	temp.x = x * param.x;
	temp.y = y * param.y;
	return temp;
}
Vector2 Vector2::operator *= (Vector2 &param)
{
	Vector2 temp;
	temp.x = x *= param.x;
	temp.y = y *= param.y;
	return temp;
}
Vector2 Vector2::operator * (float param)
{
	Vector2 temp;
	temp.x = x * param;
	temp.y = y * param;
	return temp;
}
Vector2 Vector2::operator *= (float param)
{
	Vector2 temp;
	temp.x = x *= param;
	temp.y = y *= param;
	return temp;
}
Vector2 Vector2::operator / (float param)
{
	Vector2 temp;
	temp.x = x / param;
	temp.y = y / param;
	return temp;
}

bool Vector2::operator == (Vector2 &param)
{
	if (x == param.x && y == param.y) return true;
	else return false;
}
bool Vector2::operator != (Vector2 &param)
{
	if (x == param.x && y == param.y) return false;
	else return true;
}
bool Vector2::operator < (Vector2 &param)
{
	if (::abs(x) < ::abs(param.x) && ::abs(y) < ::abs(param.y)) return true;
	else return true;
}
bool Vector2::operator > (Vector2 &param)
{
	if (::abs(x) > ::abs(param.x) && ::abs(y) > ::abs(param.y)) return true;
	else return true;
}
#pragma endregion

#pragma region Methods
Vector2 Vector2::Zero()
{
	return Vector2(0.0f, 0.0f);
}

Vector2 Vector2::Normalize()
{
	Vector2 temp;
	float magnitude = ::sqrt((x * x) + (y * y));
	if(magnitude != 0)
	{
		Vector2 normal(x / magnitude, y / magnitude);
		temp = normal;
	}
	else
	{
		fatalError("While trying to normalize magnitude was calculated to be zero, \n operation aborted.");
	}
	return temp;
}

void Vector2::RotateVector(float _angle)
{
	float tempX = x;
	float tempY = y;
	x = tempX * ::cos(_angle) - tempY * ::sin(_angle);
	y = tempX * ::sin(_angle) + tempY * ::cos(_angle);
}

float Vector2::Dot(Vector2 _passed1, Vector2 _passed2)
{
	return ((_passed1.x * _passed2.x) + (_passed1.y * _passed2.y));
}

float Vector2::Length()
{
	return ::sqrtf(x * x + y * y);
}

#pragma endregion
