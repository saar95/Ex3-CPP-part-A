#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
//#define CHECK_EQ DOCTEST_CHECK_EQ

ariel::NumberWithUnits units1 {2,"km"};
ariel::NumberWithUnits units2 {100,"m"};
ariel::NumberWithUnits units3 {360,"sec"};
ariel::NumberWithUnits units4 {4,"min"};
ariel::NumberWithUnits units5 {3.33,"ILS"};
ariel::NumberWithUnits units6 {1,"USD"};

TEST_CASE("Tests the constructor"){
	// istream units_file("units.txt");
	// NumberWithUnits::read_units(units_file);
	double random=0;
	for (size_t i = 0; i < 5; i++)
	{
		random=(double)(rand()%1000)+1;
		CHECK_THROWS(NumberWithUnits check1=NumberWithUnits(random,"pc"));
		CHECK_NOTHROW(NumberWithUnits check2=NumberWithUnits(random,"km"));
		CHECK_NOTHROW(NumberWithUnits check3=NumberWithUnits(random,"m"));
		CHECK_NOTHROW(NumberWithUnits check4=NumberWithUnits(random,"cm"));
		CHECK_NOTHROW(NumberWithUnits check5=NumberWithUnits(random,"kg"));
		CHECK_NOTHROW(NumberWithUnits check6=NumberWithUnits(random,"g"));
		CHECK_NOTHROW(NumberWithUnits check7=NumberWithUnits(random,"ton"));
		CHECK_NOTHROW(NumberWithUnits check8=NumberWithUnits(random,"hour"));
		CHECK_NOTHROW(NumberWithUnits check9=NumberWithUnits(random,"min"));
		CHECK_NOTHROW(NumberWithUnits check10=NumberWithUnits(random,"sec"));
		CHECK_NOTHROW(NumberWithUnits check11=NumberWithUnits(random,"USD"));
		CHECK_NOTHROW(NumberWithUnits check12=NumberWithUnits(random,"ILS"));
	}
}

TEST_CASE("Accounting operators"){
	//opertor + 
	CHECK((units1+units2)==NumberWithUnits{2.1,"km"});
	CHECK((units2+units1)==NumberWithUnits{2100,"m"});
	CHECK_THROWS(units1+units3);
	//opertor - 
	CHECK((units3-units4)==NumberWithUnits{120,"sec"});
	CHECK((units4-units3)==NumberWithUnits{-2,"m"});
	CHECK_THROWS(units4-units1);
	////////////////////////////
	//postfix & prefix
	// CHECK_EQ(units1++,2);
	// CHECK_EQ(++units1,4);
	// CHECK_EQ(units4++,4);
	// CHECK_EQ(++units1,6);
	CHECK(units1++ == NumberWithUnits{2,"km"});
	CHECK(++units1 == NumberWithUnits{4,"km"});
	//CHECK(units4++,4);
	//CHECK(++units1,6); 
	
	//opertor += & -= 
	CHECK((units5+=units6)==NumberWithUnits{6.66,"ILS"});
	CHECK((units6+=units5)==NumberWithUnits{3,"USD"});
	CHECK((units5-=units6)==NumberWithUnits{-3.33,"ILS"});
	CHECK((units6-=units5)==NumberWithUnits{4,"USD"});
	CHECK_THROWS(units5+=units1);
	CHECK_THROWS(units6-=units3);
}

TEST_CASE("Comparison operators"){
	CHECK(NumberWithUnits{2,"km"} > NumberWithUnits{1,"km"});
	CHECK(NumberWithUnits{0.5,"km"} < NumberWithUnits{1,"km"});//==true?
	CHECK(NumberWithUnits{2,"km"} > NumberWithUnits{1.5,"m"});
	CHECK(NumberWithUnits{17.3,"km"} >= NumberWithUnits{17,"km"});
	CHECK(NumberWithUnits{2,"km"} <= NumberWithUnits{2000,"m"});
	//CHECK(NumberWithUnits{3,"kg"} == NumberWithUnits{3000,"g"});
	//CHECK(NumberWithUnits{2,"min"} != NumberWithUnits{150,"sec"});
	//CHECK_THROWS((NumberWithUnits{2,"ILS"} != NumberWithUnits{150,"sec"}));
	//CHECK_THROWS((NumberWithUnits{2,"USD"} == NumberWithUnits{150,"ks"}));
}


// TEST_CASE("input and output"){
// 	   // Check input and output with stringstream
//      istringstream iss("2[km]");
//      iss >> units1;
//      cout << "NumberWithUnits units1 is: " << units1 << endl;

//      ostringstream oss;
//      oss << units1;
//      CHECK(oss.str() == "2[km]");
// }





