#include "SortAlgorithms.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

SortAlgorithms::SortAlgorithms(char *_inputFile, char *_outputFile, char *_algorithmSelected, int _numberThreads){
	
	inputFile = _inputFile;
 	outputFile = _outputFile; 
	algorithmSelected = _algorithmSelected; 
	numberThreads = _numberThreads;
	
}

void SortAlgorithms::runAlgorithm(){

	bool write=true;
	//inputFile
	ifstream file(inputFile);	
	
	//outputFile
	ofstream myFile;
	myFile.open(outputFile);	

	string line;
	//For read the lines in the file
	while(getline(file,line)){
		//split and convert to integer
		vector<int> numbers;
		
		stringstream iss(line);
		while(1){
			if(!iss)
				break;
			int s;
			iss >> s;
			numbers.push_back(s);
					
		}
		//the last number of array appear repeat so a temporary solution was erase the last element
		numbers.pop_back();
		
		int size = numbers.size();
 
		//convert to a int vector
		int values[size];
		for(int i=0;i<size;i++){
			values[i]=numbers.at(i);		
		}

		

		if(strcmp(algorithmSelected, "merge")==0){
			//cout<<" You choose merge!"<<endl;
			this->mergeSort(values,0,size-1);

		//}else if(strcmp(algorithmSelected, "insertion")==0){
			//cout<<" You choose insertion!"<<endl;
			//this->insertion(values,size);

		//}else if(strcmp(algorithmSelected, "bubble")==0){
			//cout<<" You choose bubble!"<<endl;
			//this->bubble(values,size);

		}else if(strcmp(algorithmSelected, "quicksort")==0 ){
			//cout<<" You choose quicksort!"<<endl;
			this->quickSort(values,0,size-1);

		//}else if(strcmp(algorithmSelected, "heapsort")==0 ){
			//cout<<" You choose heapsort!"<<endl;
			//this->heapSort(values,size);
		
		}else{
			cout<<"Invalid name for sort algorithm option "<<endl;
			write = false;
		}
		
		/*code for testing
		for(int i=0;i<size;i++){
			cout<<values[i]<<endl;		
		}*/
		
		if(write){
			
			for(int i=0;i<size;i++){
				myFile<< values[i];
				if(i<size-1)
					myFile<<",";
				if(i==size-1)
					myFile<<"\n";		
			}		
		}

	}
	
}


void SortAlgorithms::merge(int *a,int low, int high, int mid){

	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
	
}

void SortAlgorithms::mergeSort(int *a, int low, int high){
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		this->mergeSort(a, low, mid);
		this->mergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		this->merge(a, low, high, mid);
	}
}

void SortAlgorithms::insertion(int *vector, int size){
	int i, j, tmp;
	for(i=1;i<size;i++){
		j=i;
		while(j>0 && vector[j-1] > vector[j]){
			tmp = vector[j];
            vector[j] = vector[j - 1];
            vector[j - 1] = tmp;
            j--;		
		}
	}
}

void SortAlgorithms::bubble(int *vector, int size){
	
	int i, j, temp; 
   	bool swapped;
	//2 for cycle for travel the all array compares each element with his contigous element 
	//taking it out like a bubble
   	for (i = 0; i < size-1; i++) 
   	{ 
     	swapped = false; 
     	for (j = 0; j < size-i-1; j++) 
     	{ 
        	if (vector[j] > vector[j+1]) 
        	{ 
				temp=vector[j];
				vector[j]=vector[j+1];
           		vector[j+1]=temp; 
           		swapped = true; 
        	} 
     	} 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
}

void SortAlgorithms::quickSort(int *vector, int low, int high){
	if (low < high) 
    { 
        /* pi is partitioning index, vector[p] is now 
           at right place */
        int pi = partition(vector, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        this->quickSort(vector, low, pi - 1); 
        this->quickSort(vector, pi + 1, high); 
    } 
}

int SortAlgorithms::partition(int *vector, int low, int high){
	int pivot = vector[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (vector[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
			int temp = vector[i];
			vector[i]=vector[j];
			vector[j]=temp;
        } 
    } 
	int temp = vector[i+1];
	vector[i+1]=vector[high];
	vector[high]=temp;
    return (i + 1); 
}

void SortAlgorithms::heapSort(int *vector, int size){
	// Build heap (rearrange array) 
    for (int i = size / 2 - 1; i >= 0; i--) 
        heapify(vector, size, i); 
  
    // One by one extract an element from heap 
    for (int i=size-1; i>=0; i--) 
    { 
        // Move current root to end 
		int temp = vector[0];
		vector[0] = vector[i];
		vector[i] = temp; 
  
        // call max heapify on the reduced heap 
        this->heapify(vector, i, 0); 
    }	
}

void SortAlgorithms::heapify(int *vector, int n, int i){
	int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && vector[l] > vector[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && vector[r] > vector[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
		int temp=vector[i];
		vector[i] = vector[largest];
		vector[largest] = temp;
  
        // Recursively heapify the affected sub-tree 
        this->heapify(vector, n, largest); 
    } 
}



