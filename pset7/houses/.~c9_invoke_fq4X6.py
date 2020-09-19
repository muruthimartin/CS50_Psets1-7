# TODO
from cs50 import SQL
from sys import argv, exit
# ensure user parses the csv as an argument
if len(argv) != 2 :
    print("Error: Please pass a csv file as an argument")
    exit(1)
    
# create a database instance 
db = SQL("sqlite:///students.db")

# open the file
with open(argv[1] as csv_file):
    

