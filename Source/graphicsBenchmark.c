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


void drawCall() { drawCalls++; }