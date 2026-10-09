#include<iostream>
using namespace std;
int my_strlen(const char*s); 
char * my_strcpy(char *s,const char *d);
//ostream& operator<<(ostream &out, const STRING &s);
//istream& operator>>(istream&,STRING&);
using namespace std;
class STRING{
char *p;
public:
//friend int my_strlen(const char*s); 
//friend char * my_strcpy(char *s,const char *d);

STRING()//constructor
{
p=nullptr;
}

////parameter
STRING(const char *s)
{
int i=0;
p=new char[my_strlen(s)+1];
my_strcpy(p,s);
}

////copy
STRING(STRING &f)
{
p=new char[my_strlen(f.p)+1];
my_strcpy(p,f.p);
}
////assi
STRING& operator = ( const STRING&f);

////addd
STRING operator+( const STRING &f);

////////index
char& operator[](int index);

/////////
///comperision ===
bool operator ==(const STRING &s);


/////!=
bool operator !=(const STRING &s);


/////compertion(s1<s2)
bool operator <(const STRING&s);


////(s1<=s2)
bool operator <=(const STRING&s);


///s1>s2
bool operator >(const STRING&s);


//(s1>=s2)
bool operator >=(const STRING&s);


////////
void getdata(void );
~STRING()
{
if(p!=nullptr)
{
//cout<<"dis"<<endl;
delete [] p;
p=nullptr;
}
}

/////////////friend
friend int my_strlen(const char*s); 
friend char * my_strcpy(char *s,const char *d);
friend ostream& operator<<(ostream &out, const STRING &s);
friend istream& operator>>(istream&,STRING&);
friend int strlen(STRING &s);
friend void strcpy(STRING &,STRING &);
friend void strncpy(STRING &,STRING &,int);
friend int strcmp(STRING &,STRING &);
friend int strncmp(STRING &,STRING &,int);
friend void strcat(STRING &, STRING &);
friend void strncat( STRING &,  STRING &, int );
friend void strrev(STRING &);
friend void strlwr(STRING &);
friend void strupr(STRING &);
friend void strupr(STRING &);
friend char* strchr(STRING &,char);
friend char* strrchr(STRING &,char);
friend char* strstr(STRING &,const char *);
};
int strlen(STRING &s);
void strcpy(STRING &,STRING &);
void strncpy(STRING &,STRING &,int);
int strcmp(STRING &,STRING &);
int strncmp(STRING &,STRING &,int);
void strcat(STRING &, STRING &);
void strncat( STRING &,  STRING &, int );
void strrev(STRING &);
void strlwr(STRING &);
void strupr(STRING &);
char* strchr(STRING &,char);
char* strrchr(STRING &,const char);
char* strstr(STRING &,const char *);
