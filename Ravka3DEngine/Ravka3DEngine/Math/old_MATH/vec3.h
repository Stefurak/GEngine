#pragma once
#include <math.h>

template <class T>
class vec3
{

public:

	vec3();
	vec3(T _x, T _y, T _z);
	vec3(const vec3<T> & copy);
	~vec3();
	vec3<T> operator + (vec3<T> & param);
	vec3<T> operator += (vec3<T> & param);
	vec3<T> operator - (vec3<T> & param);
	vec3<T> operator -= (vec3<T> & param);
	vec3<T> operator *= (vec3<T> & param);
	vec3<T> operator *= (T param);
	vec3<T> operator * (T param);
	vec3<T> operator / (T param);
	vec3<T> operator /= (T param);
	bool operator == (vec3<T> & param);
	bool operator != (vec3<T> & param);
	static vec3<T> zero();
	static vec3<T> one();
	static vec3<T> upVector();
	static vec3<T> rightVector();
	static vec3<T> forwardVector();
	vec3<T> normalize();
	vec3<T> cross(vec3<T> param);
	T length();
	static T dot(vec3<T> param1, vec3<T> param2);

	T x, y, z;
};
