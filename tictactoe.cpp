#include<iostream>
#include<stdlib.h>
using namespace std;

void display(char matrix[])
{
	cout<<"     |     |     \n";
	cout<<"  "<<matrix[1]<<"  |  "<<matrix[2]<<"  |  "<<matrix[3]<<endl;
	cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  "<<matrix[4]<<"  |  "<<matrix[5]<<"  |  "<<matrix[6]<<endl;
	cout<<"_____|_____|_____\n";
	cout<<"     |     |    \n";
	cout<<"  "<<matrix[7]<<"  |  "<<matrix[8]<<"  |  "<<matrix[9]<<endl;
	cout<<"     |     |    \n";
}

bool won(char m[],bool &tie)
{
	//horizontally won
	if((m[1]=='X' && m[2]=='X' && m[3]=='X') || (m[1]=='O' && m[2]=='O' && m[3]=='O') )
	   return true;

	if((m[4]=='X' && m[5]=='X' && m[6]=='X') || (m[4]=='O' && m[5]=='O' && m[6]=='O') )
	   return true;

	if((m[7]=='X' && m[8]=='X' && m[9]=='X') || (m[7]=='O' && m[8]=='O' && m[9]=='O') )
	   return true;

	//vertically won
	if((m[1]=='X' && m[4]=='X' && m[7]=='X') || (m[1]=='O' && m[4]=='O' && m[7]=='O') )
	   return true;
	if((m[2]=='X' && m[5]=='X' && m[8]=='X') || (m[2]=='O' && m[5]=='O' && m[8]=='O') )
	   return true;
	if((m[3]=='X' && m[6]=='X' && m[9]=='X') || (m[3]=='O' && m[6]=='O' && m[9]=='O') )
	   return true;

	//diagonally won
	if((m[1]=='X' && m[5]=='X' && m[9]=='X') || (m[1]=='O' && m[5]=='O' && m[9]=='O') )
	   return true;
	if((m[7]=='X' && m[5]=='X' && m[3]=='X') || (m[7]=='O' && m[5]=='O' && m[3]=='O') )
	   return true;
	
	   
	
	for(int i=1;i<=9;i++)
	{
		if(m[i]!='X' && m[i]!='O')
		 	return false;
	}

		tie=true;
	   return true;
}




void chance(char m[],string n1,string n2,char &token, bool &tie)
{
	int digit;
	if(token=='X')
	{
		cout<<n1<<" please enter";
		cin>>digit;
	}
	else if(token=='O')
	{
		cout<<n2<<" please enter";
		cin>>digit;
	}
	if(digit>9 || digit<1)
	   cout<<"invalid !!!!";
	//cout<<m[digit]<<" "<<token<<endl;
	if(token=='X' && m[digit]=='0'+digit)
	{
		m[digit]=token;
		display(m);
		if(won(m,tie))
		   return;
		token='O';
	}
	
	else if(token=='O' && m[digit]=='0'+digit)
	{
		m[digit]=token;
		display(m);
		if(won(m,tie))
		   return;
		token='X';
	}
	else{
		cout<<"place already occupied"<<endl;
	}
    return chance(m,n1,n2,token,tie);
    
}

int main()
{
	char matrix[]={'0','1','2','3','4','5','6','7','8','9'};
	string n1;
	string n2;
	bool tie=false;
	char token='X';
	cout<<"enter the name of player1: ";
	cin>>n1;
	cout<<"enter the name of player2: ";
	cin>>n2;
	cout<<n1<<" plays with X"<<endl<<n2<<" plays with O"<<endl;
	display(matrix);
	//while(!won(matrix,tie))
	//{
	    chance(matrix,n1,n2,token,tie);
	//	display(matrix);
	//}
	
	if(token=='X' && tie==false)
	   cout<<n1<<" won!!";
	else if(token=='O' && tie==false)
	   cout<<n2<<" won!!";
	else
	   cout<<"it's a draw";
}
