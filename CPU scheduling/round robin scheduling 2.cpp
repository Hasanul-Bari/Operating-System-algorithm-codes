#include<bits/stdc++.h>
using namespace std;

class process
{
public:
    int no,avt,bt,tt,wt,ft,rt,entryTime;
    bool isComplete,inQueue;
};

//class comparator
//{
//public:
//    bool operator()(process p1,process p2)
//    {
//        if(p1.entryTime==p2.entryTime)
//            return p1.no<p2.no;
//        else
//            return p1.entryTime<p2.entryTime;
//    }
//}

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
        p[i].rt=p[i].bt;
    }

    sort(p,p+n,cmpAv);

    int tq;
    cin>>tq;

    int complete=0,arriveCnt=0,tm=0,sum_tt=0,sum_wt=0;

    queue<process> process_que;

    while(complete!=n)
    {
        //check if any process has arrived before current time
        if(arriveCnt<n)
        {
            for(int i=0; i<n; i++)
            {
                if(p[i].inQueue==false && p[i].avt<=tm)
                {
                    process_que.push(p[i]);
                    p[i].inQueue=true;
                    arriveCnt++;
                }
            }
        }

        if(!process_que.empty())
        {
            process curr=process_que.front();
            process_que.pop();

            int mn=min(curr.rt,tq);

            curr.rt=curr.rt-mn;
            tm=tm+mn;

            if(curr.rt==0)
            {
                curr.ft=tm;

                //turnaround time
                curr.tt=curr.ft-curr.avt;
                //cout<<p[i].tt<<endl;

                sum_tt+=curr.tt;


                //waiting time
                curr.wt=curr.tt-curr.bt;
                //cout<<p[pr].wt<<endl;

                sum_wt+=curr.wt;

                curr.isComplete=true;

                complete++;
            }
            else
            {
                process_que.push(curr);
            }

        }
        else
            tm++;








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





