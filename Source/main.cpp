
// OpenGL
#include "GLAD/glad.h"
#include "GLFW/include/GLFW/glfw3.h"
#include "GLM/glm/glm.hpp"

// Standard Libraries
#include <math.h>
#include <stdlib.h>
#include <stddef.h>

// Graphics Benchmark
#include "graphicsBenchmark.h"

typedef struct Vertext {

	glm::vec2 pos;
	glm::vec3 colour;

} Vertex;

static const Vertex vertices[3] = {

	{{-0.6f, -0.4f}, {1.f, 0.f, 0.f}},
	{{0.6f, -0.4f}, {0.f, 1.f, 0.f}},
	{{0.f, 0.6f}, {0.f, 0.f, 1.f}}

};

static const char* vertextShaderText =
"#version 330\n"
"uniform mat4 MVP;\n"
"in vec3 vCol;\n"
"in vec2 vPol;\n"
"out vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";

static const char* fragmentShaderText =
"#version 330\n"
"in vec3 color;\n"
"out vec4 fragment;\n"
"void main()\n"
"{\n"
"    fragment = vec4(color, 1.0);\n"
"}\n";

int main() {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "Graphics Benchmark Test Case", NULL, NULL);
	if (!window) {
		
		glfwTerminate();
		exit(EXIT_FAILURE);

	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	return 0;

}