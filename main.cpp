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
    map mutation;
    uint_fast32_t A,B;
    string x,y,z,w;
    vector<string> p(2);

#ifdef LOCAL
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
#endif

    cin>>A>>B;

    for(uint_fast16_t i=A;i>0;i--){
        cin>>x;
        a.insert(set::value_type(x));
    }

    for(uint_fast16_t i=B;i>0;i--){
        cin>>x;
        b.insert(set::value_type(x));
    }

   for(set::const_iterator it = a.begin();it != a.end(); ++it){
       x = *it;
       for(int i=0; i < x.length()-1; i++){
           y+=x[i];
           if (a.count(y) > 0) {
               for (int j=i+1; j<x.length(); j++){
                    z += x[j];
               }
               for(set::const_iterator it2 = b.begin();it2 != b.end(); ++it2){
                   w = z + *it2;
                   if (b.count(w) > 0) {
                       a.erase(x);
                       a.erase(y);
                       b.erase(*it2);
                       b.erase(w);
                   }
               }
           }
       }
   }
    cout<<a.size()<<' '<<b.size()<<endl;

#ifdef LOCAL
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds >(end - start).count() << std::endl;
#endif
    return 0;
}
