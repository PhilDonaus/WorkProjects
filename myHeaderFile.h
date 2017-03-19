#include <iostream>
#include <random>
using namespace std;

class Gaussian
{
public:

	void init();

	double gaussian_box_muller() {
		double x = 0.0;
		double y = 0.0;
		double euclid_sq = 0.0;
		do{
		x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
		y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
		euclid_sq = x*x + y*y;
		}
		while (euclid_sq >= 1.0);
		return x*sqrt(-2*log(euclid_sq)/euclid_sq);
	}
};


class MonteCarloSim : public Gaussian
{
public:

	void init();

	double mu;
	double sig;
	double dt;
	double S1;
	double RealS1;
	double Value;
	double S2;

	int sims;
	
public:

	double computeSim(double mu, double sig, double dt, double S1, double RealS1, double Value, double S2, int sims)//Returns the Average Final Value
	{
		for(int i = 0; i < sims; i++){
			S1 = RealS1;
			for (int j = 0; j<10; j++){
				S2 = S1 + S1*mu*dt +  S1* sig * gaussian_box_muller();
				cout<<S2<<endl;
			}
			Value =  Value +  S2;
		}
	return Value/sims;
	}

	double optionPrice(double mu, double sig, double dt, double S1, double S2, double sims)
	{
		double Value = 0;
		for(int i = 0; i < sims; i++){
			S1 = RealS1;
			for (int j = 0; j<10; j++){
				S2 = S1*exp((mu - (0.5*(sig*sig)))*dt + sig*sqrt(dt)*gaussian_box_muller());
			}
			Value = Value + S2;
		}
		return (Value/sims)*exp(-1*mu*dt);
	}

};



