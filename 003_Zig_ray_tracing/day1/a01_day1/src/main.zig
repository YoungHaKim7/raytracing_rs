const std = @import("std");
const a01_day1 = @import("a01_day1");

const WIDTH = 256;
const HEIGHT = 256;

pub fn main() !void {
    var wbuf: [4096]u8 = undefined;
    var file_writer = std.fs.File.stdout().writer(&wbuf);
    const out = &file_writer.interface;

    // const height = 256;
    // const width = 256;

    try out.print("P3\n{d} {d}\n255\n", .{ WIDTH, HEIGHT });

    for (0..HEIGHT) |h| {
        for (0..WIDTH) |w| {
            const fh: f32 = @floatFromInt(h);
            const fw: f32 = @floatFromInt(w);

            const r: u8 = @intFromFloat(255.99 * (fh / (HEIGHT - 1.0)));
            const g: u8 = @intFromFloat(255.99 * (fw / (WIDTH - 1.0)));
            const b: u8 = 0;

            try out.print("{d} {d: >3} {d: >3}", .{ r, g, b });
        }
    }
}

test "simple test" {}

test "fuzz example" {}
