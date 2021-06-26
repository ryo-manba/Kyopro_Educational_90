from PIL import Image, ImageDraw


WIDTH = 600
HEIGHT = 400
MAX_ITER = 70
min_re = -2
max_re = 1
min_im = -1
max_im = 1


def mandelbrot(c):
    z = 0
    n = 0
    while abs(z) <= 2 and n < MAX_ITER:
        z = z * z + c
        n += 1
    return n


def main():
    img = Image.new('RGB', (WIDTH, HEIGHT), (0, 0, 0))
    draw = ImageDraw.Draw(img)

    for x in range(0, WIDTH):
        for y in range(0, HEIGHT):
            c = complex(min_re + (x / WIDTH) * (max_re - min_re),
                        min_im + (y / HEIGHT) * (max_im - min_im))
            m = mandelbrot(c)
            color = 255 - int(m * 255 / MAX_ITER)
            draw.point([x, y], (color, color, color))
    img.save('mandelbrot.png', 'PNG')


if __name__ == "__main__":
    main()
