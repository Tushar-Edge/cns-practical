#include<bits/stdc++.h>
using namespace std;

void encode_data(int db[])
{
	int encode[7];
    encode[0]=db[0];
    encode[1]=db[1];
    encode[2]=db[2];
    encode[4]=db[3];
   
    encode[6]=encode[4]^encode[2]^encode[0];       // p1--d3 d5 d7   exor operations gives even parity
    encode[5]=encode[4]^encode[1]^encode[0];       //p2--d3 d6 d7
    encode[3]=encode[2]^encode[1]^encode[0];       //p4--d5 d6 d7
    
    
    
    for(int j=0;j<7;j++)                        //printing encoded data
    {
        
        cout<<encode[j]<<" ";
        
    }
    cout<<" "<<endl;
	
	
	
}


void detection_correction(int rd[])
{
	
	int a=0,b=0,c=0;
	if(rd[6]!=rd[4]^rd[2]^rd[0] )  
	{
		a=1;
			
	}
	if(rd[5]!=rd[4]^rd[1]^rd[0])
	{
		b=1;
		
	}
	if(rd[3]!=rd[2]^rd[1]^rd[0])
	{
		c=1;
		
	}
	else
	{
		cout<<"no error";
		return ;
	}
	
	
	if(a==b && b==c)
	{
		cout<<"d7 bit is corrupted"<<"  "<<" position 0"<<endl;
	  	 rd[0]=rd[4]^rd[2]^rd[6];
		
	}
	else if(a==b)
	{
		
		cout<<"d3 bit is corrupted"<<"  "<<"position 4"<<endl;
		rd[4]=rd[5]^rd[2]^rd[0];
	}
	else if(b==c)
	{
		cout<<"d6 bit is coorrupted"<<"  "<<"position 1"<<endl;
		rd[1]=rd[4]^rd[5]^rd[0];
	}
	else if(a==c)
	{
		cout<<"d5 is corrupted"<<"  "<<"position 2"<<endl;
		rd[2]=rd[4]^rd[6]^rd[0];
	}
	
	cout<<"corrected bit stream"<<endl;
	for(int i=0;i<7;i++)
    {
    	cout<<rd[i];
	}
	
	
}

int main()
{
    //7 bit hamming
    
    int data_bits[4];
    cout<<"Enter the bits";
    for(int i=0;i<4;i++)            //we input data bits
    {
        cin>>data_bits[i];
        
    }
    cout<<"Data bits are";
    for(int i=0;i<4;i++)          //print data bits
    {
        cout<<data_bits[i]<<" ";
        
    }
    cout<<endl;
    
    cout<<"encoded data to be sent"<<endl;
    encode_data(data_bits);
    
    // 2nd part
	cout<<"Enter the recevied data"<<endl;
    int rd[7];
    for(int i=0;i<7;i++)
    {
    	cin>>rd[i];
	}
	
	detection_correction(rd);
	return 0;
	
    
    
}
