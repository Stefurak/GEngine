#pragma once

struct Vector2
	{
	public:

		Vector2(void);
		Vector2(float, float);
		Vector2(Vector2, Vector2);
		~Vector2(void);

		Vector2 operator + (Vector2 &param);
		Vector2 operator += (Vector2 &param);
		Vector2 operator + (float);
		Vector2 operator += (float);
		Vector2 operator - (Vector2 &param);
		Vector2 operator -= (Vector2 &param);
		Vector2 operator * (Vector2 &param);
		Vector2 operator *= (Vector2 &param);
		Vector2 operator * (float);
		Vector2 operator *= (float);
		Vector2 operator / (float);

		bool operator == (Vector2 &param);
		bool operator != (Vector2 &param);
		bool operator < (Vector2 &param);
		bool operator > (Vector2 &param);

		static Vector2 Zero();
		Vector2 Normalize();
		static inline float Dot(Vector2, Vector2);

		void RotateVector(float);
		float Length();

		float x, y;
	};

