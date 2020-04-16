/*
 * MyException.h
 *
 *  Created on: 2020年4月16日
 *      Author: Zuokp
 */

#ifndef MYEXCEPTION_H_
#define MYEXCEPTION_H_
#include <exception>
#include <string>

class MyException: public std::exception
{
public:
	MyException(std::string const &message) : msg_(message) {}

	virtual char const* what() const noexcept {	return msg_.c_str();}

private:
	std::string msg_;
};
#endif /* MYEXCEPTION_H_ */
