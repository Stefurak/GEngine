#include "mat3.h"

template <class T>
mat3<T>::mat3() 
{
	// Empty
}

template <class T>
mat3<T>::mat3(
	T a_One, T a_Two, T a_Three,
	T b_One, T b_Two, T b_Three,
	T c_One, T c_Two, T c_Three)
{
	I11 = a_One;	I12 = a_Two;	I13 = a_Three;
	I21 = b_One;	I22 = b_Two;	I23 = b_Three;
	I31 = c_One;	I32 = c_Two;	I33 = c_Three;
}

/*

Copy Constructor

*/
template <class T>
mat3<T>::mat3(const mat3<T> & copy) :
I11(copy.I11),	I12(copy.I12),	I13(copy.I13),
I21(copy.I21),	I22(copy.I22),	I23(copy.I23),
I31(copy.I31),	I32(copy.I32),	I33(copy.I33)
{
	// Empty
}

/*

Destructor

*/
template <class T>
mat3<T>::~mat3() {}

/*
**operator + (mat3<T> & param)
Addition operator Overload
@param param mat3

*/
template <class T>
mat3<T> mat3<T>::operator + (mat3<T> & param)
{
	mat3<T> temp;
	temp.I11 = I11 + param.I11;		temp.I12 = I12 + param.I12;		temp.I13 = I13 + param.I13;
	temp.I21 = I21 + param.I21;		temp.I22 = I22 + param.I22;		temp.I23 = I23 + param.I23;
	temp.I31 = I31 + param.I31;		temp.I32 = I32 + param.I32;		temp.I33 = I33 + param.I33;
	return temp;
}

/*
**operator += (mat3<T> & param)
Assignment by Sum Operator Overload
@param param mat3

*/
template <class T>
mat3<T> mat3<T>::operator += (mat3<T> & param)
{
	mat3<T> temp;
	return temp = temp + param;
}

/*
**operator - (mat3<T> & param)
Subtraction operator Overload
@param param mat3

*/
template <class T>
mat3<T> mat3<T>::operator - (mat3<T> & param)
{
	mat3<T> temp;
	temp.I11 = I11 - param.I11;		temp.I12 = I12 - param.I12;		temp.I13 = I13 - param.I13;
	temp.I21 = I21 - param.I21;		temp.I22 = I22 - param.I22;		temp.I23 = I23 - param.I23;
	temp.I31 = I31 - param.I31;		temp.I32 = I32 - param.I32;		temp.I33 = I33 - param.I33;
	return temp;
}

/*
**operator -= (mat3<T> & param)
Assignment by Difference Operator Overload
@param param mat3

*/
template <class T>
mat3<T> mat3<T>::operator -= (mat3<T> & param)
{
	mat3<T> temp;
	temp.I11 = I11 -= param.I11;		temp.I12 = I12 -= param.I12;		temp.I13 = I13 -= param.I13;
	temp.I21 = I21 -= param.I21;		temp.I22 = I22 -= param.I22;		temp.I23 = I23 -= param.I23;
	temp.I31 = I31 -= param.I31;		temp.I32 = I32 -= param.I32;		temp.I33 = I33 -= param.I33;
	return temp;
}

/*
**operator * (mat3<T> & param)
Multiplication operator Overload
@param param mat3

*/
template <class T>
mat3<T> mat3<T>::operator * (mat3<T> & param)
{
	mat3<T> temp;
	temp.I11 = (I11 * param.I11) + (I12 * param.I21) + (I13 * param.I31);
	temp.I12 = (I11 * param.I12) + (I12 * param.I22) + (I13 * param.I32);
	temp.I13 = (I11 * param.I13) + (I12 * param.I23) + (I13 * param.I33);

	temp.I21 = (I21 * param.I11) + (I22 * param.I21) + (I23 * param.I31);
	temp.I22 = (I21 * param.I12) + (I22 * param.I22) + (I23 * param.I32);
	temp.I23 = (I21 * param.I13) + (I22 * param.I23) + (I23 * param.I33);

	temp.I31 = (I31 * param.I11) + (I32 * param.I21) + (I33 * param.I31);
	temp.I32 = (I31 * param.I12) + (I32 * param.I22) + (I33 * param.I32);
	temp.I33 = (I31 * param.I13) + (I32 * param.I23) + (I33 * param.I33);

	return temp;
}

/*
**operator *= (mat3<T> & param)
Assignment by Product operator Overload
@param param mat3

*/
template <class T>
mat3<T> mat3<T>::operator *= (mat3<T> & param)
{
	mat3<T> temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);
	return temp = temp * param;
}

/*
**operator * (T & param)
Multiplication operator Overload
@param param T

*/
template <class T>
mat3<T> mat3<T>::operator * (T & param)
{
	mat3<T> temp;

	temp.I11 = I11 * param;		temp.I12 = I12 * param;		temp.I13 = I13 * param;
	temp.I21 = I21 * param;		temp.I22 = I22 * param;		temp.I23 = I23 * param;
	temp.I31 = I31 * param;		temp.I32 = I32 * param;		temp.I33 = I33 * param;

	return temp;
}

/*
**operator *= (T & param)
Assignment by Product operator Overload
@param param T

*/
template <class T>
mat3<T> mat3<T>::operator *= (T & param)
{
	mat3<T> temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);
	temp.I11 = I11 *= param;		temp.I12 = I12 *= param;		temp.I13 = I13 *= param;
	temp.I21 = I21 *= param;		temp.I22 = I22 *= param;		temp.I23 = I23 *= param;
	temp.I31 = I31 *= param;		temp.I32 = I32 *= param;		temp.I33 = I33 *= param;
	return temp;
}

/*
**operator / (T & param)
Division operator Overload
@param param T

*/
template <class T>
mat3<T> mat3<T>::operator / (T & param)
{
	mat3<T> temp;
	if (param > (T)0.0 || param < (T)0.0)
	{
		temp.I11 = I11 / param;		temp.I12 = I12 / param;		temp.I13 = I13 / param;
		temp.I21 = I21 / param;		temp.I22 = I22 / param;		temp.I23 = I23 / param;
		temp.I31 = I31 / param;		temp.I32 = I32 / param;		temp.I33 = I33 / param;
	}
	return temp;
}

/*
operator /= (T & param)
Assignment by Quotient operator Overload
@param param T

*/
template <class T>
mat3<T> mat3<T>::operator /= (T & param)
{
	mat3<T> temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);
	if (param > (T)0.0 || param < (T)0.0)
	{
		temp.I11 = I11 /= param;		temp.I12 = I12 /= param;		temp.I13 = I13 /= param;
		temp.I21 = I21 /= param;		temp.I22 = I22 /= param;		temp.I23 = I23 /= param;
		temp.I31 = I31 /= param;		temp.I32 = I32 /= param;		temp.I33 = I33 /= param;
	}

	return temp;
}

/*
**operator == (mat3<T> & param)
Equality operator overload

*/
template <class T>
bool mat3<T>::operator == (mat3<T> & param)
{
	if (I11 == param.I11 && I12 == param.I12 && I13 == param.I13 &&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33) return true;
	else return false;
}

/*
**operator != (mat3<T> & param)
Inequality operator overload

*/
template <class T>
bool mat3<T>::operator != (mat3<T> & param)
{
	if (I11 == param.I11 && I12 == param.I12 && I13 == param.I13 &&
		I21 == param.I21 && I22 == param.I22 && I23 == param.I23 &&
		I31 == param.I31 && I32 == param.I32 && I33 == param.I33) return false;
	else return true;
}

/*
**zero()
Returns a mat3 initialized to zero

*/
template <class T>
mat3<T> mat3<T>::zero()
{
	return mat3<T>(
		(T)0.0, (T)0.0, (T)0.0,
		(T)0.0, (T)0.0, (T)0.0,
		(T)0.0, (T)0.0, (T)0.0);
}

/*
**identity()
Returns the identity mat3

*/
template <class T>
mat3<T> mat3<T>::identity()
{
	return mat3<T>(
		(T)1.0, (T)0.0, (T)0.0,
		(T)0.0, (T)1.0, (T)0.0,
		(T)0.0, (T)0.0, (T)1.0);
}

/*
invertMatrix()
Returns the inverted mat3 of a given mat3

*/
template <class T>
mat3<T> mat3<T>::invertMatrix()
{
	mat3<T> temp;
	T determinant;

	temp.I11 = D11 = (I22 * I33) - (I32 * I23);		temp.I12 = D12 = (I21 * I33) - (I31 * I23);		temp.I13 = D13 = (I21 * I32) - (I31 * I22);
	temp.I21 = D21 = (I12 * I33) - (I32 * I13);		temp.I22 = D22 = (I11 * I33) - (I31 * I13);		temp.I23 = D23 = (I11 * I32) - (I31 * I12);
	temp.I31 = D31 = (I12 * I23) - (I22 * I13);		temp.I32 = D32 = (I11 * I23) - (I21 * I13);		temp.I33 = D33 = (I11 * I22) - (I21 * I12);

	temp = temp.getAdjunct();

	temp.transposeMatrix();

	determinant = get3x3Determinant(I11, D11, I12, D12, I13, D13);

	temp = temp / determinant;

	return temp;
}

/*
**transposeMatrix()
Returns the transose mat3 of a given mat3

*/
template <class T>
mat3<T> mat3<T>::transposeMatrix()
{
	mat3<T> transpose;

	transpose.I11 = I11;		transpose.I12 = I21;		transpose.I13 = I31;
	transpose.I21 = I12;		transpose.I22 = I22;		transpose.I23 = I32;
	transpose.I31 = I13;		transpose.I32 = I23;		transpose.I33 = I33;

	return transpose;
}

/*
**getAdjunct()
Returns the adjunct mat3 of a given mat3

*/
template <class T>
mat3<T> mat3<T>::getAdjunct()
{
	mat3<T> temp(I11, I12, I13, I21, I22, I23, I31, I32, I33);

	temp.I12 != (T)0.0 ? temp.I12 *= (T)-1.0 : temp.I12;		temp.I21 != (T)0.0 ? temp.I21 *= (T)-1.0 : temp.I21;
	temp.I23 != (T)0.0 ? temp.I23 *= (T)-1.0 : temp.I23;		temp.I32 != (T)0.0 ? temp.I32 *= (T)-1.0 : temp.I32;


	return temp;
}

/*
**rotateMatrix(T angle, char axis)
Pass in the angle and the axis you wish to rotate on
Returns a matrix that will rotate a mat3 on that axis by that angle

*/
template <class T>
mat3<T> mat3<T>::rotateMatrix(T angle, char axis)
{
	mat3<T> temp;

	if (axis == 'x' || axis == 'X')
	{
		mat3<T> rotateByFloat(
			(T)1.0, (T)0.0, (T)0.0,
			(T)0.0, (T)cos((angle * PI) / (T)180.0), (T)-sin((angle * PI) / (T)180.0),
			(T)0.0, (T)sin((angle * PI) / (T)180.0), (T)cos((angle * PI) / (T)180.0));
		temp = rotateByFloat;
		return temp;
	}

	if (axis == 'y' || axis == 'Y')
	{
		mat3<T> rotateByFloat(
			(T)cos((angle * PI) / (T)180.0), (T)-sin((angle * PI) / (T)180.0), (T)0.0,
			(T)sin((angle * PI) / (T)180.0), (T)cos((angle * PI) / (T)180.0), (T)0.0,
			(T)0.0, (T)0.0, (T)1.0);
		temp = rotateByFloat;
		return temp;
	}

	if (axis == 'z' || axis == 'Z')
	{
		mat3<T> rotateByFloat(
			(T)cos((angle * PI) / (T)180.0), (T)0.0, (T)sin((angle * PI) / (T)180.0),
			(T)0, (T)1, (T)0,
			-(T)sin((angle * PI) / (T)180.0), (T)0.0, (T)cos((angle * PI) / (T)180.0));
		temp = rotateByFloat;
		return temp;
	}

	if (axis != 'x' && axis != 'X' && axis != 'y' && axis != 'Y' && axis != 'z' && axis != 'Z')
	{
		return mat3<T>::zero();
	}
	return temp;
}

/*

**get3x3Determinant(T _I11, T _D11, T _I12, T _D12, T _I13, T _D13)
Returns the determinant of a given matrix

*/
template <class T>
T mat3<T>::get3x3Determinant(T _I11, T _D11, T _I12, T _D12, T _I13, T _D13)
{
	return ((_I11 * _D11) + (_I12 * _D12) + (_I13 * _D13));
}

/*
**scalingfMatrix(T param)
Returns a mat3 that can be used to scale a mat3

*/
template <class T>
mat3<T> mat3<T>::scalingfMatrix(T param)
{
	mat3<T> temp(
		param, (T)0.0, (T)0.0,
		(T)0.0, param, (T)0.0,
		(T)0.0, (T)0.0, param);
	return *(this) * temp;
}

template class mat3 < float >;
template class mat3 < double >;