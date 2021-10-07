#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    //cout<<"Enter the size of the disk queue : ";
    cin>>n;

    int dq[n];
    //cout<<"Enter the request for cylinders : ";
    for(int i=0; i<n; i++)
    {
        cin>>dq[i];
    }

    int sz;
    //cout<<"Enter the size of the disk : ";
    cin>>sz;

    int head;
    //cout<<"Enter the starting head position : ";
    cin>>head;

    string dir;
    cout<<"Enter the direction of head movement (left or right) : ";
    cin>>dir;

    vector<int> left,right;

    for(int i=0; i<n; i++)
    {
        if(dq[i]<head)
        {
            left.push_back(dq[i]);
        }
        else if(dq[i]>head)
        {
            right.push_back(dq[i]);
        }
    }


    sort(left.begin(),left.end(), greater<int>());
    sort(right.begin(),right.end());

    int output[n], j=0, movement=0, curr_head=head;;


    if(dir=="left")
    {
        for(int x : left)
        {
            movement=movement+abs(curr_head-x);
            output[j]=x;
            j++;
            curr_head=x;
        }


        movement=movement+curr_head;
        curr_head=0;

        for(int x : right)
        {
            movement=movement+abs(curr_head-x);
            output[j]=x;
            j++;
            curr_head=x;
        }

    }
    else if(dir=="right")
    {
        for(int x : right)
        {
            //cout<<abs(curr_head-x)<<endl;
            movement=movement+abs(curr_head-x);
            output[j]=x;
            j++;
            curr_head=x;
        }

        //cout<<abs(curr_head-(sz-1))<<endl;

        movement=movement+abs(curr_head-(sz-1));
        curr_head=sz-1;

        for(int x : left)
        {
            //cout<<abs(curr_head-x)<<endl;
            movement=movement+abs(curr_head-x);
            output[j]=x;
            j++;
            curr_head=x;
        }
    }
    else
    {
        cout<<"Enter a correct Direction"<<endl;
        return 0;
    }




    cout<<"Total head movement "<<movement<<" cylinders"<<endl;
    cout<<"Order of service : "<<endl<<head;
    for(int i=0; i<n; i++)
    {
        cout<<" -> "<<output[i];
    }
    cout<<endl;




    return 0;
}

/*
8
98 183 37 122 14 124 65 67
200
53
*/

/*
8
176 79 34 60 92 11 41 114
200
50
*/

