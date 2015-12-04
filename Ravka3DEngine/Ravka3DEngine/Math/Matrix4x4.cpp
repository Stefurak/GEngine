#include "Error.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include <math.h>

#pragma region Matrix4x4

static const float PI = 3.141592653589793f;

Matrix4x4::Matrix4x4(void)
{
}

Matrix4x4::Matrix4x4(float a_One, float a_Two, float a_Three, float a_Four, 
									float b_One, float b_Two, float b_Three, float b_Four, 
									float c_One, float c_Two, float c_Three, float c_Four, 
									float d_One, float d_Two, float d_Three, float d_Four)
{
	I11 = a_One;		I12 = a_Two;		I13 = a_Three;		I14 = a_Four;
	I21 = b_One;		I22 = b_Two;		I23 = b_Three;		I24 = b_Four;
	I31 = c_One;		I32 = c_Two;		I33 = c_Three;		I34 = c_Four;
	I41 = d_One;		I42 = d_Two;		I43 = d_Three;		I44 = d_Four;
}

Matrix4x4::Matrix4x4(Vector4 row1, Vector4 row2, Vector4 row3, Vector4 row4)
{
	I11 = row1.x;		I12 = row1.y;		I13 = row1.z;		I14 = row1.w;
	I21 = row2.x;		I22 = row2.y;		I23 = row2.z;		I24 = row2.w;
	I31 = row3.x;		I32 = row3.y;		I33 = row3.z;		I34 = row3.w;
	I41 = row4.x;		I42 = row4.y;		I43 = row4.z;		I44 = row4.w;
}

Matrix4x4::~Matrix4x4(void)
{
}

Matrix4x4 Matrix4x4::operator + (Matrix4x4 param)
{
	Matrix4x4 temp;
	temp.I11 = I11 + param.I11;		temp.I12 = I12 + param.I12;		temp.I13 = I13 + param.I13;		temp.I14 = I14 + param.I14;
	temp.I21 = I21 + param.I21;		temp.I22 = I22 + param.I22;		temp.I23 = I23 + param.I23;		temp.I24 = I24 + param.I24;
	temp.I31 = I31 + param.I31;		temp.I32 = I32 + param.I32;		temp.I33 = I33 + param.I33;		temp.I34 = I34 + param.I34;
	temp.I41 = I41 + param.I41;		temp.I42 = I42 + param.I42;		temp.I43 = I43 + param.I43;		temp.I44 = I44 + param.I44;
	return temp;
}

Matrix4x4 Matrix4x4::operator += (Matrix4x4 param)
{
	Matrix4x4 temp;
	return temp = temp + param;
}

Matrix4x4 Matrix4x4::operator - (Matrix4x4 param)
{
	Matrix4x4 temp;
	temp.I11 = I11 - param.I11;		temp.I12 = I12 - param.I12;		temp.I13 = I13 - param.I13;		temp.I14 = I14 - param.I14;
	temp.I21 = I21 - param.I21;		temp.I22 = I22 - param.I22;		temp.I23 = I23 - param.I23;		temp.I24 = I24 - param.I24;
	temp.I31 = I31 - param.I31;		temp.I32 = I32 - param.I32;		temp.I33 = I33 - param.I33;		temp.I34 = I34 - param.I34;
	temp.I41 = I41 - param.I41;		temp.I42 = I42 - param.I42;		temp.I43 = I43 - param.I43;		temp.I44 = I44 - param.I44;
	return temp;
}

Matrix4x4 Matrix4x4::operator -= (Matrix4x4 param)
{
	Matrix4x4 temp;
	return temp = temp - param;
}

Matrix4x4 Matrix4x4::operator * (Matrix4x4 param)
{
	Matrix4x4 temp;
	//ROW 1
	temp.I11 = (I11 * param.I11) + (I12 * param.I21) + (I13 * param.I31) + (I14 * param.I41);
	temp.I12 = (I11 * param.I12) + (I12 * param.I22) + (I13 * param.I32) + (I14 * param.I42);
	temp.I13 = (I11 * param.I13) + (I12 * param.I23) + (I13 * param.I33) + (I14 * param.I43);
	temp.I14 = (I11 * param.I14) + (I12 * param.I24) + (I13 * param.I34) + (I14 * param.I44);

	//ROW 2
	temp.I21 = (I21 * param.I11) + (I22 * param.I21) + (I23 * param.I31) + (I24 * param.I41);
	temp.I22 = (I21 * param.I12) + (I22 * param.I22) + (I23 * param.I32) + (I24 * param.I42);
	temp.I23 = (I21 * param.I13) + (I22 * param.I23) + (I23 * param.I33) + (I24 * param.I43);
	temp.I24 = (I21 * param.I14) + (I22 * param.I24) + (I23 * param.I34) + (I24 * param.I44);

	//ROW 3
	temp.I31 = (I31 * param.I11) + (I32 * param.I21) + (I33 * param.I31) + (I34 * param.I41);
	temp.I32 = (I31 * param.I12) + (I32 * param.I22) + (I33 * param.I32) + (I34 * param.I42);
	temp.I33 = (I31 * param.I13) + (I32 * param.I23) + (I33 * param.I33) + (I34 * param.I43);
	temp.I34 = (I31 * param.I14) + (I32 * param.I24) + (I33 * param.I34) + (I34 * param.I44);

	//ROW 4
	temp.I41 = (I41 * param.I11) + (I42 * param.I21) + (I43 * param.I31) + (I44 * param.I41);
	temp.I42 = (I41 * param.I12) + (I42 * param.I22) + (I43 * param.I32) + (I44 * param.I42);
	temp.I43 = (I41 * param.I13) + (I42 * param.I23) + (I43 * param.I33) + (I44 * param.I43);
	temp.I44 = (I41 * param.I14) + (I42 * param.I24) + (I43 * param.I34) + (I44 * param.I44);

	return temp;
}

Matrix4x4 Matrix4x4::operator *= (Matrix4x4 param)
{
	Matrix4x4 temp;
	return temp = temp * param;
}

Matrix4x4 Matrix4x4::operator * (float param)
{
	Matrix4x4 temp;
	temp.I11 = I11 * param;		temp.I12 = I12 * param;		temp.I13 = I13 * param;		temp.I14 = I14 * param;
	temp.I21 = I21 * param;		temp.I22 = I22 * param;		temp.I23 = I23 * param;		temp.I24 = I24 * param;
	temp.I31 = I31 * param;		temp.I32 = I32 * param;		temp.I33 = I33 * param;		temp.I34 = I34 * param;
	temp.I41 = I41 * param;		temp.I42 = I42 * param;		temp.I43 = I43 * param;		temp.I44 = I44 * param;
	return temp;
}

Matrix4x4 Matrix4x4::operator *= (float param)
{
	Matrix4x4 temp;
	return temp = temp * param;
}

Matrix4x4 Matrix4x4::operator / (float param)
{
	Matrix4x4 temp;
	temp.I11 = I11 / param;		temp.I12 = I12 / param;		temp.I13 = I13 / param;		temp.I14 = I14 / param;
	temp.I21 = I21 / param;		temp.I22 = I22 / param;		temp.I23 = I23 / param;		temp.I24 = I24 / param;
	temp.I31 = I31 / param;		temp.I32 = I32 / param;		temp.I33 = I33 / param;		temp.I34 = I34 / param;
	temp.I41 = I41 / param;		temp.I42 = I42 / param;		temp.I43 = I43 / param;		temp.I44 = I44 / param;
	return temp;
}

Matrix4x4 Matrix4x4::operator /= (float param)
{
	Matrix4x4 temp;
	return temp = temp / param;
}

bool Matrix4x4::operator == (Matrix4x4 param)
{
	if(I11 == param.I11 && I12 == param.I12	&& I13 == param.I13	&& I14 == param.I14	&& 
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 && I24 == param.I24 && 
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33 && I34 == param.I34 && 
		I41 == param.I41 && I42 == param.I42 && I43 == param.I43 && I44 == param.I44) return true;
	else return false;
}

bool Matrix4x4::operator != (Matrix4x4 param)
{
		if(I11 != param.I11 || I12 != param.I12	|| I13 != param.I13	|| I14 != param.I14	|| 
		I21 != param.I21 || I22 != param.I22 || I23 != param.I23 || I24 != param.I24 || 
		I31 != param.I31 || I32 != param.I32 || I33 != param.I33 || I34 != param.I34 || 
		I41 != param.I41 || I42 != param.I42 || I43 != param.I43 || I44 != param.I44) return true;
	else return false;
}

Matrix4x4 Matrix4x4::TransposeMatrix()
{
	Matrix4x4 transpose;

	transpose.I11 = I11;		transpose.I12 = I21;		transpose.I13 = I31;		transpose.I14 = I41;
	transpose.I21 = I12;		transpose.I22 = I22;		transpose.I23 = I32;		transpose.I24 = I42;
	transpose.I31 = I13;		transpose.I32 = I23;		transpose.I33 = I33;		transpose.I34 = I43;
	transpose.I41 = I14;		transpose.I42 = I24;		transpose.I43 = I34;		transpose.I44 = I44;

	return transpose;
}

float Matrix4x4::Get3x3Determinant(float aI, float aD, float bI, float bD, float cI, float cD)
{
	return ((aI * aD) + (bI * bD) + (cI * cD));
}


Matrix4x4 Matrix4x4::GetAdjunct()
{
	Matrix4x4 temp(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);

	temp.I12 != 0.0f ? temp.I12 *= -1 : temp.I12;		temp.I14 != 0.0f ? temp.I14 *= -1 : temp.I14;		temp.I21 != 0.0f ? temp.I21 *= -1 : temp.I21;
	temp.I23 != 0.0f ? temp.I23 *= -1 : temp.I23;		temp.I32 != 0.0f ? temp.I32 *= -1 : temp.I32;		temp.I34 != 0.0f ? temp.I34 *= -1 : temp.I34;
	temp.I41 != 0.0f ? temp.I41 *= -1 : temp.I41;		temp.I43 != 0.0f ? temp.I43 *= -1 : temp.I43;

	return temp;
}

Matrix4x4 Matrix4x4::RotateMatrix(float _angle, char _axis)
{
	Matrix4x4 temp;

	if(_axis == 'x' || _axis == 'X')
	{
		Matrix4x4 rotateByFloat( 1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, (float)::cos((-_angle * PI) / 180), (float)-::sin((-_angle * PI) / 180), 0.0f, 
			0.0f, (float)::sin((-_angle * PI) / 180), (float)::cos((-_angle * PI) / 180), 0.0f, 
			0.0f, 0.0f, 0.0f, 1.0f);
		temp = rotateByFloat;
		return temp;
	}

	if(_axis == 'y' || _axis == 'Y')
	{
		Matrix4x4 rotateByFloat((float)::cos((-_angle * PI) / 180), 0.0f, (float)::sin((-_angle * PI) / 180), 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			(float)-::sin((-_angle * PI) / 180), 0.0f, (float)::cos((-_angle * PI) / 180), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
		temp = rotateByFloat;
		return temp;
	}

	if(_axis == 'z' || _axis == 'Z')
	{
		Matrix4x4 rotateByFloat((float)::cos((-_angle * PI) / 180), (float)-::sin((-_angle * PI) / 180), 0.0f, 0.0f,
			(float)::sin((_angle * PI) / 180), (float)::cos((_angle * PI) / 180), 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
		temp = rotateByFloat;
		return temp;
	}

	if(_axis != 'x' && _axis != 'X' && _axis != 'y' && _axis != 'Y' && _axis != 'z' && _axis != 'Z' || _axis == NULL)
	{
		fatalError("When Rotating Matrix you must pass x, X, y, Y, z or Z into the char axis argument");
	}
	return temp;
}




Matrix4x4 Matrix4x4::InvertMatrix()
{
	Matrix4x4 returnMatrix(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);

	float Determinant = 0.0f;
	Matrix3x3 temp(I22, I23, I24, I32, I33, I34, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I21, I23, I24, I31, I33, I34, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I21, I22, I24, I31, I32, I34, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I21, I22, I23, I31, I32, I33, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I12, I13, I14, I32, I33, I34, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I13, I14, I31, I33, I34, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I12, I14, I31, I32, I34, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I12, I13, I31, I32, I33, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I12, I13, I14, I22, I23, I24, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I13, I14, I21, I23, I24, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I12, I14, I21, I22, I24, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I12, I13, I21, I22, I23, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I12, I13, I14, I22, I23, I24, I32, I33, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I13, I14, I21, I23, I24, I31, I33, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I12, I14, I21, I22, I24, I31, I32, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = Matrix3x3(I11, I12, I13, I21, I22, I23, I31, I32, I33);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += Get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	returnMatrix = returnMatrix.GetAdjunct();

	returnMatrix.TransposeMatrix();

	returnMatrix = returnMatrix / Determinant;

	return returnMatrix;

}

Matrix4x4 Matrix4x4::Zero()
{
	return Matrix4x4(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
}

Matrix4x4 Matrix4x4::TranslationMatrix()
{
	return Matrix4x4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

///////////////////////////////////////////////////////////
//Needed For Assignment 4 Rachida's Class

Matrix4x4 Matrix4x4::TranslationMatrix(Vector3 _param)
{
	return Matrix4x4(1.0f,0.0f,0.0f,_param.x,0.0f,1.0f,0.0f,_param.y,0.0f,0.0f,1.0f,_param.z,0.0f,0.0f,0.0f,1.0f);
}

Vector3 Matrix4x4::Translate3Dm(Vector3 _param, Matrix4x4 _translationParam)
{
	Vector4 temp(_param.x, _param.y, _param.z, 0.0f);
	Vector4 temp2;
	temp2 = temp * _translationParam;

	return Vector3(temp.x, temp.y, temp.z);
}

Vector3 Matrix4x4::Translate3Da(Vector3 _param, Vector3 _changeParam)
{
	return _param += _changeParam;
}

Matrix4x4 Matrix4x4::RotateX(float _angle)
{
	return Matrix4x4( 1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, (float)::cos((-_angle * PI) / 180), (float)-::sin((-_angle * PI) / 180), 0.0f, 
			0.0f, (float)::sin((-_angle * PI) / 180), (float)::cos((-_angle * PI) / 180), 0.0f, 
			0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::RotateY(float _angle)
{
	return 	Matrix4x4((float)::cos((-_angle * PI) / 180), 0.0f, (float)::sin((-_angle * PI) / 180), 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			(float)-::sin((-_angle * PI) / 180), 0.0f, (float)::cos((-_angle * PI) / 180), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::RotateZ(float _angle)
{
	return 	Matrix4x4((float)::cos((-_angle * PI) / 180), (float)-::sin((-_angle * PI) / 180), 0.0f, 0.0f,
			(float)::sin((_angle * PI) / 180), (float)::cos((_angle * PI) / 180), 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::ScaleX(float _param)
{
	Matrix4x4 temp(
		_param, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	return *(this) * temp;
}

Matrix4x4 Matrix4x4::ScaleY(float _param)
{
	Matrix4x4 temp(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, _param, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	return *(this) * temp;
}

Matrix4x4 Matrix4x4::ScaleZ(float _param)
{
	Matrix4x4 temp(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, _param, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	return *(this) * temp;
}

Matrix4x4 Matrix4x4::ScaleW(float _param)
{
	Matrix4x4 temp(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, _param);
	return *(this) * temp;
}

Matrix4x4 Matrix4x4::ScaleAll(float _param)
{
	Matrix4x4 temp(
		_param, 0.0f, 0.0f, 0.0f,
		0.0f, _param, 0.0f, 0.0f,
		0.0f, 0.0f, _param, 0.0f,
		0.0f, 0.0f, 0.0f, _param);
	return *(this) * temp;
}

////////////////////////////////////////////////////////
#pragma endregion