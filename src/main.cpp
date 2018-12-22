#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "SortAlgorithms.h"

using namespace std;

//Global variables for threads and pointer to sort process
std::thread myThreads[4];
SortAlgorithms *myProcess=nullptr;

//main function to start each thread
void mainThread(){
	bool finish=false;
	do{
		string line=myProcess->readLine(finish);
		//if there are info for process then do it
		if(finish){
			myProcess->sorting(line);
		}
	}while(finish);
}

int main(int argc, char * argv[]){	
	
	//validation of the right input  
	if(argc<4){
		cout<<"To few arguments for the code, please enter:"<<endl;
		cout<<" ./ProducerConsume /path/to/InputFile /path/to/OutputFile algorithmToSort"<<endl;
		cout<<" the last argument must be quicksort or mergesort"<<endl;
		
	}else if(argc>4){
		cout<<"To many arguments for the code, please check if you enter an aditional space"<<endl;
		
	}else{
	
		//Checking if files exist!
		ifstream inputFile(argv[1]);
		if(inputFile.fail()){
			cout<<"File does not exist! Please checking name. "<<endl;		
		}else{
			cout<<"Starting process "<<endl;
			myProcess= new SortAlgorithms(argv[1], argv[2], argv[3], 4);
			//myProcess.runAlgorithm();	
			//myProcess.runAlgorithm2();
			bool algortithmSelectedExist = myProcess->rightAlgorithmSelected();
			
			if(algortithmSelectedExist){

				myThreads[0]= std::thread(mainThread);
				myThreads[1]= std::thread(mainThread);
				myThreads[2]= std::thread(mainThread);
				myThreads[3]= std::thread(mainThread);
				
				//join the threads
				myThreads[0].join();
				myThreads[1].join();
				myThreads[2].join();
				myThreads[3].join();
			}

			cout<<"Ending process "<<endl;
			delete myProcess;

		}		
		
	}


	//End of programm
	return 0;
}
