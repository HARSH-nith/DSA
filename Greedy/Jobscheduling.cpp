
#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
    char id;
    int dead;
    int profit;
};

bool comp(Job &a,Job &b){
    return(a.dead<b.dead);
}
struct jobProfit {
    bool operator()(Job const& a, Job const& b)
    {
        return (a.profit < b.profit);
    }
};

void printJobScheduling(Job arr[],int n){
    
    vector<Job> result;
    sort(arr,arr+n,comp);
    

    priority_queue<Job,vector<Job>,jobProfit> pq;
    
    for(int i=n-1;i>=0;i--){
        int slots=-1;
        if(i==0){
            slots=arr[i].dead;
            
        }
        else{
            slots=arr[i].dead-arr[i-1].dead;
        }
        pq.push(arr[i]);
        
        
        while(slots>0 && pq.size()>0){
            Job job=pq.top();
            pq.pop();
            slots--;
            result.push_back(job);
        }
    }
    
    sort(result.begin(),result.end(),comp);
    for (int i = 0; i <result.size(); i++){
        cout << result[i].id << ' ';}
    cout << endl;
    
}


int main(){
    Job arr[] = { { 'a', 3, 100 },
                  { 'b', 1, 19 },
                  { 'c', 3, 27 },
                  { 'd', 1, 25 },
                  { 'e', 4, 15 } };
   
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
 
    
    printJobScheduling(arr, n);
    return 0;
}