#pragma once
#include<complex>

using namespace std;

void FFT(complex<double>* x, int N) {


	complex<double>* odd = new complex<double>[N / 2];
	complex<double>* even = new complex<double>[N / 2];
	for (int i = 0; i < N / 2; i++) {
		even[i] = x[i * 2];
		odd[i] = x[i * 2 + 1];
	}



	if (N > 1)
	{
		FFT(even, N / 2);
		FFT(odd, N / 2);
	}



	for (int k = 0; k < N / 2; k++)
	{

		complex<double> t = exp(complex<double>(0, -2 * acos(-1) * k / N)) * odd[k];
		x[k] = even[k] + t;
		x[N / 2 + k] = even[k] - t;
	}

	delete[] odd;
	delete[] even;



}