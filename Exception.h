#ifndef EXCEPTION_H
#define EXCEPTION_H
#include<iostream>
#include <exception>
using namespace std;
class Exception :public exception {
private:
	string message = "";
public:
	Exception(string message);
	virtual ~Exception() = default;
	const char* what() const noexcept override;

};


#endif // EXCEPTION_H

