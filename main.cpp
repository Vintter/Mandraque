#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#define LOCAL

using namespace std;
typedef std::unordered_map<string ,string> map;
typedef std::unordered_set<string> set,S;

using std::reverse;

int main() {

    map a,b;
    set geneA,geneB;
    uint_fast32_t A,B;
    string x,y,k;
    S SA,SB;

#ifdef LOCAL
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
#endif

    cin>>A>>B;

    for(int i=A;i>0;i--){
        cin>>x;
        a.insert(map::value_type(x,""));
    }

    for(int i=B;i>0;i--){
        cin>>x;
        string y (x.rbegin(), x.rend());
        b.insert(map::value_type(y,""));
    }

    map::const_iterator it = a.begin();
    while(it != a.end()){
        x = it->first;
        for(int i=0; i < x.length()-1;i++){
            y += x[i];
            if(a.contains(y)){
                for (int j=i+1; j<x.length(); j++){
                    k += x[j];
                }
                geneA.insert(k);
                k = "";
            }
        }
        y = "";
        it++;
    }

    it = b.begin();
    while(it != b.end()){
        x = it->first;
        for(int i=0; i < x.length()-1;i++){
            y += x[i];
            if(b.contains(y)){
                for (int j=i+1; j<x.length(); j++){
                    k += x[j];
                }
                string k2 (k.rbegin(), k.rend());
                geneB.insert(k2);
                k = "";
            }
        }
        y = "";
        it++;
    }

    it = a.begin();
    while(it != a.end()){
        x = it->first;
        for(int i=0; i < x.length()-1;i++){
            y += x[i];
            if(a.contains(y)){
                for (int j=i+1; j<x.length(); j++){
                    k += x[j];
                }
                if(geneB.contains(k)){
                    SA.insert(x);
                    SA.insert(y);
                }
                k = "";
            }
        }
        y = "";
        it++;
    }

    it = b.begin();
    while(it != b.end()){
        x = it->first;
        for(int i=0; i < x.length()-1;i++){
            y += x[i];
            if(b.contains(y)){
                for (int j=i+1; j<x.length(); j++){
                    k += x[j];
                }
                string k2 (k.rbegin(), k.rend());
                if(geneA.contains(k2)){
                    SB.insert(x);
                    SB.insert(y);
                }
                k = "";
            }
        }
        y = "";
        it++;
    }

    cout<<A-SA.size()<<' '<<B-SB.size()<<endl;

#ifdef LOCAL
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
#endif
    return 0;
}
