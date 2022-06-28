#include<bits/stdc++.h>
using namespace std;

float ta_t_avg=0,w_t_avg=0;
struct gantt{
	int l,r,p;
};
class data{
	public:
	int p_no,a_t,b_t,pr;
	int c_t,ta_t,w_t;	
	
	bool operator < (data obj) const{
		return pr < obj.pr;
	}
	bool operator > (data obj) const{
		return pr > obj.pr;
	}
	
};
vector< data> vec,vec1;
vector <gantt> res;
int ch;

void display(){
	cout<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i].p<<" "<<res[i].l<<" "<<res[i].r<<endl;
	}
}
void bubbleSort() 
{ 
    int i, j; 
    for (i = 0; i < vec.size()-1; i++)     
    for (j = 0; j < vec.size()-i-1; j++) 
        if ( vec[j].a_t > vec[j+1].a_t)
        {
        	swap( vec[j].pr,vec[j+1].pr);
        	swap( vec[j].a_t,vec[j+1].a_t);
        	swap( vec[j].b_t,vec[j+1].b_t);
        	swap( vec[j].p_no,vec[j+1].p_no);
		}   
} 

void displayq( vector<data> v){
	cout<<endl;
	for(int i=0;i<v.size();i++)
		cout<<v[i].pr<<" "<<v[i].p_no<<" "<<v[i].a_t<<" "<<v[i].b_t<<endl;
	cout<<endl;
}
void inputData(){
	int n;
	cout<<"Enter the number of processess: ";
	cin>>n;
	cout<<"Enter the data in the given sequence:\nPriority No.\tProcess No.\tArrival Time\tBurst Time"<<endl;
	
	for(int i=0;i<n;i++){
		int l,a,b,c;
		cin>>l>>a>>b>>c;
		data d;
		d.pr=l;d.p_no=a;d.a_t=b;d.b_t=c;
		vec.push_back(d);
	}
	bubbleSort();
	vec1=vec;
//	displayq(vec1);
	cout<<"Priority Order:\n1.Higher Number Higher Priority\n2.Lower Number Higher Priority\n";
	cin>>ch;
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

int checklogic_SJF(){
	vector<data> q;
	for(int i=0;i<vec1.size();i++){
		
		if( res[res.size()-1].r >= vec1[i].a_t ){
			q.push_back(vec1[i]);
		}
	}
	if(q.size()==0)
		return 0;
	
	if(ch==1){
		sort(q.begin(),q.end(),greater<data>());
	}
	else{
		sort(q.begin(),q.end());
	}
	return q[0].p_no;
	
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
		x=checklogic_SJF();
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


void sort_p_no(){
	int i, j; 
    for (i = 0; i < vec.size()-1; i++)     
    for (j = 0; j < vec.size()-i-1; j++) 
        if ( vec[j].p_no> vec[j+1].p_no)
        {
        	swap( vec[j].pr,vec[j+1].pr);
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
	cout<<"Pr\tP_No\tA_t\tB_t\tC_t\tTA_t\tW_t"<<endl;
	for(int i=0;i<vec.size();i++){
		cout<<vec[i].pr<<"\t"<<vec[i].p_no<<"\t"<<vec[i].a_t<<"\t"<<vec[i].b_t<<"\t"<<vec[i].c_t<<"\t"<<vec[i].ta_t<<"\t"<<vec[i].w_t<<endl;
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
	cout<<"PRIORITY BASED SCHEDULING (non preemptive)"<<endl<<endl;
	inputData()	;
	solve();
//	display();
	sort_p_no();
	assign();
	displayfull();
}
