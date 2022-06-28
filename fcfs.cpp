#include<bits/stdc++.h>
using namespace std;

float ta_t_avg=0,w_t_avg=0;
struct gantt{
	int l,r,p;
};
class data{
	public:
	int p_no,a_t,b_t;
	int c_t,ta_t,w_t;	
	
	bool operator < (data obj) const{
		return a_t < obj.a_t;
	}
	
};
vector< data> vec,vec1;
vector <gantt> res;
int askNumber(){
	int r;
	cout<<"Enter the number of processess: ";
	cin>>r;
	return r;
}

void inputData(){
	int n=askNumber();
	cout<<"Enter the data in the given sequence:\nProcess No.\tArrival Time\tBurst Time"<<endl;
	
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		data d;
		d.p_no=a;d.a_t=b;d.b_t=c;
		vec.push_back(d);
	}
	sort(vec.begin(),vec.end());
	vec1=vec;
}
int checklogic_FCFS(){
	vector<data> q;
	for(int i=0;i<vec1.size();i++){
		
		if( res[res.size()-1].r >= vec1[i].a_t ){
			q.push_back(vec[i]);
		}
		else
			break;
	}
	if(q.size()==0)
		return 0;
	sort(q.begin(),q.end());
	return q[0].p_no;
}

int findIndex(int p){
	int f=0;
	for(int i=0;i<vec1.size();i++){
		if(vec1[i].p_no==p){
			f=i;
			break;	
		}
	}
	return f;
}



void solve(){
	gantt g;int x=0;
	if(res.size()==0){
		g.l=vec1[0].a_t;
		g.r=vec1[0].b_t+g.l;
		g.p=vec1[0].p_no;	
		res.push_back(g);
		vec1.erase(vec1.begin());
	}
	else{
		x=checklogic_FCFS();
		if( x==0 ){
			g.l=vec1[0].a_t;
			g.r=vec1[0].b_t+g.l;
			g.p=vec1[0].p_no;	
			res.push_back(g);
			vec1.erase(vec1.begin());
		}
		else{
			int i=findIndex(x);
			g.l=res[ res.size()-1].r;
			g.r=vec1[i].b_t+g.l;
			g.p=vec1[i].p_no;	
			res.push_back(g);
			vec1.erase(vec1.begin()+i);
		}
	}
	
	if(vec1.size()>0){
		solve();
	}
}
void display(){
	cout<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i].p<<" "<<res[i].l<<" "<<res[i].r<<endl;
	}
}

void sort_p_no(){
	int i, j; 
    for (i = 0; i < vec.size()-1; i++)     
    for (j = 0; j < vec.size()-i-1; j++) 
        if ( vec[j].p_no> vec[j+1].p_no)
        {
        	swap( vec[j].a_t,vec[j+1].a_t);
        	swap( vec[j].b_t,vec[j+1].b_t);
        	swap( vec[j].p_no,vec[j+1].p_no);
		}  
}

void assign(){
	for(int i=0;i<vec.size();i++){
		for(int j=res.size()-1;j>=0;j--){
			if( res[j].p==vec[i].p_no){
				vec[i].c_t=res[j].r;
				vec[i].ta_t=vec[i].c_t - vec[i].a_t;
				vec[i].w_t=vec[i].ta_t - vec[i].b_t;
				break;
			}
		}
	}
}

void displayfull(){
	cout<<endl;
	cout<<"P_No\tA_t\tB_t\tC_t\tTA_t\tW_t"<<endl;
	for(int i=0;i<vec.size();i++){
		cout<<vec[i].p_no<<"\t"<<vec[i].a_t<<"\t"<<vec[i].b_t<<"\t"<<vec[i].c_t<<"\t"<<vec[i].ta_t<<"\t"<<vec[i].w_t<<endl;
		ta_t_avg=ta_t_avg+vec[i].ta_t;
		w_t_avg=w_t_avg+vec[i].w_t;
	}
	ta_t_avg/=vec.size();
	w_t_avg/=vec.size();
	cout<<endl;
	cout<<"Turn Around Time Average: "<<ta_t_avg<<endl;
	cout<<"Waiting Time Average: "<<w_t_avg<<endl;
	cout<<endl;
}


int main(){
	cout<<"FIRST COME FIRST SERVE"<<endl<<endl;
	inputData()	;
	solve();
//	display();
	sort_p_no();
	assign();
	displayfull();
}

