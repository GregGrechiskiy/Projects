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


rect = Rectangle((-2, 3), (4, -5))


pos = rect.get_pos()


size = rect.get_size()


rect.move(2, -1)


rect.resize(8, 6)


perimeter = rect.perimeter()
area = rect.area()


print(pos)
print(size)
print(perimeter)
print(area)