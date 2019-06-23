print('Hello from MFA Oil !!!')
initial = 0
counter = 0
for iterator in [9, 41, 12, 3, 74, 15]:
    counter += 1
    initial += iterator
    print (counter, iterator, initial)
    if counter <= 1 :
        smallest = iterator

    if smallest > iterator :
        smallest = iterator

print('After end of loop: smallest = ', smallest, ' and average = ', initial / counter)

data = "Hello, my student email is a.azdiallo@ccis.edu and I love what I study there."
position = data.find('@')
schoolend = data.find(' ', position)
school = data[position+1 : schoolend]
print(school, schoolend)

# reading a file from a directory
print('Reading from a directory')
# fhand = open('inputFile.txt')
request = input('Please enter the file you want to read: ')
try:
    fhand = open(request)
except:
    print('file cannot be opened')
    quit()
numberLines = 0
for file in fhand:
    file = file.strip()
    print(file)
    numberLines = numberLines+1

print('Number of lines in the file is:', numberLines)
