#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace ariel{
  class NumberWithUnits{
    private:
      double num;
      string str;
    public:
      NumberWithUnits(double num,string str){
        this->num=num;
        this->str=str;
      }
      static void read_units(ifstream& units_file);
      // + - += -= (+) (-)
      friend NumberWithUnits operator+( NumberWithUnits const & left, NumberWithUnits const & right );
      friend NumberWithUnits & operator+( NumberWithUnits & value );

      friend NumberWithUnits operator-( NumberWithUnits const & left, NumberWithUnits const & right );
      friend NumberWithUnits & operator-( NumberWithUnits & value );

      friend NumberWithUnits & operator+=( NumberWithUnits & left, NumberWithUnits const & right );
      friend NumberWithUnits & operator-=( NumberWithUnits & left, NumberWithUnits const & right );

      // > >= < <= == !=
      friend bool operator==( NumberWithUnits const & left, NumberWithUnits const & right );
      friend bool operator!=( NumberWithUnits const & left, NumberWithUnits const & right );
      friend bool operator<( NumberWithUnits const & left, NumberWithUnits const & right );
      friend bool operator<=( NumberWithUnits const & left, NumberWithUnits const & right );
      friend bool operator>( NumberWithUnits const & left, NumberWithUnits const & right );
      friend bool operator>=( NumberWithUnits const & left, NumberWithUnits const & right );

      // ++ --
      // prefix ++v
      friend NumberWithUnits & operator++( NumberWithUnits & value );
      //postfix v++
      friend NumberWithUnits operator++( NumberWithUnits & value, int );
      // prefix --v
      friend NumberWithUnits & operator--( NumberWithUnits & value );
      //postfix v--
      friend NumberWithUnits operator--( NumberWithUnits & value, int );

      // *
      friend NumberWithUnits operator*( NumberWithUnits const & left, double const right );
      friend NumberWithUnits operator*( double const left, NumberWithUnits const & right);

      // << >>
      friend ostream& operator<<(ostream & os, NumberWithUnits const & value);
      friend istream& operator>>(istream& in, NumberWithUnits& value );
    };
}
