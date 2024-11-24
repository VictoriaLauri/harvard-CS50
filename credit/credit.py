def get_ccn():
    while True:
        try:
            card = int(input("Enter card number: "))
            if card > 0:
                return card
        except ValueError:
            pass

card = get_ccn()

def luhn_checksum(card):
    def digits_of(n):
        return[int(d) for d in str(n)]
    digits = digits_of(card)
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]
    checksum = 0
    checksum += sum(odd_digits)
    for d in even_digits:
        checksum += sum(digits_of(d*2))
    return checksum % 10

length = len(str(card))
first_digit = int(str(card)[:1])
first_2digits = int(str(card)[:2])

if luhn_checksum(card) == 0:
    if first_digit == 4 and (length == 13 or length == 16):
        print("VISA")
    elif length == 15 and (first_2digits == 34 or first_2digits == 37):
        print("AMEX")
    elif length == 16 and (first_2digits > 50 and first_2digits < 56):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
