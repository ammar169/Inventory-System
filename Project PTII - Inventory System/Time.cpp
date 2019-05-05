//This program are the implementation of the constructors and/or function definition
//in Time.h file
#include "Time.h"

Time::Time() {
	time_t	Time;
	tm*	time_now;

	//To get the local current time
	time(&Time);
	time_now = localtime(&Time);

	date = time_now->tm_mday; /*std::cout << "Date: " << date << std::endl;*/
	month = time_now->tm_mon; /*std::cout << "Month: " << month << std::endl;*/
	year = 1900 + time_now->tm_year; /*std::cout << "Year: " << year << std::endl;*/
}