#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <iostream>
#include <string.h>
#include <thread>
#include <mutex>
#include <fstream>
#include "Save.h"

using namespace std;

class SortAlgorithms{

private:
	char *inputFileName;
 	char *outputFileName;
	char *algorithmSelected; 
	int numberThreads;
	Save mySave;
	std::mutex mtxReader;
	ifstream myInputFile;
	
public:
	//Constructor and destructor
	SortAlgorithms(char *_inputFileName, char *_outputFileName, char *_algorithmSelected, int _numberThreads);
	~SortAlgorithms();
	
	//checking if user write the aavalible algorithms right
	//return true if user write quicksort or merge as 4th argument in console
	// false in other case
	bool rightAlgorithmSelected();

	//Function that consumes line from inputFile
	/*
	 * IsData is a boolean that will tell me if there are data from the inputFile to process
	*/
	string readLine(bool &isData);

	//main process, start preparing the vector
	//sort depends of the sort method selected, and then print process using a object of Save class
	void sorting(string line);
	
	//merge and mergeSort are method for the merge sort Algorithm
	//merge is a 
	/*
	 *	a is pointer for the array to sort
	 *	low is first position of the array partition
	 *	high is last position of the array partition
	 *	mid is the value divides the size array by 2
	 */
	void merge(int *a,int low, int high, int mid);

	//mergeSort is the main fuction for this sort algorithm
	/*
	 *	a is an array to sort
	 *	low is first position always 0
	 *	high is size of array
	 */
	void mergeSort(int *a, int low, int high);

	//insertion sort algorithm
	/*
	 *	vector is array to sort
	 *	size is size of array
	*/
	void insertion(int *vector, int size);

	//Bubble sort algorithm
	/*
	 *	vector is array to sort
	 *	size is size of array
	*/	
	void bubble(int *vector, int size);
	
	//For quicksort we need a recursive fuction called partition
	//quicksort is main fuction of this sort algorithm
	//This function takes last element as pivot, places 
   	//the pivot element at its correct position in sorted 
    //array, and places all smaller (smaller than pivot) 
   	//to left of pivot and all greater elements to right 
   	//of pivot 
	/*
	 * vector is the array
	 * low is first position
	 * high is size of array -1
	*/
	void quickSort(int *vector, int low, int high);

	/*
	 * vector is the array
	 * low is first position
	 * high is size of array - 1
	*/
	int partition(int *vector, int low, int high);

	//For Heapsort we need 2 methods
	// main function to do heap sort 
	/*
	 * vector is the array to sort
	 * size is size of array
	 */
	void heapSort(int *vector, int size);

	// To heapify a subtree rooted with node i which is 
	// an index in vector[]. n is size of heap
	/*
	 * vector 
	 * n 
	 * i 
	 */ 
	void heapify(int *vector, int n, int i);

};

#endif
