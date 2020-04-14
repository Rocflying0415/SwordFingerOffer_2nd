/*
 * CMyString.h
 *
 *  Created on: 2020年2月25日
 *      Author: Zuokp
 */

#ifndef CMYSTRING_H_
#define CMYSTRING_H_
#include <iostream>
#include <cstring>
#include <cstdlib>

class CMyString
{
	friend std::ostream& operator <<(std::ostream &out, const CMyString &str);
	friend std::istream& operator >>(std::istream &in, const CMyString &str);
public:
	CMyString();
	CMyString(const char *pData = nullptr);
	CMyString(const CMyString &str);
	CMyString(size_t n, char c);
	~CMyString();

	CMyString& operator +(const char *str);
	CMyString& operator +(const CMyString &str);
	CMyString& operator +=(const char *str);
	CMyString& operator +=(const CMyString &str);
	CMyString& operator =(const char *str);
	CMyString& operator =(const CMyString &str);
	inline char operator[](size_t index);

	bool operator ==(const char *str) const;
	bool operator ==(const CMyString &str) const;
	bool operator !=(const char *str) const;
	bool operator !=(const CMyString &str) const;

	bool operator >(const char *str) const;
	bool operator >(const CMyString &str) const;
	bool operator <(const char *str) const;
	bool operator <(const CMyString &str) const;

	inline const char* c_str();
private:
	char *m_pData;
};

#endif /* CMYSTRING_H_ */
