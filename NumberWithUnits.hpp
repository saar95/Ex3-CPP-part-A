#include <iostream>
#include <map>
#include <string>

namespace ariel {
    class NumberWithUnits{

    private:
        double m_value;
        std::string m_type;

    public:
        NumberWithUnits(double value, std::string type);
        // ariel::NumberWithUnits::NumberWithUnits(double value, std::string type){
        //     this->m_value=value;
        //     this->m_type=type;
        // }
        static void read_units(std::ifstream& units_type);

        /* Accounting operators */
        friend NumberWithUnits operator+(const NumberWithUnits& units1,const NumberWithUnits& units2);
        friend NumberWithUnits operator-(const NumberWithUnits& units1,const NumberWithUnits& units2);
        NumberWithUnits operator-() const;
        NumberWithUnits operator+() const;
        NumberWithUnits& operator+=(const NumberWithUnits& units2);
        NumberWithUnits& operator-=(const NumberWithUnits& units2);
        
        /* Multiplication operator */
        friend NumberWithUnits& operator*(NumberWithUnits& units1,double multi);
        friend NumberWithUnits operator*(double num, NumberWithUnits& units1);

        /* Prefix & Postfix */
        NumberWithUnits& operator++(); // prefix  - ++a
        NumberWithUnits& operator--(); // prefix  - --a
        const NumberWithUnits operator++(int); // postfix - a++
        const NumberWithUnits operator--(int); // postfix - a--

        /* Comparison operators */
        bool operator>(const NumberWithUnits& units1) const;
        bool operator>=(const NumberWithUnits& units1) const;
        bool operator<(const NumberWithUnits& units1) const;
        bool operator<=(const NumberWithUnits& units1) const;
        bool operator==(const NumberWithUnits& units1) const;
        bool operator!=(const NumberWithUnits& units1) const;

        /* Input & Output operators */
        friend std::ostream& operator<<(std::ostream& os, const NumberWithUnits& units1);
        friend std::istream& operator>>(std::istream& is, NumberWithUnits& units1);
        ~NumberWithUnits();
    };
}
