#include "util.hh"

void pause() {
  int a;
  cin >> a;
}

int main(int argc, char** argv) {
  FIBITMAP *bitmap = FreeImage_Allocate(500, 500, 24);
  RGBQUAD fi_color;
  fi_color.rgbBlue = 255;
  fi_color.rgbRed = 0;
  fi_color.rgbGreen = 0;
  for (int i = 0; i < 500; ++i) {
    for (int j = 0; j < 500; ++j) {
      FreeImage_SetPixelColor(bitmap, j, i, &fi_color);
    }
  }

  if (FreeImage_Save(FIF_PNG, bitmap, "tmp.png", 0)) {
    cout << "Image saved to " << "tmp.png" << endl;
  } else {
    cout << "Could not save the image to " << "tmp.png" << endl;
  }
  pause();
}