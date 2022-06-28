#include<bits/stdc++.h>

using namespace std;

float ta_t_avg=0,w_t_avg=0;
int t_q;
struct gantt{
	int l,r,p;
};
class data{
	public:
	int p_no,a_t,b_t;	
	int c_t,ta_t,w_t;
	int q;
	
	bool operator < (data obj) const{
		return a_t < obj.a_t;
	}
	
};
vector< data> vec,vec1;
vector <gantt> res;
vector<int> q;
void display(){
	cout<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i].p<<" "<<res[i].l<<" "<<res[i].r<<endl;
	}
}


void inputData(){
	int n;
	cout<<"Enter the number of processess: ";
	cin>>n;
	cout<<"Enter the time quanta: ";
	cin>>t_q;
	cout<<"Enter the data in the given sequence:\nProcess No.\tArrival Time\tBurst Time\tQueue No."<<endl;
	
	for(int i=0;i<n;i++){
		int a,b,c,e;
		cin>>a>>b>>c>>e;
		data d;
		d.p_no=a;d.a_t=b;d.b_t=c;d.q=e;
		vec.push_back(d);
	}
	sort(vec.begin(),vec.end());
	vec1=vec;
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
int checkq(int p){
	for(int i=0;i<q.size();i++)
		if(p==q[i])
			return 1;
	return 0;
}
int checklogic_RBS(){
	
	for(int i=0;i<vec1.size();i++){
		
		if( res[res.size()-1].r >= vec1[i].a_t &&  !checkq(vec1[i].p_no) && vec1[i].p_no<=res[res.size()-1].p){	//find(q.begin(), q.end(), vec[i].p_no)==q.end()
			q.push_back(vec1[i].p_no);
		}
	}
	int x=q[0];
	q.erase(q.begin());
	if( vec1[findIndex(x)].b_t >0)
	q.push_back(x);
	if(vec1[findIndex(x)].b_t==0)
	vec1.erase(vec1.begin()+findIndex(x));
//	cout<<"\t"<<q.size()<<endl;
	if(q.size()==0)
		return -1;
	
	return q[0];
	
}

void solve(){
	gantt g;int x=0;
	if(res.size()==0){
		
		g.l=vec1[0].a_t;
		if( vec1[0].b_t <= t_q){
			g.r=g.l+vec1[0].b_t;
			vec1[0].b_t=0;
		}
		else{
			g.r=g.l+t_q;
			vec1[0].b_t=vec1[0].b_t-t_q;
			
		}
		g.p=vec1[0].p_no;	
		res.push_back(g);
		q.push_back(vec1[0].p_no);
		
		
	}
	else{
		x=checklogic_RBS();
		if( x==-1 ){
			g.l=vec[0].a_t;
			if( vec1[0].b_t <= t_q){
				g.r=g.l+vec1[0].b_t;
				vec1[0].b_t=0;
			}
			else{
				g.r=g.l+t_q;
				vec1[0].b_t=vec1[0].b_t-t_q;
				
			}
			g.p=vec1[0].p_no;
		//	q.push_back(vec1[0].p_no);	
			res.push_back(g);
			
			}
		else{
			int i=findIndex(x);
			g.l=res[ res.size()-1].r;
			if( vec1[i].b_t <= t_q){
				g.r=g.l+vec1[i].b_t;
				vec1[i].b_t=0;
			}
			else{
				g.r=g.l+t_q;
				vec1[i].b_t=vec1[i].b_t-t_q;
				
			}
			g.p=vec1[i].p_no;
			//q.push_back(vec1[0].p_no);		
			res.push_back(g);
			
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
        	swap( vec[j].a_t,vec[j+1].a_t);
        	swap( vec[j].b_t,vec[j+1].b_t);
        	swap( vec[j].p_no,vec[j+1].p_no);
		}  
}

void assign(int a[]){
	for(int i=0;i<vec.size();i++){
		for(int j=res.size()-1;j>=0;j--){
			if(res[j].p==res[j-1].p && j>0)
				continue;
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
	cout<<endl;
	cout<<"Turn Around Time: "<<ta_t_avg<<endl;
	cout<<"Waiting Time: "<<w_t_avg;
	ta_t_avg/=vec.size();
	w_t_avg/=vec.size();
	cout<<endl;
	cout<<"Turn Around Time Average: "<<ta_t_avg<<endl;
	cout<<"Waiting Time Average: "<<w_t_avg<<endl;
	cout<<endl;
}

int main(){
	cout<<"AVISHEK KUMAR\n20JE0221\n\n";
	cout<<"Multilevel Queue(MLQ)\n"<<endl<<endl;
	inputData()	;
	solve();
	//display();
	sort_p_no();
	assign();
	displayfull();
	
	
}
