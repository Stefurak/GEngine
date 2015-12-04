#pragma once
#include "mat3.h"
#include "vec3.h"
#include <math.h>

template <class T> 
class mat4
{

public:

	mat4();

	// A1 A2 A3 A4
	// B1 B2 B3 B4
	// C1 C2 C3 C4
	// D1 D2 D3 D4
	mat4(
		T a_One, T a_Two, T a_Three, T a_Four,
		T b_One, T b_Two, T b_Three, T b_Four,
		T c_One, T c_Two, T c_Three, T c_Four,
		T d_One, T d_Two, T d_Three, T d_Four);
	mat4(const mat4<T> & copy);
	~mat4();
	mat4<T> operator + (mat4<T> param);
	mat4<T> operator += (mat4<T> param);
	mat4<T> operator - (mat4<T> param);
	mat4<T> operator -= (mat4<T> param);
	mat4<T> operator * (mat4<T> param);
	mat4<T> operator *= (mat4<T> param);
	mat4<T> operator * (T param);
	mat4<T> operator *= (T param);
	mat4<T> operator / (T param);
	mat4<T> operator /= (T param);
	bool operator == (mat4<T> param);
	bool operator != (mat4<T> param);
	static mat4<T> zero();
	static mat4<T> identity();
	static mat4<T> translationMatrix(vec3<T> _param);
	mat4<T> invertMatrix();
	mat4<T> transposeMatrix();
	mat4<T> getAdjunct();
	mat4<T> rotateMatrix(T & _angle, char _axis);
	mat4<T> rotateMatrix(vec3<T> param);
	mat4<T> rotationAboutAnArbitraryAxis(vec3<T> axis, T angle);
	mat4<T> scalingMatrix(vec3<T> _param);
	T get3x3Determinant(T _I11, T _D11, T _I12, T _D12, T _I13, T _D13);

	T I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44;
	T D11, D12, D13, D14, D21, D22, D23, D24, D31, D32, D33, D34, D41, D42, D43, D44;
};