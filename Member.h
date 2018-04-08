#pragma once
#include <iostream>
#include <map>
#include<iterator>

using namespace std;

class Member{
    public:
        map<int,Member*> following;
        map<int,Member*> followers;
        int id;
    public:
        Member();
        void follow(Member& other);
        void unfollow(Member& other);
        int  numFollowers();
        int numFollowing();
       static int count();
         ~Member();
};
