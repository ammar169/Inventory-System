#include "Time.h"

Time::Time() {
	time_t	Time;
	tm*		time_now;

	char d[7][10] = { "Sunday","Monday","Teusday","Wednesday","Thursday","Friday","Saturday" };
	char m[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

	//To get the local current time
	time(&Time);
	time_now = localtime(&Time);

	date = time_now->tm_mday;				std::cout << "Date: " << date << std::endl;
	month = time_now->tm_mon;				std::cout << "Month: " << month << std::endl;
	year = 1900 + time_now->tm_year;		std::cout << "Year: " << year << std::endl;

	//Shows the current date
	std::cout << "Today's date: " << date << " " << m[month] << " " << year << std::endl;
}