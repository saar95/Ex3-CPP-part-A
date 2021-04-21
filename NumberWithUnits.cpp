#include <limits.h>
#include <string>
#include <iostream>
#include "NumberWithUnits.hpp"
#include <cmath>
#include <fstream>

using namespace std;

namespace ariel {
        //static map<string,map <double,string>> map;
        static map<string, map<string,double> > my_map;

        ariel::NumberWithUnits::NumberWithUnits(double value, std::string type){
            this->m_value=value;
            this->m_type=type;
        }

        double convert(string from,string to,double value){
            if (from==to) {return value;}
            else
            {
                try
                {
                    if(my_map[from][to]==my_map[to][from])
                        return my_map[from][to]*value;
                }
                catch(const std::exception& e)
                {
                    cout << " cannot convert from " << from <<"to"<< to << endl;
                }
            }
            return 0;
        }
        
        void NumberWithUnits::read_units(ifstream& text_file){
            double value1,value2;
            string unit1,unit2,equal;
            while (text_file>>value1>>unit1>>equal>>value2>>unit2){
                my_map[unit1][unit2]=value2;
                my_map[unit2][unit1]=1/value2;
            }
        }

        /* Accounting operators */
        NumberWithUnits operator + (const NumberWithUnits& units1,const NumberWithUnits& units2){// x=(a+b) ->FRIND FUNCTION
            double value=convert(units2.m_type,units1.m_type,units2.m_value);
            value=value+units1.m_value;
            return NumberWithUnits{value,units1.m_type};
        } 
        NumberWithUnits operator - (const NumberWithUnits& units1,const NumberWithUnits& units2){// x=(a-b) ->FRIND FUNCTION
            double value=convert(units2.m_type,units1.m_type,units2.m_value);
            value=units1.m_value-value;
            return NumberWithUnits{value,units1.m_type};
        } 
        NumberWithUnits NumberWithUnits ::operator + () const{// x=|a| ->ONARY FUNCTION
            double value=abs(this->m_value);
            return NumberWithUnits{value,this->m_type};
            //this->m_value=value;
            //return *this;
        }   
        NumberWithUnits NumberWithUnits ::operator - () const{// x=-(a) ->ONARY FUNCTION
             double value=(-1)*(this->m_value);
            return NumberWithUnits{value,this->m_type};
        }   
        NumberWithUnits& NumberWithUnits ::operator += (const NumberWithUnits& units1){// a=a+b
            this->m_value+=units1.m_value;
            return *this;
        } 
        NumberWithUnits& NumberWithUnits ::operator -= (const NumberWithUnits& units1){// a=a-b
            this->m_value-=units1.m_value;
            return *this;
        } 

        /* Comparison operators */
        bool NumberWithUnits :: operator > (const NumberWithUnits& units1) const{ 
            double value=convert(units1.m_type,this->m_type,units1.m_value);
            return (this->m_value > value);
        }
        bool NumberWithUnits :: operator >= (const NumberWithUnits& units1) const{
            double value=convert(units1.m_type,this->m_type,units1.m_value);
            return (this->m_value >= value);
        }
        bool NumberWithUnits :: operator < (const NumberWithUnits& units1) const{
            double value=convert(units1.m_type,this->m_type,units1.m_value);
            return (this->m_value < value);
        }
        bool NumberWithUnits :: operator <= (const NumberWithUnits& units1) const{
            double value=convert(units1.m_type,this->m_type,units1.m_value);
            return (this->m_value <= value);
        }
        bool NumberWithUnits :: operator == (const NumberWithUnits& units1) const{
            double value=convert(units1.m_type,this->m_type,units1.m_value);
            return (this->m_value == value);
        }
        bool NumberWithUnits :: operator != (const NumberWithUnits& units1) const{
            return !(*this == units1);
        }

        //prefix and postfix
        NumberWithUnits& NumberWithUnits :: operator ++ (){
            return *this;
        }      // prefix  - ++a
		const NumberWithUnits NumberWithUnits :: operator ++ (int){
            return NumberWithUnits{0,"cm"};
        }   // postfix - a++
        NumberWithUnits& NumberWithUnits :: operator -- (){
            return *this;
        }      // prefix  - --a
		const NumberWithUnits  NumberWithUnits :: operator -- (int){
            return NumberWithUnits{0,"cm"};
        }   // postfix - a--

        /* Multiplication operator */
        NumberWithUnits operator * (double multi,NumberWithUnits& units1) {
            //double value= this->m_value*multi;
            //return NumberWithUnits{value,this->m_type};
            return units1;
        }
        NumberWithUnits& operator * (NumberWithUnits& units1,double multi) {
            //double value= this->m_value*multi;
            //return NumberWithUnits{value,this->m_type};
            return units1;
        }
        /* Input & Output operators */ //->FRIND FUNCTIONS
        ostream& operator <<(ostream& os,const NumberWithUnits& units){
            return os<<units.m_value<<"["<<units.m_type<<"]";
        } 
        istream& operator >>(istream& is,NumberWithUnits& units){
            string str;
            return is >> units.m_value >> str >> units.m_type;
        }  

        NumberWithUnits::~NumberWithUnits(){};
}

