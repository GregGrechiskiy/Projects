class TriangleChecker:
    def is_triangle(self, a, b, c):
        if type(a) != int or type(b) != int or type(c) != int:
            return 'Нужно вводить только числа!'
        elif a <= 0 or b <= 0 or c <= 0:
            return 'С отрицательными числами ничего не выйдет!'
        elif a + b > c and a + c > b and b + c > a:
            return 'Ура, можно постоить треугольник!'
        else:
            return 'Жаль, но из этого треугольник не сделать.'

checker = TriangleChecker()
result = checker.is_triangle(3, 4, 5)
print(result)