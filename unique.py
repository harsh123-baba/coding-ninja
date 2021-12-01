import re
dict = {}


def uniqueWord(Word):
    if Word in dict:
        dict[words] += 1
 
    else:
        dict.update({words: 1})
 

s = input()


# string = "I like to swim and i like to travel abroad"
ListOfWords = re.split("[\W]+", string)

for words in ListOfWords:
    uniqueWord(words)

for elements in dict:
    if dict[elements] == 1:
        count+=1

print(count)