/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project
	Instructor:		Professor Jeff Phillips
*/


#include <camera.h>
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>


Camera::Camera(int width, int height, glm::vec3 initialPosition, bool isPerspective) :
	_isPerspective{ isPerspective },
	_position{ initialPosition },
	_lookDirection {0.f, 0.f, 1.f},
	_width { width },
	_height { height } {
	recalculateVectors();
}

glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(_position,				// X amount of units back on the z-axis
		   _position + _lookDirection,		// Looking towards origin point
		   _upDirection);							// X amount of units up on the y-axis
}

glm::mat4 Camera::GetProjectionMatrix() const {
	auto aspectRatio = (float)_width / (float)_height;
	
	if (_isPerspective) {
		return glm::perspective(glm::radians(_fieldOfView), aspectRatio, _nearClip, _farClip);
	}

	return glm::ortho(-aspectRatio, aspectRatio, -1.f, -1.f, _nearClip, _farClip);
}

void Camera::MoveCamera(MoveDirection direction, float moveAmount) {
	glm::vec3 moveDirection{};

	switch (direction) {
		case MoveDirection::Forward: {			// Forward
			moveDirection = _lookDirection;
			break;
		}
		case MoveDirection::Backward: {			// Backward
			moveDirection = -_lookDirection;
			break;
		}
		case MoveDirection::Left: {				// Left
			moveDirection = glm::normalize(glm::cross(_lookDirection, _upDirection));
			break;
		}
		case MoveDirection::Right: {			// Right
			moveDirection = -glm::normalize(glm::cross(_lookDirection, _upDirection));
			break;
		}
		case MoveDirection::Up: {
			moveDirection = _upDirection;
			break;
		}
		case MoveDirection::Down: {
			moveDirection = -_upDirection;
			break;
		}
	}

	_position += moveDirection * moveAmount;
}

void Camera::RotateBy(float yaw, float pitch) {
	_yaw += yaw;		// Left/right movement
	_pitch += pitch;	// Up/down movement

	pitch = std::clamp(_pitch, -89.f, 89.f);		// Clamps between -89 and 89 degrees

	recalculateVectors();

}

void Camera::IncrementZoom(float amount) {
	_fieldOfView -= amount;
	_fieldOfView = std::clamp(_fieldOfView, 1.f, 75.f);
}

void Camera::recalculateVectors() {
	// Calculate look direction
	_lookDirection = glm::normalize(
		glm::vec3 {
			(std::cos(glm::radians(_yaw)) * std::cos(glm::radians(_pitch))),
			std::sin(glm::radians(_pitch)),
			std::sin(glm::radians(_yaw)) * std::cos(glm::radians(_pitch))
		}
	);

	// Calculate right direction
	auto rightDirection = glm::normalize(glm::cross(_lookDirection, glm::vec3(0.f, 1.f, 0.f)));

	// Calculate up direction
	_upDirection = glm::normalize(glm::cross(rightDirection, _lookDirection));
}
