#pragma once
#include <sys/time.h>

class Stopwatch
{
    public:
        void start()
        {
            gettimeofday(&_start, NULL);
        }
        long stop()
        {
            gettimeofday(&_end, NULL);
            return elapsed();
        }
        long elapsed()
        {
            long seconds  = _end.tv_sec  - _start.tv_sec;
            long useconds = _end.tv_usec - _start.tv_usec;
            return ((seconds) * 1000 + useconds/1000.0) + 0.5;
        }

    private:
        struct timeval _start, _end;
};
