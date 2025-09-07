# 1. Save the PPM output
- Run your Rust code and redirect the output into a file:

```bash
cargo run > image.ppm
```

# 2. Convert PPM to PNG (using ImageMagick)
- If you have ImageMagick
  - https://imagemagick.org/

```bash
convert image.ppm image.png
```

- or newer versions:

```bash
magick image.ppm image.png
```


# rust image crate
- https://crates.io/crates/image
