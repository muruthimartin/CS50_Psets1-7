from cs50 import get_float

while True:
    # prompt the user to enter chage owed dollars. User must enter values < 0
    dollars = get_float("Change owed: ")
    if dollars >= 0:
        break
# convert dollars to cents

cents = int((dollars * 100))

coins = 0
for coin in [25, 10, 5, 1]:
    coins += cents // coin
    cents %= coin

print(coins)