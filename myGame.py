import pygame, sys
#from pygame.locals import *

pygame.init() # initialize pygame

# Console window size
width  = 600
height = 400

window = pygame.display.set_mode((width, height)) # sets the window size
pygame.display.set_caption('Welcome to my first game in python') # sets the title of the window
space = pygame.image.load('GalaxianGalaxip.gif')
clock = pygame.time.Clock()

# let's define a rectangle
x = 20
y = 20
w = 100
h = 80
col = (55, 110, 128)
velocity = 0

def load_image(x, y):
    window.blit(space, (x, y))

xs = (width * 0.45)
ys = (height * 0.85)

while True :
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                velocity = -5

            if event.key == pygame.K_RIGHT:
                velocity = 5

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_RIGHT or event.key == pygame.K_LEFT:
                velocity = 0

    if 0 <= xs + velocity and xs + 32 + velocity <= width:
        xs += velocity

    window.fill(col)
    load_image(xs, ys)
    pygame.display.update()
    clock.tick(60)
