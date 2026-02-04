#include <stdio.h>
int main(void)
{
  // image
  int image_width = 256;
  int image_height = 256;

  // render
  FILE *f = fopen("image.ppm", "w");

  fprintf(f, "P3\n");
  fprintf(f, "%d %d\n", image_width, image_height);
  fprintf(f, "255\n");

  for (int j = 0; j < image_height; j++) {
    printf("\rLines remaining: %d", image_height - j);
    for (int i = 0; i < image_width; i++) {
      double r = (double)i / (image_width - 1);
      double g = (double)j / (image_height - 1);
      double b = 0.0;

      int ir = (int)(255.999 * r);
      int ig = (int)(255.999 * g);
      int ib = (int)(255.999 * b);

      fprintf(f, "%d %d %d\n", ir, ig, ib);
    }
  }
  printf("\r\033[2KDone.\n");
  fflush(stdout);
}
