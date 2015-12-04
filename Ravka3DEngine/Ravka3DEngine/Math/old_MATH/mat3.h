#pragma once
#include <math.h>

#define PI 3.141592653589793f

template <class T>
class mat3
{
public:

	mat3();
	mat3(
		T a_One, T a_Two, T a_Three,
		T b_One, T b_Two, T b_Three,
		T c_One, T c_Two, T c_Three);
	mat3(const mat3 & copy);
	~mat3();
	mat3<T> operator + (mat3<T> & param);
	mat3<T> operator += (mat3<T> & param);
	mat3<T> operator - (mat3<T> & param);
	mat3<T> operator -= (mat3<T> & param);
	mat3<T> operator * (mat3<T> & param);
	mat3<T> operator *= (mat3<T> & param);
	mat3<T> operator * (T & param);
	mat3<T> operator *= (T & param);
	mat3<T> operator / (T & param);
	mat3<T> operator /= (T & param);
	bool operator == (mat3<T> & param);
	bool operator != (mat3<T> & param);
	static mat3<T> zero();
	static mat3<T> identity();
	mat3<T> invertMatrix();
	mat3<T> transposeMatrix();
	mat3<T> getAdjunct();
	mat3<T> rotateMatrix(T angle, char axis);
	T get3x3Determinant(T _I11, T _D11, T _I12, T _D12, T _I13, T _D13);
	mat3<T> scalingfMatrix(T param);

	float I11, I12, I13, I21, I22, I23, I31, I32, I33;
	float D11, D12, D13, D21, D22, D23, D31, D32, D33;
};