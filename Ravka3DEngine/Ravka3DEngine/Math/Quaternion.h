#pragma once
#include "Vector3.h"
#include "Vector4.h"

struct Quaternion
	{
	public:
		Quaternion(void);

		Quaternion(float _w, Vector3 _v);
		Quaternion(Vector4 _v);
		Quaternion(float _w, float _x, float _y, float _z);
		~Quaternion(void);

		void QuaternionFromEulerAngles(float theta_z, float theta_y, float theta_x);
		void QuaternionFromEulerAngles(const Vector3 &angles);

		Quaternion operator = (Quaternion);	
		Quaternion operator + (Quaternion);
		Quaternion operator - (Quaternion);	
		Quaternion operator * (Quaternion);	
		Quaternion operator / (Quaternion);	
		Quaternion operator * (float);
		Quaternion operator / (float);
		Quaternion operator - ();
		Quaternion operator += (Quaternion);	
		Quaternion operator -= (Quaternion);		
		Quaternion operator *= (Quaternion);	
		Quaternion operator *= (float);
		Quaternion operator /= (float);

	
		float Length();
		float Length_Squared();
		void Normalize();
		Quaternion Normalized();
		void Conjugate();
		void Invert();
		Quaternion Log();
		Quaternion Exp();
		static inline float Dot(Quaternion q1, Quaternion q2);
		static Quaternion Lerp(Quaternion q1, Quaternion q2, float t);
		static Quaternion Slerp(Quaternion q1, Quaternion q2, float t);
		static Quaternion SlerpNoInvert(Quaternion q1, Quaternion q2, float t);
		static Quaternion Squad(Quaternion q1, Quaternion q2, Quaternion a, Quaternion b, float t);
		static Quaternion Bezier(Quaternion q1, Quaternion q2, Quaternion a, Quaternion b, float t);
		static Quaternion Spline(Quaternion qnm1, Quaternion qn, Quaternion qnp1);
		static inline Quaternion From_Axis_Angle(Vector3 axis, float angle);
		void To_Axis_Angle(Vector3 axis, float angle);
		Vector3 Rotate(Vector3 v);

		Vector3 Euler_Angles(bool homogenous = true);

		Vector3 v;
		float s;
	};