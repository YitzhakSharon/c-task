#include "Member.h"
#include "Member.cpp"
#include <iostream>
#include <map>
#include<iterator>
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

void test3 (){
	Member yitzhak, Gilad;
	Gilad.follow(yitzhak);
    int follow_number = yitzhak.numFollowing();
	Gilad.follow(yitzhak);

	if(yitzhak.numFollowing()!=follow_number  )
		cout<<"problem: Member can follow twice after one Member"<<endl;
	else
		cout<<"the function work sussesfull"<<endl;
}












Member avi, beni, chana;

void test1() {
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}

int main() {
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;

	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	test1();
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
	cout << Member::count() << endl; // 3

	return 0;
}