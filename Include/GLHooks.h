#ifndef GLHOOKS_H
#define GLHOOKS_H


#ifndef __gl_h_
#error "No OpenGL definitions detected, try including it before graphicsBenchmark.h"
#endif

#include "graphicsBenchmark.h"

#define BENCHMARK_GL_BEGIN glBegin
#define BENCHMARK_GL_END glEnd

#define glBegin(mode) \
	(drawCall(), BENCHMARK_GL_BEGIN(mode))

#define glEnd() \
(BENCHMARK_GL_END())


#endif