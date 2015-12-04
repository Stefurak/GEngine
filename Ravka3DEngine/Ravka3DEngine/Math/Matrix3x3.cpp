#include "Error.h"
#include "Matrix3x3.h"
#include <math.h>

#pragma region Matrix3x3

#pragma region Constructors & Deconstructors

static const float PI = 3.141592653589793f;

Matrix3x3::Matrix3x3(void)
{
}


Matrix3x3::Matrix3x3(float one, float two, float three, float four, float five, float six, float seven, float eight, float nine)
{
	I11 = one;		I12 = two;		I13 = three;
	I21 = four;		I22 = five;		I23 = six;
	I31 = seven;	I32 = eight;	I33 = nine;
}

Matrix3x3::Matrix3x3(Vector3 paramOne, Vector3 paramTwo, Vector3 paramThree)
{
	I11 = paramOne.x;		I12 = paramOne.y;		I13 = paramOne.z;
	I21 = paramTwo.x;		I22 = paramTwo.y;		I23 = paramTwo.z;
	I31 = paramThree.x;		I32 = paramThree.y;		I33 = paramThree.z;
}

Matrix3x3::~Matrix3x3(void)
{
}
#pragma endregion

#pragma region Operators
Matrix3x3 Matrix3x3::operator + (Matrix3x3 &param)
{
	Matrix3x3 temp;
	temp.I11 = I11 + param.I11;		temp.I12 = I12 + param.I12;		temp.I13 = I13 + param.I13;
	temp.I21 = I21 + param.I21;		temp.I22 = I22 + param.I22;		temp.I23 = I23 + param.I23;
	temp.I31 = I31 + param.I31;		temp.I32 = I32 + param.I32;		temp.I33 = I33 + param.I33;
	return temp;
}

Matrix3x3 Matrix3x3::operator += (Matrix3x3 &param)
{
	Matrix3x3 temp;

	return temp = temp + param;
}

Matrix3x3 Matrix3x3::operator - (Matrix3x3 &param)
{
	Matrix3x3 temp;
	temp.I11 = I11 - param.I11;		temp.I12 = I12 - param.I12;		temp.I13 = I13 - param.I13;
	temp.I21 = I21 - param.I21;		temp.I22 = I22 - param.I22;		temp.I23 = I23 - param.I23;
	temp.I31 = I31 - param.I31;		temp.I32 = I32 - param.I32;		temp.I33 = I33 - param.I33;
	return temp;
}

Matrix3x3 Matrix3x3::operator -= (Matrix3x3 &param)
{
	Matrix3x3 temp;
	temp.I11 = I11 -= param.I11;		temp.I12 = I12 -= param.I12;		temp.I13 = I13 -= param.I13;
	temp.I21 = I21 -= param.I21;		temp.I22 = I22 -= param.I22;		temp.I23 = I23 -= param.I23;
	temp.I31 = I31 -= param.I31;		temp.I32 = I32 -= param.I32;		temp.I33 = I33 -= param.I33;
	return temp;
}

Matrix3x3 Matrix3x3::operator * (Matrix3x3 &param)
{
	Matrix3x3 temp;
	temp.I11 = (I11 * param.I11) + (I12 * param.I21) + (I13 * param.I31);
	temp.I12 = (I11 * param.I12) + (I12 * param.I22) + (I13 * param.I32);
	temp.I13 = (I11 * param.I13) + (I12 * param.I23) + (I13 * param.I33);

	temp.I21 = (I21 * param.I11) + (I22 * param.I21) + (I23 * param.I31);
	temp.I22 = (I21 * param.I12) + (I22 * param.I22) + (I23 * param.I32);
	temp.I23 = (I21 * param.I13) + (I22 * param.I23) + (I23 * param.I33);

	temp.I31 = (I31 * param.I11) + (I32 * param.I21) + (I33 * param.I31);
	temp.I32 = (I31 * param.I12) + (I32 * param.I22) + (I33 * param.I32);
	temp.I33 = (I31 * param.I13) + (I32 * param.I23) + (I33 * param.I33);

	return temp;
}

Matrix3x3 Matrix3x3::operator *= (Matrix3x3 &param)
{
	Matrix3x3 temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	return temp = temp * param;
}

Matrix3x3 Matrix3x3::operator * (float &param)
{
	Matrix3x3 temp;

	temp.I11 = I11 * param;		temp.I12 = I12 * param;		temp.I13 = I13 * param;
	temp.I21 = I21 * param;		temp.I22 = I22 * param;		temp.I23 = I23 * param;
	temp.I31 = I31 * param;		temp.I32 = I32 * param;		temp.I33 = I33 * param;

	return temp;
}

Matrix3x3 Matrix3x3::operator *= (float &param)
{
	Matrix3x3 temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	return temp = temp * param;
}

Matrix3x3 Matrix3x3::operator / (float &param)
{
	Matrix3x3 temp;
	if(param > 0.0f || param < 0.0f)
	{
		temp.I11 = I11 / param;		temp.I12 = I12 / param;		temp.I13 = I13 / param;
		temp.I21 = I21 / param;		temp.I22 = I22 / param;		temp.I23 = I23 / param;
		temp.I31 = I31 / param;		temp.I32 = I32 / param;		temp.I33 = I33 / param;
	}
	return temp;
}

Matrix3x3 Matrix3x3::operator /= (float &param)
{
	Matrix3x3 temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	return temp = temp / param;
}

bool Matrix3x3::operator == (Matrix3x3 &param)
{
	if(I11 == param.I11 && I12 == param.I12 && I13 == param.I13 &&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33) return true;
	else return false;
}

bool Matrix3x3::operator != (Matrix3x3 &param)
{
	if(I11 == param.I11 && I12 == param.I12 && I13 == param.I13 &&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33) return false;
	else return true;
}

#pragma endregion

#pragma region Methods

Matrix3x3 Matrix3x3::TransposeMatrix()
{
	Matrix3x3 transpose;

	transpose.I11 = I11;		transpose.I12 = I21;		transpose.I13 = I31;
	transpose.I21 = I12;		transpose.I22 = I22;		transpose.I23 = I32;
	transpose.I31 = I13;		transpose.I32 = I23;		transpose.I33 = I33;

	return transpose;
}

float Matrix3x3::Get3x3Determinant(float I11, float D11, float I12, float D12, float I13, float D13)
{
	return ((I11 * D11) + (I12 * D12) + (I13 * D13));
}

Matrix3x3 Matrix3x3::GetAdjunct()
{
	Matrix3x3 temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	temp.I12 != 0.0f ? temp.I12 *= -1 : temp.I12;		temp.I21 != 0.0f ? temp.I21 *= -1 : temp.I21;
	temp.I23 != 0.0f ? temp.I23 *= -1 : temp.I23;		temp.I32 != 0.0f ? temp.I32 *= -1 : temp.I32;


	return temp;
}

Matrix3x3 Matrix3x3::InvertMatrix()
{
	Matrix3x3 temp;
	float determinant;

	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	temp.I21 = D21 = (I12 * I33) - (I32 * I13);		temp.I22 = D22 = (I11 * I33) - (I31 * I13);		temp.I23 = D23 = (I11 * I32) - (I31 * I12);
	temp.I31 = D31 = (I12 * I23) - (I22 * I13);		temp.I32 = D32 = (I11 * I23) - (I21 * I13);		temp.I33 = D33 = (I11 * I22) - (I21 * I12);

	temp = temp.GetAdjunct();

	temp.TransposeMatrix();

	determinant = Get3x3Determinant(I11, D11, I12, D12, I13, D13);

	temp = temp / determinant;

	return temp;
}

Matrix3x3 Matrix3x3::RotateMatrix(float _angle, char _axis)
{
	Matrix3x3 temp;

	if(_axis == 'x' || _axis == 'X')
	{
		Matrix3x3 rotateByFloat( 
			1.0f, 0.0f, 0.0f, 
			0.0f, ::cos((_angle * PI) / 180.0f), -::sin((_angle * PI) / 180.0f), 
			0.0f, ::sin((_angle * PI) / 180.0f), ::cos((_angle * PI) / 180.0f));
		temp = rotateByFloat;
		return temp;
	}

	if(_axis == 'y' || _axis == 'Y')
	{
		Matrix3x3 rotateByFloat( 
			::cos((_angle * PI) / 180.0f), -::sin((_angle * PI) / 180.0f), 0.0f, 
			::sin((_angle * PI) / 180.0f), ::cos((_angle * PI) / 180.0f), 0.0f, 
			0.0f, 0.0f, 1.0f);
		temp = rotateByFloat;
		return temp;
	}

	if(_axis == 'z' || _axis == 'Z')
	{
		Matrix3x3 rotateByFloat( 
			::cos((_angle * PI) / 180.0f), 0.0f, ::sin((_angle * PI) / 180.0f), 
			0.0f, 1.0f, 0.0f, 
			-::sin((_angle * PI) / 180.0f), 0.0f, ::cos((_angle * PI) / 180.0f));
		temp = rotateByFloat;
		return temp;
	}

	if(_axis != 'x' && _axis != 'X' && _axis != 'y' && _axis != 'Y' && _axis != 'z' && _axis != 'Z' || _axis == NULL)
	{
		fatalError("When Rotating Matrix you must pass x, X, y, Y, z or Z into the char axis argument");
	}
	return temp;
}

Matrix3x3 Matrix3x3::Zero()
{
	return Matrix3x3(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0);
}

Matrix3x3 Matrix3x3::TranslationMatrix()
{
		return Matrix3x3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0);
}

///////////////////////////////////////////////////////////
//Needed For Assignment 4 Rachida's Class
Matrix3x3 Matrix3x3::RotateX(float _angle)
{
	return 	Matrix3x3( 
			1.0f, 0.0f, 0.0f, 
			0.0f, ::cos((_angle * PI) / 180.0f), -::sin((_angle * PI) / 180.0f), 
			0.0f, ::sin((_angle * PI) / 180.0f), ::cos((_angle * PI) / 180.0f));
}

Matrix3x3 Matrix3x3::RotateY(float _angle)
{
	return	Matrix3x3( 
			::cos((_angle * PI) / 180.0f), -::sin((_angle * PI) / 180.0f), 0.0f, 
			::sin((_angle * PI) / 180.0f), ::cos((_angle * PI) / 180.0f), 0.0f, 
			0.0f, 0.0f, 1.0f);
}

Matrix3x3 Matrix3x3::RotateZ(float _angle)
{
	return	Matrix3x3( 
			::cos((_angle * PI) / 180.0f), 0.0f, ::sin((_angle * PI) / 180.0f), 
			0.0f, 1.0f, 0.0f, 
			-::sin((_angle * PI) / 180.0f), 0.0f, ::cos((_angle * PI) / 180.0f));
}

Matrix3x3 Matrix3x3::ArbitraryAxis(float _angle, Vector3 _axis)
{
	return Matrix3x3(
	((float)::cos((-_angle * PI) / 180) + ( 1 - (float)::cos((-_angle * PI) / 180)) * ( _axis.x * _axis.x)),
	((1 - (float)::cos((-_angle * PI) / 180)) * (_axis.x * _axis.y) - (((float)::sin((_angle * PI) / 180)) * _axis.z)),
	((1 - (float)::cos((-_angle * PI) / 180)) * (_axis.x * _axis.z) + (((float)::sin((_angle * PI) / 180)) * _axis.y)),
	((1 - (float)::cos((-_angle * PI) / 180)) * (_axis.x * _axis.y) + (((float)::sin((_angle * PI) / 180)) * _axis.z)),
	((float)::cos((-_angle * PI) / 180) + ( 1 - (float)::cos((-_angle * PI) / 180)) * ( _axis.y * _axis.y)),
	((1 - (float)::cos((-_angle * PI) / 180)) * (_axis.y * _axis.z) - (((float)::sin((_angle * PI) / 180)) * _axis.x)),
	((1 - (float)::cos((-_angle * PI) / 180)) * (_axis.x * _axis.z) - (((float)::sin((_angle * PI) / 180)) * _axis.y)),
	((1 - (float)::cos((-_angle * PI) / 180)) * (_axis.y * _axis.z) + (((float)::sin((_angle * PI) / 180)) * _axis.x)),
	((float)::cos((-_angle * PI) / 180) + ( 1 - (float)::cos((-_angle * PI) / 180)) * ( _axis.z * _axis.z)));
}

Matrix3x3 Matrix3x3::ScaleX(float _param)
{
	Matrix3x3 temp(
		_param, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f);
	return *(this) * temp;
}

Matrix3x3 Matrix3x3::ScaleY(float _param)
{
	Matrix3x3 temp(
		1.0f, 0.0f, 0.0f,
		0.0f, _param, 0.0f,
		0.0f, 0.0f, 1.0f);
	return *(this) * temp;
}

Matrix3x3 Matrix3x3::ScaleZ(float _param)
{
	Matrix3x3 temp(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, _param);
	return *(this) * temp;
}

Matrix3x3 Matrix3x3::ScaleAll(float _param)
{
	Matrix3x3 temp(
		_param, 0.0f, 0.0f,
		0.0f, _param, 0.0f,
		0.0f, 0.0f, _param);
	return *(this) * temp;
}


///////////////////////////////////////////////////////////

#pragma endregion

#pragma endregion