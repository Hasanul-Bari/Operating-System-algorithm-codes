#include<bits/stdc++.h>
using namespace std;

class request
{
public:
    int req_pos;
    bool isComplete;

};

int main()
{
    int n;
    //cout<<"Enter the size of the disk queue : ";
    cin>>n;

    request disk_queue[n];
    //cout<<"Enter the requests for cylinders : ";
    for(int i=0; i<n; i++)
    {
        cin>>disk_queue[i].req_pos;
        disk_queue[i].isComplete=false;
    }

    int head;
    //cout<<"Enter the starting head position : ";
    cin>>head;

    int output[n],j=0,cnt=0,curr_head=head, complete=0, movement=0;



    while(complete!=n)
    {
        int id=-1,mn_dst;

        for(int i=0; i<n; i++)
        {
            if(disk_queue[i].isComplete==false)
            {
                if(id==-1)
                {
                    mn_dst=abs(curr_head-disk_queue[i].req_pos);
                    id=i;
                }
                else if(mn_dst>abs(curr_head-disk_queue[i].req_pos))
                {
                    mn_dst=abs(curr_head-disk_queue[i].req_pos);
                    id=i;
                }

            }
        }

        //cout<<id<<" "<<disk_queue[id].req_pos<<endl;

        disk_queue[id].isComplete=true;
        complete++;
        movement=movement+mn_dst;


        output[j]=disk_queue[id].req_pos;
        curr_head=output[j];
        j++;

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
//236


/*
8
176 79 34 60 92 11 41 114
50
*/
//204



/*
8
64  12  42  19  62  32  16  86
25
*/
//87

