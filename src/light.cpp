/*
	Name:			Jasmine Zeng
	Course:			CS 330
	Assignment:		7-2 Project 
	Instructor:		Professor Jeff Phillips
*/

#include <light.h>
#include <types.h>

Light::Light() {
	createShader();
	createMesh();
}

void Light::Init() {

}

void Light::Update(float deltaTime) {

}

void Light::Draw(const glm::mat4& view, const glm::mat4& projection) {
	for (auto& model : _models) {
		auto* shader = model.GetShader();
		auto* mesh = model.GetMesh();
		shader->Bind();
		shader->SetMat4("projection", projection);
		shader->SetMat4("view", view);
		shader->SetMat4("model", Transform * mesh->Transform);

		mesh->Draw();
	}
}

void Light::createShader() {
	_basicUnlitShader = std::make_shared<Shader>(Path("basic_unlit_color.vert"), Path("basic_unlit_color.frag"));
}

void Light::createMesh() {
	auto home = std::make_shared<Mesh>(Shapes::houseVertices, Shapes::houseElements, glm::vec3(0.f, 1.f, 0.f));
	_models.emplace_back(home, _basicUnlitShader);
}
