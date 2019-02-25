#include <iostream>
#include <ctime> // time and date functions and structures
using namespace std;

int main() {

	// Get the current date and time (seconds elapsed since January 1st 1970)
	time_t now = time(0);

	// ------------------------------------------------------------------------------------------
	

	// Convert the `time_t` object to a human-readable string which contains time and\
	// date in the format "Www Mmm dd hh:mm:ss yyyy"
	char* dateTimeString = ctime(&now);
	cout << "The local date and time is: " << dateTimeString << "\n";

	// ------------------------------------------------------------------------------------------
	
	// Get a pointer to the current UTC time and date using the time from a `time_t` object\
	// (`now` in this case) 
	tm* gmtm = gmtime(&now);
	// Convert the pointer to a human-readable string of the current UTC time and date
	dateTimeString = asctime(gmtm);
	cout << "The UTC date and time is: "<< dateTimeString << "\n";

	// ------------------------------------------------------------------------------------------

	// Use the values pointed by the argument of `localtime()` to fill a `tm` structure so\
	// that the components of local time and date can be accessed
	tm* dtComponents = localtime(&now);
	// This member returns the number of years passed since 1900 (hence add 1900 to it to\
	// obtain the current year)
	int currYear = 1900 + dtComponents->tm_year;
	// This member returns an integer between 0 and 11, thus we need to increment it by 1 to\
	// obtain the current month
	int currMonth = 1 + dtComponents->tm_mon;
	// Get the current day of the month (1-31)
	int currDay = dtComponents->tm_mday;
	// Get the current hour (0-24)
	int currHour = dtComponents->tm_hour;
	// Get the current minute (0-60)
	int currMin = dtComponents->tm_min;
	// Get the current second (0-60)
	int currSec = dtComponents->tm_sec;

	cout << "Current year: " << 1900 + dtComponents->tm_year << "\n";
	cout << "Current month: " << 1 + dtComponents->tm_mon << "\n";
	cout << "Current day: " << dtComponents->tm_mday << "\n";
	cout << "Current hour: " << dtComponents->tm_hour << "\n";
	cout << "Current minute: " << dtComponents->tm_min << "\n";
	cout << "Current second: " << dtComponents->tm_sec << "\n\n";

	cout << "Today is " << currMonth << "/" << currDay << "/" << currYear << "\n";
	cout << "The local time is " << currHour << ":" << currMin << ":" << currSec << "\n";

	return 0;
}