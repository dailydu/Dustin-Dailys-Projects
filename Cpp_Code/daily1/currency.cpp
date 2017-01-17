// File:     currency.cpp
// Author:   Dustin Daily

// Description
// This file defines the methods I created for Currency Class


#include "currency.h"

currencyType Currency::roundOrShowCentsOrTruncate = ShowCents;
currencyType Currency::dollarSignorNotDollarSign = ShowDollarSign;


  // method - money
  // description - return number
  // preconditions - num is initalized
  // postconditions - none
  // method input - none
  // method output - number
Currency::Currency(double r)
{
  if((static_cast<int>(r*1000)%10) >= 5)
  {	
    r=r+.005;
  }
 num = r;
 
 dollar = num;
 cents = (num - dollar) * 100 + .005;
  
}




  // method - money
  // description - return number
  // preconditions - num is initalized
  // postconditions - none
  // method input - none
  // method output - number
double Currency::money() const
{
  return num; 
}





 // method - == operator (object)
  // description - to check is objects are equal
  // preconditions - 2 objects input
  // postconditions - none
  // method input - 2 objects
  // method output - true or false
bool Currency::operator==(const Currency& c) const
{
   return money() == c.money();
}




  // method - == operator (number)
  // description - to check if object and number are equal
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
bool Currency::operator==(double n) const
{
   return money() == n;
}




  // method - < operator (number)
  // description - to check if object is less than number
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
bool Currency::operator<(double n) const
{
  
  return money() < n;
  

}





  // method - < operator (object)
  // description - to check if object is less than other object
  // preconditions - 2 objects input
  // postconditions - none
  // method input - 2 objects
  // method output - true or false
bool Currency::operator<(const Currency& c) const
{
  if(getDollars() == c.getDollars())
  {
    if(getCents() == c.getCents())
    {
	return !(money() < c.money());
    }
    if(getCents() < c.getCents())
    {
	return money() < c.money();
    }
  }
  else
  {
      return (money() < c.money());
  }

}




  // method - > operator (object)
  // description - to check if object is more than other object
  // preconditions - 2 objects input
  // postconditions - none
  // method input - 2 objects
  // method output - true or false
bool Currency::operator>(const Currency& c) const
{
 return !(*this<c);
}


  // method - > operator (number)
  // description - to check if object is more than number
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
bool Currency::operator>(double n) const
{
  return !(*this<n);
}


  // method - >= operator (number)
  // description - to check if object is equal or more than number
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
bool Currency::operator>=(double n) const
{
  if(money() == n)
    {
	return money() == n;
    }
  else
  {
      return !(*this<n);
  }
}

  // method - >= operator (object)
  // description - to check if object is equal or more than other object
  // preconditions - 2 objects input
  // postconditions - none
  // method input - 2 objects
  // method output - true or false
bool Currency::operator>=(const Currency& c) const
{
  if(getDollars() == c.getDollars())
  {
    if(getCents() == c.getCents())
    {
	return money() == c.money();
    }
     
  }
  else
  {
      return !(*this<c);
  }
}


  // method - <= operator (number)
  // description - to check if object is equal or less than number
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
bool Currency::operator<=(double n) const
{
  if(money() == n)
    {
	return money() == n;
    }
  else
  {
      return (*this<n);
  }
}


  // method - <= operator (object)
  // description - to check if object is equal or less than other object
  // preconditions - 2 objects input
  // postconditions - none
  // method input - 2 objects
  // method output - true or false
bool Currency::operator<=(const Currency& c) const
{
  if(getDollars() == c.getDollars())
  {
    if(getCents() == c.getCents())
    {
	return money() == c.money();
    }
     
  }
  else
  {
      return (*this<c);
  }
}







  // method - + operator (object)
  // description - to check is objects are equal
  // preconditions - 2 objects input
  // postconditions - none
  // method input - 2 objects
  // method output - true or false
const Currency Currency::operator+(const Currency& c) const
{
 return money()+c.money();
 
}




  // method - + operator (number)
  // description - to add 1 object and 1 number
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
const Currency Currency::operator+(double n) const
{
	return money()+n;
}




  // method - operator (object)
  // description - to subtract 2 objects 
  // preconditions - 2 objects input
  // postconditions - none
  // method input - 2 objects
  // method output - true or false
const Currency Currency::operator-(const Currency& c) const
{
   return money()-c.money();
}




  // method - - operator (number)
  // description - subtract a number and a object
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
const Currency Currency::operator-(double n) const
{
	return money()-n;
}




  // method - * operator (object)
  // description - to add 1 object and 1 number
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
const Currency Currency::operator*(const Currency& c) const
{
   return money()*c.money();
}




  // method - * operator (number)
  // description - to add 1 object and 1 number
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
const Currency Currency::operator*(double n) const
{
	return money()*n;
}




  // method - / operator (object)
  // description - to divide 2 objects
  // preconditions - 2 objects input
  // postconditions - none
  // method input - 2 objects
  // method output - true or false
const Currency Currency::operator/(const Currency& c) const
{
   return money()/c.money();
}




  // method - / operator (number)
  // description - to divide 1 object by 1 number
  // preconditions - 1 object and 1 number
  // postconditions - none
  // method input - 1 object and 1 number
  // method output - true or false
const Currency Currency::operator/(double n) const
{
	return money()/n;
}




  // method - Get Dollars
  // description - to return the object of dollars
  // preconditions - dollar to be declared in the constructor
  // postconditions - none
  // method input - long dollar
  // method output - object of dollar
double Currency::getDollars() const
{
	return dollar;
}




  // method - Get Cents
  // description - to give the object of cents
  // preconditions - for cents to be declared in the constructor
  // postconditions - none
  // method input - short cents
  // method output - object of cents
double Currency::getCents() const
{
	return cents;
}


  // method - > setFormat (currencyType)
  // description - to set the currencyType format
  // preconditions - 1 currencyType created
  // postconditions - none
  // method input - 1 currencyType
  // method output - none
void Currency::setFormat(currencyType ov)
{
   if( ov == Round || ov == Truncate || ov == ShowCents)
   {
	   roundOrShowCentsOrTruncate = ov;
   }
   else
   {
	   dollarSignorNotDollarSign = ov;
   }
}



  // method - > getRoundValue
  // description - return the static variable
  // preconditions - static variable made
  // postconditions - none
  // method input - none
  // method output - currencyType
currencyType Currency::getRoundValue()
{
   return roundOrShowCentsOrTruncate;
}



  // method - > getDollarValue
  // description - return static variable
  // preconditions - static varibale created
  // postconditions - none
  // method input - none
  // method output - currencyType
currencyType Currency::getDollarValue()
{
   return dollarSignorNotDollarSign;
}



  // method - << outstream
  // description - output the class
  // preconditions - Format declared and class has a number
  // postconditions - none
  // method input - Currency object, currencyType format
  // method output - string
ostream& operator<<(ostream& out,const Currency& c)
{
	
   if (Currency::getRoundValue() == Round && Currency::getDollarValue() == ShowDollarSign)
   {
	   double temp;
		temp = c.money();
	
	   if(static_cast<int>(temp*100)%100 >= 50)
	   {
		  out << "$" << c.getDollars() + 1;		  
	   }
	   else
	   {
		   out << "$" << c.getDollars();
	   }
	    
   }
   else if (Currency::getRoundValue() == Truncate && Currency::getDollarValue() == ShowDollarSign)
   {
	    out << "$" << c.getDollars();
   } 
   else if (Currency::getRoundValue() == ShowCents && Currency::getDollarValue() == ShowDollarSign)
   {
	    out << "$" << c.money();
   }    
   else if (Currency::getRoundValue() == ShowCents && Currency::getDollarValue() == NoDollarSign)
   {
	    out << c.money();
   }  
   else if (Currency::getRoundValue() == Round && Currency::getDollarValue() == NoDollarSign)
   {
	   double temp;
		temp = c.money();
	   
	   if(static_cast<int>(temp*100)%100 >= 50)
	   {
		  out << c.getDollars() + 1;
	   }
	   else
	   {
		   out << c.getDollars();
	   }
   } 
   else if (Currency::getRoundValue() == Truncate && Currency::getDollarValue() == NoDollarSign)
   {
	    out << c.getDollars();
   }  
	  
	  
   return out;
}
