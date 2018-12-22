#include "Save.h"


Save::Save(char *_outputFile){
 	outputFile = _outputFile;
	myFile.open(outputFile);
}

Save::~Save(){
	myFile.close();	
}

void Save::savingControl(int *array, int size){
	std::lock_guard<std::mutex> guard(mtxWriter);
	for(int i=0;i<size;i++){
		myFile<< array[i];
		if(i<size-1)
			myFile<<",";
		if(i==size-1)
			myFile<<"\n";
	}
}
