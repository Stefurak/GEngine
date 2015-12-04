#pragma once

#include "GLM\glm.hpp"

namespace Ravka3DEngine
{

	/**
	* This represents a plane by storing the equation of the plane plus a point on the plane.
	* The equation of a plane has the form  aX + bY + cZ + d = 0.  The first 3 values, a, b, and c,
	* form a normalized vector which is normal to the plane.  The value of d represents the
	* distance of the plane from the origin.
	* @author R.N. Robson
	*/
	class Plane
	{
	private:
		/** This is a point on the plane */
		glm::vec3							point;
		/** These are the multipliers for the equation of the plane aX + bY + cZ +d = 0 */
		float								a, b, c, d;
	public:
		/**
		* Default constructor for XZ plane.
		*/
		Plane() :
			a(0.0), b(1.0), c(0.0), d(0.0), point(glm::vec3(0.0f, 0.0f, 0.0f)) {}

		/**
		* Construct a plane from the equation of the plane and a point on the plane.
		* @param _a X value of the vector describing the normal to the plane
		* @param _b Y value of the vector describing the normal to the plane
		* @param _b Z value of the vector describing the normal to the plane
		* @param pt A point lying on the plane
		*/
		Plane(float _a, float _b, float _c, float _d, glm::vec3 &pt);

		/**
		* Construct a plane from three points lying on the plane.  This is done
		* by computing two vectors which lie on the plane from the three points.
		* The cross-product of the 2 vectors then yields the normal to the plane.
		* @param p1 A point lying on the plane
		* @param p2 A point lying on the plane
		* @param p3 A point lying on the plane
		*/
		Plane(glm::vec3 &p1, glm::vec3 &p2, glm::vec3 &p3);

		/**
		* Return the normal to the plane (a, b, c) as a vector.
		* @return The normal to the plane.
		*/
		glm::vec3 getNormal() const;

		/**
		* Return the distance of the plane from the origin (d).  This assumed all
		* values have been normalized.
		* @return The distance from the origin
		*/
		float getDistance() const;

		/**
		* Assignment operator.
		* @param other The plane to assign to this plane
		* @return a reference to the plane to which the value was assigned
		*/
		Plane& operator=(const Plane &other);

		/**
		* Equality operator.
		* @param a First plane to compare
		* @param b second plane to compare
		* @return true if the planes are equal
		*/
		friend bool operator==(const Plane &a, const Plane &b);

		/**
		* Inequality operator.
		* @param a First plane to compare
		* @param b second plane to compare
		* @return true if the planes are not equal
		*/
		friend bool operator!=(const Plane &a, const Plane &b);

		/**
		* Compute the signed distance from the plane to a point.  The sign of the
		* distance tells you what side of the plane the point lies on.  If the
		* signed distance is negative, then the point lies on the side opposite
		* the normal.  We use the formula N dot pt + D = 0 to compute the distance
		* and just evaluate the left side of the equation.
		* @param pt The point to determine the distance of
		* @return the signed distance from the plane to the point
		*/
		float signedDistance(glm::vec3 &pt);

	};
}
