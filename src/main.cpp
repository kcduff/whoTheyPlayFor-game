/** @file main.cpp
 * Who they play for, main program
 * Author: Brent Duff
 * Dec 12 2021
 * LICENSE: GNU GPLv3
 */

#include <iostream>
#include <vector>
#include <string>

#include "Rosters.hpp"
#include "Inferencer.hpp"


using namespace std;

enum SystemModes {
	textmode,
	inferencemode,
	gamemode};

struct Settings{
	int mode=textmode;
	std::string modelpath="";
	string imgpath="";
};
	
void show_usage(){
	cout << "USAGE: ./whoTheyPlayFor [-m [MODEL_FILE] -d [IMG_DIR]]" << endl;
	cout << "Program can run in two modes: \n \
				1. text query mode \n \
				2. DNN inference mode \n \
			-m and -d flags are *required* if running in inference mode. \n \
			Specify mode via these two flags." << endl;
}
int main(int argc, char* argv[])
{
	Settings s;
	
	if(argc > 1){ // I.e. it has options
	//Set mode and path accordingly.
	//TODO: Parse options
	}
	//Otherwise, proceed.
	
	/*Program Init*/
	if(!InitRosters()){
		cout << "CRITICAL ERROR! Roster initialization FAILED. Exiting..." << endl;
		exit(-1);
	}
	if(s.mode==inferencemode){
		if(!InitInferencer()){
			cout << "CRITICAL ERROR! Inference system initialization FAILED. Exiting..." << endl;
			exit(-1);
		}
	}
	
	while(1){ //Main loop
		//Query user, depending on mode, for either text query or image file for inferencer.
		if(s.mode==textmode){
			std::string queryStr;
			cout << "Enter player name to look up: " << endl;
			std::getline(cin,queryStr);

			Player* res = QueryPlayerName(queryStr);
			if(res==nullptr){
				cout << "Player: "<< queryStr << "not found!!" << endl;
			}else{
				cout << "Player: " << queryStr << " FOUND." <<endl;
				cout << "They play for the " << res->team->name << endl;
			}
			
		}else if(s.mode==inferencemode){
			
		}
		//TODO: Investigate if cleanup on key-quit is worthwhile?
	}
  
    return 0;
}
