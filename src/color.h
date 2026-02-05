#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <stdio.h>

typedef vec3 color;

color color_create(double x, double y, double z);
void write_color(FILE *out, color c);

#endif
