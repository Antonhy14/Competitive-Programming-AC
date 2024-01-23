#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define nl cout<<"\n"
#define sp(x,n) fixed<<setprecision(x) << n
#define all(x) x.begin(),x.end()
#define fore(i,l,r) for(auto i=l;i<r;i++)
#define pb push_back
#define pf push_front
/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/
enum{
    NACER,
    MORIR,
    PREGUNTAR,
}
struct Event{
    int persona;
    int type;
    int pos;
    int nacio = -1;
};
struct Respuestas{
  int total;
  int joven;
  int viejo;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<Event> events;
    
    fore(i,0,n) {
        int a,b;
        cin >> a >> b;
        
        events.pb({i, NACER, a});
        events.pb({i, MORIR, b});
    }
    fore(i,0,q) {
        int x;
        cin >> x;
        
        events.pb({i, PREGUNTAR, x});
    }
    sort(all(events), [&](Event a, Event b) {
       if(a.pos!=b.pos)
         return a.pos < b.pos;
        return a.type < b.type;
    });
    
    set<pair<int,int>> vivos;
    Respuestas ans[q];
    for(auto e: events) {
        if(e.type==NACER) {
            vivos.insert({e.nacio, e.persona});
        }
        else if(e.type==MORIR) {
            if(vivos.empty) ans[e.pos].total=ans[e.pos].joven=ans[e.pos].viejo=0;
            else {
                ans[e.pos].total = vivos.size();
                ans[e.pos].joven = vivos.rbegin()->first;
                ans[e.pos].viejo = vivos.begin()->first;
            }
        }
        else if(e.type==PREGUNTAR) {
            
        }
    }

    cout << "\n";
    
    return 0;
}
