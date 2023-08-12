/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/


#include <shader.h>
#include <iostream>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource) {
	// Load shader and fragment source
	load(vertexSource, fragmentSource);
}

Shader::Shader(const Path& vertexPath, const Path& fragmentPath) {

	// Try opening vertex and fragment source files
	try {
		// Load vertices and fragment sources from files
		std::ifstream vShaderFile;		// Stream vertices shader file
		std::ifstream fShaderFile;		// Stream fragment shader file
		
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		// Take into string stream
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		// Close shader files
		vShaderFile.close();
		fShaderFile.close();

		// Load shader
		load(vShaderStream.str(), fShaderStream.str());
	} catch (std::ifstream::failure& e) {		// Catch file read failure
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}
}

void Shader::Bind() {
	// Bind shaders
	glUseProgram(_shaderProgram);
}

void Shader::SetMat4(const std::string& uniformName, const glm::mat4 & mat4) {
	auto uniformLoc = getUniformLocation(uniformName);

	if (uniformLoc != -1) {
		//Bind();
		glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(mat4));
	}
}

void Shader::SetInt(const std::string& uniformName, int value) {
	auto uniformLoc = getUniformLocation(uniformName);

	if (uniformLoc != -1) {
		//Bind();
		glUniform1i(uniformLoc, value);
	}
}

void Shader::load(const std::string& vertexSource, const std::string& fragmentSource) {
	const char* vShaderCode = vertexSource.c_str();
	const char* fShaderCode = fragmentSource.c_str();

	// Vertex shader compiler
	auto vertexShader = glCreateShader(GL_VERTEX_SHADER);			// Initialize vertex shader
	glShaderSource(vertexShader, 1, &vShaderCode, nullptr);		// Establish shader source
	glCompileShader(vertexShader);		// Compile shader

	int success;														// Initialize successful compilation message
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {														// Failed compilation message
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Fragment shader compiler
	auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);			// Initialize fragment shader
	glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);		// Establish shader source
	glCompileShader(fragmentShader);		// Compile shader

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	// Failed compilation message
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Link vertex and fragment shaders
	_shaderProgram = glCreateProgram();
	glAttachShader(_shaderProgram, vertexShader);		// Attach vertex shader
	glAttachShader(_shaderProgram, fragmentShader);		// Attach fragment shader
	glLinkProgram(_shaderProgram);						// Link vertex and fragment shaders

	// Get successful compilation message
	glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);

	// Failed compilation message
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::FRAGMENT::LINK_FAILED\n" << infoLog << std::endl;
	}

	// Delete shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

GLint Shader::getUniformLocation(const std::string& uniformName) {
	return glGetUniformLocation(_shaderProgram, uniformName.c_str());
}
