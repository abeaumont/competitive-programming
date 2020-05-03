#!/usr/bin/env python
from PIL import Image

with Image.open('zatoichi.png') as im:
    rs = []
    p = [4, 3, 0, 2, 5, 1]
    for i in range(0, 600, 300):
        for j in range(0, 450, 150):
            rs.append(im.crop((j, i, j+150, i+300)))
    k = 0
    for i in range(0, 600, 300):
        for j in range(0, 450, 150):
            im.paste(rs[p[k]], (j, i, j+150, i+300))
            k += 1
    im.save('zatoichi-ordered.png')

# Then zsteg, decode hex, translate braille.
