#ifndef GLHOOKS_H
#define GLHOOKS_H

#include "graphicsBenchmark.h"

#define BENCHMARK_GL_BEGIN glBegin
#define BENCHMARK_GL_END glEnd

#define glBegin(mode) \
    do { drawCall(); BENCHMARK_GL_BEGIN(mode); } while(0)

#define glEnd() \
    do { BENCHMARK_GL_END(); } while(0)


#endif