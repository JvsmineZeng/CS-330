/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/


#include <application.h>
#include <iostream>
#include <types.h>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <light.h>

Application::Application(std::string WindowTitle, int width, int height) :
	_applicationName{ std::move(WindowTitle) }, _width{ width }, _height{ height },
	_camera{ width, height, {-10.f, .5f, 3.f }, true },
	_cameraLookSpeed{ .1f, .1f } {

}

void Application::Run() {
	// Open window
	if (!openWindow()) {
		return;
	}

	setupInputs();

	_running = true;

	// Set the scene
	setupScene();

	// Run application
	while (_running) {
		float currentTime = glfwGetTime();

		if (_lastFrameTime == -1.f) {
			_lastFrameTime = currentTime;
		}

		auto deltaTime = currentTime - _lastFrameTime;
		_lastFrameTime = currentTime;

		if (glfwWindowShouldClose(_window)) {
			_running = false;
			continue;
		}

		// Update
		update(deltaTime);

		// Draw
		draw();
	}

	glfwTerminate();	// Terminate GLFW
}

bool Application::openWindow() {
	glfwInit();		// Initialize window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);	// OpenGL version 4.2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// Use values to intialize properly

	_window = glfwCreateWindow(800, 600, "CS 330 Project Jasmine Zeng", nullptr, nullptr);		// Create window

	if (!_window) {		// If window cannot open
		std::cerr << "ERROR: Could not initialize GLFW window." << std::endl;	// Print error message
		glfwTerminate();	// End application
	}

	glfwMakeContextCurrent(_window);		// Context current window for call

	glfwSetWindowUserPointer(_window, (void*)this);

	glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {		// When the window is resized
		glViewport(0, 0, width, height);

		auto app = reinterpret_cast<Application*> (glfwGetWindowUserPointer(window));
		app->_width = width;
		app->_height = height;

		// Resize camera
		app->_camera.SetSize(width, height);
		});

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {		// If glad loader cannot be called
		std::cerr << "ERROR: Could not initialize GLAD." << std::endl;
		glfwTerminate();	// End application
		return false;
	}

	glEnable(GL_DEPTH_TEST);

	return true;
}

void Application::setupInputs() {
	glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

		switch (key) {
		case GLFW_KEY_ESCAPE: {					// If key is ESC
			if (action == GLFW_PRESS) {
				app->_running = false;			// Close app
			}
			break;
		}
		case GLFW_KEY_P: {						// If key is P
			if (action == GLFW_PRESS) {			// Change perspective
				app->_camera.SetIsPerspective(!app->_camera.IsPerspective());
			}
		}
		default: {}
		}
		});

	glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xpos, double ypos) {			// Mouse movement
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		app->mousePositionCallback(xpos, ypos);
		});

	glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset) {	// Scroll movement
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		app->_camera.IncrementZoom(yOffset * 2);
		});

	glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods) {
		switch (button) {
		case GLFW_MOUSE_BUTTON_LEFT: {
			if (action == GLFW_PRESS) {
				std::cout << "Mouse button left pressed." << std::endl;
			}
			else {

			}
			break;
		}
		case GLFW_MOUSE_BUTTON_MIDDLE: {
			if (action == GLFW_PRESS) {
				std::cout << "Mouse button middle pressed." << std::endl;
			}
			else {

			}
			break;
		}
		case GLFW_MOUSE_BUTTON_RIGHT: {
			if (action == GLFW_PRESS) {
				std::cout << "Mouse button right pressed." << std::endl;
			}
			else {

			}
			break;
		}
		default:
			std::cout << "Unhandled mouse button event." << std::endl;
		}
		});
}

void Application::setupScene() {
	_meshes.emplace_back(Shapes::houseVertices, Shapes::houseElements);
	Path shaderPath = std::filesystem::current_path() / "assets" / "shaders";		// Shader file variable
	_shader = Shader(shaderPath / "basic_shader.vert", shaderPath / "basic_shader.frag");		// Vertices and fragment shader combined
	auto texturePath = std::filesystem::current_path() / "assets" / "textures";
	_textures.emplace_back(texturePath / "StainedGlass.jpg");
}

bool Application::update(float deltaTime) {
	glfwPollEvents();

	handleInput(deltaTime);

	return false;
}

bool Application::draw() {
	// Clear screen to specified color
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Camera
	glm::mat4 view = _camera.GetViewMatrix();
	glm::mat4 projection = _camera.GetProjectionMatrix();

	// Transformation in space for the object
	// glm::mat4 model = glm::mat4{ 1.f };

	// Bind shaders
	_shader.Bind();
	_shader.SetMat4("projection", projection);
	_shader.SetMat4("view", view);
	_shader.SetInt("tex0", 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _houseTexture);

	for (auto i = 0; i < _textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i);
		_textures[i].Bind();
	}

	// Iterate mesh draw
	for (auto& mesh : _meshes) {
		//mesh.Transform = glm::rotate(mesh.Transform, glm::radians(0.02f), glm::vec3(0, 1, 0));
		// mesh.Transform = glm::rotate(mesh.Transform, glm::radians(0.02f), glm::vec3(1, 0, 0));
		_shader.SetMat4("model", mesh.Transform);
		mesh.Draw();
	}

	// Keep current window open
	glfwSwapBuffers(_window);

	return false;
}

void Application::handleInput(float deltaTime) {
	auto moveAmount = _moveSpeed * deltaTime;

	if (glfwGetKey(_window, GLFW_KEY_W)) {									// W = forward
		_camera.MoveCamera(Camera::MoveDirection::Forward, moveAmount);
	}
	else if (glfwGetKey(_window, GLFW_KEY_S)) {								// S = backward
		_camera.MoveCamera(Camera::MoveDirection::Backward, moveAmount);
	}
	else if (glfwGetKey(_window, GLFW_KEY_A)) {								// A = left
		_camera.MoveCamera(Camera::MoveDirection::Left, moveAmount);
	}
	else if (glfwGetKey(_window, GLFW_KEY_D)) {								// D = right
		_camera.MoveCamera(Camera::MoveDirection::Right, moveAmount);
	}
	else if (glfwGetKey(_window, GLFW_KEY_Q)) {								// Q = up
		_camera.MoveCamera(Camera::MoveDirection::Up, moveAmount);
	}
	else if (glfwGetKey(_window, GLFW_KEY_E)) {								// E = down
		_camera.MoveCamera(Camera::MoveDirection::Down, moveAmount);
	}

	double xpos, ypos;
	glfwGetCursorPos(_window, &xpos, &ypos);

	mousePositionCallback(xpos, ypos);
}

void Application::mousePositionCallback(double xpos, double ypos) {
	if (!_firstMouse) {
		_lastMousePosition.x = static_cast<float>(xpos);
		_lastMousePosition.y = static_cast<float>(ypos);
		_firstMouse = true;
	}
	glm::vec2 moveAmount {
		xpos - _lastMousePosition.x,
			_lastMousePosition.y - ypos,
	};

	_lastMousePosition.x = static_cast<float>(xpos);
	_lastMousePosition.y = static_cast<float>(ypos);

	_camera.RotateBy(moveAmount.x * _cameraLookSpeed.x, moveAmount.y * _cameraLookSpeed.y);
}
