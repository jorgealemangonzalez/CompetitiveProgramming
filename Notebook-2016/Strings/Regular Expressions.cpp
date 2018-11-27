#include <regex>
#include <iostream>
using namespace std;
int main ()
{
  if (regex_match("subject", regex("(sub)(.*)")))
    cout << "yes\n";
}