import math


class Rectangle:
    def __init__(self, point1, point2):
        self.x1, self.y1 = point1
        self.x2, self.y2 = point2

    def perimeter(self):
        width = abs(self.x2 - self.x1)
        height = abs(self.y2 - self.y1)
        perimeter = 2 * (width + height)
        return round(perimeter, 2)

    def area(self):
        width = abs(self.x2 - self.x1)
        height = abs(self.y2 - self.y1)
        area = width * height
        return round(area, 2)

    def get_pos(self):
        return (self.x1, self.y1)

    def get_size(self):
        width = abs(self.x2 - self.x1)
        height = abs(self.y2 - self.y1)
        return (width, height)

    def move(self, dx, dy):
        self.x1 += dx
        self.y1 += dy
        self.x2 += dx
        self.y2 += dy

    def resize(self, width, height):
        self.x2 = self.x1 + width
        self.y2 = self.y1 + height

    def turn(self):
        center_x = (self.x1 + self.x2) / 2
        center_y = (self.y1 + self.y2) / 2

        new_x1 = 2 * center_x - self.x2
        new_x2 = 2 * center_x - self.x1
        new_y1 = 2 * center_y - self.y2
        new_y2 = 2 * center_y - self.y1

        self.x1 = new_x1
        self.x2 = new_x2
        self.y1 = new_y1
        self.y2 = new_y2

    def scale(self, factor):
        center_x = (self.x1 + self.x2) / 2
        center_y = (self.y1 + self.y2) / 2

        width = abs(self.x2 - self.x1)
        height = abs(self.y2 - self.y1)

        new_width = round(width * factor, 2)
        new_height = round(height * factor, 2)

        self.x1 = center_x - new_width / 2
        self.x2 = center_x + new_width / 2
        self.y1 = center_y - new_height / 2
        self.y2 = center_y + new_height / 2


rect = Rectangle((1, 1), (5, 4))


rect.move(2, -1)


rect.resize(8, 6)


rect.turn()


rect.scale(1.5)


pos = rect.get_pos()


size = rect.get_size()


perimeter = rect.perimeter()
area = rect.area()


print(pos)
print(size)
print(perimeter)
print(area)