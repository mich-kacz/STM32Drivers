#ifndef POWER_H
#define POWER_H

typedef enum PowerVOS_e
{
    PowerVOS_mode3         = 1,
    PowerVOS_mode2         = 2,
    PowerVOS_mode1_Default = 3
} PowerVOS_t;

void powerSetVOS(PowerVOS_t mode);

#endif