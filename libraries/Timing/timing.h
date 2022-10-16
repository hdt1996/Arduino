#include <Arduino.h>
#ifndef TIMING
    #define TIMING

    namespace Timing
    {
        class Timer
        {
            public:
                double time;
                double interval;
                unsigned long (*unit_fn)();

                Timer(unsigned long (*unit_fn)(), double interval);
                Timer(){};
                void update();
                bool check();
        };
    }
#endif