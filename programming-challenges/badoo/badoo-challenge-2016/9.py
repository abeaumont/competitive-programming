#!/usr/bin/env python2

from PIL import Image

cipher = Image.open('HoN.png')
(x, y) = cipher.size
red = Image.new('1', cipher.size)
green = Image.new('1', cipher.size)
blue = Image.new('1', cipher.size)
for j in xrange(y):
    for i in xrange(x):
        xy = (i, j)
        (rr, gg, bb) = cipher.getpixel(xy)
        red.putpixel(xy, rr & 1)
        green.putpixel(xy, gg & 1)
        blue.putpixel(xy, bb & 1)
red.save("red.png")
green.save("green.png")
blue.save("blue.png")
print "I completed the steganography challenge and the only prize I got is advancing to the next challenge!"
