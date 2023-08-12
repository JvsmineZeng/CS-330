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

void main() {
	FragColor = vertexColor;
}