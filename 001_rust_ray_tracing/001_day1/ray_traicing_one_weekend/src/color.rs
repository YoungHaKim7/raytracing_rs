use std::io::Write;

pub struct Color {
    r: f64,
    g: f64,
    b: f64,
}

impl Color {
    pub fn new(r: f64, g: f64, b: f64) -> Self {
        Self { r, g, b }
    }
}

pub fn write_color(out: &mut impl Write, pixel_color: Color) {
    let rbyte = (255.99 * pixel_color.r) as usize;
    let gbyte = (255.99 * pixel_color.r) as usize;
    let bbyte = (255.99 * pixel_color.r) as usize;
    writeln!(out, "{rbyte}, {gbyte}, {bbyte}");
}
