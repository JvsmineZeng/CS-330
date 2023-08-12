/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/


#include <texture.h>
#include <stb_image.h>
#include <iostream>

Texture::Texture(const std::filesystem::path& path) {
	// Load texture
	stbi_set_flip_vertically_on_load(true);
	auto texturePath = path.string();
	int width, height, numChannels;
	unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &numChannels, STBI_rgb_alpha);

	glGenTextures(1, &_textureHandle);
	glBindTexture(GL_TEXTURE_2D, _textureHandle);

	if (data) {
		glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width, height);	// Allocate space on GPU
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);	// Assign data
		glGenerateMipmap(GL_TEXTURE_2D);	// Generate minmap of texture
	}
	else {
		std::cerr << "Failed to load texture at path: " << texturePath << std::endl;
	}
	// Free the data after upload
	stbi_image_free(data);
}

void Texture::Bind() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _textureHandle);
}
