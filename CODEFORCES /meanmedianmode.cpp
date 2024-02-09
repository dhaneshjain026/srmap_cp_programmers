#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double mean(vector<int> &a,int n)
{
  double sum = accumulate(begin(a), end(a), 0);
  double average = sum / n;
  return average;
}

double median(vector<int> &a,int n)
{
    double medians = a[n / 2];
    if (! (n & 1)) {
    medians += a[n / 2 - 1];
    medians /= 2;
   }
   return medians;
}

int mode(vector<int> &a,int n)
{
    sort(a.begin(), a.end()); 
    int max_count = 1, res = a[0], count = 1; 
    for (int i = 1; i < n; i++) { 
        if (a[i] == a[i - 1]) 
            count++; 
        else { 
            if (count > max_count) { 
                max_count = count; 
                res = a[i - 1]; 
            } 
            count = 1; 
        } 
    } 
  
    if (count > max_count) 
    { 
        max_count = count; 
        res = a[n - 1]; 
    } 
    return res;
}

double covariance(vector<int> &a,vector<int> &b,int n)
{
    double sum = 0;
    double mean_arr1 = mean(a, n);
    double mean_arr2 = mean(b, n);
    for (int i = 0; i < n; i++)
        sum = sum + (a[i] - mean_arr1) * (b[i] - mean_arr2);
    return sum / (n - 1);
}

float standarddeviation(vector<int> &a)
{
    
    float sum = 0.0, mean, sd = 0.0;

    int i;
    for(i = 0; i < a.size(); ++i)
    {
        sum = sum + a[i];  
    }
    int n = a.size();
    mean = sum/n;  
    for(i = 0; i < a.size(); ++i)
        sd = sd + pow(a[i] - mean, 2);  
    return sqrt(sd / n);
}


void solve(){
  int t;
  cin>>t;
  while(t--)
  {
       int n;
       cin >> n;
       vector<int> a(n),b(n);

       for (int i = 0; i < n; i++) {
          cin >> a[i];
       }
        
       for(int i=0;i<n;i++){
           cin>>b[i];
       }
       
       cout<<"Mean : "<<setprecision(2)<<fixed<<mean(a,n)<<"\n";
       cout<<"Median : "<<setprecision(2)<<fixed<<median(a,n)<<"\n";
       cout<<"Mode : "<<setprecision(2)<<fixed<<mode(a,n)<<"\n";
       cout<<"Covariance : "<<setprecision(2)<<fixed<<covariance(a,b,n)<<"\n";
       cout<<"Standarddeviation : "<<setprecision(2)<<fixed<<standarddeviation(a)<<"\n";
   }
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
