/**
 * The Interface Segregation Principle
 * Created by adamluissean on 13.06.16.
 */
#include <iostream>
#include <list>
using namespace std;

namespace bad {

//    the abstract class demonstrates a chaotic design. The design is chaotic as it seems to represent many things,
//    such as employee, address, and contact. One of the ways in which the preceding abstract class can be refactored is
//    by breaking the single interface into three separate interfaces

    struct IEmployee {
        virtual string getDoor() = 0;
        virtual string getStreet() = 0;
        virtual string getCity() = 0;
        virtual string getPinCode() = 0;
        virtual string getState() = 0;
        virtual string getCountry() = 0;
        virtual string getName() = 0;
        virtual string getTitle() = 0;
        virtual string getCountryDialCode() = 0;
        virtual string getContactNumber() = 0;

        virtual ~IEmployee() {

        }
    };
}
struct IAddress {
    string doorNo, street, city, pinCode, state, country;

    IAddress(const string &doorNo, const string &street, const string &city, const string &pinCode, const string &state,
             const string &country) : doorNo(doorNo), street(street), city(city), pinCode(pinCode), state(state),
                                      country(country) {}
    virtual string getAddress() = 0;
    virtual string getContactNumber() = 0;
    virtual ~IAddress() {

    }
};

struct IContact {
    string countryCode, mobileNumber;

    IContact(const string &countryCode, const string &mobileNumber) : countryCode(countryCode),
                                                                      mobileNumber(mobileNumber) {}
    virtual string getMobileNumber() = 0;

    virtual ~IContact() {

    }
};
struct IEmplyee {
    string firstname, middlename, lastname;
    string title;
    string employeeCode;

    list<IAddress> addresses;
    list<IContact> contacts;
};


int main() {


    getchar();
    return 0;
}