from cs50 import get_int

def get_height():
    while True:
        try:
            h = int(input("height: "))
            if h > 0 and h < 9:
                return h
        except ValueError:
             pass


h = get_height()

for times in range(1, h+1):
        print(" "*(h-times) + "#"*times + "  " + "#"*times)







