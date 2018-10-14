#include "search.h"
#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include<string.h>
using namespace std;

void dSearch::binaryWordSearch(vector<string> A, int n, string value) {

    int first = 0; // The first element in the vector A
    int last = n-1; // The last element in the vector A
    int middle;
    bool found = false; //Boolean for whether a match for the word is found
    int comparison = 0; //The number of word comparisons carried out for the current search

    while (!found && first <= last) { 
        middle = (first + last)/2; //The index halfway between the first and last variables
        if (A[middle] == value){ //If the middle value itself is the value we are searching for, set found to true
            found = true;
        } else if (A[middle] > value){ // If the middle value is higher than the search value alphabetically, make the last index the middle-1 index
            last = middle - 1;
            }
        else {
            first = middle + 1; // If the middle value is lower than the search value alphabetically, make the first index the middle + 1 index
        }
        comparison += 1; // increase the comparison by 1 every time the loop is run to update the number of word comparisons
    }
    
    if(found == true){ //If found, print out a success notice and the number of comparisons carried out
        cout << "word found" << endl;
        cout << comparison << " word comparisons carried out" << endl;
        } 
        else cout<< "word not found" << endl; // If not found, a failure to find query notice.
        
}

void dSearch::binaryWordStarSearch(vector<string> A, int n, string value, int wordcount) {
    int first = 0; // The first element in the vector A
    string newValue=value.substr(0,value.length()-1); //The search query value without the * mark which is the last character
    int last = n-1; // The last element in the vector A
    int middle;
    int position; //The position where the value is found in the vector A
    bool found = false; //Boolean for whether a match for the word is found
    int comparison = 0; //The number of word comparisons carried out for the current search
    int numFound = 0;
    while (!found && first <= last) {
        middle = (first + last)/2; //The index halfway between the first and last variables
        if (A[middle].find(newValue) == 0){ //If the middle value STARTS with the newValue substring
            found = true;
            position = middle; //Set the position to be the index of the middle
        } else if (A[middle] > newValue) last = middle - 1; // If the middle value is higher than the search value alphabetically, make the last index the middle-1 index
        else first = middle + 1; // If the middle value is lower than the search value alphabetically, make the first index the middle + 1 index
        comparison += 1; // Increase the comparison by 1 every time the loop is run to update the number of word comparisons
    }
    int startIndex=position+1; //Index to start the search for matching values to the left of the current position index
    while(A[startIndex-1].find(newValue) == 0) { //While the previous value to the current startIndex STARTS with newValue substring
        startIndex=startIndex-1; //Reduce the startIndex by one 
        comparison += 1; // Increase the comparison by 1 every time the loop is run to update the number of word comparisons
    }
    int endIndex=position; //Index to start the search for matching values to the right of the current position index
    while(A[endIndex+1].find(newValue) == 0) { //While the next value to the current endIndex STARTS with newValue substring
        endIndex=endIndex+1; //Increase the endIndex by one 
        comparison += 1; // Increase the comparison by 1 every time the loop is run to update the number of word comparisons
    }

    if(!found) {
        cout<< "word not found" << endl;
    } else {
        cout << "word found" << endl;
        cout << comparison << " word comparisons carried out" << endl;
        if((endIndex-startIndex)>0) { //If there is more than one matched word in the search ( endIndex!=startIndex would work too )
        for(int j=0;j<(endIndex+1-startIndex);j++) { //Run loop from startIndex to endIndex
            if(j<wordcount) { //As long as j is less than the wordcount specified by the user
            cout << A[startIndex+j] << endl; //Print the word
        }
        numFound+=1;
        }
    } else { //If only one word is matched simply print it out
        cout << A[position] << endl;
    }
    cout << numFound << " total matches found for " << value <<endl;
    }
}

void dSearch::binaryWordQSearch(vector<string> A, int n, int qMarkPos, string value, int wordcount) {

    string frontStringPart = value.substr(0,qMarkPos); //The substring of the search query from the first character to the ? mark character excluding the question mark
    string backStringPart = value.substr(qMarkPos+1,value.size()-1); //The substring of the search query from the ? mark character to the last character
    int first = 0; // The first element in the vector A
    int last = n-1; // The last element in the vector A
    int middle;
    int position;
    bool found = false; //Boolean for whether a match for the frontStringPart to be found in the start of any word in the dictionary
    int comparison = 0; //The number of word comparisons carried out for the current search
    int numFound = 0;
    while (!found && first <= last) {
        middle = (first + last)/2; //The index halfway between the first and last variables
        if (A[middle].find(frontStringPart) == 0){ //If the middle value itself starts with the frontStringPart
            found = true;
            position = middle;
        } else if (A[middle] > frontStringPart) last = middle - 1; // If the middle value is higher than the search value alphabetically, make the last index the middle-1 index
        else first = middle + 1; // If the middle value is lower than the search value alphabetically, make the first index the middle + 1 index
        comparison += 1; // Increase the comparison by 1 every time the loop is run to update the number of word comparisons
    }

    int startIndex=position+1; //Index to start the search for matching values to the left of the current position index
    while(A[startIndex-1].find(frontStringPart) == 0) { //While the previous value to the current startIndex STARTS with frontStringPart 
        startIndex=startIndex-1; //Reduce the startIndex by one 
    }
    int endIndex=position; //Index to start the search for matching values to the right of the current position index
        while(A[endIndex+1].find(frontStringPart) == 0) { //While the next value to the current endIndex STARTS with frontStringPart
        endIndex=endIndex+1; //Increase the endIndex by one 
    }
    int first2= startIndex; //The starting index for the range of words that start with the substring before the ? mark denoted by the string frontStringPart
    int last2= endIndex; //The last index for the range of words that start with the substring before the ? mark denoted by the string frontStringPart
    
    bool foundFinal = false; //Boolean for whether word(s) are matched exactly to the search query 
    int finalPosition; 
    string curBackStringPart; 
    int wordCounter=0; //The number of words matched which will be limit what is printed out by the wordcount preferred by the user
    
    for(int j=0;j<(last2+1-first2);j++) {
        comparison+=1; // Increase the comparison by 1 every time the loop is run to update the number of word comparisons
        if(A[first2+j].size()==value.size()) { //If the current word in loop and the search query have the same legnth
        curBackStringPart = A[first2+j].substr(qMarkPos+1,A[first2+j].size()-1); //The substring formed from the current word in the loop from the index of the ? mark in the query string to to last character
        if((curBackStringPart==backStringPart)) { //If the 'virtual' substring formed above matches the backStringPart, then we know that this is a match as the substring before and after the ? mark match  
            numFound+=1;
            foundFinal=true; 
            finalPosition=first2+j;
            if((wordCounter<wordcount)) { //Limit words printed out to user specified number, wordcount
            cout << A[first2+j] << endl; //Print matched word
        }
        wordCounter+=1; 
        }
    }
 }
    if(!foundFinal) {
        cout<< "word not found" << endl;
    } else {
        cout << "word found" << endl;
        cout << comparison << " word comparisons carried out" << endl;
        cout << numFound << " total matches found for " << value <<endl;
    }
}
