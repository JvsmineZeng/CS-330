/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/

#include <model.h>

Model::Model(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader) : _shader { shader }, _mesh { mesh }{}