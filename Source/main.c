
// OpenGL
#include "GLAD/glad.h"
#include "GLFW/include/GLFW/glfw3.h"
#include "linmath.h"
#include "triangle.vert"
#include "triangle.frag"

// Standard Libraries
#include <stdio.h>
#include <stddef.h>

// Graphics Benchmark
#include "graphicsBenchmark.h"

typedef struct Vertext {

	vec2 pos;
	vec3 colour;

} Vertex;

static const Vertex vertices[3] = {

	{{-0.6f, -0.4f}, {1.f, 0.f, 0.f}},
	{{0.6f, -0.4f}, {0.f, 1.f, 0.f}},
	{{0.f, 0.6f}, {0.f, 0.f, 1.f}}

};

int main() {

	if (!glfwInit()) {

		fprintf(stderr, "GLFW init failed\n");
		return -1;

	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(640, 480, "Graphics Benchmark Test Case", NULL, NULL);

	if (!window) {

		fprintf(stderr, "Window creation failed\n");
		glfwTerminate();
		return -1;

	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

		fprintf(stderr, "GLAD init failed\n");
		return -1;

	}

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

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);
	glEnableVertexAttribArray(vposLocation);
	glVertexAttribPointer(vposLocation, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),	(void*) offsetof(Vertex, pos));
	
	glEnableVertexAttribArray(vcolLocation);
	glVertexAttribPointer(vcolLocation, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, colour));

	while (!glfwWindowShouldClose(window)) {
	
		timeFrame();
		printStats();

		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		const float ratio = width / (float) height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		mat4x4 m, p, mvp;
		mat4x4_identity(m);
		mat4x4_rotate_Z(m, m, (float) glfwGetTime());
		mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		mat4x4_mul(mvp, p, m);

		glUseProgram(program);
		glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, (const GLfloat*) &mvp);
		glBindVertexArray(vertexArray);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	
	}

	return 0;

}