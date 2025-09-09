use crate::color::{Color, write_color};

mod color;
mod vec3;

const IMAGE_WIDTH: u32 = 256;
const IMAGE_HEIGHT: u32 = 256;

fn main() {
    println!("P3\n{IMAGE_WIDTH} {IMAGE_HEIGHT}\n255");

    let mut out = std::io::stdout();

    for j in 0..IMAGE_HEIGHT {
        eprint!("\rScanlines remaining : {}", IMAGE_HEIGHT - j);
        for i in 0..IMAGE_WIDTH {
            let pixel_color = Color::new(
                i as f64 / (IMAGE_WIDTH - 1) as f64,
                j as f64 / (IMAGE_HEIGHT - 1) as f64,
                0.0,
            );

            write_color(&mut out, pixel_color);
        }
    }

    eprint!("\rDone \t\t\t\t\t\t\t\t\t\t\n");
}
