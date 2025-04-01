file_path= "binary_bayes_filter_result01.txt"  ## length 45000
with open(file_path, 'r') as file:
    line = file.readline().strip()   # Read the line and strip any surrounding whitespace
    content = line.split()           # Split the line into values separated by spaces
print(len(content)) 

## cd scripts/mapping
## python binary_bayes_filter_result.py