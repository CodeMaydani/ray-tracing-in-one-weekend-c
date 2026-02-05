#ifndef RAY_H
#define RAY_H

#include "point3.h"
#include "vec3.h"

typedef struct {
  point3 origin;
  vec3 direction;
} ray;

ray ray_create(point3 origin, vec3 direction);

point3 ray_at(ray r, double t);

#endif
