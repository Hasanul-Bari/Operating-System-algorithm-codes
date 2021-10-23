#include<bits/stdc++.h>
using namespace std;

class process
{
public:
    int no,avt,bt,tt,wt,ft,rt,entryTime,pr;
};

class comparator
{
public:
    bool operator()(process p1,process p2)
    {
        if(p1.entryTime==p2.entryTime)
        {
            if(p1.pr==p2.pr)
                return p1.no>p2.no;
            else
                return p1.pr>p2.pr;
        }

        else
            return p1.entryTime>p2.entryTime;
    }
};

bool cmpAv(process p1,process p2)
{
    return p1.avt<p2.avt;
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

    }
    //cout<<"Enter CPU burts time of "<<n<<" processes : ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].bt;
        p[i].rt=p[i].bt;
    }

    sort(p,p+n,cmpAv);

    int tq;
    cin>>tq;

    int tm=0,sum_tt=0,sum_wt=0;

    priority_queue<process, vector<process>,comparator> pq;

    for(int i=0; i<n; i++)
    {
        p[i].entryTime=p[i].avt;
        p[i].pr=0;
        pq.push(p[i]);
    }

    int i=0;

    while(!pq.empty())
    {
        process curr=pq.top();
        pq.pop();


        int mn=min(curr.rt,tq);

        curr.rt=curr.rt-mn;
        tm=tm+mn;

        cout<<curr.no+1<<" time: "<<tm<<endl;

        if(curr.rt==0)
        {
            curr.ft=tm;

            //cout<<tm<<" "<<curr.no<<" "<<curr.ft<<endl;

            curr.tt=curr.ft-curr.avt;

            sum_tt+=curr.tt;

            curr.wt=curr.tt-curr.bt;

            sum_wt+=curr.wt;

            p[i]=curr;
            i++;
        }
        else
        {
            curr.entryTime=tm;
            curr.pr=1;
            pq.push(curr);
        }
    }


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
3
*/


/*
5
4 0 8 2 6
3 5 2 5 5
2
*/

/*
5
4 0 8 2 6
3 5 2 8 7
3
*/

/*
5
0 5 1 6 8
8 2 7 3 5
3
*/
//wt=10  tt=15

/*
4
0 1 2 3
5 4 2 1
2
*/

/*
4
0 2 2 2
4 6 6 4
2
*/






