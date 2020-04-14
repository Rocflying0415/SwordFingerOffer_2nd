/*
 * CMyString.cpp
 *
 *  Created on: 2020年2月25日
 *      Author: Zuokp
 */

#include "CMyString.h"

CMyString::CMyString()
{
	m_pData = new char[1];
	if (nullptr != m_pData)
		m_pData[0] = '\0';
}

CMyString::CMyString(const char *pData)
{
	if (nullptr == pData)
	{
		m_pData = new char[1];
		if (nullptr != m_pData)
			m_pData[0] = '\0';
	}
	else
	{
		size_t length = strlen(pData);
		m_pData = new char[length + 1];
		if (nullptr != m_pData)
			strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString &str)
{
	size_t length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	if (nullptr != m_pData)
		strcpy(m_pData, str.m_pData);
}

CMyString::CMyString(size_t n, char c)
{
	m_pData = new char[n + 1];
	if (nullptr != m_pData)
	{
		memset(m_pData, c, n);
		m_pData[n] = '\0';
	}
}

CMyString::~CMyString()
{
	delete[] m_pData;
	m_pData = nullptr;
}

CMyString& CMyString::operator +(const char *str)
{
	if (nullptr != str)
	{
		size_t length = strlen(str);
		char *pTemp = new char[length + strlen(m_pData) + 1];
		if (nullptr != pTemp)
		{
			strcpy(pTemp, m_pData);
			strcat(pTemp, str);
			delete[] m_pData;
			m_pData = pTemp;
		}
	}
	return *this;
}

CMyString& CMyString::operator +(const CMyString &str)
{
	*this = *this + str.m_pData;
	return *this;
}

CMyString& CMyString::operator +=(const char *str)
{
	if (nullptr != str)
	{
		size_t length = strlen(str);
		char *pTemp = new char[length + strlen(m_pData) + 1];
		if (nullptr != pTemp)
		{
			strcpy(pTemp, m_pData);
			strcat(pTemp, str);
			delete[] m_pData;
			m_pData = pTemp;
		}
	}
	return *this;
}

CMyString& CMyString::operator +=(const CMyString &str)
{
	*this = *this + str.m_pData;
	return *this;
}

CMyString& CMyString::operator =(const char *str)
{
	if (nullptr != str)
	{
		CMyString strTemp(str);

		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

CMyString& CMyString::operator =(const CMyString &str)
{
	if (this != &str)
	{
		CMyString strTemp(str);

		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

char CMyString::operator[](size_t index)
{
	return m_pData[index];
}

bool CMyString::operator ==(const char *str) const
{
	if (0 != strcmp(m_pData, str))
		return false;
	return true;
}

bool CMyString::operator ==(const CMyString &str) const
{
	if (0 != strcmp(m_pData, str.m_pData))
		return false;
	return true;
}

bool CMyString::operator !=(const char *str) const
{
	return !(*this == str);
}

bool CMyString::operator !=(const CMyString &str) const
{
	return !(*this == str);
}

bool CMyString::operator >(const char *str) const
{
	if (1 == strcmp(m_pData, str))
		return true;
	return false;
}

bool CMyString::operator >(const CMyString &str) const
{
	if (1 == strcmp(m_pData, str.m_pData))
		return true;
	return false;
}

bool CMyString::operator <(const char *str) const
{
	if (-1 == strcmp(m_pData, str))
		return true;
	return false;
}

bool CMyString::operator <(const CMyString &str) const
{
	if (-1 == strcmp(m_pData, str.m_pData))
		return true;
	return false;
}

const char* CMyString::c_str()
{
	return m_pData;
}

std::ostream& operator <<(std::ostream &out, const CMyString &str)
{
	out << str.m_pData;
	return out;
}

std::istream& operator >>(std::istream &in, const CMyString &str)
{
	in >> str.m_pData;
	return in;
}
