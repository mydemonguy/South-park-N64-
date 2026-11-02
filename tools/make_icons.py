"""Generate original, generic app artwork for the South Park recomp port.

A simple night-sky + snowy-hills design with "64" — deliberately nothing resembling
the game's characters, logo or lettering. Usage: python3 -I make_icons.py <repo root>
"""
import os
import struct
import sys

from PIL import Image, ImageDraw, ImageFont

SKY_TOP, SKY_BOTTOM = (27, 54, 93), (64, 112, 168)
SNOW, SNOW_SHADE = (245, 248, 252), (205, 218, 235)


def font(size):
    for path in ("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf",
                 "/usr/share/fonts/truetype/liberation/LiberationSans-Bold.ttf"):
        if os.path.exists(path):
            return ImageFont.truetype(path, size)
    return ImageFont.load_default()


def background(n):
    im = Image.new("RGBA", (n, n))
    d = ImageDraw.Draw(im)
    for y in range(n):
        t = y / max(1, n - 1)
        d.line([(0, y), (n, y)], fill=tuple(int(a + (b - a) * t) for a, b in zip(SKY_TOP, SKY_BOTTOM)) + (255,))
    return im


def hills(d, n, fill_back, fill_front):
    d.ellipse([-0.35 * n, 0.62 * n, 0.75 * n, 1.5 * n], fill=fill_back)
    d.ellipse([0.25 * n, 0.68 * n, 1.4 * n, 1.55 * n], fill=fill_front)


def snowflakes(d, n, fill):
    for (x, y, r) in ((0.18, 0.2, 0.025), (0.8, 0.16, 0.02), (0.68, 0.36, 0.015), (0.3, 0.42, 0.018), (0.88, 0.5, 0.017)):
        d.ellipse([(x - r) * n, (y - r) * n, (x + r) * n, (y + r) * n], fill=fill)


def label(d, n, fill, scale=0.30, y=0.44):
    f = font(int(n * scale))
    w = d.textlength("64", font=f)
    d.text(((n - w) / 2, y * n - n * scale / 2), "64", font=f, fill=fill)


def full_icon(n, transparent_corners=False):
    im = background(n)
    d = ImageDraw.Draw(im)
    snowflakes(d, n, SNOW + (255,))
    hills(d, n, SNOW_SHADE + (255,), SNOW + (255,))
    label(d, n, (255, 255, 255, 255))
    if transparent_corners:
        mask = Image.new("L", (n, n), 0)
        ImageDraw.Draw(mask).ellipse([0, 0, n - 1, n - 1], fill=255)
        im.putalpha(mask)
    return im


def foreground(n):
    # Adaptive icon foreground: content in the central 66% safe zone.
    im = Image.new("RGBA", (n, n), (0, 0, 0, 0))
    d = ImageDraw.Draw(im)
    s = n * 0.66
    o = (n - s) / 2
    sub = Image.new("RGBA", (int(s), int(s)), (0, 0, 0, 0))
    sd = ImageDraw.Draw(sub)
    snowflakes(sd, int(s), SNOW + (255,))
    hills(sd, int(s), SNOW_SHADE + (255,), SNOW + (255,))
    label(sd, int(s), (255, 255, 255, 255))
    im.alpha_composite(sub, (int(o), int(o)))
    return im


def monochrome(n):
    fg = foreground(n)
    alpha = fg.split()[3]
    im = Image.new("RGBA", (n, n), (255, 255, 255, 0))
    im.putalpha(alpha)
    return im


def write_ico(path, png_img):
    png_img.save(path, format="ICO", sizes=[png_img.size])


def launcher_svg():
    return """<?xml version="1.0" encoding="utf-8"?>
<!-- Original generic artwork for the launcher background: snowy hills at night. -->
<svg version="1.1" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 498.5 461.1">
  <circle cx="400" cy="90" r="38" fill="#F3F6FA" fill-opacity="0.85"/>
  <circle cx="90" cy="120" r="6" fill="#F3F6FA"/>
  <circle cx="190" cy="60" r="5" fill="#F3F6FA"/>
  <circle cx="300" cy="170" r="4" fill="#F3F6FA"/>
  <circle cx="140" cy="230" r="5" fill="#F3F6FA"/>
  <ellipse cx="120" cy="470" rx="300" ry="190" fill="#CDDAEB"/>
  <ellipse cx="420" cy="500" rx="300" ry="200" fill="#F5F8FC"/>
</svg>
"""


def main():
    root = sys.argv[1]
    res = os.path.join(root, "android/app/src/main/res")
    dens = {"mdpi": (48, 108), "hdpi": (72, 162), "xhdpi": (96, 216), "xxhdpi": (144, 324), "xxxhdpi": (192, 432)}
    for name, (legacy, adaptive) in dens.items():
        dd = os.path.join(res, f"mipmap-{name}")
        full_icon(legacy).convert("RGB").save(os.path.join(dd, "ic_launcher.png"))
        full_icon(legacy, transparent_corners=True).save(os.path.join(dd, "ic_launcher_round.png"))
        background(adaptive).save(os.path.join(dd, "ic_launcher_background.png"))
        foreground(adaptive).save(os.path.join(dd, "ic_launcher_foreground.png"))
        monochrome(adaptive).save(os.path.join(dd, "ic_launcher_monochrome.png"))
    icons = os.path.join(root, "icons")
    full_icon(512).save(os.path.join(icons, "512.png"))
    for n in (16, 32, 64, 128, 256, 512):
        write_ico(os.path.join(icons, f"{n}.ico"), full_icon(n))
    with open(os.path.join(root, "assets/launcher-background.svg"), "w") as f:
        f.write(launcher_svg())


if __name__ == "__main__":
    main()
