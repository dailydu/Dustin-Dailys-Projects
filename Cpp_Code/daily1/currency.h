// File:     Currency.h
// Author:   Dustin Daily

// Description
// This file contains the specification for a currency class

#ifndef _CURRENCY_H_
#define _CURRENCY_H_

#include <iostream>
using namespace std;

enum currencyType {Round, Truncate, ShowCents, NoDollarSign, ShowDollarSign};

class Currency
{
   public:
      Currency(double=0); 
    double money() const;

    
    	/*************************************************
	NAME: bool checking operators
	NEEDED TO RUN: 2 object or 1 object and 1 number
	FUCTION: to check if equal, less than, greater than
	**************************************************/
	  bool operator==(double num) const;
      bool operator==(const Currency& c) const;
      bool operator<(const Currency&) const;
	  bool operator<(double num) const;
	  bool operator>(double num) const;
	  bool operator<=(double num) const;
	  bool operator>=(double num) const;
      bool operator!=(const Currency&) const;
      bool operator<=(const Currency&) const;
      bool operator>(const Currency&) const;
      bool operator>=(const Currency&) const;
	  /*************************************************
	NAME: overloading operators
	NEEDED TO RUN: to take in 2 objects or 1 object and 1 number
	FUCTION: to do basic math with values and numbers
	**************************************************/
      const Currency operator+(const Currency&) const;
      const Currency operator+(double num) const;
      const Currency operator-(const Currency&) const;
      const Currency operator-(double num) const;
      const Currency operator*(const Currency&) const;
      const Currency operator*(double num) const;
      const Currency operator/(const Currency&) const;
      const Currency operator/(double num) const;

	/*************************************************
	NAME: get dollars and get cents
	NEEDED TO RUN: long dollar and short cents
	FUCTION: to return those values
	**************************************************/
	  double getCents() const;
	  double getDollars() const;

	  /*************************************************/
	  
	/*************************************************
	NAME: get dollarsValue and get centsValue and setFormat
	NEEDED TO RUN: currencyType variables
	FUCTION: to return those variables and set the format
	**************************************************/
	  static currencyType getDollarValue();
	  static currencyType getRoundValue();
	  static void setFormat(currencyType);
	  
	/*************************************************
	NAME: currencyType variables
	NEEDED TO RUN: N/A
	FUCTION: to keep track of which format is used
	**************************************************/
	  static currencyType roundOrShowCentsOrTruncate;
	  static currencyType dollarSignorNotDollarSign;  
	  
	/*************************************************
	NAME: ostream
	NEEDED TO RUN: format and currency object
	FUCTION: to output the format and object
	**************************************************/
	  friend ostream& operator<<(ostream& out,const Currency& c);  
	  
   private:
      double num;
      long dollar;
      short cents;

};





















#endif