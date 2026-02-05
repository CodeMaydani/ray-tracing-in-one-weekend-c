#include "ray.h"
#include "point3.h"
#include "vec3.h"

ray ray_create(point3 origin, vec3 direction)
{
  ray r;
  r.origin = origin;
  r.direction = direction;

  return r;
}

point3 ray_at(ray r, double t)
{
  return vec3_add(r.origin, vec3_mul(r.direction, t));
}
