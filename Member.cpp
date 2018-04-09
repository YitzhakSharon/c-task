#include <iostream>
#include <map>
#include<iterator>
#include "Member.h"

using namespace std;

 static int id_member =0;
	

Member::Member(){
	id_member++;
	id=id_member;
}

void Member::follow(Member& other){
	if(this->id!=other.id){
	pair<int,Member*> ptr;
	map<int,Member*>::iterator find1;
	find1=followers.find(other.id);				    			


	if(find1 == followers.end()){
// insert other to my members of following
		ptr.first=other.id;
		ptr.second=&other;
		following.insert(ptr);//&

// insert this to other members of followers
		ptr.first=this ->id;
		ptr.second=this;

		other.followers.insert( ptr );

			}
	}
}

void Member::unfollow(Member& other){ 

	map<int,Member*>::iterator find1;
		// erase from the map that follow after other.
	find1=other.followers.find(this->id);
	//if(find1!= other.followers.end()){	
	other.followers.erase(find1);

		// erase from the map that follow after me.

	find1=following.find(other.id);
	following.erase(find1);
	
		//}
}	
int Member::  numFollowers(){
	return  followers.size();
}	
		
int Member:: numFollowing(){
	return following.size();
}

int Member:: count(){
	return id_member;}

Member:: ~Member(){
	id_member--;
	map<int,Member*>::iterator it;
	map<int,Member*>::iterator find1;

	for(it=following.begin(); it!=following.end();++it){
		find1=it->second->followers.find(this->id);
		it->second->followers.erase(find1);
		following.erase(it);

	}

	for(it=followers.begin(); it!=followers.end();++it){
		find1=it->second->following.find(this->id);
		it->second->following.erase(find1);
		followers.erase(it);

	}


}
	



