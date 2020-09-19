# TODO
from cs50 import SQL
from sys import argv, exit
import csv

def main():
    # ensure user parses the csv as an argument
    if len(argv) != 2 :
        print("Error: Please pass a csv file as an argument")
        exit(1)

    # create a database instance
    db = SQL("sqlite:///students.db")

    # open the file
    with open(argv[1]) as csv_file:
        house_data = csv.DictReader(csv_file)
        for row in house_data:
            # call the split_name function on the name columns. You will basically loop through every row
            names = split_name(row["name"])
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                    names[0], names[1], names[2], row["house"], row["birth"]
            )


# handle a missing middle name
def split_name(fullName):
    names = fullName.split()
    # the split_name function will convert the name into a list and put None if the middle name is missing
    return names if len(names) >= 3 else [ names[0], None, names[1]]

if __name__ == "__main__":
    main()

