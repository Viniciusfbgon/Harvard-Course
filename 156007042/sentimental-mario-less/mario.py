def get_int(prompt):

    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input, Please input a positive integer")


heigth = get_int("Heigth: ")

while heigth < 1 or heigth > 8:
    print("Heigth must be between 1 and 8")
    heigth = get_int("Heigth: ")

for i in range(1, heigth + 1):
    print(" " * (heigth - i) + "#" * i)
