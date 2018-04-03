#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	int num;
	cin>>num;
	string str = "";
	int numt = num;
	while(numt-100>=0){
		str+="B";
		numt-=100;
	}
	while(numt-10>=0){
		str+="S";
		numt-=10;
	}
	for(int i=1;i<=numt;i++){
		switch(i){
			case 1:
				str+="1";
				break;
			case 2:
				str+="2";
				break;
			case 3:
				str+="3";
				break;
			case 4:
				str+="4";
				break;
			case 5:
				str+="5";
				break;
			case 6:
				str+="6";
				break;
			case 7:
				str+="7";
				break;
			case 8:
				str+="8";
				break;
			case 9:
				str+="9";
				break;
		}
	}
	cout<<str;
}
