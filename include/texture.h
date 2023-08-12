/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/


#pragma once
#include <filesystem>
#include <glad/glad.h>


class Texture {
public:
	explicit Texture(const std::filesystem::path& path);
	void Bind();

private:
	GLuint _textureHandle;
};