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
typedef std::unordered_set<string> set;
typedef std::unordered_multimap<string,vector<string>> map;
using std::reverse;

int main() {

    set a,b;
    map geneA,geneB;
    uint_fast32_t A,B;
    string x,y,z,w,k;
    vector<string> p(2);

#ifdef LOCAL
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
#endif

    cin>>A>>B;

    for(int i=A;i>0;i--){
        cin>>x;
        a.insert(set::value_type(x));
    }

    for(int i=B;i>0;i--){
        cin>>x;
        string y (x.rbegin(), x.rend());
        b.insert(set::value_type(y));
    }


    set::const_iterator it1 = a.begin();
    set::const_iterator it2 = b.begin();
    while(it1 != a.end() && it2 != b.end()){
        x = *it1;
        w = *it2;
        for(int i=0; i < x.length()-1 || i < w.length()-1 ; i++) {
            y += x[i];
            z += w[i];
            if(x.size()-1 > i && a.contains(y)){
                p[0] = x;
                p[1] = y;
                for (int j=i+1; j<x.length(); j++){
                    k += x[j];
                }
                geneA.insert(map::value_type(k,p));
            }
            k = "";
            if(w.size()-1 > i && b.contains(z)){
                p[0] = w;
                p[1] = z;
                for (int j=i+1; j<w.length(); j++){
                    k += w[j];
                }
                geneB.insert(map::value_type(k,p));
            }
        }
        y = "";
        z = "";
        it1++;
        it2++;
    }

    for(map::iterator i1 = geneA.begin();i1 != geneA.end(); ++i1){
        if(geneB.count(i1->first) > 0){
            map::iterator i2 = geneB.find(i1->first);
            a.erase(i1->second[0]);
            a.erase(i1->second[1]);
            b.erase(i2->second[0]);
            b.erase(i2->second[1]);
        }
    }

    cout<<a.size()<<' '<<b.size()<<endl;

#ifdef LOCAL
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds >(end - start).count() << std::endl;
#endif
    return 0;
}
