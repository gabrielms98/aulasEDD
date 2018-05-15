#include <iostream>

class IteratorRange;

class Range{
public:
  friend IteratorRange;
  typedef IteratorRange iterator;

	Range(int x_, int y_);

  //iterator begin() {return &intervalo[x-1];}
  //iterator end() {return &intervalo[y];}

	int x, y;
	int *intervalo;


};

class IteratorRange{
  friend class Range;
public:
  IteratorRange(Range &range_) : range(range_) {}

  int operator*() {return ;}


private:
  Range range;
};

//template<class T>
Range::Range(int x_, int y_){
	intervalo = new int[y_-1];
	for(int i=x_; i<=y_; i++){
		intervalo[i] = i;
	}
}
