# print('Hello from MFA Oil !!!')
# initial = 0
# counter = 0
# for iterator in [9, 41, 12, 3, 74, 15]:
#     counter += 1
#     initial += iterator
#     print (counter, iterator, initial)
#     if counter <= 1 :
#         smallest = iterator
#
#     if smallest > iterator :
#         smallest = iterator
#
# print('After end of loop: smallest = ', smallest, ' and average = ', initial / counter)
#
# data = "Hello, my student email is a.azdiallo@ccis.edu and I love what I study there."
# position = data.find('@')
# schoolend = data.find(' ', position)
# school = data[position+1 : schoolend]
# print(school, schoolend)
#
# reading a file from a directory
# print('Reading from a directory')
# # fhand = open('inputFile.txt')
# request = input('Please enter the file you want to read: ')
# try:
#     fhand = open(request)
# except:
#     print('file cannot be opened')
#     quit()
#
# numberLines = 0
# myWords = dict() #creating an empty dictionary
# for file in fhand: #looping through every line of the file 'fhand'
#     file = file.strip() # split the file into lines
#     wordsPerLine = file.split() # split every line into words
#
#     #Looping through every line and counting repetition of words
#     for word in wordsPerLine : # filling up the dictionary
#         myWords[word] = myWords.get(word, 0)+1 # count repetition of words
#
# #print(myWords.items(), myWords.values()) # printing the dictionary
# for key, value in myWords.items() :
#     print(key, value)
    #print(file)
    #numberLines = numberLines+1
#print('Number of lines in the file is:', numberLines)
#
# # Checking that strings are unmutable
# print('Checking that strings are unmutable')
# banana = 'Banana'
# banana[0] = 'b'
# print(banana)

#using directories in python
# mydict = dict() # dictionary name
# listOfElements = ['Banana', 'Mango', 'Orange', 'Pineapple',
#                   'Banana', 'Watermelon', 'Sugar', 'Mango',
#                   'Lime', 'Orange', 'Pineapple', 'Mango'
#                  ]
# #Defining a loop that loops through the 'listOfElements'
# for element in listOfElements :
#     if element in mydict : # if element already in list, add 1 as a repetition
#         mydict[element] = mydict[element] + 1
#
#     else : # create element if doesn't exist
#         mydict[element] = 1
#
# #print dictionary
# print (sorted(mydict.items()))


# HTTP Request in python using sockets
# import socket
# mySocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# mySocket.connect(('data.pr4e.org', 80))
# cmd = 'GET http://data.pr4e.org/romeo.txt HTTP/1.0\r\n\r\n'.encode()
# mySocket.send(cmd)
#
# while True:
#     data = mySocket.recv(512)
#     if (len(data) < 1):
#         break
#     print(data.decode())
# mySocket.close()


# the use urllib in python "urlib does the python sockets"
# import urllib.request, urllib.parse, urllib.error
# fhand = urllib.request.urlopen('http://data.pr4e.org/romeo.txt')
# for line in fhand:
#     print(line.decode().strip())


# import urllib.request, urllib.parse, urllib.error
# from bs4 import BeautifulSoup
# import ssl
#
# # Ignore ssl certificate errors
# ctx = ssl.create_default_context()
# ctx.check_hostname = False
# ctx.verify_mode = ssl.CERT_NONE
#
# url = input()

# using xml in python
import xml.etree.ElementTree as ET
data = '''
        <person>
            <name> Chuck </name>
            <phone type='intl'> +734 303 4456 </phone>
            <email hide='yes' />
        </person>
        '''
tree = ET.fromstring(data)
print('Name: ', tree.find('name').text)
print('Attr: ', tree.find('email').get('hide'))
