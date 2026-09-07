a=int(input("Enter a number: "))
print(a)
b=int(input("Enter another number: "))
print(b)
operation=input("Enter an operation (+, -, *, /): ")

match operation:
    case '+':
        result = a + b
    case '-':
        result = a - b
    case '*':
        result = a * b
    case '/':
        result = a / b
print("Result:", result)

print("bitwise operations:")
c = a & b
print("AND:", c)
d = a | b
print("OR:", d)
e = a ^ b
print("XOR:", e)

print("Shift operations:")
f = a << 1
print("Left shift:", f)
g = a >> 1
print("Right shift:", g)


