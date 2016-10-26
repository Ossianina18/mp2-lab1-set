// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) :BitField(mp)//
{
	MaxPower = mp;
}

TSet::TSet(const TSet &s) : BitField(s.BitField)//
{
	MaxPower = s.MaxPower;
}

TSet::TSet(const TBitField &bf) : BitField(bf)// 
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField() //TBitField
{
	TBitField result(BitField);
	return result;
}

int TSet::GetMaxPower(void) const // 
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // 
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // 
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // 
{
	BitField.ClrBit(Elem);
}

//

TSet& TSet::operator=(const TSet &s) // 
{
	BitField = s.BitField;
	MaxPower = s.GetMaxPower();
	return *this;
}

int TSet::operator==(const TSet &s) const // 
{
	return BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const // 
{
	return BitField != s.BitField;
}

TSet TSet::operator+(const TSet &s) // 
{
	TSet result(BitField | s.BitField);
	return result;
}

TSet TSet::operator+(const int Elem) // 
{
	if (Elem > BitField.GetLength())
	{
		throw ("Elem > Length");
	}
	TBitField temp(MaxPower);
	temp.SetBit(Elem);
	TSet result(BitField | temp);
	return result;
}

TSet TSet::operator-(const int Elem) // 
{
	if (Elem > BitField.GetLength())
	{
		throw ("Elem > Length");
	}
	TBitField temp(MaxPower);
	temp.SetBit(Elem);
	TSet result(BitField & temp);
	return result;
}

TSet TSet::operator*(const TSet &s) // 
{
	TSet result(BitField & s.BitField);
	return result;
}

TSet TSet::operator~(void) // 
{
	TSet result(~BitField);
	return result;
}

// 

istream &operator>>(istream &istr, TSet &s) // {s1,s2,s3}
{
	char c;
	printf("__Input set\n");
	printf("lenght of set = %i\n", s.GetMaxPower());
	for (int i = 0; i < s.GetMaxPower(); i++)
	{
		printf("set(%i) = ", i);
		istr >> c;
		if (c == '1') s.InsElem(i); else s.DelElem(i);
	}
	printf("end.\n\n");
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // 
{
	ostr << "__Print set" << endl;
	ostr << "lenght of set = " << s.GetMaxPower() << endl;
	for (int i = 0; i < s.GetMaxPower(); i++)
		ostr << "set(" << i << ")= " << s.IsMember(i) << endl;
	ostr << "end." << endl << endl;
	return ostr;
}