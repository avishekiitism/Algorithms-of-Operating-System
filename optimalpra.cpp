
#include <bits/stdc++.h>

using namespace std;
void display(vector<int> q){
    for(int i=0;i<q.size();i++){
        cout<<q[i]<<" ";
    }
}
int search_page(vector<int>q,int x){
    for(auto i: q)
        if(i==x)
            return 1;
    
    return 0;
}
int check(vector<int>q, vector<int> v,int z){
    vector<int> index(q.size(),INT_MAX);
    for(int i=0;i<q.size();i++){
        for(int j=z;j<v.size();j++){
            if( q[i]==v[j]){
                index[i]=j;
            }
        }
    }
    int res=-1,in=-1;
    for(int i=0;i<index.size();i++){
        if(res<= index[i]){
            res=index[i];
            in=i;
        }
    }
    return in;
}
void OPRA(vector<int> v, int total_frames){
    cout<<endl;
    vector<int> q;
    int hit=0;
    q.push_back(v[0]);
    cout<<"Insert "<<v[0]<<" : ";
    display(q);
    cout<<"   MISS"<<endl;
    for(int i=1;i<v.size();i++){
        cout<<"Insert "<<v[i]<<" : ";
        if( !search_page(q,v[i])){
            if(q.size() < total_frames ){
                q.push_back(v[i]);
            }
            else{
                int l=check(q,v,i+1);
                q.erase(q.begin()+l);
                q.push_back(v[i]);
            }
            display(q);
            cout<<"   MISS"<<endl;
        }
        else{
            hit++;
            display(q);    
            cout<<"   HIT"<<endl;
        }
        
    }
    cout<<endl<<"Page Hit: "<<hit<<endl;
    cout<<"Page Fault: "<<v.size()-hit<<endl;
    cout<<"Page Hit Ratio: "<<(float)hit*100/v.size()<<endl;
    cout<<"Page Fault Ratio: "<<(float)(v.size()-hit)*100/v.size()<<endl;
    
}

int main()
{   
    cout<<"Avishek Kumar"<<endl<<"20JE0221"<<endl;
    cout<<"Page Replacement Algorithm (PRA)"<<endl;
    cout<<"Optimal PRA"<<endl;
    cout<<"Enter the total number of Pages (>0) : ";
    int total_pages;cin>>total_pages;
    vector<int> v(total_pages);
    for(int i=0;i<total_pages;i++){
        cout<<"Enter the "<<i+1<<" Page Size : ";
        cin>>v[i];
        
    }
    cout<<"Enter the total number of frames: ";
    int total_frames;cin>>total_frames;
    
    OPRA(v,total_frames);
    
    

    return 0;
}
