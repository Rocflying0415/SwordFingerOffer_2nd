/*
 * CMyString.h
 *
 *  Created on: 2019年12月9日
 *      Author: Zuokp
 */

#ifndef CMYSTRING_H_
#define CMYSTRING_H_
#include <iostream>
#include <cstring>

#define TEST  std::cout << __func__ << ":[" << __LINE__ << "]" << std::endl

class CMyString
{
public:
	CMyString(const char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();
	void show() const;
	CMyString& operator=(const CMyString& str);
private:
	char* m_pData;
};
#endif /* CMYSTRING_H_ */
