#include "Error.h"
#include "Vector4.h"
#include <math.h>


#pragma region Vector4

Vector4::Vector4(void)
{

}

Vector4::Vector4(float xx, float yy, float zz, float ww)
{
	x = xx; 
	y = yy; 
	z = zz; 
	w = ww;
}

Vector4::~Vector4(void)
{
}

void Vector4::operator () (float xx, float yy, float zz, float ww)	
{
	x = xx; 
	y = yy; 
	z = zz; 
	w = ww;
}

bool Vector4::operator == (Vector4 &param)
{
	return (x == param.x && y == param.y && z == param.z && w == param.w);
}

bool Vector4::operator != (Vector4 &param)
{
	return (x != param.x || y != param.y || z != param.z || w != param.w);
}

Vector4 Vector4::operator = (Vector4 &param)
{
	x = param.x; 
	y = param.y;	
	z = param.z;	
	w = param.w;	
	return *this;
}

Vector4 Vector4::operator - (void)
{
	return Vector4(-x, -y, -z, w);
}

Vector4 Vector4::operator + (Vector4 &param)
{
	return Vector4(x + param.x, y + param.y, z + param.z, w);
}

Vector4 Vector4::operator += (Vector4 &param)
{
	x += param.x;
	y += param.y;
	z += param.z;	
	return *this;
}

Vector4 Vector4::operator - (Vector4 &param)
{
	return Vector4(x - param.x, y - param.y, z - param.z, 0);
}

Vector4 Vector4::operator -= (Vector4 &param)
{
	x -= param.x;
	y -= param.y;
	z -= param.z;	
	return *this;
}

float Vector4::operator * (Vector4 &param)
{
	return x * param.x + y * param.y + z * param.z;
}

Vector4 Vector4::operator * (float param)
{
	Vector4 temp(*this);			
	return temp *= param;
}

Vector4 Vector4::operator *= (float  param)
{
	x *= param;
	y *= param;
	z *= param;
	w *= param;
	return *this;
}

Vector4 Vector4::operator / (float param)
{
	Vector4 temp(*this);			
	return temp /= param;
}



Vector4 Vector4::operator /= (float  param)
{
	x /= param; 
	y /= param; 
	z /= param;	
	w /= param;								
	return *this;
}

Vector4 Vector4::operator % (Vector4 &param)
{
	Vector4 temp(y * param.z - z * param.y, z * param.x - x * param.z, x * param.y - y * param.x, 0);
	return temp;
}

Vector4 Vector4::operator * (Matrix4x4 &param)
{
	Vector4 temp;
	temp.x = (x * param.I11) + (y * param.I21) + (z * param.I31) + (w * param.I41);
	temp.y = (x * param.I12) + (y * param.I22) + (z * param.I32) + (w * param.I42);
	temp.z = (x * param.I13) + (y * param.I23) + (z * param.I33) + (w * param.I43);
	temp.w = (x * param.I14) + (y * param.I24) + (z * param.I34) + (w * param.I44);
	return temp;
}

float Vector4::Length_Squared()
{
	return (float)(*this * *this);
}

float Vector4::Length()
{
	return (float)::sqrt(*this * *this);
}

float Vector4::Dot(Vector4 &_param, Vector4 &_param2)
{
	return ((_param.x * _param2.x) + (_param.y * _param2.y) + (_param.z * _param2.z) + (_param.w * _param2.w));
}

void Vector4::Normalize()
{
	*this /= Length();
}

void Vector4::Reflect(Vector4 &param)
{
	Vector4 original(*this);
	Project(param);
	*this = *this * 2 - original;
}

void Vector4::Project(Vector4 &param)
{
	*this = param * (*this * param) / (param * param);
}

Vector4 Vector4::Projected(Vector4 &param)
{
	return param * (*this * param) / (param * param);
}

Vector4 Vector4::Zero()
{
	return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
}

Vector4 Vector4::One()
{
	return Vector4(1.0f, 1.0f, 1.0f, 1.0f);
}

Vector4 Vector4::UpVector()
{
	return Vector4(0.0f, 1.0f, 0.0f, 0.0f);
}


#pragma endregion