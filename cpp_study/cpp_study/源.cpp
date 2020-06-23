#include "mystring.h"

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
		int str_len = strlen(pstr);
		m_pdata = (char*)malloc(str_len*sizeof(char));
		//m_pdata = new char[str_len + 1];
		strncpy(m_pdata, pstr, str_len);
		m_pdata[str_len] = '\0';
	}
	std::cout << "this is constructed function with param" << std::endl;
}
CMyString::CMyString(const CMyString& objString) {
	int len = strlen(objString.m_pdata);
	m_pdata = (char*)malloc(len*sizeof(char));
	strncpy(m_pdata, objString.m_pdata, len);
	m_pdata[len] = '\0';
	std::cout << "this is copy constructed function" << std::endl;
}
CMyString::~CMyString() {
	free(m_pdata);
	m_pdata = NULL;
	std::cout << "this is destructor" << std::endl;
}
CMyString& operator =(const CMyString& objString) {
	free(m_pdata);
	char* tmptr = malloc(sizeof(char) * strlen(objString.m_pdata));
	strncpy(tmptr, objString.m_pdata, strlen(objString.m_pdata));
	m_pdata = tmptr;
	return *this;
}
CMyString& CMyString::operator +=(const CMyString& objString) {
	size_t iNewSize = strlen(objString.m_pdata) + strlen(this->m_pdata);
	char* tmptr = malloc(iNewSize*sizeof(char));
	strncat(tmptr,this->m_pdata);
	strncat(tmptr, objString.m_pdata);
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
		newstring.m_pdata = malloc((strlen(this->m_pdata) + strlen(objString)) * sizeof(char));
		strncpy(m_pdata, this->m_pdata, strlen(this->m_pdata));
		strncat(m_pdata, objString.m_pdata, strlen(this->m_pdata));
	}
	return newstring;
}

