#include "point3.h"
#include "vec3.h"

point3 point3_create(double x, double y, double z)
{
  return vec3_create(x, y, z);
}
