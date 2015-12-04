#pragma once

#include "Plane.h"
//#include "Plane.h"
//#include "AABoundingBox.h"
namespace Ravka3DEngine
{


	/**
	* The frustum is the conical section of space with its apex at the eye of the viewer and
	* its far end at the farthest distance the viewer can see.  The actual view seen by a human
	* has an oval shape where the width is slightly greater than the height.  The reason for this
	* is that our 2 eyes let us see more along the horizontal axis than the vertical axis.
	*
	* This class approximates the conical shape of the scene viewed by a human by using
	* 2 planes to represent the near and far limits of what can be seen.  A further 4 planes
	* delimit the sides of the frustum.  While using planes results in an approximation, it
	* is close enough and easire to calculate than using a true conical shape.
	*
	* The frustum must be updated:
	* - every time the application window is resized
	* - whenever the camera position or orientation changes
	*
	* All of the information necessary to recompute the frustum can be obtained from the
	* information sent to the graphics system when handling a window resize event or when
	* repositioning the camera
	* @author R.N. Robson
	*/
	class Frustum
	{
	private:
		/** The names of the 6 planes */
		enum PlaneNames {
			NEARP, FARP, TOPP, BOTTOMP, RIGHTP, LEFTP
		};
		/** The camera position at the apex of the frustum */
		glm::vec3										camPos;
		/** A normalized vector looking in the same direction as the camera */
		glm::vec3										viewDir;
		/** Distance from the camera to the near plane */
		float											nearDist;
		/** Distance from the camera to the far plane */
		float											farDist;
		/** The centre of the near plane */
		glm::vec3										nearCent;
		/** The centre of the far plane */
		glm::vec3										farCent;
		/** Width of the near plane */
		float											nearWd;
		/** Height of the near plane */
		float											nearHt;
		/** Width of the far plane */
		float											farWd;
		/** Height of the far plane */
		float											farHt;
		/** A normalized vector pointing up WRT the camera */
		glm::vec3										upDir;
		/** A normalized vector pointing right WRT the camera */
		glm::vec3										rightDir;
		/** The 6 planes delimiting the frustum */
		Plane											planes[6];
		/** The corner points of the near and far planes */
		glm::vec3										ntl, nbl, nbr, ntr, ftl, fbl, fbr, ftr;
		/** The ratio from the graphics system perspective calculations */
		float											ratio;
		/** The angle of the field of view */
		float											angle;
		/** Tangent of half the angle */
		float											tang;
	public:
		/** Used to determine if an object is inside the frustum */
		static enum EnclosureType {
			INSIDE, OUTSIDE, OVERLAP
		};

		/**
		* Default Constructor.
		*/
		Frustum() {}

		/**
		* This handles the situation where the window is resized.  It updates the
		* internal variables to reflect the new window size.
		* @param _angle The field of view angle
		* @param _ratio The ratio used in the perspective
		* @param nearD Distance from eye to near plane
		* @param farD Distance from eye to far plane
		*/
		void windowResized(float _angle, float _ratio, float nearD, float farD);

		/**
		* This is called to recompute the frustum every time the position of the
		* camera changes.
		* @param camPosn The position of the camera
		* @param lookAt The point at which the camera is looking
		* @param up The up vector for the camera
		*/
		void cameraChanged(glm::vec3 &camPosn, glm::vec3 &lookAt, glm::vec3 &up);

		/**
		* Determine if a point is inside the frustum.
		* @param pt The point to check to see if inside the frustum
		* @return Whether the point is inside, outside or overlapping the frustum
		*/
		EnclosureType isInside(glm::vec3 &pt);

		/**
		* Determine if a sphere is inside the frustum.
		* @param cent The centre of the sphere
		* @param radius The radius of the sphere
		* @return Whether the sphere is inside, outside or overlapping the frustum
		*/
		EnclosureType isInside(glm::vec3 &cent, float radius);

		/**
		* Determine if an axis aligned bounding box is inside the frustum.
		* @param box The axis aligned bounding box to test
		* Whether the box is inside, outside or overlapping the frustum
		*/
		/*
		EnclosureType isInside(AABoundingBox &box);
		*/
	};
}

