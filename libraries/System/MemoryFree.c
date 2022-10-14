#include "MemoryFree.h"

// predefined variables
extern unsigned int __data_start;
extern unsigned int __data_end;
extern unsigned int __bss_start;
extern unsigned int __bss_end;
extern unsigned int __heap_start;
extern void *__brkval;

int memory_min = 0x7FFF; // default bigger value

/**
 * Get the total free memory 
 *
 * @return Available free memory in bytes
 */
int getFreeMemory()
{
    int free_memory;

    if((int)__brkval == 0)
        free_memory = ((int)&free_memory) - ((int)&__bss_end);
    else
        free_memory = ((int)&free_memory) - ((int)__brkval);

    return free_memory;
}

/**
 * Checks for the new minimum memory
 */
void memoryCheck()
{
    int free_memory = getFreeMemory();

    if (free_memory < memory_min) memory_min = free_memory;

    return;
}

/**
 * Get the minimum memory
 */
int getMinMemory()
{
    return memory_min;
}
