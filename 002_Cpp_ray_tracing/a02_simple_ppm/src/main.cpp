#include <iostream>
#include <fstream>

#define WIDTH 256
#define HEIGHT 256

int main() {
    std::ofstream out("image.ppm");
    if (!out) {
        std::cerr << "Error: could not open file\n";
        return 1;
    }

    // int width = 256;
    // int height = 256;

    // Write PPM header
    out << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

    // Block sizes
    int block_width = WIDTH / 3;   // 85 pixels wide
    int block_height = HEIGHT / 2; // 128 pixels tall

    // Define 6 colors: Red, Green, Blue, Yellow, White, Black
    int colors[6][3] = {
        {255, 0, 0},     // Red
        {0, 255, 0},     // Green
        {0, 0, 255},     // Blue
        {255, 255, 0},   // Yellow
        {255, 255, 255}, // White
        {0, 0, 0}        // Black
    };

    // Generate pixel data
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            int block_row = j / block_height;  // 0 or 1
            int block_col = i / block_width;   // 0,1,2
            int block_index = block_row * 3 + block_col;

            int r = colors[block_index][0];
            int g = colors[block_index][1];
            int b = colors[block_index][2];

            out << r << " " << g << " " << b << "\n";
        }
    }

    out.close();
    return 0;
}
