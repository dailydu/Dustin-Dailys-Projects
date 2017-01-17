#include "date.h"
#include <ctime>
#include <stdexcept>
#include <string>

namespace DateNameSpace
{

type Date::outputType = NUMERIC;

  // method - constructor
  // description - calls set today to get current date
  // preconditions - that set today calls for todays date
  // postconditions - none
  // method input - to decalre a date object
  // method output - the current date
Date::Date()
{
	setToday();
}

  // method - today method
  // description - creates the days date
  // preconditions - that todays date can be retrieved
  // postconditions - none
  // method input - to declare a variable to today
  // method output - todays date in a object
Date Date::Today()
{

	Date today;
	return today;
}

  // method - set today
  // description - sets the objects date as today
  // preconditions - to get the current date
  // postconditions - none
  // method input - called to reset the date to today
  // method output - todays date
void Date::setToday()
{
	tm *current;
    time_t lt;
    lt = time('\0');
    current = localtime(&lt);
    year = current->tm_year + 1900;
    month = current->tm_mon+1;
    day = current->tm_mday;
}

  // method - constructor (special date)
  // description - takes in a date specified by user
  // preconditions - the user puts in a date
  // postconditions - none
  // method input - 3 ints spaced by commas
  // method output - sets the date to these dates
Date::Date(int a, int b, int c)
{
	month = a;
	day = b;
	year = c;
}

  // method - set date
  // description - sets the object to the date given
  // preconditions - for user to assign a date
  // postconditions - none
  // method input - 3 integers for month, day , year
  // method output - none
int Date::setDate(int a, int b, int c)
{


	if(a > 12)
	{
		throw DateException("DateException: invalid month, month is =< 13");
	}
	
	if(c == 1999 && a == 2 && b > 28)
	{
		throw DateException("DateException: invalid day, month=2, day=29, year=1999");
	}
	
	month = a;
	day = b;
	year = c;

}

  // method -check date
  // description - to see if the date is throwing an error
  // preconditions - that a, b, c be assigned
  // postconditions - none
  // method input - 3 integers for month, day, year.
  // method output - none
int checkDate(int a, int b, int c) throw (DateException)
{
	
	if(a > 12)
	{
		throw DateException("DateException: invalid month, month is =< 13");
	}
	
	if(c == 1999 && a == 2 && b > 28)
	{
		throw DateException("DateException: invalid day, month=2, day=29, year=1999");
	}
	
	return a;
	return b;
	return c;
}

  // method - output format
  // description - makes the output type switch based on preference
  // preconditions - that there is an output statement for the different outputs
  // postconditions - none
  // method input - none
  // method output - none
void Date::outputFormat(type d) 
{
	switch(d)
	{
		case TEXT: outputType = TEXT; break;
		case DAYTEXT: outputType = DAYTEXT; break;
		case NUMERIC: outputType = NUMERIC; break;
		case DAYNUMERIC: outputType = DAYNUMERIC; break;
	}
   
}

  // method - display month
  // description - gives the name of the month
  // preconditions - that the month be set
  // postconditions - none
  // method input - none
  // method output - the name of the month
string Date::displayMonth() const
{

	string textMonth;

	switch(getMonth())
	{
		case 1: textMonth = "January"; break;
		case 2: textMonth = "February"; break;
		case 3: textMonth = "March"; break;
		case 4: textMonth = "April"; break;
		case 5: textMonth = "May"; break;
		case 6: textMonth = "June"; break;
		case 7: textMonth = "July"; break;
		case 8: textMonth = "August"; break;
		case 9: textMonth = "September"; break;
		case 10: textMonth = "October"; break;
		case 11: textMonth = "November"; break;
		case 12: textMonth = "December"; break;
	}
	return textMonth;
}

  // method - leap year
  // description - checks to see if the year is a leap year
  // preconditions - that a year is set
  // postconditions - none
  // method input - a year
  // method output - true or false
bool leapyear(int year)
{
	if(year %4 == 0 || year %400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

  // method - get day of the week
  // description - to get the day of the week in string
  // preconditions - that day is set
  // postconditions - none
  // method input - the day
  // method output - day of the week in a string
string Date::getDayOfWeek() const 
{
	int centuries;
	int months;
	int dayofweek;
	bool leapyear(int year);
	string textDay;
   centuries = (3-year/100%4)*2;
   switch (month)
   {
      case 1  : if (leapyear(year))
                   months = 6;
                else
                   months = 0; break;
      case 2  : if (leapyear(year))
                   months = 2;
                else
                   months = 3; break;
      case 3  : months = 3; break;
      case 4  : months = 6; break;
      case 5  : months = 1; break;
      case 6  : months = 4; break;
      case 7  : months = 6; break;
      case 8  : months = 2; break;
      case 9  : months = 5; break;
      case 10 : months = 0; break;
      case 11 : months = 3; break;
      case 12 : months = 5; break;
   }
   dayofweek = (centuries+year%100+year%100/4+months+day)%7;

   switch (dayofweek)
   {
      case 0 : textDay = "Sunday"; break;
      case 1 : textDay = "Monday"; break;
      case 2 : textDay = "Tuesday"; break;
      case 3 : textDay = "Wednesday"; break;
      case 4 : textDay = "Thursday"; break;
      case 5 : textDay = "Friday"; break;
      case 6 : textDay = "Saturday"; break;
   }
   return textDay;
}

  // method - get day
  // description - returns day
  // preconditions - day is set
  // postconditions - none
  // method input - none
  // method output - day
int Date::getDay() const
{
	return day;
}

  // method - get month
  // description - returns month
  // preconditions - month is set
  // postconditions - none
  // method input - none
  // method output - month
int Date::getMonth() const
{
	return month;
}

  // method - get year
  // description - returns the year
  // preconditions - year is set
  // postconditions - none
  // method input - none
  // method output - year
int Date::getYear() const
{
	return year;
}

  // method - next day
  // description -  adds a day to day
  // preconditions - day is set
  // postconditions - none
  // method input - none
  // method output - +1 day
int Date::nextDay()
{
	day = day +1;
	return day;
}

  // method - less day
  // description - -1 the day
  // preconditions - day is set
  // postconditions - none
  // method input - none
  // method output - -1 off of day
int Date::lessDay()
{
 day = day -1;
 return day;
}

  // method - operator ++
  // description - adds a day to day
  // preconditions - day is set and next day adds a day
  // postconditions - none
  // method input - none
  // method output - returns +1 day
 Date Date::operator++() //pre increment
{
    nextDay();
	return *this;
}

  // method - operator ++ (int)
  // description - adds a day but saves the previous day to return
  // preconditions - that day is set and next day works
  // postconditions - none
  // method input - none
  // method output - day before increment
Date Date::operator++(int) //post increment
{
   Date temp = *this;
   nextDay();
   return temp;
}

  // method - operator --
  // description - takes one day away from day
  // preconditions - day is set
  // postconditions - none
  // method input - none
  // method output - -1 day
Date Date::operator--()  //pre increment
{
	lessDay();
	return *this;
}

  // method -operator -- (int)
  // description - saves day then takes a day away
  // preconditions - day is set and less day works
  // postconditions - none
  // method input - none
  // method output - day before increment
Date Date::operator--(int day) //post increment
{
   Date temp = *this;
   lessDay();
   return temp;
}

  // method - operator ==
  // description - checks is dates are equal
  // preconditions - 2 arguents to check
  // postconditions - none
  // method input - 2 dates
  // method output - true or false
bool Date::operator==(const Date& c) const
{
	if(month == c.month && day == c.day && year == c.year)
	{return true;}
	else
	{ return false;}
}

  // method - operator <<
  // description - outputs the format selected
  // preconditions - a format is selected
  // postconditions - none
  // method input - none
  // method output - the format selected
ostream& operator<<(ostream& out,const Date& c)
{

switch(c.outputType)
{
	case NUMERIC: out << c.getMonth() << "/" << c.getDay() << "/" << c.getYear() << endl; return out; break;
	case TEXT: out << c.displayMonth() <<" "<< c.getDay() << ", " << c.getYear() << endl; return out; break;
	case DAYTEXT: out << c.getDayOfWeek() <<" "<< c.displayMonth() <<" "<< c.getDay() << ", " << c.getYear() << endl; return out; break;
	case DAYNUMERIC: out << c.getDayOfWeek() << ", " << c.getMonth() << "/" << c.getDay() << "/" << c.getYear() << endl; return out; break;
}

}
}//end namespace
