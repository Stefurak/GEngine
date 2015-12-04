#pragma once
#include "Matrix3x3.h"

struct Matrix3x3;
	struct Vector3
	{
		public:

		Vector3(void);
		Vector3(float, float, float);
		Vector3(Vector3, Vector3);
		~Vector3(void);

		Vector3 operator + (Vector3 &param);
		Vector3 operator += (Vector3 &param);
		Vector3 operator + (float);
		Vector3 operator += (float);
		Vector3 operator - (Vector3 &param);
		Vector3 operator -= (Vector3 &param);
		Vector3 operator * (Vector3 &param);
		Vector3 operator *= (Vector3 &param);
		Vector3 operator * (float);
		Vector3 operator *= (float);
		Vector3 operator * (Matrix3x3 &param);
		Vector3 operator / (float);
		Vector3 operator /= (float);

		bool operator == (Vector3 &param);
		bool operator != (Vector3 &param);
		bool operator < (Vector3 &param);
		bool operator > (Vector3 &param);
		
		static Vector3 Zero();
		static Vector3 One();
		static Vector3 UpVector();
		Vector3 Normalize();
		Vector3 Cross(Vector3);
		float Length();
		static float Dot(Vector3, Vector3);

		float x, y, z;
	};
