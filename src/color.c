#include "color.h"
#include <stdio.h>

color color_create(double x, double y, double z)
{
  return vec3_create(x, y, z);
}
void write_color(FILE *out, color c)
{
  // Translate the [0,1] component values to the byte range [0,255].
  int r = (int)(255.999 * c.x);
  int g = (int)(255.999 * c.y);
  int b = (int)(255.999 * c.z);

  // Write out the pixel color components.
  fprintf(out, "%d %d %d\n", r, g, b);
}
