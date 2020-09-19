# TODO
from cs50 import SQL
from sys import argv, exit


def main():
    # ensure user parses an argument when calling the database
    if len(argv) != 2 :
        print("Error: Please enter a correct number of arguments")
        exit(1)

    # create a database instance

    db = SQL("sqlite:///students.db")

    querried_house = argv[1]

    results = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", querried_house)

    for person in results:
        first, middle, last, birth = person["first"], person["middle"], person["last"], person["birth"]

        print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")

if __name__ == "__main__":
    main()