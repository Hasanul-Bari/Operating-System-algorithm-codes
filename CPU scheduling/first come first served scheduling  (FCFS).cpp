#include<bits/stdc++.h>
using namespace std;

class process
{
public:
    int no,avt,bt,tt,wt,ft;
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
        p[i].no=i+1;
    }

    //cout<<"Enter CPU burts time of "<<n<<" processes : ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].bt;
    }

    sort(p,p+n,cmpAv);


    int sum_tt=0,sum_wt=0;

    for(int i=0; i<n; i++)
    {
        //finishing time
        if(i==0)
        {
            p[i].ft=p[i].avt+p[i].bt;
        }
        else
        {
            p[i].ft=p[i-1].ft+p[i].bt;
        }
        //cout<<p[i].ft<<endl;

        //turnaround time
        p[i].tt=p[i].ft-p[i].avt;
        //cout<<p[i].tt<<endl;

        sum_tt+=p[i].tt;


        //waiting time
        p[i].wt=p[i].tt-p[i].bt;
        cout<<p[i].wt<<endl;

        sum_wt+=p[i].wt;


    }



    sort(p,p+n,cmpSl);

    cout<<"Process ArrivalTime BurstTime FinishingTime TurnAroundTime Waiting Time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i].no<<"    "<<p[i].avt<<"    "<<p[i].bt<<"    "<<p[i].ft<<"    "<<p[i].tt<<"    "<<p[i].wt<<endl;
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


