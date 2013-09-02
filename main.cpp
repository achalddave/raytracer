#include "geometry.hh"
#include "util.hh"

char* output_file = "output/tmp.png";

Point3f eye(0,0,0);
Vector3f lookAt(0,0,-1);
Vector3f up(0,1,0);

float viewingPlaneDistance = 10;
int imgWidth = 500;
int imgHeight = 500;

void pause() {
  cin.get();
}

int main(int argc, char** argv) {
  FIBITMAP *bitmap = FreeImage_Allocate(imgWidth, imgHeight, 24);

  Sphere sphere(Point3f(-50,-50,-200), 199);

  Vector3f right = (lookAt.cross(up)).normalized();

  RGBQUAD fi_color;
  fi_color.rgbBlue = 255;
  fi_color.rgbRed = 0;
  fi_color.rgbGreen = 0;
  for (int col = -(imgWidth / 2); col < (imgWidth / 2); ++col) {
    for (int row = -(imgHeight / 2); row < (imgHeight / 2); ++row) {
      Point3f currPointOnViewPlane = eye + lookAt*viewingPlaneDistance + col*right + row*up;
      Ray currRay(eye, currPointOnViewPlane - eye);
      float intersectTime = sphere.intersection(currRay);
      if (intersectTime > -FLT_MIN) {
        FreeImage_SetPixelColor(bitmap, col + (imgWidth / 2), row + (imgHeight / 2), &fi_color);
      }
    }
  }

  if (FreeImage_Save(FIF_PNG, bitmap, output_file, 0)) {
    cout << "Image saved to " << output_file << endl;
  } else {
    cout << "Could not save the image to " << output_file << endl;
  }
  pause();

}