# Graphics-Benchmark
A C library for testing the performance of a program using OpenGL, expressing this in the time it takes for a produced frame in ms, how many of those frames are made per second, draw calls per frame, and draw calls per second.

## Installation
The repository can be cloned with the following command:
> git clone https://github.com/archiethehead/Graphics-Benchmark

A Microsoft Visual Studio 2022 Solution is provided for compilation of the source if testing is needed, but use of the library should be done with the uncompiled header, in assistance of other programs. The system dependant libraries are accounted for and as such, this library is usable on Windows, MacOS, and Linux.

## Quick Start
Simply include the library in your program (AFTER your OpenGL imports, and wherever draw calling occurs), call the frameTime() function in the main loop (or frameBegin() and frameEnd() if you're just snapshotting a 3D environment), and use printStats() to view the data that was collected. The library is written in C, meaning because C++ is a superset of C, this library can be used with any C or C++ OpenGL program. A demo program utilising the GLFW triangle rotation template is provided to show how functionality with this llibrary should be performed.

## Contributors
Mr. Archie T. Healy - archiehealy06@gmail.com

## License
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
