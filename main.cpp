#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "SortAlgorithms.h"

using namespace std;

int main(int argc, char * argv[]){	
	
	//validation of the right input  
	if(argc<4){
		cout<<"To few arguments for the code, please enter:"<<endl;
		cout<<" ./ProducerConsume /path/to/InputFile /path/to/OutputFile algorithmToSort"<<endl;
		cout<<"the last argument must be quicksort or mergesort"<<endl;
		
	}else if(argc>4){
		cout<<"To many arguments for the code, please check if you enter an aditional space"<<endl;
		
	}else{
	
		//Checking if files exist!
		ifstream inputFile(argv[1]);
		if(inputFile.fail()){
			cout<<"File does not exist! Please checking name. "<<endl;		
		}else{
			cout<<"Starting process "<<endl;
			SortAlgorithms myProcess(argv[1], argv[2], argv[3], 4);
			myProcess.runAlgorithm();						
			cout<<"Ending process "<<endl;
		
			/*int val[5] ={40 , 2, 6, 8, 10};
			int size= sizeof(val)/sizeof(val[0]);
			for(int j=0; j<size; j++){
				cout<<val[j]<<" ";	
			}
				cout<<endl;
			
			//myProcess.bubble(val,size);
			//myProcess.quickSort(val,0,size-1);
			myProcess.heapSort(val,size);
			for(int j=0; j<size; j++){
				cout<<val[j]<<" ";	
			}
				cout<<endl;
			*/

		}		
		
	}


	//End of programm
	return 0;
}
