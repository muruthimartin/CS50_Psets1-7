from cs50 import get_int

# there's no do while loop in python so we use while True condition

while True:
    # make sure the input is between 1 an 8. Prompt user continuously until they give correct input
    height = get_int("Enter pyramid's height: ")

    if 1 <= height <= 8:

        break

# print spaces before the # symbols

for pyramid_row in range(1, height + 1):

    print(' ' * (height - pyramid_row) + '#' * pyramid_row + ' ' * 2 + '#' * pyramid_row)