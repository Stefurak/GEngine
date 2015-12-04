#include "Plane.h"

namespace Ravka3DEngine
{

	Plane::Plane(float _a, float _b, float _c, float _d, glm::vec3 &pt)
	{
		point = pt;
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}

	Plane::Plane(glm::vec3 &p1, glm::vec3 &p2, glm::vec3 &p3)
	{
		///////////////////////////////////////////////////////////////////////
		// 1. Construct vectors from p1 -> p2 and p1 -> p3
		// 2. Use cross product to find normal to these vectors
		// 3. The equation of the plane with a normalized normal N through
		//    two points, X0 and X1 is N dot (X1 - X).  Substituting the
		//    general equation of a plane aX + bY + cZ +d = 0 yields
		//    d = aX - bY - cZ, which allows us to calculate the distance
		//    from the origin to the plane.
		// 4. Finally, P1 is the point on the plane from where the normal was
		//    calculated.
		///////////////////////////////////////////////////////////////////////
		glm::vec3 v1 = p2 - p1;
		glm::vec3 v2 = p3 - p1;
		glm::vec3 normal = glm::normalize(glm::cross(v1, v2));
		a = normal[0];
		b = normal[1];
		c = normal[2];
		d = -(a * p1[0] + b * p1[1] + c * p1[2]);
		point = p1;
	}

	glm::vec3 Plane::getNormal() const
	{
		return glm::vec3(a, b, c);
	}

	float Plane::getDistance() const
	{
		return d;
	}

	Plane& Plane::operator=(const Plane &other)
	{
		a = other.a;
		b = other.b;
		c = other.c;
		d = other.d;
		return *this;
	}

	bool operator==(const Plane &a, const Plane &b)
	{
		return (a.a == b.a) &&
			(a.b == b.b) &&
			(a.c == b.c) &&
			(a.d == b.d);
	}

	bool operator!=(const Plane &a, const Plane &b)
	{
		return !((a.a == b.a) &&
			(a.b == b.b) &&
			(a.c == b.c) &&
			(a.d == b.d));
	}

	float Plane::signedDistance(glm::vec3 &pt)
	{
		glm::vec3 N(a, b, c);
		return glm::dot(N, pt) + d;
	}
}
