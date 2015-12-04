#include "mat4.h"

/*

Constructors

*/
template <class T>
mat4<T>::mat4() 
{
	// Empty
}

// A1 A2 A3 A4
// B1 B2 B3 B4
// C1 C2 C3 C4
// D1 D2 D3 D4
template <class T>
mat4<T>::mat4(
	T a_One, T a_Two, T a_Three, T a_Four,
	T b_One, T b_Two, T b_Three, T b_Four,
	T c_One, T c_Two, T c_Three, T c_Four,
	T d_One, T d_Two, T d_Three, T d_Four)
{
	I11 = a_One;		I12 = a_Two;		I13 = a_Three;		I14 = a_Four;
	I21 = b_One;		I22 = b_Two;		I23 = b_Three;		I24 = b_Four;
	I31 = c_One;		I32 = c_Two;		I33 = c_Three;		I34 = c_Four;
	I41 = d_One;		I42 = d_Two;		I43 = d_Three;		I44 = d_Four;
}

/*

Copy Constructor

*/
template <class T>
mat4<T>::mat4(const mat4<T> & copy) :
I11(copy.I11), I12(copy.I12), I13(copy.I13), I14(copy.I14),
I21(copy.I21), I22(copy.I22), I23(copy.I23), I24(copy.I24),
I31(copy.I31), I32(copy.I32), I33(copy.I33), I34(copy.I34),
I41(copy.I41), I42(copy.I42), I43(copy.I43), I44(copy.I44)
{
	// Empty
}

/*

Destructor

*/
template <class T>
mat4<T>::~mat4() {}

/*
**operator + (mat4<T> & param)
Addition Operator Overload
@param param mat4

*/
template <class T>
mat4<T> mat4<T>::operator + (mat4<T> param)
{
	mat4<T> temp;
	temp.I11 = I11 + param.I11;		temp.I12 = I12 + param.I12;		temp.I13 = I13 + param.I13;		temp.I14 = I14 + param.I14;
	temp.I21 = I21 + param.I21;		temp.I22 = I22 + param.I22;		temp.I23 = I23 + param.I23;		temp.I24 = I24 + param.I24;
	temp.I31 = I31 + param.I31;		temp.I32 = I32 + param.I32;		temp.I33 = I33 + param.I33;		temp.I34 = I34 + param.I34;
	temp.I41 = I41 + param.I41;		temp.I42 = I42 + param.I42;		temp.I43 = I43 + param.I43;		temp.I44 = I44 + param.I44;
	return temp;
}

/*
**operator += (mat4<T> param)
Assignment by Sum Operator Overload
@param param mat4

*/
template <class T>
mat4<T> mat4<T>::operator += (mat4<T> param)
{
	mat4<T> temp;
	return temp = temp + param;
}

/*
**operator - (mat4<T> param)
Subtraction Operator Overload
@param param mat4

*/
template <class T>
mat4<T> mat4<T>::operator - (mat4<T> param)
{
	mat4<T> temp;
	temp.I11 = I11 - param.I11;		temp.I12 = I12 - param.I12;		temp.I13 = I13 - param.I13;		temp.I14 = I14 - param.I14;
	temp.I21 = I21 - param.I21;		temp.I22 = I22 - param.I22;		temp.I23 = I23 - param.I23;		temp.I24 = I24 - param.I24;
	temp.I31 = I31 - param.I31;		temp.I32 = I32 - param.I32;		temp.I33 = I33 - param.I33;		temp.I34 = I34 - param.I34;
	temp.I41 = I41 - param.I41;		temp.I42 = I42 - param.I42;		temp.I43 = I43 - param.I43;		temp.I44 = I44 - param.I44;
	return temp;
}

/*
**operator -= (mat4<T> param)
Assignment by Difference operator Overload
@param param mat4

*/
template <class T>
mat4<T> mat4<T>::operator -= (mat4<T> param)
{
	mat4<T> temp;
	return temp = temp - param;
}

/*
**operator * (mat4<T> param)
Multiplication Operator overload
@param param mat4
Dumptruck method

*/
template <class T>
mat4<T> mat4<T>::operator * (mat4<T> param)
{
	mat4<T> temp;
	//ROW 1
	temp.I11 = (I11 * param.I11) + (I12 * param.I21) + (I13 * param.I31) + (I14 * param.I41);
	temp.I12 = (I11 * param.I12) + (I12 * param.I22) + (I13 * param.I32) + (I14 * param.I42);
	temp.I13 = (I11 * param.I13) + (I12 * param.I23) + (I13 * param.I33) + (I14 * param.I43);
	temp.I14 = (I11 * param.I14) + (I12 * param.I24) + (I13 * param.I34) + (I14 * param.I44);

	//ROW 2
	temp.I21 = (I21 * param.I11) + (I22 * param.I21) + (I23 * param.I31) + (I24 * param.I41);
	temp.I22 = (I21 * param.I12) + (I22 * param.I22) + (I23 * param.I32) + (I24 * param.I42);
	temp.I23 = (I21 * param.I13) + (I22 * param.I23) + (I23 * param.I33) + (I24 * param.I43);
	temp.I24 = (I21 * param.I14) + (I22 * param.I24) + (I23 * param.I34) + (I24 * param.I44);

	//ROW 3
	temp.I31 = (I31 * param.I11) + (I32 * param.I21) + (I33 * param.I31) + (I34 * param.I41);
	temp.I32 = (I31 * param.I12) + (I32 * param.I22) + (I33 * param.I32) + (I34 * param.I42);
	temp.I33 = (I31 * param.I13) + (I32 * param.I23) + (I33 * param.I33) + (I34 * param.I43);
	temp.I34 = (I31 * param.I14) + (I32 * param.I24) + (I33 * param.I34) + (I34 * param.I44);

	//ROW 4
	temp.I41 = (I41 * param.I11) + (I42 * param.I21) + (I43 * param.I31) + (I44 * param.I41);
	temp.I42 = (I41 * param.I12) + (I42 * param.I22) + (I43 * param.I32) + (I44 * param.I42);
	temp.I43 = (I41 * param.I13) + (I42 * param.I23) + (I43 * param.I33) + (I44 * param.I43);
	temp.I44 = (I41 * param.I14) + (I42 * param.I24) + (I43 * param.I34) + (I44 * param.I44);

	return temp;
}

/*
**operator *= (mat4<T> param)
Assignment by Product Operator overload
@param param mat4

*/
template <class T>
mat4<T> mat4<T>::operator *= (mat4<T> param)
{
	mat4<T> temp(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);
	return temp = temp * param;
}

/*
**operator * (T param)
Multiplication Operator Overload
@param param T

*/
template <class T>
mat4<T> mat4<T>::operator * (T param)
{
	mat4<T> temp;
	temp.I11 = I11 * param;		temp.I12 = I12 * param;		temp.I13 = I13 * param;		temp.I14 = I14 * param;
	temp.I21 = I21 * param;		temp.I22 = I22 * param;		temp.I23 = I23 * param;		temp.I24 = I24 * param;
	temp.I31 = I31 * param;		temp.I32 = I32 * param;		temp.I33 = I33 * param;		temp.I34 = I34 * param;
	temp.I41 = I41 * param;		temp.I42 = I42 * param;		temp.I43 = I43 * param;		temp.I44 = I44 * param;
	return temp;
}

/*
**operator *= (T param)
Assignment by Product Operator Overload
@param param T

*/
template <class T>
mat4<T> mat4<T>::operator *= (T param)
{
	mat4<T> temp(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);
	temp.I11 = I11 *= param;		temp.I12 = I12 *= param;		temp.I13 = I13 *= param;		temp.I14 = I14 *= param;
	temp.I21 = I21 *= param;		temp.I22 = I22 *= param;		temp.I23 = I23 *= param;		temp.I24 = I24 *= param;
	temp.I31 = I31 *= param;		temp.I32 = I32 *= param;		temp.I33 = I33 *= param;		temp.I34 = I34 *= param;
	temp.I41 = I41 *= param;		temp.I42 = I42 *= param;		temp.I43 = I43 *= param;		temp.I44 = I44 *= param;
	return temp;
}

/*
**operator / (T param)
Division Operator Overload
@param param T

*/
template <class T>
mat4<T> mat4<T>::operator / (T param)
{
	mat4<T> temp;
	if (param > (T)0.0 || param < (T)0.0)
	{
		temp.I11 = I11 / param;		temp.I12 = I12 / param;		temp.I13 = I13 / param;		temp.I14 = I14 / param;
		temp.I21 = I21 / param;		temp.I22 = I22 / param;		temp.I23 = I23 / param;		temp.I24 = I24 / param;
		temp.I31 = I31 / param;		temp.I32 = I32 / param;		temp.I33 = I33 / param;		temp.I34 = I34 / param;
		temp.I41 = I41 / param;		temp.I42 = I42 / param;		temp.I43 = I43 / param;		temp.I44 = I44 / param;
	}
	return temp;
}

/*
**operator /= (T param)
Assignment by Quotient operator overload
@param param T

*/
template <class T>
mat4<T> mat4<T>::operator /= (T param)
{
	mat4<T> temp(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);
	if (param > (T)0.0 || param < (T)0.0)
	{
		temp.I11 = I11 /= param;		temp.I12 = I12 /= param;		temp.I13 = I13 /= param;		temp.I14 = I14 /= param;
		temp.I21 = I21 /= param;		temp.I22 = I22 /= param;		temp.I23 = I23 /= param;		temp.I24 = I24 /= param;
		temp.I31 = I31 /= param;		temp.I32 = I32 /= param;		temp.I33 = I33 /= param;		temp.I34 = I34 /= param;
		temp.I41 = I41 /= param;		temp.I42 = I42 /= param;		temp.I43 = I43 /= param;		temp.I44 = I44 /= param;
	}
	return temp;
}

/*
**operator == (mat4<T> param)
Equality Operator overload


*/
template <class T>
bool mat4<T>::operator == (mat4<T> param)
{
	if (I11 == param.I11 && I12 == param.I12	&& I13 == param.I13	&& I14 == param.I14	&&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 && I24 == param.I24 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33 && I34 == param.I34 &&
		I41 == param.I41 && I42 == param.I42 && I43 == param.I43 && I44 == param.I44) return true;
	else return false;
}

/*
**operator != (mat4<T> param)
Inequality Operator overload


*/
template <class T>
bool mat4<T>::operator != (mat4<T> param)
{
	if (I11 != param.I11 || I12 != param.I12 || I13 != param.I13 || I14 != param.I14 ||
		I21 != param.I21 || I22 != param.I22 || I23 != param.I23 || I24 != param.I24 ||
		I31 != param.I31 || I32 != param.I32 || I33 != param.I33 || I34 != param.I34 ||
		I41 != param.I41 || I42 != param.I42 || I43 != param.I43 || I44 != param.I44) return true;
	else return false;
}

/*
**zero()
Returns a mat4 initialized to zero

*/
template <class T>
mat4<T> mat4<T>::zero()
{
	return mat4<T>(
		(T)0.0, (T)0.0, (T)0.0, (T)0.0,
		(T)0.0, (T)0.0, (T)0.0, (T)0.0,
		(T)0.0, (T)0.0, (T)0.0, (T)0.0,
		(T)0.0, (T)0.0, (T)0.0, (T)0.0);
}

/*
**identity()
Returns the identity mat4

*/
template <class T>
mat4<T> mat4<T>::identity()
{
	return mat4<T>(
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0);

}

/*
**translationMatrix(vec3<T> _param)
Returns a mat4 that will translate a mat4 by the given vec3

*/
template <class T>
mat4<T> mat4<T>::translationMatrix(vec3<T> _param)
{
	return mat4<T>(
		(T)1.0, (T)0.0, (T)0.0, (T)0.0,
		(T)0.0, (T)1.0, (T)0.0, (T)0.0,
		(T)0.0, (T)0.0, (T)1.0, (T)0.0,
		_param.x, _param.y, _param.z, (T)1.0);
}

/*
**invertMatrix()
Returns the inverted mat4 for a given mat4

*/
template <class T>
mat4<T> mat4<T>::invertMatrix()
{
	mat4<T> returnMatrix(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);

	T Determinant = (T)0.0;
	mat3<T> temp(I22, I23, I24, I32, I33, I34, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I21, I23, I24, I31, I33, I34, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I21, I22, I24, I31, I32, I34, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I21, I22, I23, I31, I32, I33, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I12, I13, I14, I32, I33, I34, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I13, I14, I31, I33, I34, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I12, I14, I31, I32, I34, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I12, I13, I31, I32, I33, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I12, I13, I14, I22, I23, I24, I42, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I13, I14, I21, I23, I24, I41, I43, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I12, I14, I21, I22, I24, I41, I42, I44);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I12, I13, I21, I22, I23, I41, I42, I43);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I12, I13, I14, I22, I23, I24, I32, I33, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I13, I14, I21, I23, I24, I31, I33, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I12, I14, I21, I22, I24, I31, I32, I34);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	temp = mat3<T>(I11, I12, I13, I21, I22, I23, I31, I32, I33);
	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	Determinant += get3x3Determinant(temp.I11, D11, temp.I12, D12, temp.I13, D13);

	returnMatrix = returnMatrix.getAdjunct();

	returnMatrix.transposeMatrix();

	returnMatrix = returnMatrix / Determinant;

	return returnMatrix;
}

/*
**transposeMatrix()
Returns the transpose mat4 for a given mat4

*/
template <class T>
mat4<T> mat4<T>::transposeMatrix()
{
	mat4<T> transpose;

	transpose.I11 = I11;		transpose.I12 = I21;		transpose.I13 = I31;		transpose.I14 = I41;
	transpose.I21 = I12;		transpose.I22 = I22;		transpose.I23 = I32;		transpose.I24 = I42;
	transpose.I31 = I13;		transpose.I32 = I23;		transpose.I33 = I33;		transpose.I34 = I43;
	transpose.I41 = I14;		transpose.I42 = I24;		transpose.I43 = I34;		transpose.I44 = I44;

	return transpose;
}

/*
**getAdjunct()
Returns the adjunct mat4 for a given mat4

*/
template <class T>
mat4<T> mat4<T>::getAdjunct()
{
	mat4<T> temp(I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44);

	temp.I12 != (T)0.0 ? temp.I12 *= (T)-1.0 : temp.I12;		temp.I14 != (T)0.0 ? temp.I14 *= (T)-1.0 : temp.I14;		temp.I21 != (T)0.0 ? temp.I21 *= (T)-1.0 : temp.I21;
	temp.I23 != (T)0.0 ? temp.I23 *= (T)-1.0 : temp.I23;		temp.I32 != (T)0.0 ? temp.I32 *= (T)-1.0 : temp.I32;		temp.I34 != (T)0.0 ? temp.I34 *= (T)-1.0 : temp.I34;
	temp.I41 != (T)0.0 ? temp.I41 *= (T)-1.0 : temp.I41;		temp.I43 != (T)0.0 ? temp.I43 *= (T)-1.0 : temp.I43;

	return temp;
}

/*
**rotateMatrix(T _angle, char _axis)
Pass in the angle and the axis you wish to rotate on
Returns a matrix that will rotate a mat4 on that axis by that angle

*/
template <typename T>
mat4<T> mat4<T>::rotateMatrix(T & _angle, char _axis)
{
	mat4<T> temp;
	T c = ::cos((_angle * PI) / (T)180.0);
	T s = ::sin((_angle * PI) / (T)180.0);

	if (_axis == 'x' || _axis == 'X')
	{
		//Type this into WolfRam Alpha
		//replace the 30.0 with the angle you are using to prove it works
		// [{1.0, 0.0, 0.0, 0.0} ,{0.0, cos(30), -sin(30), 0.0}, {0.0, sin(30), cos(30), 0.0}, {0.0, 0.0, 0.0, 1.0}]
		mat4<T> rotateByFloat(
			(T)1.0, (T)0.0, (T)0.0, (T)0.0,
			(T)0.0, c, -s, (T)0.0,
			(T)0.0, s, c, (T)0.0,
			(T)0.0, (T)0.0, (T)0.0, (T)1.0);
		temp = rotateByFloat;
		return temp;
	}

	if (_axis == 'y' || _axis == 'Y')
	{
		mat4<T> rotateByFloat(
			c, (T)0.0, s, (T)0.0,
			(T)0.0, (T)1.0, (T)0.0, (T)0.0,
			-s, (T)0.0, c, (T)0.0,
			(T)0.0, (T)0.0, (T)0.0, (T)1.0);
		temp = rotateByFloat;
		return temp;
	}

	if (_axis == 'z' || _axis == 'Z')
	{
		mat4<T> rotateByFloat(
			c, -s, (T)0.0, (T)0.0,
			s, c, (T)0.0, (T)0.0,
			(T)0.0, (T)0.0, (T)1.0, (T)0.0,
			(T)0.0, (T)0.0, (T)0.0, (T)1.0);
		temp = rotateByFloat;
		return temp;
	}

	if (_axis != 'x' && _axis != 'X' && _axis != 'y' && _axis != 'Y' && _axis != 'z' && _axis != 'Z')
	{
		mat4<T>::identity();
	}
	return temp;
}

/*
**rotateMatrix(vec3<T> param)
Returns a mat4 that can be used to rotate a mat4
That was based on Euler Angles
There are twelve possible permutations 
for this RotateMatrix Class to add here
xyz, yzx, zxy, zyx, xzy, yxz, xyx, xzx, yxy, yzy, zxz, zyz
passing in a vec3<T> gives strat values of x,y,z so calculation is done 
Z * Y * X
*/
template <class T>
mat4<T> mat4<T>::rotateMatrix(vec3<T> param)
{
	mat4<T> temp;
	return temp.rotateMatrix(param.z, 'z') * temp.rotateMatrix(param.y, 'y') * temp.rotateMatrix(param.x, 'x');
}

/*
**arbitraryAxis(vec3<T> axis, T angle)


*/
template <class T>
mat4<T> mat4<T>::rotationAboutAnArbitraryAxis(vec3<T> axis, T angle)
{
	axis = axis.normalize();
	float s = sin((angle * PI) / (T)180.0);
	float c = cos((angle * PI) / (T)180.0);
	float oc = 1.0 - c;

	return mat4<T>(
		oc * axis.x * axis.x + c, oc * axis.x * axis.y - axis.z * s, oc * axis.z * axis.x + axis.y * s, 0.0,
		oc * axis.x * axis.y + axis.z * s, oc * axis.y * axis.y + c, oc * axis.y * axis.z - axis.x * s, 0.0,
		oc * axis.z * axis.x - axis.y * s, oc * axis.y * axis.z + axis.x * s, oc * axis.z * axis.z + c, 0.0,
		0.0, 0.0, 0.0, 1.0);
}

/*
**scalingMatrix(vec3 _param)
Returns a mat4 that can be used to scale a mat4

*/
template <class T>
mat4<T> mat4<T>::scalingMatrix(vec3<T> _param)
{
	mat4<T> temp(
		_param.x, (T)0.0, (T)0.0, (T)0.0,
		(T)0.0, _param.y, (T)0.0, (T)0.0,
		(T)0.0, (T)0.0, _param.z, (T)0.0,
		(T)0.0, (T)0.0, (T)0.0, (T)1.0);
	return *(this) * temp;
}

/*
**get3x3Determinant(T _I11, T _D11, T _I12, T _D12, T _I13, T _D13)
returns the determinant of a given mat4

*/
template <class T>
T mat4<T>::get3x3Determinant(T _I11, T _D11, T _I12, T _D12, T _I13, T _D13)
{
	return ((_I11 * _D11) + (_I12 * _D12) + (_I13 * _D13));
}

template class mat4 < float >;
template class mat4 < double >;