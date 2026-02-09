#include "graphicsBenchmark.h"
#include <time.h>

#ifdef _WIN32

#include <windows.h>
static LARGE_INTEGER frequency, frameStartTime, frameEndTime;

#else

#include <time.h>
static struct timespec frameStartTime, frameEndTime;

#endif


static unsigned int drawCalls = 0;
static double frameTime = 0.0;
static int isFrame = 0;

void frameBegin() {

	drawCalls = 0;

#ifdef _WIN32

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&frameStartTime);

#else

	clock_gettime(CLOCK_MONOTONIC, &frameStartTime);

#endif

	isFrame = 1;

}

void frameEnd() {

#ifdef _WIN32

	QueryPerformanceCounter(&frameEndTime);
	frameTime = (double)(frameEndTime.QuadPart - frameStartTime.QuadPart) * 1000.0 / frequency.QuadPart;

#else

	clock_gettime(CLOCK_MONOTONIC, &frameEndTime);
	frameTime = (frameEndTime.tv_sec - frameStartTime.tv_sec) * 1000.0 + (frameEndTime.tv_nsec - frameStartTime.tv_nsec) / 1e6;


#endif

	isFrame = 0;

}

void drawCall() { drawCalls++; }