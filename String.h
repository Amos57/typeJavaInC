#pragma once
#define final const
#define null nullptr;

typedef bool boolean;
class String : public Object{

private:
	 char* value;
	 int len;

public:
	//operetors
      String& operator = (final String &str);
	  String& operator+(final String &str);
	//  String& operator+(final char* str);
	  String& operator+=(final String &str);
	 // std::ostream& operator<<(final String &str);
	//end

    //constructors
	  String();
	  String(char*);
	  String(const char*);
	  String(const String& str);
	//end
    

	//methods
	  char* toString();
	  char charAt(int index);
	  String substring(int begin,int end);
	  int length();
	  boolean equals(String &s);
	  boolean equals(const char* obj);
	  boolean equals(char* obj);
	  boolean isEmpty();
	  boolean conteins(String&);
	  boolean conteins(final char*);
	  
	//end 
	~String();
};

