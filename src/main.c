#include "color.h"
#include "point3.h"
#include "ray.h"
#include "vec3.h"
#include <stdio.h>

color ray_color(ray r)
{

  vec3 unit_direction = vec3_unit(r.direction);
  double a = 0.5 * (unit_direction.y + 1.0);
  // blendedValue = (1−a) * startValue + a * endValue,
  return vec3_add(vec3_mul(color_create(1.0, 1.0, 1.0), 1.0 - a),
                  vec3_mul(color_create(0.5, 0.7, 1.0), a));
}

int main(void)
{
  // Image

  double aspect_ratio = 16.0 / 9.0;
  int image_width = 400;

  // Calculate the image height, and ensure that it's at least 1.
  int image_height = (int)image_width / aspect_ratio;
  image_height = (image_height < 1) ? 1 : image_height;

  // Camera

  double focal_length = 1.0;
  double viewport_height = 2.0;
  double viewport_width =
      viewport_height * ((double)image_width) / image_height;
  point3 camera_center = point3_create(0, 0, 0);

  // Calculate the vectors across the horizontal and down the vertical viewport
  // edges.
  vec3 viewport_u = vec3_create(viewport_width, 0, 0);
  vec3 viewport_v = vec3_create(0, -viewport_height, 0);

  // Calculate the horizontal and vertical delta vectors from pixel to pixel.
  // Basicly the pixel size
  vec3 pixel_delta_u = vec3_div(viewport_u, image_width);
  vec3 pixel_delta_v = vec3_div(viewport_v, image_height);

  // Calculate the location of the upper left pixel.
  // From the camera, move forward by focal_length to reach the viewport plane,
  // then move left by half the viewport width (viewport_u / 2)
  // and up by half the viewport height (viewport_v / 2)
  point3 viewport_upper_left = vec3_sub(
      vec3_sub(vec3_sub(camera_center, vec3_create(0, 0, focal_length)),
               vec3_div(viewport_u, 2)),
      vec3_div(viewport_v, 2));
	// Center of pixel 0,0
  point3 pixel00_loc =
      vec3_add(viewport_upper_left,
               vec3_mul(vec3_add(pixel_delta_u, pixel_delta_v), 0.5));

  // render
  FILE *f = fopen("image.ppm", "w");

  fprintf(f, "P3\n");
  fprintf(f, "%d %d\n", image_width, image_height);
  fprintf(f, "255\n");

  for (int j = 0; j < image_height; j++) {
    printf("\rLines remaining: %d", image_height - j);
    for (int i = 0; i < image_width; i++) {
      // Find the center of the pixel
      point3 pixel_center =
          vec3_add(pixel00_loc, vec3_add(vec3_mul(pixel_delta_u, i),
                                         vec3_mul(pixel_delta_v, j)));
      // Create a vector from the camera to the pixel
      vec3 ray_direction = vec3_sub(pixel_center, camera_center);
      ray r = ray_create(camera_center, ray_direction);

      color pixel_color = ray_color(r);
      write_color(f, pixel_color);
    }
  }
  printf("\r\033[2KDone.\n");
  fflush(stdout);
	printf("%f %f %f\n", viewport_upper_left.x, viewport_upper_left.y, viewport_upper_left.z);
}
