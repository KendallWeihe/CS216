Author: Kendall Weihe
Program: Project #3 CS216 Fall 2016

General program description:
  This program reads in a text file full of keys and weights.
  Then the user is able to enter a prefix and the program will find all the keys with the matching prefix, and print them in descending order based on weight values.
  Keys are strings that are terminated by a new line. Weights are 64-bit integer values.
  The program uses bubble sort (O(n^2)) to sort all the keys, and then a form of binary search to find all the keys that match the prefix.
    The binary search works as follows:
      - finds an endpoint in the binary search with matching prefix
      - scans in both directions until the prefix no longer matches the key

NOTE:
  From the text files I tested with, there was always a tab "\t" in between the weight and the key.
  So then, I used the line of code `temp_key = temp_key.substr(1, temp_key.length());` to get rid of the tab.
  IF YOUR TEXT FILE DOES NOT USE TABS IN BETWEEN THE WEIGHT AND KEY, THEN THE FIRST CHAR OF EVERY KEY WILL BE CUT OFF.

Algorithms used:
  - bubble sort
    - O(n^2)
    - I could've used mergesort, or even quicksort to improve sorting time to the order O(nlogn)
  - binary search
    - O(logn)
    - see the General program description for information on how the binary search algorithm was used to find all keys with matching prefixes


Files turning in:
  - makefile
  - main.cpp
  - autocomplete.h
  - autocomplete.cpp
  - term.h
  - term.cpp
  - README.txt
