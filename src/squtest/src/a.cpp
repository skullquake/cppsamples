#include<iostream>
#include"./squtest.hpp"
int main(void){
	SQ::UTest t0("test0");
	t0.test("t0",1);
	t0.test("t1",0);
	t0.report();
};
