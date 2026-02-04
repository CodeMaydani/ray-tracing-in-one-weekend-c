#include "vec3.h"
#include <math.h>

vec3 vec3_create(double x, double y, double z)
{
  vec3 v = {x, y, z};
  return v;
}

vec3 vec3_add(vec3 a, vec3 b)
{
  return vec3_create(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3 vec3_sub(vec3 a, vec3 b)
{
  return vec3_create(a.x - b.x, a.y - b.y, a.z - b.z);
}

vec3 vec3_mul(vec3 a, double t)
{
  return vec3_create(a.x * t, a.y * t, a.z * t);
}

vec3 vec3_div(vec3 v, double t)
{
  return vec3_mul(v, 1.0 / t);
}

// Vector math
double vec3_dot(vec3 a, vec3 b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 vec3_cross(vec3 a, vec3 b)
{
  return vec3_create(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                     a.x * b.y - a.y * b.x);
}

double vec3_length_squared(vec3 v)
{
  return vec3_dot(v, v);
}

double vec3_length(vec3 v)
{
  return sqrt(vec3_length_squared(v));
}

vec3 vec3_unit(vec3 v)
{
  return vec3_div(v, vec3_length(v));
}
