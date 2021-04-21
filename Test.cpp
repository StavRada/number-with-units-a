#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace ariel;
using namespace std;
using namespace doctest;

ifstream units_file{"units.txt"};

TEST_CASE("+ - += -= (-) (+)"){
  NumberWithUnits::read_units(units_file);
  //check m and km
  NumberWithUnits a{2, "km"};
  NumberWithUnits b{2000, "m"};
  NumberWithUnits c{2500, "m"};


  CHECK((a+b) == NumberWithUnits{4, "km"});
  CHECK((a+c) == NumberWithUnits{4.5, "km"});
  CHECK((c+a) == NumberWithUnits{4500, "m"});
  CHECK((a-b) == NumberWithUnits{0, "km"});
  CHECK((c-b) == NumberWithUnits{50, "m"});
  CHECK((a+=b) == NumberWithUnits{4, "km"});
  CHECK((b-=a) == NumberWithUnits{0, "m"});
  CHECK((-a) == NumberWithUnits{-2, "km"});
  CHECK((+a) == NumberWithUnits{2, "km"});
  CHECK((-a) == NumberWithUnits{-2, "km"});

  //check g , kg and ton
  NumberWithUnits g1{1000, "g"};
  NumberWithUnits g2{2500, "g"};
  NumberWithUnits kg1{1, "kg"};
  NumberWithUnits kg2{1000, "kg"};    
  NumberWithUnits ton1{1, "ton"};
  NumberWithUnits ton2{4, "ton"};
  
  CHECK((g1+kg1) == NumberWithUnits{2000, "g"});
  CHECK((kg2+ton1) == NumberWithUnits{2000, "kg"});
  CHECK((kg2+ton2) == NumberWithUnits{5000, "kg"});
  CHECK((ton2+kg1) == NumberWithUnits{4.001, "ton"});
  CHECK((kg2-ton1) == NumberWithUnits{0, "kg"});
  CHECK((g2-kg1) == NumberWithUnits{1500, "g"});
  CHECK((kg1+=ton1) == NumberWithUnits{1001, "kg"});
  CHECK((g2-=kg1) == NumberWithUnits{1500, "g"});
  CHECK((-ton1) == NumberWithUnits{-1, "ton"});
  
 //check sec , min and hour
  NumberWithUnits s1{60, "sec"};
  NumberWithUnits s2{120, "sec"};
  NumberWithUnits m1{60, "min"};
  NumberWithUnits m2{2, "min"};
  NumberWithUnits h1{1, "hour"};
  NumberWithUnits h2{4, "hour"}; 

  CHECK((s1+m2) == NumberWithUnits{180, "sec"});
  CHECK((s2+m1) == NumberWithUnits{3720, "sec"});
  CHECK((m1+h1) == NumberWithUnits{120, "min"});
  CHECK((h1+m2) == NumberWithUnits{2.2, "hour"});
  CHECK((h2-m1) == NumberWithUnits{3, "hour"});
  CHECK((m2-s1) == NumberWithUnits{1, "min"});
  CHECK((h1+=m1) == NumberWithUnits{2, "hour"});
  CHECK((s2-=m2) == NumberWithUnits{0, "sec"});


  //check USD and ILS
  NumberWithUnits d1{2, "USD"};
  NumberWithUnits ils{6.66, "ILS"};
  
  CHECK((d1+ils) == NumberWithUnits{4, "USD"});
  CHECK((d1-ils) == NumberWithUnits{0, "USD"});

  //Error checking
  CHECK_THROWS(a+g1);
  CHECK_THROWS(kg2+m1);
  CHECK_THROWS(d1+ton2);
  CHECK_THROWS(c+g2);
  CHECK_THROWS(c+s2);
  CHECK_THROWS(b+m2);
  CHECK_THROWS(ton2+m2);
  CHECK_THROWS(ils+a);
  }

TEST_CASE("> >= < <= == !="){
NumberWithUnits::read_units(units_file);
  // check m and km
  NumberWithUnits a{2, "km"};
  NumberWithUnits b{2000, "m"};
  NumberWithUnits c{2500, "m"};
  NumberWithUnits d{100, "m"};
  NumberWithUnits e{10, "km"};

  CHECK_LT(a , c);
  CHECK_LT(b , c);
  CHECK_LT(d , a);
  CHECK_LT(d , b);
  CHECK_GT(c , a);
  CHECK_GT(e , a);
  CHECK_GT(e , c);
  CHECK_GT(c , b);
  CHECK_GT(b, d);
  CHECK(a >= b);
  CHECK(a <= b);
  CHECK_EQ(a , b);
  CHECK_NE(a , c);
  CHECK_NE(d , b);
  CHECK_NE(c , e);
  CHECK_NE(a , c);
  CHECK_NE(c , b);

  //check g , kg and ton
  NumberWithUnits g1{1000, "g"};
  NumberWithUnits g2{2500, "g"};
  NumberWithUnits kg1{1, "kg"};
  NumberWithUnits kg2{1000, "kg"};    
  NumberWithUnits ton1{1, "ton"};
  NumberWithUnits ton2{4, "ton"};

  CHECK_LT(g1 , ton1);
  CHECK_LT(kg1 , ton1);
  CHECK_GT(ton1 , ton2);
  CHECK_GT(g2 , kg1);
  CHECK_EQ(g1 , kg1);
  CHECK_EQ(kg2 , ton1);
  CHECK_NE(g2 , kg1);
  CHECK_NE(kg2 , ton2);

 //check sec , min and hour
  NumberWithUnits s1{60, "sec"};
  NumberWithUnits s2{120, "sec"};
  NumberWithUnits m1{60, "min"};
  NumberWithUnits m2{2, "min"};
  NumberWithUnits h1{1, "hour"};
  NumberWithUnits h2{4, "hour"}; 

  CHECK_LT(s1 , m1);
  CHECK_LT(m1 , h2);
  CHECK_GT(s2 , m2);
  CHECK_GT(h2 , m1);
  CHECK_EQ(m1 , h1);
  CHECK_EQ(s2 , m2);
  CHECK_NE(h2 , s1);
  CHECK_NE(m2 , h1);


  //check USD and ILS
  NumberWithUnits d1{2, "USD"};
  NumberWithUnits d2{5, "USD"};
  NumberWithUnits ils1{6.66, "ILS"};
  NumberWithUnits ils2{12, "ILS"};

  CHECK_LT(d1 , ils2);
  CHECK_LT(ils1 , d2);
  CHECK_GT(ils2 , d1);
  CHECK_EQ(d1, ils1);
  CHECK_NE(d2 , ils2);
  
}

TEST_CASE("++ -- ++value --value"){
NumberWithUnits::read_units(units_file);
//check m and km
  NumberWithUnits a{2, "km"};
  NumberWithUnits b{2000, "m"};
  NumberWithUnits c{2500, "m"};
  NumberWithUnits d{100, "m"};
  NumberWithUnits e{10, "km"};
//++
CHECK( a++ == NumberWithUnits{3,"km"});
CHECK( b++ == NumberWithUnits{2001,"m"});
CHECK( c++ == NumberWithUnits{2501,"m"});
CHECK( d++ == NumberWithUnits{101,"m"});
CHECK( e++ == NumberWithUnits{11,"km"});
//++value
CHECK( ++a == NumberWithUnits{3,"km"});
CHECK( ++b == NumberWithUnits{2001,"m"});
CHECK( ++c == NumberWithUnits{2501,"m"});
CHECK( ++d == NumberWithUnits{101,"m"});
CHECK( ++e == NumberWithUnits{11,"km"});
//--
CHECK( a-- == NumberWithUnits{1,"km"});
CHECK( b-- == NumberWithUnits{1999,"m"});
CHECK( c-- == NumberWithUnits{2499,"m"});
CHECK( d-- == NumberWithUnits{99,"m"});
CHECK( e-- == NumberWithUnits{9,"km"});
//--value
CHECK( --a == NumberWithUnits{1,"km"});
CHECK( --b == NumberWithUnits{1999,"m"});
CHECK( --c == NumberWithUnits{2499,"m"});
CHECK( --d == NumberWithUnits{99,"m"});
CHECK( --e == NumberWithUnits{9,"km"});


//check g , kg and ton
  NumberWithUnits g1{1000, "g"};
  NumberWithUnits g2{2500, "g"};
  NumberWithUnits kg1{1, "kg"};
  NumberWithUnits kg2{1000, "kg"};    
  NumberWithUnits ton1{1, "ton"};
  NumberWithUnits ton2{4, "ton"};
//++
CHECK( g1++ == NumberWithUnits{1001,"g"});
CHECK( kg1++ == NumberWithUnits{2,"kg"});
CHECK( ton2++ == NumberWithUnits{5,"ton"});
//++value
CHECK( ++g1 == NumberWithUnits{1001,"g"});
CHECK( ++kg1 == NumberWithUnits{2,"kg"});
CHECK( ++ton2 == NumberWithUnits{5,"ton"});
//--
CHECK( g1-- == NumberWithUnits{999,"g"});
CHECK( kg1-- == NumberWithUnits{0,"kg"});
CHECK( ton2-- == NumberWithUnits{3,"ton"});
//--value
CHECK( --g1 == NumberWithUnits{999,"g"});
CHECK( --kg1 == NumberWithUnits{0,"kg"});
CHECK( --ton2 == NumberWithUnits{3,"ton"});

//check sec , min and hour
  NumberWithUnits s2{120, "sec"};
  NumberWithUnits m1{60, "min"};
  NumberWithUnits h2{4, "hour"}; 
//++
CHECK( s2++ == NumberWithUnits{121,"sec"});
CHECK( m1++ == NumberWithUnits{61,"min"});
CHECK( h2++ == NumberWithUnits{5,"hour"});
//++value
CHECK( ++s2 == NumberWithUnits{121,"sec"});
CHECK( ++m1 == NumberWithUnits{61,"min"});
CHECK( ++h2 == NumberWithUnits{5,"hour"});
//--
CHECK( s2-- == NumberWithUnits{119,"sec"});
CHECK( m1-- == NumberWithUnits{59,"min"});
CHECK( h2-- == NumberWithUnits{3,"hour"});
//--value
CHECK( --s2 == NumberWithUnits{119,"sec"});
CHECK( --m1 == NumberWithUnits{59,"min"});
CHECK( --h2 == NumberWithUnits{3,"hour"});

//check USD and ILS
  NumberWithUnits d2{5, "USD"};
  NumberWithUnits ils1{6.66, "ILS"};
//++
CHECK( d2++ == NumberWithUnits{6,"USD"});
CHECK( ils1++ == NumberWithUnits{7.66,"ILS"});
//--
CHECK( d2-- == NumberWithUnits{4,"USD"});
CHECK( ils1-- == NumberWithUnits{5.66,"ILS"});
 

}

TEST_CASE("*"){
NumberWithUnits::read_units(units_file);
// check m and km
  NumberWithUnits a{2, "km"};
  NumberWithUnits b{2000, "m"};
CHECK( (a*2) == NumberWithUnits{4,"km"});
CHECK( (a*11) == NumberWithUnits{22,"km"});
CHECK( (b*2) == NumberWithUnits{4000,"m"});
CHECK( (b*10) == NumberWithUnits{20000,"m"});
CHECK((a*0.5) == NumberWithUnits{1, "km"});
CHECK((0.5*a) == NumberWithUnits{1, "km"});

//check g , kg and ton
  NumberWithUnits g1{3, "g"};
  NumberWithUnits kg1{1, "kg"};   
  NumberWithUnits ton1{1, "ton"};
CHECK( (g1*2) == NumberWithUnits{6,"g"});
CHECK( (kg1*11) == NumberWithUnits{11,"kg"});
CHECK( (ton1*2.5) == NumberWithUnits{2.5,"ton"});

//check sec , min and hour
  NumberWithUnits s2{120, "sec"};
  NumberWithUnits m1{60, "min"};
  NumberWithUnits h2{4, "hour"};
CHECK( (2*s2) == NumberWithUnits{240,"sec"});
CHECK( (m1*11) == NumberWithUnits{660,"min"});
CHECK( (h2*2.5) == NumberWithUnits{10,"ton"});

//check USD and ILS
  NumberWithUnits d2{5, "USD"};
  NumberWithUnits ils1{6.66, "ILS"};
CHECK( (2*d2) == NumberWithUnits{10,"USD"});
CHECK( (ils1*0.5) == NumberWithUnits{3.33,"ILS"});
}


TEST_CASE(" << >> "){
  NumberWithUnits::read_units(units_file);

  NumberWithUnits a{2, "km"};
  NumberWithUnits b{2000, "m"};
  NumberWithUnits c{2500, "m"};
  NumberWithUnits d{700, "m"};
  NumberWithUnits e{15, "m"};
// <<
    stringstream in1;
    in1 << (a+b) ;
    CHECK(in1.str() == "4[km]");

    stringstream in2;
    in2 << (a-b) ;
    CHECK(in2.str() == "0[km]");

// >>
  istringstream sample_input{"700 [ m ]"};
  sample_input >> d;

  stringstream in3;
  in3 << d;
  CHECK(in3.str() == "700[m]");


  
  istringstream sample_input1{"5 [ cm ]"};
  sample_input1 >> e;

  stringstream in4;
  in4 << e ;
  CHECK(in4.str() == "5[cm]");


}