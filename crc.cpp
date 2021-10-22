//find crc


#include <iostream>
using namespace std;
string Exor(string x, string y)
{
string ans = "";
int l = y.length();
for(int j = 1; j < l; j++)
{
if(x[j] == y[j])
ans += "0";
else
ans += "1";
}
return ans;
}
string division(string dividend, string divisor)
{
int n = divisor.length();
string subst = dividend.substr(0, n);
int l = dividend.length();
string zeros= "";
for(int i = 0; i < divisor.length(); i++)
zeros += "0";

for(int i = n; i < l; i++)
{
if(subst[0] == '1')
subst = Exor(divisor, subst) + dividend[n];
else
subst = Exor(zeros, subst) + dividend[n];
n++;
}
if(subst[0] == '1')
subst = Exor(divisor, subst);
else
subst = Exor(zeros, subst);

return subst;
}

void Encode(string Data, string key)
{
int key_l= key.length();

string zeros= "";
for(int i = 0; i < (key_l-1); i++)
{
zeros+= "0";
}
string newdata = Data + zeros; //concatenation

string remainder = division(newdata, key);

string encoded_data = Data + remainder;

cout << "Remainder : " << remainder << "\n";
cout << "Encoded Data (Data + Remainder) :"<< encoded_data << "\n";
}

int main()
{
string data_s;
string key;
cout << "Enter the data stream to be encoded(binary)";
cin >> data_s;
cout << "Enter the key(binary) ";
cin >> key;

Encode(data_s, key);

return 0;
}
