#pragma once
#include "Vector3.h"

/*

Need a print method for my matrices, quaternions and vectors

*/

struct Vector3;
	struct Matrix3x3
	{
	public:
		Matrix3x3(void);

		// A1 A2 A3
		// B1 B2 B3
		// C1 C2 C3
		Matrix3x3(float a_One, float a_Two, float a_Three, float b_One, float b_Two, float b_Three, float c_One, float c_Two, float c_Three);
		Matrix3x3(Vector3 _row1, Vector3 _row2, Vector3 _row3);
		~Matrix3x3(void);

		Matrix3x3 operator + (Matrix3x3 &param);
		Matrix3x3 operator += (Matrix3x3 &param);
		Matrix3x3 operator - (Matrix3x3 &param);
		Matrix3x3 operator -= (Matrix3x3 &param);
		Matrix3x3 operator * (Matrix3x3 &param);
		Matrix3x3 operator *= (Matrix3x3 &param);
		Matrix3x3 operator * (float &param);
		Matrix3x3 operator *= (float &param);
		Matrix3x3 operator / (float &param);
		Matrix3x3 operator /= (float &param);

		bool operator == (Matrix3x3 &param);
		bool operator != (Matrix3x3 &param);

		static Matrix3x3 Zero();
		static Matrix3x3 TranslationMatrix();
		Matrix3x3 InvertMatrix();
		Matrix3x3 TransposeMatrix();
		Matrix3x3 GetAdjunct();
		Matrix3x3 RotateMatrix(float angle, char axis);
///////////////////////////////////////////////////////////
//Needed For Assignment 4 Rachida's Class
		Matrix3x3 RotateX(float angle);
		Matrix3x3 RotateY(float angle);
		Matrix3x3 RotateZ(float angle);
		Matrix3x3 ArbitraryAxis(float _angle, Vector3 _axis);

		Matrix3x3 ScaleX(float _param);
		Matrix3x3 ScaleY(float _param);
		Matrix3x3 ScaleZ(float _param);
		Matrix3x3 ScaleAll(float _param);
///////////////////////////////////////////////////////////
		float Get3x3Determinant(float _I11, float _D11, float _I12, float _D12, float _I13, float _D13);

		float I11, I12, I13, I21, I22, I23, I31, I32, I33;
		float D11, D12, D13, D21, D22, D23, D31, D32, D33;

	};