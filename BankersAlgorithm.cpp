#include<bits/stdc++.h>
using namespace std;
class Banker{
	public:
		int p;
		vector<int> m,n,o;
};
int main(){
	cout<<"Avishek Kumar"<<endl<<"20JE0221"<<endl;
	cout<<"Banker's Algorithm for Process Synchronization\n";
	cout<<"Enter the number of Instances required: ";
	int instances;cin>>instances;
	cout<<"Enter the number of process: ";
	int process;cin>>process;
	cout<<"Enter the number of available instances of each resources:  "<<endl;
	int avai[instances];
	for(int i=0;i<instances;i++)
		cin>>avai[i];
	vector<Banker> B(process);
	cout<<"Enter the details:"<<endl;
	for(int j=0;j<process;j++){
	    B[j].p=j+1;
		cout<<"Enter the Available Instances for Proceess "<<j+1<<" : ";
		for(int i=0;i<instances;i++){
			int x;cin>>x;
			B[j].m.push_back(x);
		}
		cout<<"Enter the Required Instances for Proceess "<<j+1<<" : ";
		for(int i=0;i<instances;i++){
			int x;cin>>x;
			B[j].n.push_back(x);
		}
		for(int i=0;i<instances;i++){
			int l=0;
			l=max(l,B[j].n[i] - B[j].m[i]);
			B[j].o.push_back(l);
		}
		
	}
	
	cout<<endl;
	cout<<"Process Number\tAvailable Resources\tRequired Resources\tNeeded Resources"<<endl;
	for(int i=0;i<process;i++){
		cout<<i+1<<"\t";
		for(int j=0;j<instances;j++){
			cout<<B[i].m[j]<<" ";
		}
		cout<<"\t";
		for(int j=0;j<instances;j++){
			cout<<B[i].n[j]<<" ";
		}
		cout<<"\t";
		for(int j=0;j<instances;j++){
			cout<<B[i].o[j]<<" ";
		}
		cout<<endl;
	}
	
	vector<int> seq;
	int sig=0;
	for(int i=0;i<B.size();i=(i+1)%B.size() ){
		int j=0,h=0;
		for(j=0;j<instances;j++){
			if( avai[j] < B[i].o[j] )
				break;
		}
		if( j==instances){
		    sig++;
			seq.push_back(B[i].p);
			for(int k=0;k<instances;k++){
				avai[k]+=B[i].m[k];
			}
			B.erase(B.begin()+i);
			h=1;
		}
		if(i==B.size() && B.size()>0){
		    if(sig>0)
		    {
		      i=0;sig=0;
		    }
		}
		if(B.size()==0)
		    break;
		if(h==1)
		    i--;
	}
	if(seq.size()==process)
	{
		cout<<"\nProcess Synchronization CAN be achieved by Banker's Algorithm\n";
		cout<<"Sequence of process: ";
		for(int i=0;i<seq.size();i++)	
			cout<<seq[i]<<" ";
		cout<<endl;
	}
	else
		cout<<"\nProcess Synchronization CANNOT be achieved by Banker's Algorithm\n";

	return 0;
}

