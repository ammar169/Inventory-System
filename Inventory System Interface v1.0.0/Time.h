#ifndef _TIME_H
#define _TIME_H
#include <iostream>
#include <ctime>

class Time {
	int	date;	//To hold current date
	int	month;	//To hold current month
	int	year; //To hold current year
public:
	//Time(int d = 1, int m = 0, int y = 1900) :date(d), month(m), year(y) {}
	Time();

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

#endif
