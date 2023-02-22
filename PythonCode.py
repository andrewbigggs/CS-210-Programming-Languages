import re
import string


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

# Creates frequency.dat file containing name and frequency of every item in InputFile.txt 
def CountItems():

    ItemCountDict = {}
    itemsFile = open ("InputFile.txt")
    for line in itemsFile:
        if line in ItemCountDict:
            ItemCountDict[line] += 1
        else:
            ItemCountDict[line] = 1

    itemsFile.close()
    outFile = open('frequency.dat', 'w')
    keysList = list(ItemCountDict.keys())
    for i in keysList:
        outFile.write(keysList[i])
        outFile.write(' ')
        outFile.write(ItemCountDict[i])
        outFile.write('\n')

    outFile.close()

# Prints frequency of all items
def PrintItemFrequencies():

    itemsFile = open ("frequency.dat")
    for line in itemsFile:
        print(line, end="")
    
    itemsFile.close()

# Prints frequency of a given item, entered in the C++ code
def GetSingleItemFrequency(item_name):     
    itemsFile = open ("frequency.dat")
    for line in itemsFile:
        if item_name in line:
            print(line)
            break
    
    itemsFile.close()

    return 0
