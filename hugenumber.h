#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<climits>

#define max(len1, len2) ((len1 > len2)?(len1):len2)
#define min(len1, len2) ((len1 < len2)?(len1):len2)

static long long sldecimal_precision = 16; // Ĭ�Ͼ���

static const unsigned int lsofintow[32] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800,
0x1000, 0x2000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000,
0x1000000, 0x2000000, 0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000
};



void intotwo(const std::string& strnum, int whichsys, std::string& answeroftwo);
unsigned long long getlen(std::string& twosysstr);


class hugeinteger {
private:
	unsigned long long length;
	bool ifpositive = true;
	std::vector<unsigned int> nums; //��λ��ǰ ��λ�ں�
public:
	hugeinteger();
	hugeinteger(const unsigned int num);
	hugeinteger(const int num);
	hugeinteger(const unsigned long long len);
	hugeinteger(const unsigned long long len, unsigned int n);
	hugeinteger(const hugeinteger& number);
	hugeinteger(const std::string& strnum);
	hugeinteger oppositenumber() const;
	hugeinteger abs() const;
	bool ispositive() const;
	hugeinteger operator+(const int& number) const;
	hugeinteger operator*(const unsigned int number) const;
	hugeinteger operator<<(const unsigned long long leftlen) const;
	hugeinteger operator>>(const unsigned long long rightlen) const;
	friend bool operator==(const hugeinteger& number, const hugeinteger& number2);
	friend bool operator!=(const hugeinteger& number, const hugeinteger& number2);
	friend bool operator>(const hugeinteger number, const hugeinteger& number2);
	friend bool operator>=(const hugeinteger& number, const hugeinteger& number2);
	friend bool operator<(const hugeinteger& number, const hugeinteger& number2);
	friend bool operator<=(const hugeinteger& number, const hugeinteger& number2);
	friend hugeinteger operator+(const hugeinteger& number, const hugeinteger& number2);
	friend hugeinteger operator-(const hugeinteger& number, const hugeinteger& number2);
	friend hugeinteger operator*(const hugeinteger& number, const hugeinteger& number2);
	friend hugeinteger operator/(const hugeinteger& number, const hugeinteger& number2);
	friend hugeinteger operator%(const hugeinteger& number, const hugeinteger& number2);
	void show();
	std::string output(int index = 10);
	unsigned int lastnumber();
	void delete0intop();
	unsigned long long  delete0inbottom();
	unsigned int getnuminposition(unsigned long long position) const;
};



class sldecimal  { // �ǳ�����С��
private:	
	hugeinteger integer;
	long long pointer; // С����λ��
	long long  precision = sldecimal_precision; // ����ֵ Ĭ��16
	void currectsetting(const std::string & strnum);
 public:
	void setprecision(unsigned long long pre);
	sldecimal();
	sldecimal(const std::string & strnum, unsigned long long numofdecimal);// ���ַ�����ʼ���� ָ��С����������
	sldecimal(const std::string & strnum);
	sldecimal(const hugeinteger& integer);
	sldecimal(const hugeinteger& integer, unsigned long long numofdecimal);// �ɴ�����ʼ�� ��ָ�����Ƽ�������С��λ��
	sldecimal(const sldecimal& slnum); 
	sldecimal(const sldecimal& slnum, unsigned long long numofdecimal); // ָ������ȵĿ���
	hugeinteger getinteger()const;
	sldecimal getdecimal()const;
	sldecimal oppositenumber() const;
	sldecimal abs() const;
	friend bool operator==(const sldecimal & number, const sldecimal & number1);// һ�㲻����������жϸ������Ƿ����
	friend bool operator!=(const sldecimal & number, const sldecimal & number1);
	friend bool operator>(const sldecimal & number, const sldecimal & number1); 
	friend bool operator>=(const sldecimal & number, const sldecimal & number1);
	friend bool operator<(const sldecimal & number, const sldecimal & number1);
	friend bool operator<=(const sldecimal & number, const sldecimal & number1);
	friend bool operator==(const sldecimal & number, const hugeinteger & number1);
	friend bool operator==(const hugeinteger & number, const sldecimal & number1);
	friend bool operator!=(const sldecimal & number, const hugeinteger & number1);
	friend bool operator!=(const hugeinteger & number, const sldecimal & number1);
	friend bool operator>(const sldecimal & number, const hugeinteger & number1);
	friend bool operator>(const hugeinteger & number, const sldecimal & number1);
	friend bool operator>=(const sldecimal & number, const hugeinteger & number1);
	friend bool operator>=(const hugeinteger & number, const sldecimal & number1);
	friend bool operator<(const sldecimal & number, const hugeinteger & number1);
	friend bool operator<(const hugeinteger & number, const sldecimal & number1);
	friend bool operator<=(const sldecimal & number, const hugeinteger & number1);
	friend bool operator<=(const hugeinteger & number, const sldecimal & number1);
	friend sldecimal operator+(const sldecimal & number, const sldecimal & number1);
	friend sldecimal operator-(const sldecimal & number, const sldecimal & number1);
	friend sldecimal operator*(const sldecimal & number, const sldecimal & number1);
	friend sldecimal operator/(const sldecimal & number, const sldecimal & number1);
	friend sldecimal operator+(const hugeinteger & number, const sldecimal & number1);
	friend sldecimal operator+(const sldecimal & number, const hugeinteger & number1);
	friend sldecimal operator-(const hugeinteger & number, const sldecimal & number1);
	friend sldecimal operator-(const sldecimal & number, const hugeinteger & number1);
	friend sldecimal operator*(const hugeinteger & number, const sldecimal & number1);
	friend sldecimal operator*(const sldecimal & number, const hugeinteger & number1);
	friend sldecimal operator/(const hugeinteger & number, const sldecimal & number1);
	friend sldecimal operator/(const sldecimal & number, const hugeinteger & number1);
	sldecimal operator<<(const unsigned long long leftlen) const;
	sldecimal operator>>(const unsigned long long rightlen) const;
	void delete0inbottom();
	std::string output(int index = 10);
	void show();

};
