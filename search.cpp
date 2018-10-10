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
    int comparison = 0; //The number of word comparisons carried out
    
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
	int first = 0;
	//int starPos=value.size()-1;
	string newValue=value.substr(0,value.length()-1);
	//cout<< "Looking for " << newValue <<endl;
    int last = n-1;
    int middle;
    int position;
    bool found = false;
    int comparison = 0;
    
    while (!found && first <= last) {
        middle = (first + last)/2;
        if (A[middle].find(newValue) == 0){ //toSearch.find('*') != std::string::npos
            found = true;
            position = middle;
        } else if (A[middle] > newValue) last = middle - 1;
        else first = middle + 1;
        comparison += 1;
    }
    int currentWord=position;
    int startIndex=position+1;
    while(A[startIndex-1].find(newValue) == 0) {
    	startIndex=startIndex-1;
    	comparison += 1;
    }
    int endIndex=position;
        while(A[endIndex+1].find(newValue) == 0) {
    	endIndex=endIndex+1;
    	comparison += 1;
    }

    if(!found) {
    	cout<< "word not found" << endl;
    } else {
    	cout << "word found" << endl;
        cout << comparison << " word comparisons carried out" << endl;
        //cout << "end: " << endIndex << "... start: " << startIndex << endl;
        if((endIndex-startIndex)>0) {
        for(int j=0;j<(endIndex+1-startIndex);j++) {
        	if(j<wordcount) {
        	cout << A[startIndex+j] << endl;
        }
        }
    } else {
    	cout << A[position] << endl;
    }
    }
}

void dSearch::binaryWordQSearch(vector<string> A, int n, int qMarkPos, string value, int wordcount) {

	string frontStringPart = value.substr(0,qMarkPos);
	string backStringPart = value.substr(qMarkPos+1,value.size()-1);
	int first = 0;
    int last = n-1;
    int middle;
    int position;
    bool found = false;
    int comparison = 0;
    
    while (!found && first <= last) {
        middle = (first + last)/2;
        if (A[middle].find(frontStringPart) == 0){ 
            found = true;
            position = middle;
        } else if (A[middle] > frontStringPart) last = middle - 1;
        else first = middle + 1;
        comparison += 1;
    }

    int currentWord=position;
    int startIndex=position+1;
    while(A[startIndex-1].find(frontStringPart) == 0) {
    	startIndex=startIndex-1;
    }
    int endIndex=position;
        while(A[endIndex+1].find(frontStringPart) == 0) {
    	endIndex=endIndex+1;
    }
 	int first2= startIndex;
 	int last2= endIndex;
 	
 	bool foundFinal = false;
 	int finalPosition;
 	string curBackStringPart;
 	int wordCounter=0;
 	
 	for(int j=0;j<(last2+1-first2);j++) {
 		comparison+=1;
 		if(A[first2+j].size()==value.size()) {
 		//cout << "CURRENT WORD IN LOOP---> " << A[first2+j] << endl;
 		curBackStringPart = A[first2+j].substr(qMarkPos+1,A[first2+j].size()-1);
 		//cout << "curBackStringPart: " << curBackStringPart << endl;
 		if((curBackStringPart==backStringPart)) {
 			
 			foundFinal=true;
 			finalPosition=first2+j;
 			//cout << "wordCounter: " << wordCounter << " - wordcount: " << wordcount << endl;
 			if((wordCounter<wordcount)) {
 			cout << A[first2+j] << endl;
 		}
 		wordCounter+=1;
 		}
 	}
 }
 	//cout << "first2: " <<first2 << " last2: " << last2 << "backStringPart: " << backStringPart << "curBackStringPart: " << curBackStringPart << " Looking in: " << A[position] << endl;
    if(!foundFinal) {
    	cout<< "word not found" << endl;
    } else {
    	cout << "word found" << endl;
        cout << comparison << " word comparisons carried out" << endl;
        //cout << "end: " << endIndex << "... start: " << startIndex << endl;
     	/*for(int j=0;j<(last2+1-first2);j++) {
    	cout << A[first2+j] << endl;
    }*/
    
    }
}
