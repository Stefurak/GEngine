#include "Error.h"
#include "Vector3.h"
#include <math.h>

#pragma region Constructors & Deconstructors

Vector3::Vector3(void)
{}
Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}
Vector3::Vector3(Vector3 _paramOne, Vector3 _paramTwo)
{
	x = _paramTwo.x - _paramOne.x;
	y = _paramTwo.y - _paramOne.y;
}
Vector3::~Vector3(void)
{}

#pragma endregion

#pragma region Operators
Vector3 Vector3::operator + (Vector3 &param)
{
	Vector3 temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	temp.z = z + param.z;
	return temp;
}
Vector3 Vector3::operator += (Vector3 &param)
{
	Vector3 temp;
	temp.x = x += param.x;
	temp.y = y += param.y;
	temp.z = z += param.z;
	return temp;
}
Vector3 Vector3::operator + (float param)
{
	Vector3 temp;
	temp.x = x + param;
	temp.y = y + param;
	temp.z = z + param;
	return temp;
}
Vector3 Vector3::operator += (float param)
{
	Vector3 temp;
	temp.x = x += param;
	temp.y = y += param;
	temp.z = z += param;
	return temp;
}
Vector3 Vector3::operator - (Vector3 &param)
{
	Vector3 temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	temp.z = z - param.z;
	return temp;
}
Vector3 Vector3::operator -= (Vector3 &param)
{
	Vector3 temp;
	temp.x = x -= param.x;
	temp.y = y -= param.y;
	temp.z = z -= param.z;
	return temp;
}
Vector3 Vector3::operator * (Vector3 &param)
{
	Vector3 temp;
	temp.x = x * param.x;
	temp.y = y * param.y;
	temp.z = z * param.z;
	return temp;
}
Vector3 Vector3::operator *= (Vector3 &param)
{
	Vector3 temp;
	temp.x = x *= param.x;
	temp.y = y *= param.y;
	temp.z = z *= param.z;
	return temp;
}

Vector3 Vector3::operator * (Matrix3x3 &param)
{
	Vector3 temp;
	temp.x = (x * param.I11) + (y * param.I21) + (z * param.I31);
	temp.y = (x * param.I12) + (y * param.I22) + (z * param.I32);
	temp.z = (x * param.I13) + (y * param.I23) + (z * param.I33);
	return temp;
}

Vector3 Vector3::operator * (float param)
{
	Vector3 temp;
	temp.x = x * param;
	temp.y = y * param;
	temp.z = z * param;
	return temp;
}
Vector3 Vector3::operator *= (float param)
{
	Vector3 temp;
	temp.x = x *= param;
	temp.y = y *= param;
	temp.z = z *= param;
	return temp;
}
Vector3 Vector3::operator / (float param)
{
	Vector3 temp;
	temp.x = x / param;
	temp.y = y / param;
	temp.z = z / param;
	return temp;
}

Vector3 Vector3::operator /= (float param)
{
	Vector3 temp;
	temp = temp / param;
	return temp ;
}

bool Vector3::operator == (Vector3 &param)
{
	if (x == param.x && y == param.y && z == param.z) return true;
	else return false;
}
bool Vector3::operator != (Vector3 &param)
{
	if (x == param.x && y == param.y && z == param.z) return false;
	else return true;
}
bool Vector3::operator < (Vector3 &param)
{
	if (abs(x) < abs(param.x) && abs(y) < abs(param.y) && abs(z) < abs(param.z)) return true;
	else return true;
} 
bool Vector3::operator > (Vector3 &param)
{
	if (abs(x) > abs(param.x) && abs(y) > abs(param.y)  && abs(z) > abs(param.z)) return true;
	else return true;
}
#pragma endregion

#pragma region Methods
Vector3 Vector3::Zero()
{
	return Vector3(0.0f, 0.0f, 0.0f);
}

Vector3 Vector3::One()
{
	return Vector3(1.0f, 1.0f, 1.0);
}

Vector3 Vector3::UpVector()
{
	return Vector3(0.0f, 1.0f, 0.0f);
}

Vector3 Vector3::Normalize()
{
	Vector3 temp;
	float magnitude = ::sqrt((x * x) + (y * y) + (z * z));

	if(magnitude != 0)
	{
		Vector3 normal(x / magnitude, y / magnitude, z / magnitude);
		temp = normal;
	}
	else
	{
		fatalError("While trying to normalize magnitude was calculated to be zero, \n operation aborted \n Line 324 PhysicsEngine::Vector3 - Methods.");
	}
	return temp;
}

Vector3 Vector3::Cross(Vector3 _passed)
{
	Vector3 temp;

	temp.x = ((y * _passed.z) - (z * _passed.y));
	temp.y = ((z * _passed.x) - (x * _passed.z));
	temp.z = ((x * _passed.y) - (y * _passed.x));

	return temp;
}


float Vector3::Length()
{
	return ::sqrtf(x * x + y * y + z * z);
}

float Vector3::Dot(Vector3 _passed1, Vector3 _passed2)
{
	return ((_passed1.x * _passed2.x) + (_passed1.y * _passed2.y) + (_passed1.z * _passed2.z));
}

#pragma endregion
