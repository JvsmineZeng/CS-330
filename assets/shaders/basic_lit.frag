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

	// Ambient lighting
	float ambientStrength = 0.3;
	vec3 lightColor = vec3(1.f, 1.f, 1.f);
	vec3 ambient = ambientStrength * lightColor;

	vec3 objectColor = vertexColor.xyz;

	vec3 finalColor = objectColor * ambient;
	FragColor = vec4(finalColor, 1.0);
}