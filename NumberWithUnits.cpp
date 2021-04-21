#include "NumberWithUnits.hpp"
namespace ariel{
   void NumberWithUnits::read_units(ifstream& units_file){}
  // + - += -= (+) (-)
   NumberWithUnits operator+( NumberWithUnits const & left, NumberWithUnits const & right ){
     return NumberWithUnits(1,"km");
   }
   NumberWithUnits & operator+( NumberWithUnits & value ){
     return value;
   }

   NumberWithUnits operator-( NumberWithUnits const & left, NumberWithUnits const & right ){
     return NumberWithUnits(1,"km");
   }
   NumberWithUnits & operator-( NumberWithUnits & value ){
     value.num=value.num*(-1);
     return value;
   }

   NumberWithUnits & operator+=( NumberWithUnits & left, NumberWithUnits const & right ){
     return left;
   }
   NumberWithUnits & operator-=( NumberWithUnits & left, NumberWithUnits const & right ){
     return left;
   }

  // > >= < <= == !=
   bool operator==( NumberWithUnits const & left, NumberWithUnits const & right ){
     return false;
   }
   bool operator!=( NumberWithUnits const & left, NumberWithUnits const & right ){
     return false;
   }
   bool operator<( NumberWithUnits const & left, NumberWithUnits const & right ){
     return false;
   }
   bool operator<=( NumberWithUnits const & left, NumberWithUnits const & right ){
     return false;
   }
   bool operator>( NumberWithUnits const & left, NumberWithUnits const & right ){
     return false;
   }
   bool operator>=( NumberWithUnits const & left, NumberWithUnits const & right ){
     return false;
   }

  // ++ --
  // prefix ++T
   NumberWithUnits & operator++( NumberWithUnits & value ){
     return value;
   }
  //postfix T++
   NumberWithUnits operator++( NumberWithUnits & value, int ){
     return NumberWithUnits(1,"km");
   }
  // prefix --T
   NumberWithUnits & operator--( NumberWithUnits & value ){
     return value;
   }
  //postfix T--
   NumberWithUnits operator--( NumberWithUnits & value, int ){
     return NumberWithUnits(1,"km");
   }

  // *
   NumberWithUnits operator*( NumberWithUnits const & left, double const right ){
     return NumberWithUnits(1,"km");
   }
   NumberWithUnits operator*( double const left, NumberWithUnits const & right){
     return NumberWithUnits(1,"km");
   }

  // << >>
   ostream& operator<<(ostream& os, NumberWithUnits const & value){
     return os<<value.num<<"["<<value.str<<"]";
     //2.3[km]
   }
   istream& operator>>(istream& in, NumberWithUnits& value ){
     return in;
   }
}
