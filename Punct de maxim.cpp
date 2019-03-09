#include <iostream>
#include <fstream >
#include <vector>
#include <algorithm>
using namespace std;

ifstream f("date.in");

int recursivitate(vector<int> v, int s, int d)
{
    if(s-d==0)
    return v[s];
    if(s-d==1)
     {
         if(v[s]>v[d])
         return v[s];
         else
         return v[d];
     }

    int piv=(s+d)/2;

    if(v[piv-1]<v[piv] && v[piv]<v[piv+1])
    return recursivitate(v,piv+1,d);
    else if(v[piv-1]<v[piv] && v[piv]>v[piv+1])
    return v[piv];
    else if(v[piv-1]>v[piv] && v[piv]>v[piv+1])
    return recursivitate(v,s,piv-1);


}
int testareSir(vector<int> v, int n)
{
    if(v[0]<v[1]) //sir crescator
    {for(int i=1;i<n-2;i++)
       if(v[i]>v[i+1]) return 1;
    }
    else
    for(int i=1;i<n-2;i++)
        if(v[i]<v[i+1]) return 1;
    return 0; // returneaza 0 daca este strict crescator sau descrescator

}
int main()
{
    int n,x;
    vector<int> v;
    f>>n;
    while(f>>x)
    {
        v.push_back(x);
    }
    if(testareSir(v,n)==1)
    cout<<recursivitate(v,0,n);
    else cout<<"Din pacate acest punct nu exista :(((";
    return 0;
}
