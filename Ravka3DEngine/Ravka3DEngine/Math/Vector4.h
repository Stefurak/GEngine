#pragma once
#include "Matrix4x4.h"

struct Matrix4x4;
struct Vector4
	{
		public:

		Vector4(void);
		Vector4(float xx, float yy, float zz, float ww);
		~Vector4(void);

		void operator () (float xx, float yy, float zz, float ww);
		bool operator == (Vector4 &param);
		bool operator != (Vector4 &param);
		Vector4 operator = (Vector4 &param);
		Vector4 operator - (void);
		Vector4 operator + (Vector4 &param);
		Vector4 operator += (Vector4 &param);
		Vector4 operator - (Vector4 &param);
		Vector4 operator -= (Vector4 &param);
		Vector4 operator * (float param);
		float operator * (Vector4 &param);
		Vector4 operator *= (float param);
		Vector4 operator / (float param);
		Vector4 operator /= (float param);
		Vector4 operator * (Matrix4x4 &param);
		Vector4 operator % (Vector4 &param);

		static Vector4 Zero();
		static Vector4 One();
		static Vector4 UpVector();
		float Length_Squared();
		float Length();
		static float Dot(Vector4 &_param, Vector4 &_param2);
		void Normalize();
		void Reflect(Vector4 &param);
		void Project(Vector4 &param);
		Vector4 Projected(Vector4 &param);

		float x, y, z, w;
	};
