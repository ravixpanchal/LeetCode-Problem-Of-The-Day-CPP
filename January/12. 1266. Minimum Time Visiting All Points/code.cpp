#include<bits/stdc++.h>
using namespace std;

int getDistance(vector<vector<int>>&points){
    int totalTime=0;

    for(int i=0;i<points.size()-1;i++){
        int x1=points[i][0];
        int y1=points[i][1];

        int x2=points[i+1][0];
        int y2=points[i+1][1];

        int dx=abs(x1-x2);
        int dy=abs(y1-y2);

        totalTime+=max(dx,dy);
    }
    return totalTime;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<vector<int>>points;

    cout<<"Enter the points (x,y): ";

    for(int i=0;i<n;i++){
        int x,y;
        cout<<"point "<<i+1<<":";
        cin>>x>>y;
        points.push_back({x,y});
    }

    int ans=getDistance(points);

    cout<<ans<<endl;




    return 0;
}