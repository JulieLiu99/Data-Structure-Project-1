#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include "search.h"

using namespace std;


int main(int count, char * args[])
{
	string filename="";
	int wordcount=-1;
    dSearch search;
    ifstream infile;
    int dicSize = 0;
    vector <string> A;
    string toSearch;
    string st;

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

	cout<<"filename = "<<filename<<endl;
	cout<<"WordCount = "<<wordcount<<endl;
    
    // read from the dictionary file and store the entries into an array 
    infile.open(filename);
    string str;
	while (getline(infile, str))
	{
		if(str.size() > 0)
		    st = str.substr(0, str.size()-1);
			A.push_back(st);
			dicSize += 1;
	}
	cout << "Dictionary size is " << dicSize << endl;
    infile.close();
    
    // continuously take a user-provided input  
    while (true){
    
        cout << "Which word are you looking for? Type 'exit' to stop : " << endl;
        cin >> toSearch; 
        int qMarkPosition = toSearch.find("?");
        
        if (toSearch == "exit") break;
        
        if (toSearch.find('*') != std::string::npos) 
        	search.binaryWordStarSearch(A, dicSize, toSearch, wordcount);
        else if(qMarkPosition != std::string::npos) 
        	search.binaryWordQSearch(A, dicSize,qMarkPosition, toSearch, wordcount);
        else
            search.binaryWordSearch(A, dicSize, toSearch);
    }
	return EXIT_SUCCESS;

}
