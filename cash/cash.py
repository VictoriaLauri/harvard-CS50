def get_amount():
    while True:
        try:
            amount = float(input("What is the amount? "))
            if amount > 0:
                return amount
        except ValueError:
            pass

a = get_amount()
q = int(a / 0.25)
a = round((a - (q * 0.25)), ndigits=2)
d = int(a / 0.10)
a = round((a - (d * 0.10)), ndigits=2)
n = int(a / 0.05)
a = round((a - (n * 0.05)), ndigits=2)
p = int(a / 0.01)

coins = q + d + n + p
print(coins)

