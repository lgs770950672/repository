#include <iostream>
using namespace std;
int main()
{
  map<char *, char *>  m;
  map<char *, char *>::iterator mit;
  
  char *st = NULL;
  char *s1 = (char *)malloc(sizeof(char) * 10);
  char *s2 = (char *)malloc(sizeof(char) * 10);
  
  memcpy(s1, "key", 3);
  memcpy(s2, "value", 3);
  
  m.insert(s1, s2);
  
  for (mit = m.begin(); mit != m.end; /*mit++*/)
  {
  	
  	st = mit->first;
  	if (st)
  		free(st);
  	st = 0;
  
  	st = mit->second;
  	if (st)
  		free(st);
  	st = 0;
  
  	mit = m.erase(mit); //m.erase(mit++);		
  }
  m.clear();
  
  return 0;
}
