from sys import argv, exit
import csv

# create a main function

def main():
    # ensure user supplies correct number of arguments

    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # read the csv

    with open(argv[1]) as csv_file:

        # get read the dna summary data into an object with the name and STR counts
        dna_summary = csv.reader(csv_file)
        # remove the name part from the data
        STR_sequence_counts = next(dna_summary)[1:]

    # read the txt file

        with open(argv[2]) as text_file:
            # read all the data in the text file as a string named STR_pattern
            STR_pattern = text_file.read()
            analysed_data = [maximum_times_a_pattern_repeats(STR_pattern, seq) for seq in STR_sequence_counts]

        check_match(dna_summary, analysed_data)


# check maximum number of time a particular substring is repeated in the data read from the text file
# identify a pattern from the last index of the STR_pattern and increment the pattern_count object as you identify repeated patterns

def maximum_times_a_pattern_repeats(STR_pattern, sub):
    pattern_count = [0] * len(STR_pattern)
    for i in range(len(STR_pattern) - len(sub), -1, -1):
        if STR_pattern[i: i + len(sub)] == sub:
            if i + len(sub) > len(STR_pattern) - 1:
                pattern_count[i] = 1
            else:
                pattern_count[i] = 1 + pattern_count[i + len(sub)]

    return max(pattern_count)

# analyzed_data object contains data similar to the one extracted from the csv. Compare both and print the name of the person that matches the dna

def check_match(dna_summary, analysed_data):
    for data in dna_summary:
        person_name = data[0]
        STR_counts = [int(count) for count in data[1:]]
        if STR_counts == analysed_data:
            print(person_name)
            return
    print("No Match")


if __name__ == "__main__":
    main()
