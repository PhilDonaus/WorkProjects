#include <iostream>
#include <random>
#include <string>
#include <math.h>
#include <time.h>
#include "myHeaderFile.h"

using namespace std;

int main(){

	int seed = 0;
	srand(time(NULL));

	MonteCarloSim one;

	one.mu = .1;
	one.sig = 0.80;
	one.dt = .1;
	one.S1 = 10.0;
	one.RealS1 = 10.0;
	one.Value = 0;
	one.S2 = 0;

	one.sims = 100;

	cout<<"The final average: "<<one.computeSim(one.mu,one.sig,one.dt,one.S1,one.RealS1,one.Value,one.S2,one.sims) <<endl;


	MonteCarloSim opt;

	opt.mu = .1;
	opt.sig = 0.80;
	opt.dt = .1;
	opt.S1 = 10.0;
	opt.RealS1 = 10.0;
	opt.Value = 0;
	opt.S2 = 0;

	opt.sims = 100;


	cout<<"The Final Average Call Option Price: "<<opt.optionPrice(opt.mu, opt.sig, opt.dt, opt.S1,opt.S2,opt.sims)<<endl;
	
	cout<<endl;

	system("pause");
	return 0;

}