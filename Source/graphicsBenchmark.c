#include "graphicsBenchmark.h"
#include <time.h>
#include <stdio.h>

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
static int isPrinting = 0;

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

void timeFrame(){

	if (isFrame) {

		frameEnd();

		if (isPrinting) {

			printf("\rFrame Time: %.2f ms (%.0f FPS) | Draw Calls: %u / frame (%.2f M / sec)    ",
				frameTime,
				(1000.0 / frameTime),
				drawCalls,
				drawCalls * (1000.0 / frameTime));

			fflush(stdout);

			isPrinting = 0;

		}

	}
	frameBegin();

}

void printStats() {

	isPrinting = 1;

}

void drawCall() {

	drawCalls++; 

}

double getFrameTime() {

	return frameTime;

}

unsigned int getDrawCallCount() {

	return drawCalls;

}