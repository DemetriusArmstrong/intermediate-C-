# intermediate-C-
Class Projects
Assignment 4 - Spell Checker


The purpose of this assignment is to give you practice using dynamic memory allocation, c-string functions, sorting, and searching.  You will write a spell checking program and test it.
Program Steps

Read a dictionary word file into an array of c-strings.   You will need to dynamically allocate memory for each word in the dictionary.  The word file contains 23,907 words.
Sort the dictionary.
Reading in a test file, one line at a time.  Parse the line to get each individual word in the line.  Search the dictionary word list (the array of c-strings) for each word in the line.  If the word is not found, print a message.  The search should be performed as a binary search.
Program Requirements

Use these files for your dictionary and the final spell check test.
Use an array of char pointers store your word file.  Allocate memory dynamically to store each word in a char array.  Store the dictionary words in lower case.
Use a temporary char array to hold each line in the test file.  “Parse” each line into individual words for spell checking.  Note, you may not use the stringstream classes for this assignment.
Spell checking must ignore case.  For example, “Hello” is the same as “hello”.
Program Output

Your output should looks quite similar to this:

Misspelled word, struggled on  line 10
Misspelled word, consecrated on  line 11
Misspelled word, unfinished on  line 13
Misspelled word, nobly on  line 14
Misspelled word, advanced on  line 14
...

Program Hints

Follow the program steps.  Write only one part of the program at a time.  Test each part before you proceed to the next step.  Do not continue if one part has a problem.  Ask for help with a step, if you can't get it to work.  Remember to allow plenty of time for this assignment.
Use a small dictionary and a small test file initially as you are developing your code. 
For your dictionary sort, you can "swap pointers" since you are working with an array of pointers.
Use strtok() for the parsing of each line.
Xcode users: There is a \r at the end of each line in the test file. You can suppress it by adding "\r" as a delimiter for strtok().
Your program should find between 8 and 12 misspelled words.
