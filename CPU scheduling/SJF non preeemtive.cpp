#include<bits/stdc++.h>
using namespace std;

class process
{
public:
    int no,avt,bt,tt,wt,ft;
    bool isComplete;
};

bool cmpAv(process p1,process p2)
{
    return p1.avt<p2.avt;
}

bool cmpSl(process p1,process p2)
{
    return p1.no<p2.no;
}






int main()
{
    int n;

    //cout<<"Enter number of processes : ";
    cin>>n;

    process p[n];

    //cout<<"Enter arrval time of "<<n<<" processes : ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].avt;
        p[i].no=i;
        p[i].isComplete=false;
    }

    //cout<<"Enter CPU burts time of "<<n<<" processes : ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].bt;
    }

    sort(p,p+n,cmpAv);

    int complete=0,tm=0,sum_tt=0,sum_wt=0;

    while(complete!=n)
    {
        //find currently available process with min burst time
        int mn, id=-1;
        for(int i=0; i<n; i++)
        {
            //cout<<p[i].isComplete<<" ** "<<p[i].no<<endl;
            if(p[i].isComplete==false && p[i].avt<=tm )
            {
                //cout<<"Enter\n";
                if(id==-1)
                {
                    mn=p[i].bt;
                    id=i;
                }
                else if(mn>p[i].bt)
                {
                    mn=p[i].bt;
                    id=i;
                }
            }
        }
        cout<<id<<endl;

        //if an incomplete process with min burst time found
        if(id!=-1)
        {
            //cout<<pr<<endl;
            tm=tm+p[id].bt;
            p[id].ft=tm;

            //turnaround time
            p[id].tt=p[id].ft-p[id].avt;
            //cout<<p[i].tt<<endl;

            sum_tt+=p[id].tt;


            //waiting time
            p[id].wt=p[id].tt-p[id].bt;
            //cout<<p[pr].wt<<endl;

            sum_wt+=p[id].wt;

            p[id].isComplete=true;

            complete++;

        }
        else
        {
            tm++;
        }


    }



    //sort(p,p+n,cmpSl);





    cout<<"Process ArrivalTime BurstTime FinishingTime TurnAroundTime Waiting Time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i].no+1<<"    "<<p[i].avt<<"    "<<p[i].bt<<"    "<<p[i].ft<<"    "<<p[i].tt<<"    "<<p[i].wt<<endl;
    }

    cout<<"Average turnaround time : "<<(float)sum_tt/float(n)<<endl;
    cout<<"Average waiting time : "<<(float)sum_wt/float(n)<<endl;

    return 0;
}

/*
5
2 0 4 1 3
9 3 11 2 7

*/


/*
5
4 0 8 2 6
3 5 2 5 5
*/

/*
5
4 0 8 2 6
3 5 2 8 7
*/



