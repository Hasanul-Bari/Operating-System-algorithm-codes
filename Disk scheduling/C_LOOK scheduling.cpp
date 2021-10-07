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

    int head;
    //cout<<"Enter the starting head position : ";
    cin>>head;


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


    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    int output[n], j=0, movement=0, curr_head=head;;


    for(int x : right)
    {
        movement=movement+abs(curr_head-x);
        output[j]=x;
        j++;
        curr_head=x;
    }

    for(int x : left)
    {
        movement=movement+abs(curr_head-x);
        output[j]=x;
        j++;
        curr_head=x;
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
53
*/

/*
8
176 79 34 60 92 11 41 114
50
*/



