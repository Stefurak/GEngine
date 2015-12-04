#pragma once
#include "Vector4.h"

struct Vector4;
struct Vector3;
struct Matrix4x4
	{
	public:
		Matrix4x4(void);

		// A1 A2 A3 A4
		// B1 B2 B3 B4
		// C1 C2 C3 C4
		// D1 D2 D3 D4
		Matrix4x4(float a_One, float a_Two, float a_Three, float a_Four, 
			float b_One, float b_Two, float b_Three, float b_Four, 
			float c_One, float c_Two, float c_Three, float c_Four, 
			float d_One, float d_Two, float d_Three, float d_Four);
		Matrix4x4(Vector4 _row1, Vector4 _row2, Vector4 _row3, Vector4 _row4);
		~Matrix4x4(void);

		Matrix4x4 operator + (Matrix4x4);
		Matrix4x4 operator += (Matrix4x4);
		Matrix4x4 operator - (Matrix4x4);
		Matrix4x4 operator -= (Matrix4x4);
		Matrix4x4 operator * (Matrix4x4);
		Matrix4x4 operator *= (Matrix4x4);
		Matrix4x4 operator * (float);
		Matrix4x4 operator *= (float);
		Matrix4x4 operator / (float);
		Matrix4x4 operator /= (float);

		bool operator == (Matrix4x4);
		bool operator != (Matrix4x4);

		static Matrix4x4 Zero();
		static Matrix4x4 TranslationMatrix();
		Matrix4x4 InvertMatrix();
		Matrix4x4 TransposeMatrix();
		Matrix4x4 GetAdjunct();
///////////////////////////////////////////////////////////
//Needed For Assignment 4 Rachida's Class
		Matrix4x4 TranslationMatrix(Vector3 _param);
		Vector3 Translate3Dm(Vector3 _param, Matrix4x4 _translationParam);
		Vector3 Translate3Da(Vector3 _param, Vector3 _changeParam);

		Matrix4x4 RotateMatrix(float _angle, char _axis);
		Matrix4x4 RotateX(float _angle);
		Matrix4x4 RotateY(float _angle);
		Matrix4x4 RotateZ(float _angle);

		Matrix4x4 ScaleX(float _param);
		Matrix4x4 ScaleY(float _param);
		Matrix4x4 ScaleZ(float _param);
		Matrix4x4 ScaleW(float _param);
		Matrix4x4 ScaleAll(float _param);

//////////////////////////////////////////////////////////
		float Get3x3Determinant(float _I11, float _D11, float _I12, float _D12, float _I13, float _D13);

		float I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44;
		float D11, D12, D13, D14, D21, D22, D23, D24, D31, D32, D33, D34, D41, D42, D43, D44;
	};