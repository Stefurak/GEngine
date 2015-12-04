#include "Error.h"
#include "Quaternion.h"
#include <math.h>

#pragma region Quaternion

/****************************************
 * Quaternion class
 * By Will Perone (will.perone@gmail.com)
 * Original: 12-09-2003  
 * Revised:  27-09-2003
 *           22-11-2003
 *           10-12-2003
 *           15-01-2004
 *           16-04-2004
 *           07-29-2011    added corrections from website
 *           22-12-2011    added correction to *= operator, thanks Steve Rogers
 *           22-10-2012    fixed ctor from euler angles & added non windows platform fixes, thanks to Art Golf
 *   
 * Dependancies: My 4x4 matrix class
 * 
 * © 2003, This code is provided "as is" and you can use it freely as long as 
 * credit is given to Will Perone in the application it is used in
 *
 * Notes:  
 * if |q|=1 then q is a unit quaternion
 * if q=(0,v) then q is a pure quaternion 
 * if |q|=1 then q conjugate = q inverse
 * if |q|=1 then q= [cos(angle), u*sin(angle)] where u is a unit vector 
 * q and -q represent the same rotation 
 * q*q.conjugate = (q.length_squared, 0) 
 * ln(cos(theta),sin(theta)*v)= ln(e^(theta*v))= (0, theta*v)

Jesse Derochie (jesse.a.derochie@gmail.com)
Revised:  08-FEB-2015

Places I found this code online as of February 7th 2015
	http://www.willperone.net/Code/quaternion.php
	https://github.com/MegaManSE/willperone/tree/master/Math

****************************************/


Quaternion::Quaternion(void)
{

}

Quaternion::Quaternion(float _w, Vector3 _v)
{
	s = _w;
	v = _v;
}

Quaternion::Quaternion(Vector4 _v)
{
	s = _v.w;
	v.x = _v.x;
	v.y = _v.y;
	v.z = _v.z;
}


Quaternion::Quaternion(float _w, float _x, float _y, float _z)
{
	s = _w;
	v.x = _x;
	v.y = _y;
	v.z = _z;
}

Quaternion::~Quaternion(void)
{
}

void Quaternion::QuaternionFromEulerAngles(float theta_z, float theta_y, float theta_x)
{
		float cos_z_2 = ::cosf(0.5f * theta_z);
		float cos_y_2 = ::cosf(0.5f * theta_y);
		float cos_x_2 = ::cosf(0.5f * theta_x);

		float sin_z_2 = ::sinf(0.5f * theta_z);
		float sin_y_2 = ::sinf(0.5f * theta_y);
		float sin_x_2 = ::sinf(0.5f * theta_x);

		// and now compute quaternion
		s   = cos_z_2 * cos_y_2 * cos_x_2 + sin_z_2 * sin_y_2 * sin_x_2;
		v.x = cos_z_2 * cos_y_2 * sin_x_2 - sin_z_2 * sin_y_2 * cos_x_2;
		v.y = cos_z_2 * sin_y_2 * cos_x_2 + sin_z_2 * cos_y_2 * sin_x_2;
		v.z = sin_z_2 * cos_y_2 * cos_x_2 - cos_z_2 * sin_y_2 * sin_x_2;
}

void Quaternion::QuaternionFromEulerAngles(const Vector3 &angles)
	{	
		float cos_z_2 = ::cosf(0.5f * angles.z);
		float cos_y_2 = ::cosf(0.5f * angles.y);
		float cos_x_2 = ::cosf(0.5f * angles.x);

		float sin_z_2 = ::sinf(0.5f * angles.z);
		float sin_y_2 = ::sinf(0.5f * angles.y);
		float sin_x_2 = ::sinf(0.5f * angles.x);

		// and now compute quaternion
		s   = cos_z_2 * cos_y_2 * cos_x_2 + sin_z_2 * sin_y_2 * sin_x_2;
		v.x = cos_z_2 * cos_y_2 * sin_x_2 - sin_z_2 * sin_y_2 * cos_x_2;
		v.y = cos_z_2 * sin_y_2 * cos_x_2 + sin_z_2 * cos_y_2 * sin_x_2;
		v.z = sin_z_2 * cos_y_2 * cos_x_2 - cos_z_2 * sin_y_2 * sin_x_2;		
	} 

Quaternion Quaternion::operator = (Quaternion q)		
{ 
	s = q.s; 
	v = q.v; 
	return *this; 
}

Quaternion Quaternion::operator + (Quaternion q)	
{ 
	return Quaternion(s + q.s, v + q.v); 
}

Quaternion Quaternion::operator - (Quaternion q)	
{ 
	return Quaternion(s-q.s, v-q.v); 
}

Quaternion Quaternion::operator * (Quaternion q)
{	
	return Quaternion(s*q.s - v.x * q.v.x + v.y * q.v.y + v.z * q.v.z,
				  v.y*q.v.z - v.z*q.v.y + s*q.v.x + v.x*q.s,
				  v.z*q.v.x - v.x*q.v.z + s*q.v.y + v.y*q.s,
				  v.x*q.v.y - v.y*q.v.x + s*q.v.z + v.z*q.s);
}

Quaternion Quaternion::operator / (const Quaternion q)
{
	Quaternion p(q); 
	p.Invert(); 
	return *this * p;
}

Quaternion Quaternion::operator * (float scale)
{ 
	return Quaternion(s*scale,v*scale); 
}

Quaternion Quaternion::operator / (float scale)
{ 
	return Quaternion(s/scale,v/scale); 
}

Quaternion Quaternion::operator - ()
{ 
	return Quaternion(-s, v * -1.0f); 
}
	
Quaternion Quaternion::operator += (Quaternion q)		
{ 
	v += q.v; 
	s += q.s; 
	return *this; 
}

Quaternion Quaternion::operator -= (Quaternion q)		
{ 
	v -= q.v; 
	s -= q.s; 
	return *this; 
}

Quaternion Quaternion::operator *= (Quaternion q)		
{			
	float x = v.x;
	float y = v.y;
	float z = v.z;
	float sn = (s * q.s) - (v.x * q.v.x + v.y * q.v.y + v.z * q.v.z);

	v.x = y * q.v.z - z * q.v.y + s * q.v.x + x * q.s;
	v.y = z * q.v.x - x * q.v.z + s * q.v.y + y * q.s;
	v.z = x * q.v.y - y * q.v.x + s * q.v.z + z * q.s;
	s = sn;
	return *this;
}
	
Quaternion Quaternion::operator *= (float scale)			
{ 
	v *= scale; 
	s *= scale; 
	return *this; 
}

Quaternion Quaternion::operator /= (float scale)			
{ 
	v /= scale; 
	s /= scale; 
	return *this; 
}


float Quaternion::Length()
{ 
	return (float)::sqrt(s * s + v.x * v.x + v.y * v.y + v.z * v.z); 
}


float Quaternion::Length_Squared()
{ 
	return (float)(s * s + v.x * v.x + v.y * v.y + v.z * v.z); 
}


void Quaternion::Normalize()
{ 
	*this /= Length(); 
}

Quaternion Quaternion::Normalized()
{ 
	return  *this / Length(); 
}

void Quaternion::Conjugate()
{ 
	v = v * -1.0f;
}

void Quaternion::Invert()
{ 
	Conjugate(); 
	*this /= Length_Squared(); 
}
	
// returns the logarithm of a quaternion = v*a where q = [cos(a),v*sin(a)]
Quaternion Quaternion::Log()
{
	float a = (float)::acos(s);
	float sinOfA = (float)::sin(a);
	Quaternion quatReturn;

	quatReturn.s = 0;
	if (sinOfA > 0)
	{
		quatReturn.v.x = a * v.x/sinOfA;
		quatReturn.v.y = a * v.y/sinOfA;
		quatReturn.v.z = a * v.z/sinOfA;
	} else {
		quatReturn.v.x = quatReturn.v.y = quatReturn.v.z = 0;
	}
	return quatReturn;
}

// returns e^quaternion = exp(v*a) = [cos(a),vsin(a)]
Quaternion Quaternion::Exp()
{
	float a = (float)v.Length();
	float sinOfA = (float)::sin(a);
	float cosOfA = (float)::cos(a);
	Quaternion quatReturn;

	quatReturn.s = cosOfA;
	if (a > 0)
	{
		quatReturn.v.x = sinOfA * v.x / a;
		quatReturn.v.y = sinOfA * v.y / a;
		quatReturn.v.z = sinOfA * v.z / a;
	} else {
		quatReturn.v.x = quatReturn.v.y = quatReturn.v.z = 0;
	}
	return quatReturn;
}

float Quaternion::Dot(Quaternion q1, Quaternion q2) 
{ 
	float fTemp;
	fTemp = q1.v.Dot(q1.v, q2.v);
	return  fTemp + q1.s * q2.s; 
}

Quaternion Quaternion::Lerp(Quaternion q1, Quaternion q2, float t) 
{ 
	return (q1 * (1 - t) + q2 * t).Normalized(); 
}

Quaternion Quaternion::Slerp(Quaternion q1, Quaternion q2, float t) 
{
	Quaternion q3;
	float dot = Quaternion::Dot(q1, q2);

	/*	dot = cos(theta)
		if (dot < 0), q1 and q2 are more than 90 degrees apart,
		so we can invert one to reduce spinning	*/
	if (dot < 0)
	{
		dot = -dot;
		q3 = -q2;
	} else q3 = q2;
	
	if (dot < 0.95f)
	{
		float angle = ::acosf(dot);
		return (q1 * ::sinf(angle * (1 - t)) + q3 * ::sinf(angle * t)) / ::sinf(angle);
	} else // if the angle is small, use linear interpolation								
		return Lerp(q1,q3,t);			
}

	//! This version of slerp, used by squad, does not check for theta > 90.
Quaternion Quaternion::SlerpNoInvert(Quaternion q1, Quaternion q2, float t) 
{
	float dot = Quaternion::Dot(q1, q2);
	if (dot > -0.95f && dot < 0.95f)
	{
		float angle = ::acosf(dot);			
		return (q1 * ::sinf(angle * (1 - t)) + q2 * ::sinf(angle * t)) / ::sinf(angle);
	} else  // if the angle is small, use linear interpolation								
		return Lerp(q1,q2,t);				
}

	//! spherical cubic interpolation
Quaternion Quaternion::Squad(Quaternion q1, Quaternion q2, Quaternion a, Quaternion b, float t)
{
	Quaternion c = SlerpNoInvert(q1, q2, t), d = SlerpNoInvert(a, b, t);		
	return SlerpNoInvert(c, d, 2 * t * (1 - t));
}

	//! Shoemake-Bezier interpolation using De Castlejau algorithm
Quaternion Quaternion::Bezier(Quaternion q1, Quaternion q2, Quaternion a, Quaternion b, float t)
{

	Quaternion q11 = SlerpNoInvert(q1, a, t), q12 = SlerpNoInvert(a, b, t), q13 = SlerpNoInvert(b, q2, t);		

	return SlerpNoInvert(SlerpNoInvert(q11, q12, t), SlerpNoInvert(q12, q13, t), t);
}

	//! Given 3 quaternions, qn-1,qn and qn+1, calculate a control point to be used in spline interpolation
Quaternion Quaternion::Spline(Quaternion qnm1, Quaternion qn, Quaternion qnp1)
{
	Quaternion qni(qn.s, qn.v * -1.0f);	
	return qn * (( (qni * qnm1).Log() + (qni * qnp1).Log() ) / -4).Exp();	
}

	//! converts from a normalized axis - angle pair rotation to a quaternion
Quaternion Quaternion::From_Axis_Angle(Vector3 axis, float angle)
{ 
	return Quaternion(::cosf(angle / 2), axis * ::sinf(angle / 2)); 
}

	//! returns the axis and angle of this unit quaternion
void Quaternion::To_Axis_Angle(Vector3 axis, float angle)
{
	angle = ::acosf(s);

	// pre-compute to save time
	float sinf_theta_inv = 1.0f / ::sinf(angle);

	// now the vector
	axis.x = v.x * sinf_theta_inv;
	axis.y = v.y * sinf_theta_inv;
	axis.z = v.z * sinf_theta_inv;

	// multiply by 2
	angle *= 2;
}

	//! rotates v by this quaternion (quaternion must be unit)
Vector3 Quaternion::Rotate(Vector3 v)
{   
	Quaternion V(0, v);
	Quaternion conjugate(*this);
	conjugate.Conjugate();
	return (*this * V * conjugate).v;
}

	//! returns the euler angles from a rotation quaternion
Vector3 Quaternion::Euler_Angles(bool homogenous)
	{
		float sqw = s * s;    
		float sqx = v.x * v.x;    
		float sqy = v.y * v.y;    
		float sqz = v.z * v.z;    

		Vector3 euler;
		if (homogenous) {
			euler.x = ::atan2f(2.f * (v.x * v.y + v.z * s), sqx - sqy - sqz + sqw);    		
			euler.y = ::asinf(-2.f * (v.x * v.z - v.y * s));
			euler.z = ::atan2f(2.f * (v.y * v.z + v.x * s), -sqx - sqy + sqz + sqw);    
		} else {
			euler.x = ::atan2f(2.f * (v.z * v.y + v.x * s), 1 - 2 * (sqx + sqy));
			euler.y = ::asinf(-2.f * (v.x * v.z - v.y * s));
			euler.z = ::atan2f(2.f * (v.x * v.y + v.z * s), 1 - 2 * (sqy + sqz));
		}
		return euler;
	}

#pragma endregion