#include <iostream>
#include <map>
#include<iterator>
#include "Member.cpp"
#include "Member.h"
using namespace std;



void test_unfollow(){
	Member yitzhak,moshe,hadar;
	moshe.follow(yitzhak);
	hadar.follow(yitzhak);
	
	if(yitzhak.numFollowers()!=2){
		cout<<"error with the follow function"<<endl;
	}
	moshe.unfollow(yitzhak);
	if(yitzhak.numFollowers()!=1){
		cout<<"error with the unfollow function"<<endl;

	}
	hadar.unfollow(yitzhak);
	if(yitzhak.numFollowers()!=0){
		cout<<"error with the unfollow function"<<endl;
}
cout<<"the function work sussefuliy"<<endl;
}

void test_follow(){
	Member hadar, itzko,reut;
	hadar.follow(itzko);
	reut.follow(itzko);
	hadar.follow(reut);
	itzko.follow(hadar);
		// cout << "hadar - followers :" << hadar.numFollowers() << endl;
		// cout << "hadar - following :" << hadar.numFollowing() << endl;
		// cout << "reut - followers :" << reut.numFollowers() << endl;
		// cout << "reut - following :" << reut.numFollowing() << endl;
		// cout << "itzko - followers :" << itzko.numFollowers() << endl;
		// cout << "itzko - following " << itzko.numFollowing() << endl;
		

	if((hadar.numFollowing() != 2)&&(hadar.numFollowers() != 0)&&(reut.numFollowing() != 1)&&(reut.numFollowers() != 1)&&
	(itzko.numFollowing() != 0)&&(itzko.numFollowers() != 2)){
		cout << "error : follow function !" << endl;
		//exit(0);
	}
	else{
		cout << "success : follow function !" << endl;
	}
}

void test_follow_myself(){
    Member yitzhak;
    int follow_number = yitzhak.numFollowing();
    yitzhak.follow(yitzhak);
    if(yitzhak.numFollowing()!= follow_number){
        cout<<"there is problem with follow function"<<endl;
    }
	else cout<<" great! Member cant be following hemself"<<endl;
}
int main(){
	test_follow_myself();
	test_follow();
	test_unfollow();



	return 0;
}
