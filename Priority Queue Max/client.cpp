#include <iostream>
#include "pqueue.h"
#include "realvector.h"


int main(){
	PQueue p;
	p.enqueue(3);
	p.enqueue(15);
	p.enqueue(5);
	p.enqueue(20);
	
	while(p.size() > 0)
		std::cout<<p.dequeueMax()<<std::endl;
	return 0;
}
