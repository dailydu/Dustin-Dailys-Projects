#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <stdexcept>
using namespace std;


namespace DateNameSpace
{

enum type {TEXT, DAYTEXT, NUMERIC, DAYNUMERIC};

	class Date
	{

		public:
			Date(); 
			Date(int a, int b, int c);
		    static Date Today();
			static void outputFormat(type d);
			string getDayOfWeek() const;
			string displayMonth() const;
			void setToday();
			int setDate(int a, int b, int c);
			int getDay() const;
			int getMonth() const;
			int getYear() const;
			int lessDay();
			int nextDay();
			 Date operator++(int);
			 Date operator++();
			 Date operator--(int);
			 Date operator--();
			bool leapyear(int year);
			friend ostream& operator<<(ostream& out,const Date& c);
			bool operator==(const Date& c) const;		
		private:
			static type outputType;
			int year;
			int month;
			int day;
			int temp;
			string msg;

	};//end date class
	
	class DateException
	{
		public:
			DateException(const string& m="")
			{ msg = m;}
			
			string what()
			{return msg;}
		
		private:
			string msg;
	};


}

#endif