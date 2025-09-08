const IMAGE_WIDTH: u32 = 256;
const IMAGE_HEIGHT: u32 = 256;

fn main() {
    println!("P3\n{IMAGE_WIDTH} {IMAGE_HEIGHT}\n255");

    for j in 0..IMAGE_HEIGHT {
        eprint!("\rScanlines remaining : {}", IMAGE_HEIGHT - j);
        for i in 0..IMAGE_WIDTH {
            let r = i as f64 / (IMAGE_WIDTH - 1) as f64;
            let g = j as f64 / (IMAGE_HEIGHT - 1) as f64;
            let b = 0.0;

            let ir = (255.999 * r) as usize;
            let ig = (255.999 * g) as usize;
            let ib = (255.999 * b) as usize;

            println!("{ir} {ig} {ib}");
        }
    }

    eprint!("\rDone \t\t\t\t\t\t\t\t\t\t\n");
}
