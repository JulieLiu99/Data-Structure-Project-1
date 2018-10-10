#ifndef SEARCH_H
#define SEARCH_H

#include<iostream>
#include<string>
#include <fstream>
#include <vector>
using namespace std;


class dSearch {
	public:
		void binaryWordSearch(vector<string> v,int numWords,string query);
		void binaryWordStarSearch(vector<string> v,int numWords,string query, int wordcount);
		void binaryWordQSearch(vector<string> v,int numWords,int qMarkPos, string query, int wordcount);

};

#endif
