#include "philo.h"

long    *get_init_time()
{
    static long time;

    return (&time);
}
