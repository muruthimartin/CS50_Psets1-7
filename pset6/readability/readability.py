from cs50 import get_string

# get plaintext from user

text = get_string("Plain text: ")

letters = sentences = words = 0

# loop through the plain text and increment by 1 : letters if character is part of alphabet, words when you get a space and sentence
# if you get fullstop, exclamation mark or question mark

for char in text:
    if char.isalpha():
        letters += 1

    if char.isspace():
        words += 1

    if char in ['?', '.', '!']:
        sentences += 1

words += 1

L = (letters * 100.0) / words
S = (sentences * 100.0) / words

# apply the grading formula
grading = int((0.0588 * L - 0.296 * S - 15.8) + 0.5)

if grading < 1:
    print("Before Grade 1")

elif grading >= 16:
    print("Grade 16+")

else:
    print(f"Grade {grading}")
