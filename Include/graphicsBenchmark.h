// graphicsBenchmark.h

#ifndef GRAPHICSBENCHMARK_H
#define GRAPHICSBENCHMARK_H

#ifdef __cplusplus
extern "C" {
#endif

	void timeFrame();
	void printStats();
	double getFrameTime();
	unsigned int getDrawCallCount();
	
	void frameBegin();
	void frameEnd();
	void drawCall();

#include "GLHooks.h"

#ifdef __cplusplus
}
#endif

#endif