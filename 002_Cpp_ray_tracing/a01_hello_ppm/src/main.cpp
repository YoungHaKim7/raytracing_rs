#include <fstream>
#include <iostream>

int main()
{
    std::ofstream out("image.ppm");
    if (!out) {
        std::cerr << "Error: could not open file\n";
        return 1;
    }

    int width = 3;
    int height = 2;

    // Write PPM header
    out << "P3\n"
        << width << " " << height << "\n255\n";

    // Pixel data (row-major order)
    int pixels[6][3] = {
        { 255, 0, 0 }, // red
        { 0, 255, 0 }, // green
        { 0, 0, 255 }, // blue
        { 255, 255, 0 }, // yellow
        { 255, 255, 255 }, // white
        { 0, 0, 0 } // black
    };

    for (int i = 0; i < 6; i++) {
        out << pixels[i][0] << " " << pixels[i][1] << " " << pixels[i][2] << "\n";
    }

    out.close();
    return 0;
}
