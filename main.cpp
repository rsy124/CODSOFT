#include<iostream>
using namespace std;
int main()
{
//Declaration of variables
float ans;
int num1,num2;
char choice;
//Initialization of variables
num1=num2=ans=0;
//Accept data
cout<<"Enter two numbers:";
cin>>num1>>num2;
//Display menu
cout<<"SIMPLE CALCULATOR"<<endl;
cout<<"1.Addition"<<endl;
cout<<"2.Subtraction"<<endl;
cout<<"3.Multiplication"<<endl;
cout<<"4.Division"<<endl;
cout<<"5.Modulus"<<endl;
cout<<"6.Exit"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>choice;
//calculating
switch(choice)
{
case'1':
ans=num1+num2;
cout<<"Addition:"<<ans<<endl;
break;
case '2':
ans=num1-num2;
cout<<"Subtraction:"<<ans<<endl;
break;
case'3':
ans=num1*num2;
cout<<"Multiplication:"<<ans;
break;
case'4':
ans=(float)num1/num2;
cout<<"Division:"<<ans<<endl;
break;
case'5':
ans=num1%num2;
cout<<"Modulus:"<<ans<<endl;
break;
case'6':
exit(0);
default:
cout<<"Wrong choice";
}
return 0;
}