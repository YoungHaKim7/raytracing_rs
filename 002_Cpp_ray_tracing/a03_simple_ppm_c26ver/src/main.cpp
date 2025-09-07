#include <expected>
#include <fstream>
#include <print>

#define WIDTH 256
#define HEIGHT 256

// Function that generates the PPM file
auto generate_ppm(const std::string& filename) -> std::expected<void, std::string>
{
    std::ofstream out(filename);
    if (!out.is_open()) {
        return std::unexpected { "could not open file" };
    }

    // Write PPM header
    out << "P3\n"
        << WIDTH << " " << HEIGHT << "\n255\n";

    // Block sizes
    int block_width = WIDTH / 3;
    int block_height = HEIGHT / 2;

    // Define 6 colors: Red, Green, Blue, Yellow, White, Black
    int colors[6][3] = {
        { 255, 0, 0 }, // Red
        { 0, 255, 0 }, // Green
        { 0, 0, 255 }, // Blue
        { 255, 255, 0 }, // Yellow
        { 255, 255, 255 }, // White
        { 0, 0, 0 } // Black
    };

    // Generate pixel data
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            int block_row = j / block_height; // 0 or 1
            int block_col = i / block_width; // 0,1,2
            int block_index = block_row * 3 + block_col;

            auto [r, g, b] = colors[block_index];
            out << r << " " << g << " " << b << "\n";
        }
    }

    return {}; // success
}

int main()
{
    if (auto result = generate_ppm("image.ppm"); !result) {
        std::print(stderr, "Error: {}\n", result.error());
        return 1;
    }

    std::print("PPM image generated successfully.\n");
    return 0;
}
