#include "vec3.h"

/*

Constructors

*/
template <class T>
vec3<T>::vec3() 
{
	// Empty
}

template <class T>
vec3<T>::vec3(T _x, T _y, T _z)
{
	x = _x; y = _y; z = _z;
}

/*

Copy Constructor

*/
template <class T>
vec3<T>::vec3(const vec3<T> & copy) :
x(copy.x), y(copy.y), z(copy.z)
{
	// Empty
}

/*

Destructor

*/
template <class T>
vec3<T>::~vec3() {}

/*
**operator + (vec3<T> & param)
Addition Operator Overload
@param param vec3

*/
template <class T>
vec3<T> vec3<T>::operator + (vec3<T> & param)
{
	vec3<T> temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	temp.z = z + param.z;
	return temp;
}

/*
**operator += (vec3<T> & param)
Assignment by Sum Operator Overload
@param param vec3

*/
template <class T>
vec3<T> vec3<T>::operator += (vec3<T> & param)
{
	vec3<T> temp;
	temp.x = x += param.x;
	temp.y = y += param.y;
	temp.z = z += param.z;
	return temp;
}

/*
**operator - (vec3<T> & param)
Subtraction operator Overload
@param param vec3

*/
template <class T>
vec3<T> vec3<T>::operator - (vec3<T> & param)
{
	vec3<T> temp;
	temp.x = x - param.x;
	temp.y = y - param.y;
	temp.z = z - param.z;
	return temp;
}

/*
**operator -= (vec3<T> & param)
Assignment by Difference Operator Overload
@param param vec3

*/
template <class T>
vec3<T> vec3<T>::operator -= (vec3<T> & param)
{
	vec3<T> temp;
	temp.x = x -= param.x;
	temp.y = y -= param.y;
	temp.z = z -= param.z;
	return temp;
}

/*
**operator *= (vec3<T> & param)
Assignment by Product operator Overload
@param param vec3

*/
template <class T>
vec3<T> vec3<T>::operator *= (vec3<T> & param)
{
	vec3<T> temp;
	temp.x = x *= param.x;
	temp.y = y *= param.y;
	temp.z = z *= param.z;
	return temp;
}

/*
**operator *= (T param)
Assignment by Product Operator Overload
@param param T

*/
template <class T>
vec3<T> vec3<T>::operator *= (T param)
{
	vec3<T> temp;
	temp.x = x *= param;
	temp.y = y *= param;
	temp.z = z *= param;
	return temp;
}

/*
**operator *= (T param)
Assignment by Product Operator Overload
@param param T

*/
template <class T>
vec3<T> vec3<T>::operator * (T param)
{
	return vec3<T>(x * param, y * param, z * param);
}

/*
**operator / (T param)
Division Operator Overload
@param param T

*/
template <class T>
vec3<T> vec3<T>::operator / (T param)
{
	vec3<T> temp;
	if (param > (T)0.0 || param < (T)0.0)
	{
		temp.x = x / param;
		temp.y = y / param;
		temp.z = z / param;
	}
	return temp;
}

/*
**operator /= (T param)
Assignment by Quotient operator Overload
@param param T

*/
template <class T>
vec3<T> vec3<T>::operator /= (T param)
{
	vec3<T> temp;
	if (param > (T)0.0 || param < (T)0.0)
	{
		temp = temp / param;
	}
	return temp;
}

/*
**operator == (vec3<T> & param)
Equality operator overload

*/
template <class T>
bool vec3<T>::operator == (vec3<T> & param)
{
	if (x == param.x && y == param.y && z == param.z) return true;
	else return false;
}

/*
**operator != (vec3<T> & param)
Inequality operator Overload

*/
template <class T>
bool vec3<T>::operator != (vec3<T> & param)
{
	if (x == param.x && y == param.y && z == param.z) return false;
	else return true;
}

/*
**zero()
Returns a vec3 initialized to 0
vec3(0,0,0)

*/
template <class T>
vec3<T> vec3<T>::zero()
{
	return vec3<T>((T)0.0, (T)0.0, (T)0.0);
}

/*
**one()
Returns a vec3 initialized to 1
vec3(1,1,1)

*/
template <class T>
vec3<T> vec3<T>::one()
{
	return vec3<T>((T)1.0, (T)1.0, 1.0);
}

/*
**upVector()
Returns a vec3 that points up along the y axis
positive y

*/
template <class T>
vec3<T> vec3<T>::upVector()
{
	return vec3<T>((T)0.0, (T)1.0, (T)0.0);
}

/*
**rightVector()
Returns a vec3 that points right along the x axis
positive x

*/
template <class T>
vec3<T> vec3<T>::rightVector()
{
	return vec3<T>((T)1.0, (T)0.0, (T)0.0);
}

/*
**forwardVector()
Returns a vec3 that points forward along the z axis
positive z

*/
template <class T>
vec3<T> vec3<T>::forwardVector()
{
	return vec3<T>((T)0.0, (T)0.0, (T)1.0);
}

/*
**normalize()
Returns the normalized vec3

*/
template <class T>
vec3<T> vec3<T>::normalize()
{
	vec3<T> temp;
	T magnitude = ::sqrtf((x * x) + (y * y) + (z * z));

	if (magnitude != (T)0.0)
	{
		vec3<T> normal(x / magnitude, y / magnitude, z / magnitude);
		temp = normal;
	}
	else
	{
		magnitude = (T)1.0;
		vec3<T> normal(x / magnitude, y / magnitude, z / magnitude);
		temp = normal;
	}

	return temp;
}

/*
**cross(vec3<T> param)
Returns a vec3 which is the cross product of two vec3's
this vec3 crossed with the passed vec3

*/
template <class T>
vec3<T> vec3<T>::cross(vec3<T> param)
{
	vec3<T> temp;

	temp.x = ((y * param.z) - (z * param.y));
	temp.y = ((z * param.x) - (x * param.z));
	temp.z = ((x * param.y) - (y * param.x));

	return temp;
}

/*
**length()
Returns the length of a vec3

*/
template <class T>
T vec3<T>::length()
{
	return (T)::sqrtf(x * x + y * y + z * z);
}

/*
**dot(vec3<T> param1, vec3<T> param2)
Returns the dot product of two vec3's

*/
template <class T>
T vec3<T>::dot(vec3<T> param1, vec3<T> param2)
{
	return ((param1.x * param2.x) + (param1.y * param2.y) + (param1.z * param2.z));
}

template class vec3 < float >;
template class vec3 < double >;