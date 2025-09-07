use rayon::prelude::*;
use std::{
    fs::File,
    io::{BufWriter, Write},
};

const IMAGE_WIDTH: u32 = 256;
const IMAGE_HEIGHT: u32 = 256;

fn main() {
    let mut file = BufWriter::new(File::create("image.ppm").unwrap());
    writeln!(file, "P3\n{IMAGE_WIDTH} {IMAGE_HEIGHT}\n255").unwrap();

    // Parallelize over rows
    let rows: Vec<String> = (0..IMAGE_HEIGHT)
        .into_par_iter()
        .map(|j| {
            let mut row = String::new();
            for i in 0..IMAGE_WIDTH {
                let r = i as f64 / (IMAGE_WIDTH - 1) as f64;
                let g = j as f64 / (IMAGE_HEIGHT - 1) as f64;
                let b = 0.0;

                let ir = (255.999 * r) as usize;
                let ig = (255.999 * g) as usize;
                let ib = (255.999 * b) as usize;

                row.push_str(&format!("{ir} {ig} {ib}\n"));
            }
            row
        })
        .collect();

    // Write results in order
    for row in rows {
        write!(file, "{}", row).unwrap();
    }
}
