#!/usr/bin/env python3
"""Render the launcher icon PNGs from the SVGs in this folder (needs rsvg-convert and Pillow).

    python3 tools/icon/generate.py
"""
import os, subprocess, tempfile
from PIL import Image, ImageDraw

HERE = os.path.dirname(os.path.abspath(__file__))
RES = os.path.join(HERE, "..", "..", "android", "app", "src", "main", "res")
DENSITIES = {"mdpi": 1, "hdpi": 1.5, "xhdpi": 2, "xxhdpi": 3, "xxxhdpi": 4}

def render(svg, size):
    with tempfile.NamedTemporaryFile(suffix=".png", delete=False) as f:
        path = f.name
    subprocess.run(["rsvg-convert", "-w", str(size), "-h", str(size), os.path.join(HERE, svg), "-o", path], check=True)
    im = Image.open(path).convert("RGBA")
    os.unlink(path)
    return im

for name, scale in DENSITIES.items():
    out = os.path.join(RES, "mipmap-" + name)
    layer = round(108 * scale)
    legacy = round(48 * scale)
    bg = render("ic_background.svg", layer)
    fg = render("ic_foreground.svg", layer)
    bg.convert("RGB").save(os.path.join(out, "ic_launcher_background.png"))
    fg.save(os.path.join(out, "ic_launcher_foreground.png"))
    render("ic_monochrome.svg", layer).save(os.path.join(out, "ic_launcher_monochrome.png"))

    # Legacy icons (pre-Android 8): the middle 72 dp of the layered icon.
    full = Image.alpha_composite(bg, fg)
    inset = round(18 * scale)
    crop = full.crop((inset, inset, layer - inset, layer - inset)).resize((legacy, legacy), Image.LANCZOS)
    crop.convert("RGB").save(os.path.join(out, "ic_launcher.png"))
    mask = Image.new("L", (legacy * 4, legacy * 4), 0)
    ImageDraw.Draw(mask).ellipse((0, 0, legacy * 4 - 1, legacy * 4 - 1), fill=255)
    mask = mask.resize((legacy, legacy), Image.LANCZOS)
    round_icon = crop.copy()
    round_icon.putalpha(mask)
    round_icon.save(os.path.join(out, "ic_launcher_round.png"))
    print("mipmap-%s: %dpx layers, %dpx legacy" % (name, layer, legacy))
