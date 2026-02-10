
// OpenGL
#include "GLAD/glad.h"
#include "GLFW/include/GLFW/glfw3.h"
#include "GLM/glm/glm.hpp"
#include "triangle.vert"
#include "triangle.frag"

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

	GLuint vertex_buffer;
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	const GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertextShaderText, NULL);
	glCompileShader(vertexShader);

	const GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderText, NULL);
	glCompileShader(fragmentShader);

	const GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	const GLint mvpLocation = glGetUniformLocation(program, "MVP");
	const GLint vposLocation = glGetAttribLocation(program, "vPos");
	const GLint vcolLocation = glad_glGetAttribLocation(program, "vCol");


	return 0;

}