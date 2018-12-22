#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <cstdlib>

using namespace std;

class Save{

	std::mutex mtxWriter;
	ofstream myFile;
 	char *outputFile;
	
public:
	//constructor and destructor for class in charge on store data 
	Save(char *_outputFile);
	~Save();
	//store process 
	/*
	 * a is vector with the data to store
	 * size is the size of the data to store
	*/
	void savingControl(int *array, int size);

};

#endif
