/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/


#pragma once

#include <glm/glm.hpp>

struct Vertex {
	glm::vec3 Position {0.f, 0.f, 0.f};
	glm::vec3 Color {1.f, 1.f, 1.f};
	glm::vec3 Normal {0.f, 0.f, 0.f};
	glm::vec2 Uv{1.f, 1.f};
};

struct Shapes {
	static inline std::vector<Vertex> houseVertices {
		// ROOF ----------------------------------------------------------------------
		// Right face
		{
			.Position = { 0.f, 2.f, 0.f },
			.Color = {.23f, 0.1f, 0.04f},			// 0, Brown
			.Uv = { 0.5f, 1.f }
		},
		{
			.Position = {-2.f, 0.f, 2.f},
			.Color = {.51f, 0.08f, 0.05f},			// 1, Red
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {2.f, 0.f, 2.f},
			.Color = {.19f, 0.f, 0.f},			// 2, Red
			.Uv = {1.f, 0.f}
		},
			// Back face
		{
			.Position = {0.f, 2.f, 0.f},
			.Color = {.23f, 0.1f, 0.04f},			// 3, Brown
			.Uv = {0.5f, 1.f}
		},
		{
			.Position = {2.f, 0.f, 2.f},
			.Color = {.19f, 0.f, 0.f},			// 4, Red
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {2.f, 0.f, -2.f},
			.Color = {.19f, 0.f, 0.f},			// 5, Red
			.Uv = {1.f, 0.f}
		},
			// Left face
		{
			.Position = {0.f, 2.f, 0.f},
			.Color = {.23f, 0.1f, 0.04f},			// 6, Brown
			.Uv = {0.5f, 1.f}
		},
		{
			.Position = {2.f, 0.f, -2.f},
			.Color = {.19f, 0.f, 0.f},			// 7, Red
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {-2.f, 0.f, -2.f},
			.Color = {.51f, 0.08f, 0.05f},			// 8, Red
			.Uv = {1.f, 0.f}
		},
			// Front face
		{
			.Position = { 0.0f, 2.f, 0.0f },
			.Color = {.29f, 0.12f, 0.05f},			// 9, Brown
			.Uv = {0.5f, 1.f}
		},
		{
			.Position = {-2.f, 0.f, -2.f},
			.Color = {.51f, 0.08f, 0.05f},			// 10, Red
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {-2.f, 0.f, 2.f},
			.Color = {.51f, 0.08f, 0.05f},			// 11, Red
			.Uv = {1.f, 0.f}
		},
			// Bottom face
		{
			.Position = {-2.f, 0.f, -2.f },
			.Color = {.19f, 0.f, 0.f},			// 12, Brown
			.Uv = {0.f, 1.f}
		},
		{
			.Position = {-2.f, 0.f, 2.f},
			.Color = {.19f, 0.f, 0.f},			// 13, Red
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {2.f, 0.0f, 2.f},
			.Color = {.19f, 0.f, 0.f},			// 14, Brown
			.Uv = {1.f, 0.f}
		},
		{
			.Position = {2.f, 0.f, -2.f},
			.Color = {.19f, 0.f, 0.f},			// 15, Red
			.Uv = {1.f, 1.f}
		},
		// CUBE ---------------------------------------------------------------------------
			// Right face
		{
			.Position = {-1.5f, 0.f, 1.5f },
			.Color = {.66f, .49f, .28f},			// 16, Tan
			.Uv = {0.f, 1.f}
		},
		{
			.Position = {-1.5f, -1.5f, 1.5f},
			.Color = {.66f, .49f, .28f},			// 17, Tan
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {1.5f, -1.5f, 1.5f},
			.Color = {.13f, .1f, .01f},			// 18, Tan
			.Uv = {1.f, 0.f}
		},
		{
			.Position = {1.5f, 0.f, 1.5f},
			.Color = {.13f, .1f, .01f},			// 19, Tan
			.Uv = {1.f, 1.f}
		},
			// Back face
		{
			.Position = {1.5f, 0.f, 1.5f },
			.Color = {.13f, .1f, .01f},			// 20, Tan
			.Uv = {0.f, 1.f}
		},
		{
			.Position = {1.5f, -1.5f, 1.5f},
			.Color = {.13f, .1f, .01f},			// 21, Tan
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {1.5f, -1.5f, -1.5f},
			.Color = {.13f, .1f, .01f},			// 22, Tan
			.Uv = {1.f, 0.f}
		},
		{
			.Position = {1.5f, 0.f, -1.5f},
			.Color = {.13f, .1f, .01f},			// 23, Tan
			.Uv = {1.f, 1.f}
		},
			// Left face
		{
			.Position = {1.5f, 0.f, -1.5f },
			.Color = {.13f, .1f, .01f},			// 24, Tan
			.Uv = {0.f, 1.f}
		},
		{
			.Position = {1.5f, -1.5f, -1.5f},
			.Color = {.13f, .1f, .01f},			// 25, Tan
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {-1.5f, -1.5f, -1.5f},
			.Color = {.66f, .49f, .28f},			// 26, Tan
			.Uv = {1.f, 0.f}
		},
		{
			.Position = {-1.5f, 0.f, -1.5f},
			.Color = {.66f, .49f, .28f},			// 27, Tan
			.Uv = {1.f, 1.f}
		},
			// Front face
		{
			.Position = {-1.5f, 0.f, -1.5f },
			.Color = {.83f, .62f, .36f},			// 28, Tan
			.Uv = {0.f, 1.f}
		},
		{
			.Position = {-1.5f, -1.5f, -1.5f},
			.Color = {.83f, .62f, .36f},			// 29, Tan
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {-1.5f, -1.5f, 1.5f},
			.Color = {.83f, .62f, .36f},			// 30, Tan
			.Uv = {1.f, 0.f}
		},
		{
			.Position = {-1.5f, 0.f, 1.5f},
			.Color = {.83f, .62f, .36f},			// 31, Tan
			.Uv = {1.f, 1.f}
		},
			// Bottom face
		{
			.Position = {-1.5f, -1.5f, -1.5f },
			.Color = {.13f, .1f, .01f},			// 32, Tan
			.Uv = {0.f, 1.f}
		},
		{
			.Position = {-1.5f, -1.5f, 1.5f},
			.Color = {.13f, .1f, .01f},			// 33, Tan
			.Uv = {0.f, 0.f}
		},
		{
			.Position = {1.5f, -1.5f, 1.5f},
			.Color = {.13f, .1f, .01f},			// 34, Tan
			.Uv = {1.f, 0.f}
		},
		{
			.Position = {1.5f, -1.5f, -1.5f},
			.Color = {.13f, .1f, .01f},			// 35, Tan
			.Uv = {1.f, 1.f}
		},
		// PLANE ----------------------------------------------------------------------
		// Front left
		{
			.Position = {-10.f, -1.5f, -10.f },
			.Color = {0.01f, 0.18f, 0.f},			// 36, White
			.Uv = {0.f, 1.f}
		},
		// Front right
		{
			.Position = {-10.f, -1.5f, 10.f },
			.Color = {0.01f, 0.18f, 0.f},			// 37, White
			.Uv = {0.f, 0.f}
		},
		// Back right
		{
			.Position = {10.f, -1.5f, 10.f },
			.Color = {0.01f, 0.05f, 0.f},			// 38, White
			.Uv = {1.f, 0.f}
		},
		// Back left
		{
			.Position = {10.f, -1.5f, -10.f },
			.Color = {0.01f, 0.05f, 0.f},			// 39, White
			.Uv = {1.f, 1.f}
		}
	};

	static inline std::vector<uint32_t> houseElements {
		// PYRAMID -----------------------------------------
		0, 1, 2,					// Right face
		3, 4, 5,					// Back face
		6, 7, 8,					// Left face
		9, 10, 11,					// Front face
		12, 13, 14, 12, 14, 15,		// Bottom face
		// HOUSE ----------------------------------------
		16, 17, 18, 16, 18, 19,		// Right face
		20, 21, 22, 20, 22, 23,		// Back face
		24, 25, 26, 24, 26, 27,		// Left face
		28, 29, 30, 28, 30, 31,		// Front face
		32, 33, 34, 32, 34, 35,		// Bottom face
		// PLANE ----------------------------------------
		36, 37, 38, 36, 38, 39 
	};
};