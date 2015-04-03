//文件名 21point.cpp
//21点游戏 

#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

float getcard(int array[],int choose);
void showcard(int array[],int choose);
void judage(float value1,float value2,int card1,int card2);

int main(){		
	int card[]={1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13};
	int m,n,c,d,e,f,card1,card2;char choice,decide;float value1,value2;
	while(decide=='y'){
	
	srand(time(NULL));	
	m=rand()*52/(RAND_MAX+1);
	do{
		n=rand()*52/(RAND_MAX+1);
	}while (m==n);
	
	value1=0;
	value2=0;
	
	cout<<"palyer turn"<<endl;
	
	value1+=getcard(card,m);
	showcard(card,m);
	value1+=getcard(card,n);
	showcard(card,n);
	value2+=getcard(card,d);
	value2+=getcard(card,e);
	card1=2;                                  //get card for player
	
	cout<<"do you want another card?"<<endl;
	cin>>choice;
	
	if (choice=='y'){
		do {
			c=rand()*52/(RAND_MAX+1);
		}while(c==m||c==n||c==d||c==e);
		value1+=getcard(card,c);
		showcard(card,c);
		card1++;
		if (value1>21){
			cout<<"player lose"<<endl;
	}
		else{
			cout<<"do you want another card?"<<endl;
			cin>>choice;
		}
	}
	
	cout<<"computer turn"<<endl;
	
	do{
		d=rand()*52/(RAND_MAX+1);
	}while (d==n||d==m);
	do{
		e=rand()*52/(RAND_MAX+1);
	}while (e==n||e==m||e==d);
	
	value2+=getcard(card,d);
	value2+=getcard(card,e);
	card2=2;												//get card for player
	
	while(value2<value1){
		do {
			f=rand()*52/(RAND_MAX+1);
		}while(f==m||f==n||f==d||f==e||f==c);
		value2+=getcard(card,f);
		card2++;                                            //judage another card or not?
	}
	
	judage(value1,value2,card1,card2);
	
	cout<<"do you want play again?"<<endl;
	cin>>choice;
	
	}
	return 0;
} 

void showcard(int array[ ],int choose)
{		
		int cardcolor,cardnumber;
	    cardcolor=choose%4;
		cardnumber=array[choose];
		
		switch(cardcolor){
        	case 0: cout << "heart ";break;
        	case 1: cout << "diamonds ";break;
        	case 2: cout << "spade ";break;
        	case 3: cout << "club ";}
		
		switch(cardnumber){
			case 1:cout<<"1";break;
			case 2:cout<<"2";break;
			case 3:cout<<"3";break;
			case 4:cout<<"4";break;
			case 5:cout<<"5";break;
			case 6:cout<<"6";break;
			case 7:cout<<"7";break;
			case 8:cout<<"8";break;
			case 9:cout<<"9";break;
			case 10:cout<<"10";break;
			case 11:cout<<"J";break;
			case 12:cout<<"Q";break;
			case 13:cout<<"K";
} 
}

float getcard(int array[ ],int choose)
{
		int cardnumber;float cardvalue; 
		cardnumber=array[choose];
		
		if (cardnumber>10){
			cardvalue=0.5;}
		else{
			cardvalue=cardnumber;}
		return cardvalue;
		}
		
void judage(float value1,float value2,int card1,int card2)
	{if (value2>value1){
		cout<<"computer win"<<endl;}
	 if (value1==value2){
	 	if(card1=card2){
	 		cout<<"play even"<<endl;}
	 	if(card1>card2){
	 		cout<<"computer win"<<endl;}
	 	if(card1<card2){
	 		cout<<"player win"<<endl;}}
	
	}
	

