#include <iostream>
#include "fibo.h"

std::vector<unsigned long long> Fibo::fibonacci_numbers;

Fibo::Fibo(){
	number.push_back(false);
}



void normalize(boost::dynamic_bitset<> &fibonumber){
    boost::dynamic_bitset<> B = fibonumber;
    /* 
     * wynikiem dzialania ponizszego kodu
     * dla B.size()==0 jest 0 w postaci unormowanej
     * w przeciwnym razie jest to B w postaci unormowanej
     */
    if(B.any()) {
        B.push_back(false);
        B.push_back(false);
        B.push_back(false);
        B <<= 3;        
        int l = B.size();
        while(l>1) {
            int k = 0;
            int i = 0;
            while(i+2 < l) {
                if(!B.test(i) && B.test(i+1) && B.test(i+2)) {
                    B.set(i);
                    B.reset(i + 1);
                    B.reset(i + 2);
                    k = i;
                    i++;
                }
                i++;
            }
            l = k + 1;
        }
        size_t pierwsza_jedynka = B.find_first();
        B >>= pierwsza_jedynka;
        B.resize(B.size() - pierwsza_jedynka);
    } else {
        B.resize(1);
    }
    fibonumber = B;
}

void prepare_fibonacci_numbers(unsigned long long n, std::vector<unsigned long long>& fibonacci_numbers){
	
	if (fibonacci_numbers.empty()){
		fibonacci_numbers.push_back(1);
		fibonacci_numbers.push_back(2);
	}
	
	while (fibonacci_numbers.back() < n)
		fibonacci_numbers.push_back(
				fibonacci_numbers.back() +
		                fibonacci_numbers[fibonacci_numbers.size() - 2]);
	
}

Fibo::Fibo(unsigned long long n){
	prepare_fibonacci_numbers(n, Fibo::fibonacci_numbers);
	std::vector<unsigned long long>::reverse_iterator it = Fibo::fibonacci_numbers.rbegin();
	while (n>0 && it != Fibo::fibonacci_numbers.rend()){
		if (*it <= n ){
			number.push_back(true);
			n -= *it;
		} else {
			number.push_back(false);
		}
		++it;
	}
	normalize(number);
}

Fibo::Fibo(const std::string &str){
	for (size_t i=0; i< str.size();i++){
		if (str[i] == '1'){
			number.push_back(true);
		} else if (str[i] == '0') {
			number.push_back(false);
		} else {
			std::cerr << "Not fibonacci number";
			//TODO WYWALENIE
		}
	}
	normalize(number);
}

Fibo::Fibo(const Fibo& anotherFibo){
	//TODO
	number.push_back(0);
}

Fibo& Fibo::operator= (const Fibo& second){
	//TODO
	return *this;
}

Fibo& Fibo::operator+= (const Fibo& second){
	//TODO
	return *this;
}

Fibo& Fibo::operator&= (const Fibo& second){
	//TODO
	return *this;
}

Fibo& Fibo::operator|= (const Fibo& second){
	//TODO
	return *this;
}

Fibo& Fibo::operator^= (const Fibo& second){
	//TODO
	return *this;
}

Fibo& Fibo::operator<<= (const unsigned int number){
	//TODO
	return *this;
}
