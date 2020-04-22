/**
 * Exception class
 * A part of FamilyTree tast
 * Assists in throwing exception in an easy way
 * 
 * By bmitay4
 * 13-04-2020
 */

#ifndef _Exception_H
#define _Exception_H

#include <exception>
using namespace std;

class Exception : public std::exception {
   private:
    string itsMsg;

   public:
    Exception(const string& value) {
        itsMsg = value;
    }

    virtual const char* what() const noexcept override {
        return itsMsg.c_str();
    }
};

#endif