#include<iostream>
#include<string>

using namespace std;

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


	cout<<"filename = "<<filename<<endl;
	cout<<"WordCount = "<<wordcount<<endl;
	return EXIT_SUCCESS;
}
