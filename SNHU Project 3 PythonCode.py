import re
import string


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

def DisplayOccurence():
    MyFile = open("DataInput.txt", "r")
    # Creates dictionary to store data from file in for loop.
    d = dict()
    #Use for loop to read each line in file
    for line in MyFile:
        #Use the strip() function to remove whitespace and new lines, also using split() function to separate words by a space
        line = line.strip()
        words = line.split(" ")
        #Another for loop for every word in line, will check if word is in dictionary, if word is in dictionary, it will increase the count of the word. Otherwise it will set the count to 1.
        for word in words:
            if word in d:
                d[word] = d[word] + 1
            else: 
                d[word] = 1
    print("\n\nOccurence of items purchased is: ")
    #For loop to print each item in the dictionary
    for key in list(d.keys()):
        print(key, ":", d[key])

    MyFile.close()

def SearchItem(v):
    MyFile = open("DataInput.txt", "r")
    #Reads the text file and sets it to a string variable
    data = MyFile.read()
    #Sets this string to be lower case
    data = data.lower()
    #Get the number of occurances of the word/string passed to this function (v).
    occurrences = data.count(v)
    return occurrences #return the number of occurences found and sends it back to C++

    MyFile.close()
    

def WriteToFile():
    MyFile1 = open("DataInput.txt", "r")
    # Creates dictionary to store data from file in for loop.
    d = dict()
    #Use for loop to read each line in file
    for line in MyFile1:
        #Use the strip() function to remove whitespace and new lines, also using split() function to separate words by a space
        line = line.strip()
        words = line.split(" ")
        #Another for loop for every word in line, will check if word is in dictionary, if word is in dictionary, it will increase the count of the word. Otherwise it will set the count to 1.
        for word in words:
            if word in d:
                d[word] = d[word] + 1
            else: 
                d[word] = 1
    
    #For loop to write each item in the dictionary to file in the format of "word number" with a space inbetween
    text = ""
    for key in list(d.keys()):
        text = text + key + " " + str(d[key]) + "\n"
    
    #print(text)
    MyFile2 = open("frequency.dat", "w+")
    MyFile2.write(text)
    MyFile1.close()
    MyFile2.close()
