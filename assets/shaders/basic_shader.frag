/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/


#version 330 core

out vec4 FragColor;
in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D tex0;		// Texture 0

void main() {
	FragColor = texture(tex0, texCoord) * vertexColor;
}