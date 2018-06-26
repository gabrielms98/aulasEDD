#include <iostream>

using namespace std;

template<class KEY, class VALUE, class HASH>
class MyHashMap{
public:
  MyHashMap();
  void set(const KEY &k, const VALUE &v);


  int count(const KEY &k);
  int size() const;

private:

};
