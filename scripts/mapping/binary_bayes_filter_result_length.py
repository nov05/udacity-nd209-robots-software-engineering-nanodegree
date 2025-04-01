## length 45000
# file_path= "D:/github/udacity-nd209-robots-software-engineering-nanodegree/scripts/mapping/binary_bayes_filter_01_result.txt"  
file_path= "D:/github/udacity-nd209-robots-software-engineering-nanodegree/scripts/mapping/binary_bayes_filter_02_result.txt"
with open(file_path, 'r') as file:
    line = file.readline().strip()   # Read the line and strip any surrounding whitespace
    content = line.split()           # Split the line into values separated by spaces
print(len(content)) 

## cd scripts/mapping
## python binary_bayes_filter_result.py