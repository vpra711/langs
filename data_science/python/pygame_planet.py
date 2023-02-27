import math
import pygame

pygame.init()

width, height = 1200, 1200
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Solar System")

yellow = (255, 255, 0)
blue = (100, 149, 237)
red = (188, 39, 50)
dark_grey = (80, 78, 81)
white = (255, 255, 255)

class planet:
    AU = 149.6e6 * 1000
    G = 6.67428e-11
    SCALE = 300 / AU 
    TIMESTAMP = 3600 * 24

    def __init__(self, x, y, radius, color, mass) -> None:
        self.x = x
        self.y = y
        self.radius = radius
        self.color = color
        self.mass = mass
        self.orbit = []
        self.sun = False
        self.distance_from_sun = 0
        self.x_vel = 0
        self.y_vel = 0

    def draw(self, window):
        x = self.x * self.SCALE + width / 2
        y = self.y * self.SCALE + height / 2
        pygame.draw.circle(window, self.color, (x, y), self.radius)

        if len(self.orbit) > 2:
            updated_points = []
            for point in self.orbit:
                x, y = point
                x = x * self.SCALE + width / 2
                y = y * self.SCALE + height / 2
                updated_points.append((x ,y))

            pygame.draw.lines(window, self.color, False, updated_points)
        pygame.draw.circle(window, self.color, (x, y), self.radius)


    def attraction(self, other):
        other_x, other_y = other.x, other.y
        distance_x = other_x - self.x
        distance_y = other_y - self.y
        distance = math.sqrt(distance_x**2 + distance_y**2)

        if other.sun:
            self.distance_from_sun = distance
        
        force = self.G * self.mass * other.mass / distance**2
        theta = math.atan2(distance_y, distance_x)
        force_x = math.cos(theta) * force
        force_y = math.sin(theta) * force
        return force_x, force_y

    def update_position(self, matters):
        total_fx = total_fy = 0
        for thing in matters:
            if self == thing:
                continue

            fx,fy = self.attraction(thing)
            total_fx += fx
            total_fy += fy
        
        self.x_vel += total_fx / self.mass * self.TIMESTAMP
        self.y_vel += total_fy / self.mass * self.TIMESTAMP

        self.x += self.x_vel * self.TIMESTAMP
        self.y += self.y_vel * self.TIMESTAMP
        self.orbit.append((self.x, self.y))

def main():
    run = True
    frame_rate = pygame.time.Clock()

    sun = planet(0, 0, 40, yellow, 1.98892 * 10**30)
    sun.sun = True

    mercury = planet(0.387 * planet.AU, 0, 18, dark_grey, 3.30 * 10**23)
    mercury.y_vel = -47.4 * 1000

    venus = planet(0.723 * planet.AU, 0, 14, white, 4.8685 * 10**24)
    venus.y_vel = -35.02 * 1000

    earth = planet(-1 * planet.AU, 0, 16, blue, 5.9742 * 10**24)
    earth.y_vel = 29.783 * 1000

    mars = planet(-1.524 * planet.AU, 0, 12, red, 6.39 * 10**23)
    mars.y_vel = 24.077 * 1000

    matters = [sun, mercury, venus, earth, mars]

    while run:
        frame_rate.tick(60)
        window.fill((0, 0, 0))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        for thing in matters:
            thing.update_position(matters)
            thing.draw(window)
        
        pygame.display.update()
    
    pygame.quit()

main()