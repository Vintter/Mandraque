#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

//#define LOCAL

using namespace std;
typedef std::unordered_multimap<string,vector<string>> map;
typedef std::unordered_set<string> set;

int main() {

    set a,b;
    map mutation;
    uint_fast32_t A,B,m;
    string x,y;
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
        for(set::const_iterator it = a.begin(); it != a.end(); ++it){
            p[0] = *it;
            p[1] = x;
            y = *it + x;
            mutation.insert(map::value_type(y,p));
        }
    }

    for(map::const_iterator it = mutation.begin(); it != mutation.end(); ++it){
        if(mutation.count(it->first) > 1){
            a.erase(it->second[0]);
            b.erase(it->second[1]);
        }
    }

    cout<<a.size()<<" "<<b.size()<<endl;

#ifdef LOCAL
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds >(end - start).count() << std::endl;
#endif
    return 0;
}
