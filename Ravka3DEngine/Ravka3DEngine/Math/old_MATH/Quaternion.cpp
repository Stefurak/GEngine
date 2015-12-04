#include "Quaternion.h"

/*

Constructor

*/
template <class T>
Quaternion<T>::Quaternion(void)
{
	// Empty
}

/*

Constructor

*/
template <class T>
Quaternion<T>::Quaternion(T _w, vec3<T> _v)
{
	s = _w;
	v = _v;
}

/*

Constructor

*/
template <class T>
Quaternion<T>::Quaternion(T _w, T _x, T _y, T _z)
{
	s = _w;
	v.x = _x;
	v.y = _y;
	v.z = _z;
}

/*

Copy Constructor

*/
template <class T>
Quaternion<T>::Quaternion(const Quaternion<T> & copy) :
s(copy.s), v(copy.v)
{
	// Empty
}

/*

Destructor

*/
template <class T>
Quaternion<T>::~Quaternion(void)
{
}

/*
**quaternionFromEulerAngles(T theta_z, T theta_y, T theta_x)
Make this quaternion from Euler Angles

*/
template <class T>
void Quaternion<T>::quaternionFromEulerAngles(T theta_z, T theta_y, T theta_x)
{
		T cos_z_2 = ::cos(0.5f * theta_z);
		T cos_y_2 = ::cos(0.5f * theta_y);
		T cos_x_2 = ::cos(0.5f * theta_x);

		T sin_z_2 = ::sin(0.5f * theta_z);
		T sin_y_2 = ::sin(0.5f * theta_y);
		T sin_x_2 = ::sin(0.5f * theta_x);

		// and now compute quaternion
		s   = cos_z_2 * cos_y_2 * cos_x_2 + sin_z_2 * sin_y_2 * sin_x_2;
		v.x = cos_z_2 * cos_y_2 * sin_x_2 - sin_z_2 * sin_y_2 * cos_x_2;
		v.y = cos_z_2 * sin_y_2 * cos_x_2 + sin_z_2 * cos_y_2 * sin_x_2;
		v.z = sin_z_2 * cos_y_2 * cos_x_2 - cos_z_2 * sin_y_2 * sin_x_2;
}

/*
**quaternionFromEulerAngles(const vec3<T> & angles)
Make this quaternion from Euler Angles

*/
template <class T>
void Quaternion<T>::quaternionFromEulerAngles(const vec3<T> & angles)
	{	
		T cos_z_2 = ::cos(0.5f * angles.z);
		T cos_y_2 = ::cos(0.5f * angles.y);
		T cos_x_2 = ::cos(0.5f * angles.x);

		T sin_z_2 = ::sin(0.5f * angles.z);
		T sin_y_2 = ::sin(0.5f * angles.y);
		T sin_x_2 = ::sin(0.5f * angles.x);

		// and now compute quaternion
		s   = cos_z_2 * cos_y_2 * cos_x_2 + sin_z_2 * sin_y_2 * sin_x_2;
		v.x = cos_z_2 * cos_y_2 * sin_x_2 - sin_z_2 * sin_y_2 * cos_x_2;
		v.y = cos_z_2 * sin_y_2 * cos_x_2 + sin_z_2 * cos_y_2 * sin_x_2;
		v.z = sin_z_2 * cos_y_2 * cos_x_2 - cos_z_2 * sin_y_2 * sin_x_2;		
	} 

/*
**operator = (Quaternion<T> q)
Direct Assignment Operator Overload
@param q - the assignment

*/
template <class T>
Quaternion<T> Quaternion<T>::operator = (Quaternion<T> q)
{ 
	s = q.s; 
	v = q.v; 
	return *this; 
}

/*
**operator + (Quaternion<T> q)
Addition Operator Overload
@param q - the addition

*/
template <class T>
Quaternion<T> Quaternion<T>::operator + (Quaternion<T> q)
{ 
	return Quaternion(s + q.s, v + q.v); 
}

/*
**operator - (Quaternion<T> q)
Subtraction Operator Overload
@param q - the difference

*/
template <class T>
Quaternion<T> Quaternion<T>::operator - (Quaternion<T> q)
{ 
	return Quaternion(s-q.s, v-q.v); 
}

/*
**operator * (Quaternion<T> q)
Multiplication operator Overload
@param q - the multiplier

*/
template <class T>
Quaternion<T> Quaternion<T>::operator * (Quaternion<T> q)
{	
	return Quaternion(
					s * q.s - v.x * q.v.x + v.y * q.v.y + v.z * q.v.z,
					v.y * q.v.z - v.z * q.v.y + s * q.v.x + v.x * q.s,
					v.z * q.v.x - v.x * q.v.z + s * q.v.y + v.y * q.s,
					v.x * q.v.y - v.y * q.v.x + s * q.v.z + v.z * q.s);
}

/*
**operator / (const Quaternion<T> q)
Division Operator Overload
@param q - const value divisor

*/
template <class T>
Quaternion<T> Quaternion<T>::operator / (const Quaternion<T> q)
{
	Quaternion p(q); 
	p.invert(); 
	return *this * p;
}

/*
**operator * (T scale)
Multiplication Operator Overload
@param scale - the multiplier

*/
template <class T>
Quaternion<T> Quaternion<T>::operator * (T scale)
{ 
	return Quaternion(s * scale, v * scale); 
}

/*
**operator / (T scale)
Division Operator Overload
@param scale - the divisor

*/
template <class T>
Quaternion<T> Quaternion<T>::operator / (T scale)
{ 
	return Quaternion(s / scale, v / scale); 
}

/*
**operator += (Quaternion<T> q)
Assignment by Sum Operator Overload
@param q - the addition

*/
template <class T>
Quaternion<T> Quaternion<T>::operator += (Quaternion<T> q)
{ 
	v += q.v; 
	s += q.s; 
	return *this; 
}

/*
**operator -= (Quaternion<T> q)
Assignment by Difference Operator Overload
@param q - the difference

*/
template <class T>
Quaternion<T> Quaternion<T>::operator -= (Quaternion<T> q)
{ 
	v -= q.v; 
	s -= q.s; 
	return *this; 
}

/*
**operator *= (Quaternion<T> q)
Assignment by Product Operator overload
@param q - the multiplier

*/
template <class T>
Quaternion<T> Quaternion<T>::operator *= (Quaternion<T> q)
{			
	T x = v.x;
	T y = v.y;
	T z = v.z;
	T sn = (s * q.s) - (v.x * q.v.x + v.y * q.v.y + v.z * q.v.z);

	v.x = y * q.v.z - z * q.v.y + s * q.v.x + x * q.s;
	v.y = z * q.v.x - x * q.v.z + s * q.v.y + y * q.s;
	v.z = x * q.v.y - y * q.v.x + s * q.v.z + z * q.s;
	s = sn;
	return *this;
}

/*
**operator *= (T scale)
Assignment by Product Operator overload
@param scale - the multiplier

*/
template <class T>
Quaternion<T> Quaternion<T>::operator *= (T scale)
{ 
	v *= scale; 
	s *= scale; 
	return *this; 
}

/*
**operator /= (T scale)
Assignment by Quotient Operator Overload
@param scale - divisor
*/
template <class T>
Quaternion<T> Quaternion<T>::operator /= (T scale)
{ 
	v /= scale; 
	s /= scale; 
	return *this; 
}

/*
**length_Squared()
Returns the length of this quaterion squared

*/
template <class T>
T Quaternion<T>::length()
{ 
	return (T)::sqrtf(s * s + v.x * v.x + v.y * v.y + v.z * v.z); 
}

/*
**


*/
template <class T>
T Quaternion<T>::length_Squared()
{ 
	return (T)(s * s + v.x * v.x + v.y * v.y + v.z * v.z); 
}

/*
**normalize()
Normalizes this quaternion

*/
template <class T>
void Quaternion<T>::normalize()
{ 
	*this /= length(); 
}

/*
**normalized()
Returns the normalized quaternion

*/
template <class T>
Quaternion<T> Quaternion<T>::normalized()
{ 
	return  *this / length(); 
}

/*
**conjugate()
conjugate this quaternion

*/
template <class T>
void Quaternion<T>::conjugate()
{ 
	v = v * (T)-1.0;
}

/*
**invert()
Inverts this quaternion

*/
template <class T>
void Quaternion<T>::invert()
{ 
	conjugate(); 
	*this /= length_Squared(); 
}

/*
**log()
Returns the logarithm of a quaternion = v * a where q = [cos(a), v * sin(a)]

*/
template <class T>
Quaternion<T> Quaternion<T>::log()
{
	T a = (T)::acosf(s);
	T sinOfA = (T)::sinf(a);
	Quaternion<T> quatReturn;

	quatReturn.s = 0.0;
	if (sinOfA > 0.0)
	{
		quatReturn.v.x = a * v.x/sinOfA;
		quatReturn.v.y = a * v.y/sinOfA;
		quatReturn.v.z = a * v.z/sinOfA;
	} else {
		quatReturn.v.x = quatReturn.v.y = quatReturn.v.z = 0.0;
	}
	return quatReturn;
}

/*
**exp()
Returns e ^ quaternion = exp(v * a) = [cos(a), vsin(a)]

*/
template <class T>
Quaternion<T> Quaternion<T>::exp()
{
	T a = (T)v.length();
	T sinOfA = (T)::sinf(a);
	T cosOfA = (T)::cosf(a);
	Quaternion<T> quatReturn;

	quatReturn.s = cosOfA;
	if (a > 0.0)
	{
		quatReturn.v.x = sinOfA * v.x / a;
		quatReturn.v.y = sinOfA * v.y / a;
		quatReturn.v.z = sinOfA * v.z / a;
	} else {
		quatReturn.v.x = quatReturn.v.y = quatReturn.v.z = 0.0;
	}
	return quatReturn;
}

/*
**dot(Quaternion<T> q1, Quaternion<T> q2)
Returns the dot product of to Quaternions
@param 1 q1 - Quaternion 1
@param 2 q2 - Quaternion 2

*/
template <class T>
T Quaternion<T>::dot(Quaternion<T> q1, Quaternion<T> q2)
{ 
	T fTemp;
	fTemp = q1.v.dot(q1.v, q2.v);
	return  fTemp + q1.s * q2.s; 
}

/*
**lerp(Quaternion<T> q1, Quaternion<T> q2, T t)
Linear interpolation
@param 1 q1 - Quaternion 1
@param 2 q2 - Quaternion 2
@param 3 t - interpolation value always between (0 - 1)
see more info here - http://www.itu.dk/people/erikdam/DOWNLOAD/98-5.pdf

*/
template <class T>
Quaternion<T> Quaternion<T>::lerp(Quaternion<T> q1, Quaternion<T> q2, T t)
{ 
	return (q1 * ((T)1.0 - t) + q2 * t).normalized(); 
}

/*
**slerp(Quaternion<T> q1, Quaternion<T> q2, T t)
This version of slerp checks for theta > 90
@param 1 q1 - Quaternion 1
@param 2 q2 - Quaternion 2
@param 3 t - the interpolation value always between (0 - 1)
see more info here - http://www.itu.dk/people/erikdam/DOWNLOAD/98-5.pdf

*/
template <class T>
Quaternion<T> Quaternion<T>::slerp(Quaternion<T> q1, Quaternion<T> q2, T t)
{
	Quaternion<T> q3;
	T dot = Quaternion<T>::dot(q1, q2);

	/*	dot = cos(theta)
		if (dot < 0), q1 and q2 are more than 90 degrees apart,
		so we can invert one to reduce spinning	*/
	if (dot < (T)0.0)
	{
		dot = dot * (T)-1.0;
		q3 = q2 * (T)-1.0;
	} else q3 = q2;
	
	if (dot < (T)0.95)
	{
		T angle = ::acosf(dot);
		return (q1 * ::sinf(angle * ((T)1.0 - t)) + q3 * ::sinf(angle * t)) / ::sinf(angle);
	} else // if the angle is small, use linear interpolation								
		return lerp(q1,q3,t);			
}

/*
**slerpNoInvert(Quaternion<T> q1, Quaternion<T> q2, T t)
This version of slerp, used by squad, does not check for theta > 90.
@param 1 q1 - Quaternion 1
@param 2 q2 - Quaternion 2
@param 3 t - the interpolation value always between (0 - 1)
see more info here - http://www.itu.dk/people/erikdam/DOWNLOAD/98-5.pdf

*/
template <class T>
Quaternion<T> Quaternion<T>::slerpNoInvert(Quaternion<T> q1, Quaternion<T> q2, T t)
{
	T dot = Quaternion<T>::dot(q1, q2);
	if (dot > (T)-0.95 && dot < (T)0.95)
	{
		T angle = ::acosf(dot);			
		return (q1 * ::sinf(angle * ((T)1.0 - t)) + q2 * ::sinf(angle * t)) / ::sinf(angle);
	} else  // if the angle is small, use linear interpolation								
		return lerp(q1,q2,t);				
}

/*
**squad(Quaternion<T> q1, Quaternion<T> q2, Quaternion<T> a, Quaternion<T> b, T t)
Spherical cubic interpolation
@param 1 q1 - Quaternion 1
@param 2 q2 - Quaternion 2
@param 3 a - Additional Quaternion a
@param 4 t - the interpolation value always between (0 - 1)
see more info here - http://www.itu.dk/people/erikdam/DOWNLOAD/98-5.pdf

*/
template <class T>
Quaternion<T> Quaternion<T>::squad(Quaternion<T> q1, Quaternion<T> q2, Quaternion<T> a, Quaternion<T> b, T t)
{
	Quaternion<T> c = slerpNoInvert(q1, q2, t), d = slerpNoInvert(a, b, t);
	return slerpNoInvert(c, d, (T)2.0 * t * ((T)1.0 - t));
}

/*
**bezier(Quaternion<T> q1, Quaternion<T> q2, Quaternion<T> a, Quaternion<T> b, T t)
Shoemake-Bezier interpolation using Paul De Castlejau algorithm
Spherical Bezier Curve
see more info here - http://embots.dfki.de/doc/seminar_ca/Kremer_Quaternions.pdf
@param 1 qn - quaternion
@param 2 qnp1 - quaternion + 1
@param 3 a - Additional Quaternion a
@param 4 b - Additional Quaternion b
@param 5 t - the interpolation value always between (0 - 1)

*/
template <class T>
Quaternion<T> Quaternion<T>::bezier(Quaternion<T> qn, Quaternion<T> qnp1, Quaternion<T> a, Quaternion<T> b, T t)
{

	Quaternion<T> q11 = slerpNoInvert(qn, a, t), q12 = slerpNoInvert(a, b, t), q13 = slerpNoInvert(b, qnp1, t);

	return slerpNoInvert(slerpNoInvert(q11, q12, t), slerpNoInvert(q12, q13, t), t);
}

/*
**spline(Quaternion<T> qnm1, Quaternion<T> qn, Quaternion<T> qnp1)
Given 3 quaternions, qn-1, qn, and qn+1, 
calculate a control point to be used 
in spline interpolation
see more info here - http://embots.dfki.de/doc/seminar_ca/Kremer_Quaternions.pdf
@param 1 qnm1 = qn -1
@param 2 qn = qn
@param 3 qnp1 = qn + 1

*/
template <class T>
Quaternion<T> Quaternion<T>::spline(Quaternion<T> qnm1, Quaternion<T> qn, Quaternion<T> qnp1)
{
	Quaternion<T> qni(qn.s, qn.v * (T)-1.0);
	return qn * (((qni * qnm1).log() + (qni * qnp1).log()) / (T)-4.0).exp();
}

/*
**from_Axis_Angle(vec3<T> axis, T angle)
Converts from a normalized axis - angle pair rotation to a quaternion
@param 1 axis - the axis
@param 2 angle - the angle

*/
template <class T>
Quaternion<T> Quaternion<T>::from_Axis_Angle(vec3<T> axis, T angle)
{ 
	return Quaternion(::cosf(angle / (T)2.0), axis * ::sinf(angle / (T)2.0));
}

/*
**to_Axis_Angle(vec3<T> axis, T angle)
Returns the axis and angle of this unit quaternion
@param 1 axis - the axis
@param 2 angle - the angle

*/
template <class T>
void Quaternion<T>::to_Axis_Angle(vec3<T> axis, T angle)
{
	angle = ::acosf(s);

	// pre-compute to save time
	T sinf_theta_inv = (T)1.0 / ::sinf(angle);

	// now the vector
	axis.x = v.x * sinf_theta_inv;
	axis.y = v.y * sinf_theta_inv;
	axis.z = v.z * sinf_theta_inv;

	// multiply by 2
	angle = angle * (T)2.0;
}

/*
**rotate(vec3<T> v)
Rotates v by this quaternion (quaternion must be unit)
Returns the rotated vector
@param v - the vector to rotate using quaternions

*/
template <class T>
vec3<T> Quaternion<T>::rotate(vec3<T> v)
{   
	Quaternion<T> V((T)0.0, v);
	Quaternion<T> conjugate = Quaternion<T>(*this);
	conjugate.conjugate();
	return (*this * V * conjugate).v;
}

/*
**euler_Angles(bool homogenous)
Returns the euler angles from a rotation quaternion
@param homogeneous - is the quaternion homogenous

*/
template <class T>
vec3<T> Quaternion<T>::euler_Angles(bool homogenous)
{
		T sqw = s * s;    
		T sqx = v.x * v.x;    
		T sqy = v.y * v.y;    
		T sqz = v.z * v.z;    

		vec3<T> euler;
		if (homogenous) {
			euler.x = ::atan2f((T)2.0 * (v.x * v.y + v.z * s), sqx - sqy - sqz + sqw);
			euler.y = ::asinf((T)-2.0 * (v.x * v.z - v.y * s));
			euler.z = ::atan2f((T)2.0 * (v.y * v.z + v.x * s), -sqx - sqy + sqz + sqw);
		} else {
			euler.x = ::atan2f((T)2.0 * (v.z * v.y + v.x * s), (T)1.0 - (T)2.0 * (sqx + sqy));
			euler.y = ::asinf((T)-2.0 * (v.x * v.z - v.y * s));
			euler.z = ::atan2f((T)2.0 * (v.x * v.y + v.z * s), (T)1.0 - (T)2.0 * (sqy + sqz));
		}
		return euler;
}

template class Quaternion < float >;
template class Quaternion < double >;