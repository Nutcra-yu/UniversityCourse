import math

import pgzrun

WIDTH = 800
HEIGHT = 600

x1 = WIDTH / 3
y1 = HEIGHT / 2
x2 = WIDTH / 3 * 2
y2 = HEIGHT / 2

r = 10

speed_x1 = -10
speed_y1 = 10
speed_x2 = -10
speed_y2 = -10


def draw():
    screen.fill('white')
    screen.draw.filled_circle((x1, y1), r, 'red')
    screen.draw.filled_circle((x2, y2), r, 'blue')


def update():
    global x1, x2, y1, y2, speed_x1, speed_x2, speed_y2, speed_y1
    x1 += speed_x1
    y1 += speed_y1
    x2 += speed_x2
    y2 += speed_y2
    if x1 <= r or WIDTH - x1 <= r:
        speed_x1 = -speed_x1
    if y1 <= r or HEIGHT - y1 <= r:
        speed_y1 = -speed_y1
    if x2 <= r or WIDTH - x2 <= r:
        speed_x2 = -speed_x2
    if y2 <= r or HEIGHT - y2 <= r:
        speed_y2 = -speed_y2
    if math.sqrt((x1-x2)**2+(y1-y2)**2) <= 10:
        speed_x1 = -speed_x1
        speed_y1 = -speed_y1
        speed_x2 = -speed_x2
        speed_y2 = -speed_y2


pgzrun.go()
