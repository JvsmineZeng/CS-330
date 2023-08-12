/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/

#pragma once
#include <glm/glm.hpp>

class HouseObject {
public:
	~HouseObject() = default;
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(const glm::mat4& view, const glm::mat4& projection) = 0;
public:
	glm::mat4 Transform{ 1.f };
};