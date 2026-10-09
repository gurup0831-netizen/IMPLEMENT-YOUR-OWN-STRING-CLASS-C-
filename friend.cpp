#include"header.h"
int my_strlen(const char*s)
{
int i=0;
while(*s)
{
i++;
s++;
}
return i;
}
///////////////
char * my_strcpy(char *s,const char *d){
int i=0,j;
for(i=0;s[i];i++);
for(j=0;d[j];j++,i++)
{
s[i]=d[j];
}
s[i]='\0';
return s;
}////
///assi
STRING& STRING::operator = ( const STRING&f)
{
    int l=my_strlen(f.p);
    delete []p;
    p=new char[l+1];
    my_strcpy(p,f.p);
    return *this;
    
}
///addd
STRING STRING::operator+( const STRING &f)
{
         int l1,l2,i,j;
         l1=my_strlen(p);
   l2=my_strlen(f.p);
   STRING temp;
   temp.p=new char[l1+l2+1];
   my_strcpy(temp.p,p);
   for( i=l1,j=0;f.p[j];j++,i++)
   temp.p[i]=f.p[j];
    temp.p[i]='\0';
   return temp;
}
////////index
char& STRING::operator[](int index)
{
return p[index];
}
///comperision ===
bool STRING::operator ==(const STRING &s)
{
    int i;
    for(i=0;p[i]&&s.p[i];i++)
    {
        if(p[i]!=s.p[i])
        return false;
    }
    return p[i]==s.p[i];
}
/////!=
bool STRING::operator !=(const STRING &s)
{
    int l=my_strlen(p),f=0,i,l2=my_strlen(s.p);
    if(l!=l2)
    return true;
    for(i=0;p[i]&&s.p[i];i++)
    {
        if(p[i]==s.p[i])
        f++;
    }
    if(l==f)
    return false;
    else
    return true;
}
/////compertion(s1<s2)
bool STRING::operator <(const STRING&s)
{
    int i;
    for(i=0;p[i]&&s.p[i];i++)
    {
        if(p[i]<s.p[i])
        return true;
        if(p[i]>s.p[i])
        return false;
    }
    return p[i]<s.p[i];
    
}
////(s1<=s2)
bool STRING::operator <=(const STRING&s)
{
    int i;
    for(i=0;p[i]&&s.p[i];i++)
    {
        if(p[i]<s.p[i])
        return true;
        if(p[i]>s.p[i])
        return false;
    }
    return p[i]<=s.p[i];
    
}
///s1>s2
bool STRING::operator >(const STRING&s)
{
    int i;
    for(i=0;p[i]&&s.p[i];i++)
    {
        if(p[i]>s.p[i])
        return true;
        if(p[i]<s.p[i])
        return false;
    }
    return p[i]>s.p[i];
    
}//
//(s1>=s2)
bool STRING::operator >=(const STRING&s)
{
    int i;
    for(i=0;p[i]&&s.p[i];i++)
    {
        if(p[i]>s.p[i])
        return true;
        if(p[i]<s.p[i])
        return false;
    }
    return p[i]>=s.p[i];
    
}
////////
void STRING::getdata(void)
{
cout<<p<<endl;
}//////////////
////////////////////////
ostream& operator<<(ostream &out, const STRING  &s)
    {
        out << s.p<<endl;
        return out;
    }
    
 ////////////
 istream& operator>>(istream&in,STRING&s){
    char temp[20];
    cout<<"enter new STRING"<<endl;
    cin.getline(temp,20);
    s.p=new char [my_strlen(temp)+1];
    my_strcpy(s.p,temp);
    return in;
} 
///////////////
//frined
int strlen(STRING &s)
{
 int len = 0;
  while (s.p[len] != '\0')
     len++;
    return len;
    }
 ///////////
void strcpy(STRING &d,STRING &s) 
{
int i=0;
i=my_strlen(s.p);
d.p=new char[i+1];
my_strcpy(d.p,s.p);
}  
 //////////////
 void strncpy(STRING &d,STRING &s,int n){
 d.p=new char[n+1];
 int i;
 for(i=0;i<n&&s.p[i];i++)
 d.p[i]=s.p[i];
 d.p[i]='\0';

 }   
int strcmp(STRING &s1,STRING &s2)
{
int i=0;
while(s1.p[i] && s2.p[i])
{
if(s1.p[i]!=s2.p[i])
return s1.p[i] - s2.p[i];
i++;
}
return s1.p[i]-s2.p[i];

}
int strncmp(STRING &s1,STRING &s2,int n)
{
int i=0;
while(i<n&&s1.p[i] && s2.p[i])
{
if(s1.p[i]!=s2.p[i])
return s1.p[i] - s2.p[i];
i++;
}
return s1.p[i]-s2.p[i];

}
/////////////
//strcat
void strcat(STRING &s2, STRING &s1)
{
int len1,len2,i=0,j=0;
len2=my_strlen(s2.p);
len1=my_strlen(s1.p);
/*cout<<len1<< " " <<len2<<endl;
for(j=len2,i=0;s1.p[i];j++,i++)
{
s2.p[j]=s1.p[i];
}
s2.p[j]='\0';*/
char *temp=new char [len1+len2+1];
if(len2>1){
while(s2.p[i])
{
temp[i]=s2.p[i];
i++;
}}
j=0;
while(s1.p[j])
{
temp[i]=s1.p[j];
i++;
j++;
}
temp[i]='\0';
if(len2>1)
delete [] s2.p;
s2.p=temp;
}
///////////strncat
void strncat( STRING &s2,  STRING &s1, int n)
    {
        int len1 = my_strlen(s2.p);
        int count = 0;
        while (s1.p[count] != '\0' && count < n)
            count++;
        char *temp = new char[len1 + count + 1];
        int i = 0;
        while (s2.p[i] != '\0')
        {
            temp[i] = s2.p[i];
            i++;
        }
        int j = 0;
        while (j < count)
        {
            temp[i] = s1.p[j];
            i++;
            j++;
        }
        temp[i] = '\0';
        delete[] s2.p;
        s2.p = temp;
    }
///////////strrev
void strrev(STRING &s){
int len=my_strlen(s.p);
int i=0,j=len-1;
char temp;
while(i<j)
{
temp=s.p[i];
s.p[i]=s.p[j];
s.p[j]=temp;
i++;
j--;
}
}
//////////strlwr
void strlwr(STRING &s){
int i=0;
while(s.p[i])
{
if(s.p[i]>='A' &&s.p[i]<='Z')
s.p[i]=s.p[i]+32;
i++;
}
}
/////////strupr
void strupr(STRING &s){
int i=0;
while(s.p[i])
{
if(s.p[i]>='a' &&s.p[i]<='z')
s.p[i]=s.p[i]-32;
i++;
}
}
/////////strchar
char* strchr(STRING &s,char m){
int i=0;
while(s.p[i])
{
if(s.p[i]==m)
return &s.p[i];
i++;
}
cout<<"char not found"<<endl;
return 0;

}
////////strrchar
char* strrchr(STRING &s,char m){
int i=0;
char *last=NULL;
while(s.p[i])
{
if(s.p[i]==m)
last=&s.p[i];
i++;
}
if(last==NULL)
cout<<"char not found"<<endl;
return last;
}
////////strstr
char* strstr(STRING &s,const char *sub)
{
int i=0,j;
for(i=0;s.p[i];i++)
{
for(j=0;sub[j];j++)
if(s.p[i+j]!=sub[j])
break;
if(sub[j]=='\0')
return &s.p[i];
}
cout<<"not found"<<endl;
return 0;
}
   
