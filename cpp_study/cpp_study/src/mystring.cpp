#include "mystring.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
CMyString::CMyString() {
	m_pdata = (char*)malloc(sizeof(char));
	m_pdata[0] = '\0';
	std::cout << "this is constructed function default" << std::endl;
}
CMyString::CMyString(const char* pstr) {
	if (NULL == pstr) {
		m_pdata = (char*)malloc(sizeof(char));
		m_pdata[0] = '\0';
	}
	else {
		size_t str_len = strlen(pstr);
		m_pdata = (char*)malloc(str_len * sizeof(char) + 1);
		strncpy_s(m_pdata, str_len + 1, pstr, str_len);
	}
	std::cout << "this is constructed function with param" << std::endl;
}
CMyString::CMyString(const CMyString& objString) {
	size_t len = strlen(objString.m_pdata);
	m_pdata = (char*)malloc(len * sizeof(char)+1);
	strncpy_s(m_pdata, len+1, objString.m_pdata, len);
	std::cout << "this is copy constructed function" << std::endl;
}
CMyString::~CMyString() {
	//delete[] m_pdata;
	free(m_pdata);
	m_pdata = NULL;
	std::cout << "this is destructor" << std::endl;
}
CMyString& CMyString::operator =(const CMyString& objString) {
	free(m_pdata);
	char* tmptr = (char*)malloc(sizeof(char) * strlen(objString.m_pdata)+1);
	strncpy_s(tmptr, strlen(tmptr), objString.m_pdata, strlen(objString.m_pdata));
	m_pdata = tmptr;
	return *this;
}
CMyString& CMyString::operator +=(const CMyString& objString) {
	size_t iNewSize = strlen(objString.m_pdata) + strlen(this->m_pdata);
	char* tmptr = (char*)malloc(iNewSize * sizeof(char)+1);
	strncpy_s(tmptr, strlen(tmptr), m_pdata, strlen(m_pdata));
	strncat_s(tmptr, iNewSize+2, objString.m_pdata, strlen(objString.m_pdata));
	free(this->m_pdata);
	m_pdata = tmptr;
	return *this;
}
CMyString& CMyString::operator +(const CMyString& objString) {
	CMyString newstring;
	if (!this->m_pdata) {
		newstring = *this;
	}
	else if (!objString.m_pdata) {
		newstring = objString;
	}
	else {
		newstring.m_pdata = (char*)malloc((strlen(this->m_pdata) + strlen(objString.m_pdata)) * sizeof(char)+1);
		strncpy_s(m_pdata, strlen(m_pdata), this->m_pdata, strlen(this->m_pdata));
		strncat_s(m_pdata, strlen(m_pdata), objString.m_pdata, strlen(this->m_pdata));
	}
	return newstring;
}

