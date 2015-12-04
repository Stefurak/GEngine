#pragma once
#include "vec3.h"
#include <math.h>

template <class T>

class Quaternion
	{
	public:
		Quaternion(void);

		Quaternion(T _w, vec3<T> _v);
		Quaternion(T _w, T _x, T _y, T _z);
		Quaternion(const Quaternion<T> & copy);
		~Quaternion(void);

		void quaternionFromEulerAngles(T theta_z, T theta_y, T theta_x);
		void quaternionFromEulerAngles(const vec3<T> & angles);

		Quaternion<T> operator = (Quaternion<T>);	
		Quaternion<T> operator + (Quaternion<T>);
		Quaternion<T> operator - (Quaternion<T>);	
		Quaternion<T> operator * (Quaternion<T>);	
		Quaternion<T> operator / (Quaternion<T>);	
		Quaternion<T> operator * (T);
		Quaternion<T> operator / (T);
		Quaternion<T> operator += (Quaternion<T>);	
		Quaternion<T> operator -= (Quaternion<T>);		
		Quaternion<T> operator *= (Quaternion<T>);	
		Quaternion<T> operator *= (T);
		Quaternion<T> operator /= (T);

	
		T length();
		T length_Squared();
		void normalize();
		Quaternion<T> normalized();
		void conjugate();
		void invert();
		Quaternion<T> log();
		Quaternion<T> exp();
		static inline T dot(Quaternion<T> q1, Quaternion<T> q2);
		static Quaternion<T> lerp(Quaternion<T> q1, Quaternion<T> q2, T t);
		static Quaternion<T> slerp(Quaternion<T> q1, Quaternion<T> q2, T t);
		static Quaternion<T> slerpNoInvert(Quaternion<T> q1, Quaternion<T> q2, T t);
		static Quaternion<T> squad(Quaternion<T> q1, Quaternion<T> q2, Quaternion<T> a, Quaternion<T> b, T t);
		static Quaternion<T> bezier(Quaternion<T> q1, Quaternion<T> q2, Quaternion<T> a, Quaternion<T> b, T t);
		static Quaternion<T> spline(Quaternion<T> qnm1, Quaternion<T> qn, Quaternion<T> qnp1);
		static inline Quaternion<T> from_Axis_Angle(vec3<T> axis, T angle);
		void to_Axis_Angle(vec3<T> axis, T angle);
		vec3<T> rotate(vec3<T> v);

		vec3<T> euler_Angles(bool homogenous = true);

		vec3<T> v;
		T s;
	};