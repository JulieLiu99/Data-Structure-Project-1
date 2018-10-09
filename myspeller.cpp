#include<iostream>
#include<string>
#include <fstream>
//#include "search.h"

using namespace std;


//START STUFF THAT HAS TO BE IN SEARCH.CPP
class dSearch {
	public:
		void binaryWordSearch(string a[],int numWords,string query);
		void binaryWordStarSearch(string a[],int numWords,string query);
		void binaryWordQuestionSearch(string a[],int numWords,int qMarkPos, string query);
};

void dSearch::binaryWordSearch(string A[], int n, string value) {
    int first = 0;
    int last = n-1;
    int middle;
    int position;
    bool found = false;
    int comparison = 0;
    
    while (!found && first <= last) {
        middle = (first + last)/2;
        if (A[middle] == value){
            found = true;
            position = middle;
        } else if (A[middle] > value) last = middle - 1;
        else first = middle + 1;
        comparison += 1;
    }
    
    if(found == true){
        cout << "word found" << endl;
        cout << comparison << " word comparison carried out" << endl;
        } else cout<< "word not found" << endl;

}

void dSearch::binaryWordStarSearch(string A[], int n, string value) {
	int first = 0;
	//int starPos=value.size()-1;
	string newValue=value.substr(0,value.length()-1);
	cout<< "Looking for " << newValue <<endl;
    int last = n-1;
    int middle;
    int position;
    bool found = false;
    int comparison = 0;
    while (!found && first <= last) {
        middle = (first + last)/2;
        if (A[middle].find(newValue) != std::string::npos){ //toSearch.find('*') != std::string::npos
            found = true;
            position = middle;
        } else if (A[middle] > newValue) last = middle - 1;
        else first = middle + 1;
        comparison += 1;
    }
    int currentWord=position;
    int startIndex=position+1;
    while(A[startIndex-1].find(newValue) != std::string::npos) {
    	startIndex=startIndex-1;
    }
    int endIndex=position-1;
        while(A[endIndex+1].find(newValue) != std::string::npos) {
    	endIndex=endIndex+1;
    }

    if(!found) {
    	cout<< "word not found" << endl;
    } else {
    	cout << "word found" << endl;
        cout << comparison << " word comparison carried out" << endl;
        cout << "end: " << endIndex << "... start: " << startIndex << endl;
        if((endIndex-startIndex)>0) {
        for(int j=0;j<(endIndex-startIndex);j++) {
        	cout << A[startIndex+j] << endl;
        }
    } else {
    	cout << A[position] << endl;
    }
    }


}
//END STUFF TO GO TO SEARCH.CPP


int main(int count, char * args[])
{
	string filename="";
	int wordcount=-1;


	for(int i=1; i<count; i++)
	{
		if((string(args[i]) == "-d") && i+1 < count)
			filename=args[i+1];
		else if ((string(args[i])=="-l") && i+1 < count)
			wordcount=atoi(args[i+1]);
	}

	if(filename=="" || wordcount == -1)
	{
		cout<<"Usage ./myspeller -d <dictionaryfilename> -l <numberOfWordsSearch>"<<endl;
		return -1;
	}

    dSearch search;
    //search.binaryWordSearch();

	cout<<"filename = "<<filename<<endl;
	cout<<"WordCount = "<<wordcount<<endl;

    ifstream infile;
    int dicSize = 141; //atoi(wordcount)
    string A[dicSize];
    string toSearch;
    int position;
    int comparison;
    
    // read from the dictionary file and store the entries into an array 
    infile.open(filename);
    for (int i = 0; i < dicSize; i++){
        infile >> A[i];
    };
    infile.close();
    
    // continuously take a user-provided input  
    while (true){
        cout << "Which word are you looking for? Type 'exit' to stop : " << endl;
        cin >> toSearch; 
        int qMarkPosition = toSearch.find("?");

        if (toSearch == "exit") break;
        if (toSearch.find('*') != std::string::npos) {
        	search.binaryWordStarSearch(A, dicSize, toSearch);
        } else if(toSearch.find('?') != std::string::npos) {
        	cout<< "HAS ?" <<endl;
        }
        else{
        search.binaryWordSearch(A, dicSize, toSearch);
    }
    }

	return EXIT_SUCCESS;
	// ./a.out -d Dictionary141words.txt -l 141
}
