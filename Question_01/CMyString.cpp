/*
 * CMyString.cpp
 *
 *  Created on: 2019年12月9日
 *      Author: Zuokp
 */
#include "CMyString.h"

CMyString::CMyString(const char* pData)
{
	TEST;
	if (nullptr == pData)
	{
		m_pData = new char[1];
		if (nullptr != m_pData)
		{
			m_pData[0] = '\0';
		}
	}
	else
	{
		size_t len = strlen(pData);

		m_pData = new char[len + 1];
		if (nullptr != m_pData)
		{
			strcpy(m_pData, pData);
		}
	}
}

CMyString::CMyString(const CMyString& str)
{
	TEST;
	size_t len = strlen(str.m_pData);

	m_pData = new char[len + 1];
	if (nullptr != m_pData)
	{
		strcpy(m_pData, str.m_pData);
	}
}

CMyString::~CMyString()
{
	delete[] m_pData;
	m_pData = nullptr;
}

void CMyString::show() const
{
	std::cout << m_pData << std::endl;
}

CMyString& CMyString::operator=(const CMyString& str)
{
	TEST;
	if (this != &str)
	{
		CMyString strTemp(str);

		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}
