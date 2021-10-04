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

    int movement=0;
    for(int i=0; i<n; i++)
    {
        movement=movement+abs(head-dq[i]);
        head=dq[i];
    }

    cout<<"Total head movement "<<movement<<" cylinders"<<endl;


    return 0;
}

/*
8
98 183 37 122 14 124 65 67
53
*/

/*
8
64  12  42  19  62  32  16  86
25
*/
