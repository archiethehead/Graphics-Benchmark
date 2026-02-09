
// OpenGL
#include <GLEW/glew-2.1.0/Include/GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GLFW/include/GLFW/glfw3.h>

// Graphics Benchmark
#include "graphicsBenchmark.h"

int main() {

	glfwInit();
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	glfwMakeContextCurrent(window);

	while (1) {
	
		timeFrame();
		printStats();

	}

	return 0;

}