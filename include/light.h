/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project
	Instructor:		Professor Jeff Phillips
*/


#pragma once
#include <house_object.h>
#include <model.h>
#include <shader.h>
#include <mesh.h>

class Light : public HouseObject {
public: 
	Light();
	void Init() override;
	void Update(float deltaTime) override;
	void Draw(const glm::mat4& view, const glm::mat4& projection) override;
private:
	void createShader();
	void createMesh();
private:
	std::shared_ptr<Shader> _basicUnlitShader{};
	std::shared_ptr<Shader> _lightMesh{};
	std::vector<Model> _models {};
};