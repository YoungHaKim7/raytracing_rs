use rayon::prelude::*;
use std::{
    fs::File,
    io::{BufWriter, Write},
};

fn main() {
    let image_width = 256;
    let image_height = 256;

    let mut file = BufWriter::new(File::create("image.ppm").unwrap());
    writeln!(file, "P3\n{image_width} {image_height}\n255").unwrap();

    // Parallelize over rows
    let rows: Vec<String> = (0..image_height)
        .into_par_iter()
        .map(|j| {
            let mut row = String::new();
            for i in 0..image_width {
                let r = i as f64 / (image_width - 1) as f64;
                let g = j as f64 / (image_height - 1) as f64;
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
