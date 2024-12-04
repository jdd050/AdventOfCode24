import os
import re
from tkinter.filedialog import askopenfilename

# Get file name
input_file = askopenfilename()
while (input_file is None) or not (os.path.isfile(input_file)):
    input_file = askopenfilename()

# Placeholder lists
left_list = []
right_list = []

# Total distance between numbers
total_distance = 0

# Read the data from the file
with open(input_file, 'r') as f:
    for line in f.readlines():
        numbers = re.findall("\d+", line)
        left_list.append(int(numbers[0]))
        right_list.append(int(numbers[-1]))
    f.close()

# Sort the lists in ascending order
left_list.sort()
right_list.sort()

for i, j in zip(left_list, right_list):
    total_distance += abs(i-j)

print(total_distance)