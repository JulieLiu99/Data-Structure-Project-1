# Data-Structure-Project-1

This is a speller application termed myspeller, that can help a user lookup English words in a provided dictionary. This program is created using the elementary data structures (mostly arrays) and the Linux/FreeBSD C++ environment.

## Prerequisites

All the files including Makefile, myspeller.cpp, search.cpp, search.h, and dictionary files should be in the same directory
Sorted words in dictionary files, each word per line.

## Getting Started

This instruction will get you a copy of the project up and running on your local machine for development and testing purposes. 
./myspeller -d <dictionaryfilename> -l <numberOfWordsSearch>

```
./myspeller -d Dictionary141words.txt -l 2 //user input
filename = Dictionary141words.txt
WordCount = 2
Dictionary size is 141
Which word are you looking for? Type 'exit' to stop : 
college //user input
word found
7 word comparisons carried out
Which word are you looking for? Type 'exit' to stop : 
co* //user input
word found
10 word comparisons carried out
college
company
Which word are you looking for? Type 'exit' to stop : 
col?ege
college
word found
8 word comparisons carried out
Which word are you looking for? Type 'exit' to stop : 
exit  //user input

```

## Algorithmic Analysis

In the Main.() function, reading from the dictionary file and storing the data into an array has O(n) running time.
In the Seaching class, binary search has O(n logn) running time. binaryWordStarSearch and binaryWordQSearch functions have additional search of linear complexity on part of the dictionary array, which does not affect the overall complexity.


## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Julie Liu** 
* **Romeno Wenogk Fernando** 

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.


## Acknowledgments

* Under guidance of Professor Stavros Kolliopoulos and instructor Khalid Mengal in New York University Abu Dhabi Computer Science Department

