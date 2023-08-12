/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/


#pragma once
#include <mesh.h>
#include <shader.h>

class Model {
public:
	Model(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader);
	Shader* GetShader() { return _shader.get(); }
	Mesh* GetMesh() { return _mesh.get(); }
private:
	std::shared_ptr<Shader> _shader;
	std::shared_ptr<Mesh> _mesh;
};