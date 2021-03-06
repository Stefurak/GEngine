#include "Camera3D.h"

#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
#include "glm/gtc/matrix_transform.hpp"

namespace Ravka3DEngine
{

	static const float MaxVerticalAngle = 85.0f; //must be less than 90 to avoid gimbal lock

	Camera3D::Camera3D() :
		_position(0.0f, 0.0f, 1.0f),
		_horizontalAngle(0.0f),
		_verticalAngle(0.0f),
		_fieldOfView(50.0f),
		_nearPlane(0.01f),
		_farPlane(2.0f),
		_viewportAspectRatio(4.0f / 3.0f)
	{
		camSpeed = 5.0f;
	}

	Camera3D::~Camera3D()
	{

	}

	void Camera3D::updateCamera()
	{
		processInput();

		setPosition(glm::vec3(camPosition.x, camPosition.y, camPosition.z));
		if (camRotation.x > 0.0025f || camRotation.x < -0.0025f)
		{
			offsetOrientation(0, camRotation.x);

		}
		if (camRotation.y > 0.0025f || camRotation.y < -0.0025f)
		{
			offsetOrientation(camRotation.y, 0);
		}
	}

	void Camera3D::processInput()
	{
		camRotationSpeed.x = 0.05f;
		camRotationSpeed.y = 0.05f;
		camPosition += camVelocity;

		inputManager.processInput();

		camRotation.x = inputManager.getMouseVelocity().x  * camRotationSpeed.x;
		camRotation.y = inputManager.getMouseVelocity().y * camRotationSpeed.y;

		if (camRotation.x > 0.1f || camRotation.x < -0.1f ||
			camRotation.x < 0.05f && camRotation.x > -0.05f)
			camRotation.x = 0;
		if (camRotation.y > 0.1f || camRotation.y < -0.1f)
			camRotation.y = 0;


		//std::cout << "CAMRTOX: " << camRotation.x << "   MOUSEVEL: " << mouseVel << "   MOUSEVEL2: " << mouseVel2 << "  ctr: " << ctr << std::endl;


		switch (inputManager.getKeyEvent())
		{

			//Key Down
		case KeyEvent::LEFT_KEYDOWN:
			camVelocity.x = -camSpeed;
			break;
		case KeyEvent::RIGHT_KEYDOWN:
			camVelocity.x = camSpeed;
			break;
		case KeyEvent::UP_KEYDOWN:
			camVelocity.z = -camSpeed;
			break;
		case KeyEvent::DOWN_KEYDOWN:
			camVelocity.z = camSpeed;
			break;
		case KeyEvent::P_KEYDOWN:
			if (!pKeyPressed)
			{
				wireFrame = !wireFrame;
				pKeyPressed = true;
			}
			break;
		case KeyEvent::P_KEYUP:
			pKeyPressed = false;
			break;
			//Key Up
		case KeyEvent::LEFT_KEYUP:
			//camVelocity.x = 0.0f;
			break;
		case KeyEvent::RIGHT_KEYUP:
			//camVelocity.x = 0.0f;
			break;
		case KeyEvent::UP_KEYUP:
			break;
			//camVelocity.z = 0;
		case KeyEvent::DOWN_KEYUP:
			break;
		default:
			break;
			//camVelocity.z = 0;
		}
	}

	const glm::vec3& Camera3D::position() const {
		return _position;
	}

	void Camera3D::setPosition(const glm::vec3& position) {
		_position = position;
	}

	void Camera3D::offsetPosition(const glm::vec3& offset) {
		_position += offset;
	}

	float Camera3D::fieldOfView() const {
		return _fieldOfView;
	}

	void Camera3D::setFieldOfView(float fieldOfView) {
		assert(fieldOfView > 0.0f && fieldOfView < 180.0f);
		_fieldOfView = fieldOfView;
	}

	float Camera3D::nearPlane() const {
		return _nearPlane;
	}

	float Camera3D::farPlane() const {
		return _farPlane;
	}

	void Camera3D::setNearAndFarPlanes(float nearPlane, float farPlane) {
		assert(nearPlane > 0.0f);
		assert(farPlane > nearPlane);
		_nearPlane = nearPlane;
		_farPlane = farPlane;
	}

	glm::mat4 Camera3D::orientation() const {
		glm::mat4 orientation;
		orientation = glm::rotate(orientation, glm::radians(_verticalAngle), glm::vec3(1, 0, 0));
		orientation = glm::rotate(orientation, glm::radians(_horizontalAngle), glm::vec3(0, 1, 0));
		return orientation;
	}

	void Camera3D::offsetOrientation(float upAngle, float rightAngle) {
		_horizontalAngle += rightAngle;
		_verticalAngle += upAngle;
		normalizeAngles();
	}

	void Camera3D::lookAt(glm::vec3 position) {
		assert(position != _position);
		glm::vec3 direction = glm::normalize(position - _position);
		_verticalAngle = glm::radians(asinf(-direction.y));
		_horizontalAngle = -glm::radians(atan2f(-direction.x, -direction.z));
		normalizeAngles();
	}

	float Camera3D::viewportAspectRatio() const {
		return _viewportAspectRatio;
	}

	void Camera3D::setViewportAspectRatio(float viewportAspectRatio) {
		assert(viewportAspectRatio > 0.0);
		_viewportAspectRatio = viewportAspectRatio;
	}

	glm::vec3 Camera3D::forward() const {
		glm::vec4 forward = glm::inverse(orientation()) * glm::vec4(0, 0, -1, 1);
		return glm::vec3(forward);
	}

	glm::vec3 Camera3D::right() const {
		glm::vec4 right = glm::inverse(orientation()) * glm::vec4(1, 0, 0, 1);
		return glm::vec3(right);
	}

	glm::vec3 Camera3D::up() const {
		glm::vec4 up = glm::inverse(orientation()) * glm::vec4(0, 1, 0, 1);
		return glm::vec3(up);
	}

	glm::mat4 Camera3D::matrix() const {
		return projection() * view();
	}

	glm::mat4 Camera3D::projection() const {
		return glm::perspective(glm::radians(_fieldOfView), _viewportAspectRatio, _nearPlane, _farPlane);
	}

	glm::mat4 Camera3D::view() const {
		return orientation() * glm::translate(glm::mat4(), -_position);
	}

	void Camera3D::normalizeAngles() {
		_horizontalAngle = fmodf(_horizontalAngle, 360.0f);
		//fmodf can return negative values, but this will make them all positive
		if (_horizontalAngle < 0.0f)
			_horizontalAngle += 360.0f;

		if (_verticalAngle > MaxVerticalAngle)
			_verticalAngle = MaxVerticalAngle;
		else if (_verticalAngle < -MaxVerticalAngle)
			_verticalAngle = -MaxVerticalAngle;
	}

}
