class CMyString
{
public:
	CMyString( );
	CMyString(const char* pstr);
	CMyString(const CMyString& objString);
	CMyString& operator =(const CMyString& objString);
	CMyString& operator +=(const CMyString& objString);
	CMyString& operator +(const CMyString& objString);
	~CMyString();
private:
	char* m_pdata;
};
