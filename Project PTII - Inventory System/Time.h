//Header files that contain Time class
#ifndef _TIME_H //If Time.h is not included
#define _TIME_H //define this so that compiler know it has been included
#include <iostream>
#include <ctime>

class Time {
	int	date;	
	int	month;	
	int	year; 
public:
	/*Time(int d = 1, int m = 0, int y = 1900) :date(d), month(m), year(y) {}*/
	Time();

	void printTime() {
		char m[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
		//Shows the current date
		std::cout << "Today's date: " << date << " " << m[month] << " " << year << std::endl;
	}
	int getDate() {
		return date;
	}
	int getMonth() {
		return month;
	}
	int getYear() {
		return year;
	}
};

#endif // !TIME_H