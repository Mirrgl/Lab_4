import math

EPSILON = 0.0001

def function(x):
    return x**2 - 3 * math.sin(x)

def derivativeFunction(x):
    return 2 * x - 3 * math.cos(x)

def secondDerivativeFunction(x):
    return 2 + 3 * math.sin(x)

def methodHalf(a, b):
    step = 0
    center = 0.0

    print(f"{'N':<3}{'a':<9}{'b':<8}b - a")
    print(f"{step:<3}{a:<9.5f}{b:<8.5f}{abs(b - a):.5f}")

    while abs(b - a) >= EPSILON:
        center = (a + b) / 2
        if function(a) * function(center) < 0:
            b = center
        if function(center) * function(b) < 0:
            a = center
        step += 1
        print(f"{step:<3}{a:<9.5f}{b:<8.5f}{abs(b - a):.5f}")

    print(f"Корень = {a:.5f}\nШагов всего: {step}\n")

def methodNewton(a):
    k = 0
    x_k1 = 0.0
    x_k = a

    print(f"{'N':<3}{'x_n':<9}{'x_n+1':<9}x_n1 - x_n")
    print(f"{k:<3}{x_k:<9.5f}{x_k1:<9.5f}{x_k1 - x_k:.5f}")

    while True:
        k += 1
        x_k1 = x_k - function(x_k) / derivativeFunction(x_k)
        print(f"{k:<3}{x_k:<9.5f}{x_k1:<9.5f}{x_k1 - x_k:.5f}")
        if abs(x_k1 - x_k) < EPSILON:
            break
        x_k = x_k1

    print(f"Корень = {x_k1:.5f}\nШагов всего: {k}\n")

def canonFunction(x):
    return math.sqrt(abs(3 * math.sin(x)))

def methodSimpleIterations(a):
    k = 0
    x_k1 = 0.0
    x_k = a

    print(f"{'N':<3}{'x_n':<9}{'x_n+1':<9}x_n1 - x_n")
    print(f"{k:<3}{x_k:<9.5f}{x_k1:<9.5f}{x_k1 - x_k:.5f}")

    while True:
        k += 1
        x_k1 = canonFunction(x_k)
        print(f"{k:<3}{x_k:<9.5f}{x_k1:<9.5f}{x_k1 - x_k:.5f}")
        if abs(x_k1 - x_k) <= EPSILON:
            break
        x_k = x_k1

    print(f"Корень = {x_k1:.5f}\nШагов всего: {k}\n")

print("Метод половинного деления:")
methodHalf(-2, 1)
methodHalf(1, 2)

print("\nМетод Ньютона:")
methodNewton(-0.5)
methodNewton(1)

print("\nМетод простых итераций:")
methodSimpleIterations(-0.5)
methodSimpleIterations(1)