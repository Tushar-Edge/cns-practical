// find ip class,subnet mask,first ip and last ip of the block
#include<bits/stdc++.h>
using namespace std;
int a[3];
void find_s(string s)
{
	
	int p=0;
	for(int i=0;i<3;i++)
	{
		a[i]=s.find('.',p+1);
		p=a[i];
	
	}

}
void check_ipclass(string s)
{
	 string sub=s.substr(0,3);
	 int t=stoi(sub);
	 string first_host;
	 string last_host;

    if(t>0 && t<127)
    {

        cout<<"class A"<<"  "<<"subnet mask is: 255.0.0.0"<<endl;
		first_host=s.substr(0,a[0]+1)+"0.0.0";
		last_host=s.substr(0,a[0]+1)+"255.255.255"; 
        cout<<"first ip of block:  "<<first_host<<endl;
        cout<<"last ip of block:  "<<last_host<<endl;
    }
		  
    else if(t>=128 && t<191)
    {
        cout<<"class B"<<"  "<<"subnet mask is  255.255.0.0"<<endl;;
        first_host=s.substr(0,a[1]+1)+"0.0";
		last_host=s.substr(0,a[1]+1)+"255.255"; 
		 cout<<"first ip of block:  "<<first_host<<endl;
        cout<<"last ip of block:  "<<last_host<<endl;
    }
    else if(t>=192 && t<=223)
    {
        cout<<"class C"<<"  "<<" subnet mask is  255.255.255.0"<<endl;;
        first_host=s.substr(0,a[2]+1)+"0";
		last_host=s.substr(0,a[2]+1)+"255"; 
		cout<<"first ip of block:  "<<first_host<<endl;
        cout<<"last ip of block:  "<<last_host<<endl;
    }
    else if(t>=224 && t<=239)
        cout<<"class D"<<"  "<<"subnet mask is 255.255.255.255"<<endl;
    else if(t>=240 && t<=255)
    	cout<<"class E"<<endl;
    else
    	cout<<"enter valid ip";
        
}
int main() {
    string ip;
    cout<<"Enter the ip address";
    cin>>ip;
    cout<<"Ip address:"<<ip<<endl;
    find_s(ip);
   	check_ipclass(ip);
    return 0;
}
