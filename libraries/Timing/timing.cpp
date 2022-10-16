#include "timing.h"

namespace Timing
{
    Timer::Timer(unsigned long (*unit_fn)(), double interval)
    {
        time = unit_fn();
        unit_fn = unit_fn;
        interval = interval;
    };
    void Timer::update()
    {
        time+=interval;
    };
    bool Timer::check()
    {
        if(unit_fn() - time > interval)
        {
            time+=interval;
            return true;
        }
        return false;
    }


}