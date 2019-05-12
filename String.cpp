#include "pch.h"
#include "String.h"

//================конструктора=================//



String::String() :
  len(0){
	value = null;
}

String::String(const char * v) {
	 len = strlen(v);
	value = new char[len + 1];
	for (int i = 0; i < len; i++) {
		value[i] = v[i];
	}

	value[len - 1] = '\0';
}

String::String(char * v) {

    len = strlen(v) ;
	value = new char[len+ 1];
	for (int i = 0; i < len; i++) {
		value[i] = v[i];
	}

	value[len] = '\0';
}

String::String(final String &str) {
	if (this->value != nullptr) {
		delete[] value;
	}

	len = strlen(str.value);
	value = new char[len + 1];

	for (int i = 0; i < len; i++)
		value[i] = str.value[i];

	value[len] = '\0';
}

//==================end========================//


//=================operators===================//
String& String::operator = (final String &str) {


	if (this->value != nullptr) {
		delete [] value;
	}
	//else {
	    len = strlen(str.value);
		value = new char[len+1];
           
		for (int i = 0; i < len; i++)
			value[i] = str.value[i];
		len -= 1;
		value[len] = '\0';
	//}
	
	return *this;
}

String& String::operator + (final String &str) {

	
	int lenght1 = strlen(value);
	int lenght2 = strlen(str.value);
	int newlen = lenght1 + lenght2 + 1;

	String nstr;
	nstr.value = new char[newlen];
	nstr.len = newlen;
	int mainIndex = 0;


	for (; mainIndex < lenght1; mainIndex++) {
		nstr.value[mainIndex] = value[mainIndex];
	}

	for (int i=0; i < lenght2;i++, mainIndex++) {
		nstr.value[mainIndex] = str.value[i];
	}
	newlen -= 1;
	nstr.value[newlen] = '\0';

	return nstr;
}


String& String::operator += (final String &str) {
    int lenght1 = strlen(value);
	int lenght2 = strlen(str.value);

	len = lenght1 + lenght2 ;
	char*temp = new char[lenght1+ 1];
    
	int mainIndex = 0;

	for (int i=0; i < lenght1; i++) {
		temp[i] = value[i];
	}
	delete [] value;
	value = new char[len];
	for (; mainIndex < lenght1;  mainIndex++) {
		value[mainIndex] =temp[mainIndex];

	}
    
	for(int i=0;i<lenght2;i++,mainIndex++)
		value[mainIndex] = str.value[i];
	len -= 1;
	value[len] = '\0';
	delete [] temp;
	return *this;
}

/*String& String::operator+(final char* str) {
	int lenght1 = strlen(value);
	int lenght2 = strlen(str);
	String newString;
	
	int newlen = lenght1 + lenght2 + 1;
	char*temp = new char[lenght1];
	newString.value = new char[newlen];
	int mainIndex = 0;

	for (int i = 0; i < lenght1; i++) {
		temp[i] = value[i];
	}
	delete[] value;
	value = new char[newlen];
	for (; mainIndex < lenght1; mainIndex++) {
		newString.value[mainIndex] = temp[mainIndex];

	}

	for (int i = 0; i < lenght2; i++, mainIndex++)
		newString.value[mainIndex] = str[i];

	newString.value[newlen - 1] = '\0';
	delete[] temp;
	return newString;
}*/

//==================end========================//

char* String::toString() {
	return value;
}

char String::charAt(int index) {
	return value[index];
}


String String::substring(int begin,int end) {
	int len = end - begin ;
	String s;
	s.value = new char[len+ 1];
	s.len = len;
	for (int i = begin,j=0; i < end;j++, i++) {
		s.value[j] = value[i];
	}
	s.value[len] = '\0';
	
	return s;
}

int String::length() {
	return len;
}

boolean String::equals(String &obj) {
	if (this->len != obj.len)
		return false;

	for (int i = 0; i < len; i++) {
		if (value[i] != obj.value[i])
			return false;
	}
	return true;
}

boolean String::equals(final char*obj) {
	int in = strlen(obj);
	if (this->len != in) {
		return false;
	}

	for (int i = 0; i < len; i++) {
		if (value[i] != obj[i])
			return false;
	}
	return true;
}

boolean String::equals(char*obj) {
	if (this->len != strlen(obj)) {
		return false;
	}
	for (int i = 0; i < len; i++) {
		if (value[i] != obj[i])
			return false;
	}
	return true;
}

boolean String::isEmpty() {
	return len == 0;
}


boolean String::conteins(String&str) {
	int count = 0;
	
	for (int j = 0, i = 0; i < len; i++) {

		if (str.length() == count)
			return true;
		if (value[i] == str.value[j]) {


			j++;
			count++;
			continue;
		}

		j = 0;
		count = 0;
	}
	return false;
}

boolean String::conteins(final char * str) {
	 int count = 0;
	 int l= strlen(str);
	for (int j = 0, i = 0; i < len; i++) {

            if (l == count)
				return true;
		if (value[i] == str[j]) {

			
			j++;
			count++;
			continue;
		}

		j = 0;
		count = 0;
	}
	return false;
}
String::~String()
{
	delete [] value;
}
