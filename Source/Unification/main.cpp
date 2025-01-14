#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "unification.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
 {
	cout<<"# Running CoColour ..."<<endl;
	clock_t start_time, end_time;
	start_time = clock();

	// Utils::baseDir = argv[1];

	// std::cout << "argv[1]: " << argv[1] << std::endl;
	// std::cout << "base directory: " << Utils::baseDir << std::endl;

	string dataDir = Utils::baseDir + "Images";
	vector<string> filePathList = Utils::get_filelist(dataDir);
	cout<<"-Loaded "<<filePathList.size()<<" files."<<endl;

	ToneUnifier unifier(filePathList);   //! ToneUnifier LinearModel LinearGamma  
	unifier.unifyMultiTones();

	end_time = clock();
	cout<<"# All done! Consumed "<<double(end_time-start_time)/CLOCKS_PER_SEC<<" seconds"<<endl;

	return -1;
}