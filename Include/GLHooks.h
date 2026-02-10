#ifndef GLHOOKS_H
#define GLHOOKS_H

#include "graphicsBenchmark.h"

#define BENCHMARK_GL_BEGIN glBegin
#define BENCHMARK_GL_END glEnd
#define BENCHMARK_glad_glDrawArrays glad_glDrawArrays
#define BENCHMARK_glad_glDrawElements glad_glDrawElements
#define BENCHMARK_glad_glDrawArraysInstanced glad_glDrawArraysInstanced
#define BENCHMARK_glad_glDrawElementsInstanced glad_glDrawElementsInstanced
#define BENCHMARK_glad_glDrawArraysIndirect glad_glDrawArraysIndirect
#define BENCHMARK_glad_glDrawElementsIndirect glad_glDrawElementsIndirect
#define BENCHMARK_glad_glDrawElementsBaseVertex  glad_glDrawElementsBaseVertex
#define BENCHMARK_glad_glDrawElementsInstancedBaseVertex glad_glDrawElementsInstancedBaseVertex
#define BENCHMARK_glad_glDrawElementsInstancedBaseVertexBaseInstance glad_glDrawElementsInstancedBaseVertexBaseInstance
#define BENCHMARK_glad_glDrawArraysInstancedBaseInstance glad_glDrawArraysInstancedBaseInstance

#define glBegin(mode) \
    do { drawCall(); BENCHMARK_GL_BEGIN(mode); } while(0)

#define glEnd() \
    do { BENCHMARK_GL_END(); } while(0)

#define glad_glDrawArrays(mode, first, count) \
    do { drawCall(); BENCHMARK_glad_glDrawArrays(mode, first, count); } while (0)

#define glad_glDrawElements(mode, count, type, indices) \
    do { drawCall(); BENCHMARK_glad_glDrawElements(mode, count, type, indices); } while (0)

#define glad_glDrawArraysInstanced(mode, first, count, primcount) \
    do { drawCall(); BENCHMARK_glad_glDrawArraysInstanced(mode, first, count, primcount); } while (0)

#define glad_glDrawElementsInstanced(mode, count, type, indices, primcount) \
    do { drawCall(); BENCHMARK_glad_glDrawElementsInstanced(mode, count, type, indices, primcount); } while (0)

#define glad_glDrawArraysIndirect(mode, indirect) \
    do { drawCall(); BENCHMARK_glad_glDrawArraysIndirect(mode, indirect); } while (0)

#define glad_glDrawElementsIndirect(mode, type, indirect) \
    do { drawCall(); BENCHMARK_glad_glDrawElementsIndirect(mode, type, indirect); } while (0)

#define glad_glDrawElementsBaseVertex(mode, count, type, indices, basevertex) \
    do { drawCall(); BENCHMARK_glad_glDrawElementsBaseVertex(mode, count, type, indices, basevertex); } while (0)

#define glad_glDrawElementsInstancedBaseVertex(mode, count, type, indices, primcount, basevertex) \
    do { drawCall(); BENCHMARK_glad_glDrawElementsInstancedBaseVertex(mode, count, type, indices, primcount, basevertex); } while (0)

#define glad_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, primcount, basevertex, baseinstance) \
    do { drawCall(); BENCHMARK_glad_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, primcount, basevertex, baseinstance); } while (0)

#define glad_glDrawArraysInstancedBaseInstance(mode, first, count, primcount, baseinstance) \
    do { drawCall(); BENCHMARK_glad_glDrawArraysInstancedBaseInstance(mode, first, count, primcount, baseinstance); } while (0)

#endif