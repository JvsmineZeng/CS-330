/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/


#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <mesh.h>
#include <shader.h>
#include <camera.h>
#include <texture.h>
#include <house_object.h>
#include <light.h>

class Application {
public:
	Application(std::string WindowTitle, int width, int height);
	void Run();

private:
	bool openWindow();
	void setupInputs();
	void setupScene();
	bool update(float deltaTime);
	bool draw();
	void handleInput(float deltaTime);
	void mousePositionCallback(double xpos, double ypos);

private:
	std::string _applicationName{};
	int _width{};
	int _height{};
	GLFWwindow* _window{ nullptr };

	float _moveSpeed{ 5.f };
	Camera _camera;
	std::vector<std::unique_ptr<HouseObject>> _objects {};
	std::vector<Mesh> _meshes;
	std::vector<Texture> _textures;

	Shader _shader;
	Shader _textureShader;
	Shader _litShader;
	Shader _unlitShader;

	bool _running{ false };

	bool _firstMouse{ false };
	glm::vec2 _lastMousePosition {};
	glm::vec2 _cameraLookSpeed {};

	float _lastFrameTime{ -1.f };

	GLuint _houseTexture;

	// Lighting variables
	float _ambientStrength{ 0.1f };
	glm::vec3 _ambientLightColor{1.f, 1.f, 1.f};
};