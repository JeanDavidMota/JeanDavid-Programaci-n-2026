print("ingrese el primer numero: ")
a = float(input())
print("ingrese el segundo numero: ")
b = float(input())

if a > b:
    print(a, "es mayor que", b)
elif a < b:
    print(a, "es menor que", b)
else:
    print(a, "es igual a", b)