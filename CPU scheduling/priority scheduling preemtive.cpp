#include<bits/stdc++.h>
using namespace std;

class process
{
public:
    int no,avt,bt,tt,wt,ft,rt,pr;
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
        p[i].rt=p[i].bt;
    }
    //cout<<"Enter priority of "<<n<<" processes : ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i].pr;
    }

    sort(p,p+n,cmpAv);

    int complete=0,tm=0,sum_tt=0,sum_wt=0;

    while(complete!=n)
    {
        //find currently available process with higher priority=min number
        int mn, id=-1;
        for(int i=0; i<n; i++)
        {
            //cout<<p[i].isComplete<<" ** "<<p[i].no<<endl;
            if(p[i].isComplete==false && p[i].avt<=tm )
            {
                //cout<<"Enter\n";
                if(id==-1)
                {
                    mn=p[i].pr;
                    id=i;
                }
                else if(mn>p[i].pr)
                {
                    mn=p[i].pr;
                    id=i;
                }
            }
        }


        //if an incomplete process with min burst time found
        if(id!=-1)
        {
            //cout<<pr<<endl;
            p[id].rt--;
            tm++;
            if(p[id].rt==0)
            {
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

        }
        else
        {
            tm++;
        }


        cout<<p[id].no<<" ** "<<tm<<endl;


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
3 1 3 2 1

*/


/*
5
4 0 8 2 6
3 5 2 5 5
3 1 3 2 1
*/

/*
5
4 0 8 2 6
3 5 2 8 7
3 1 3 2 1
*/





