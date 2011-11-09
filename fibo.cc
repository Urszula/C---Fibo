#include <iostream>
#include "fibo.h"

Fibo::Fibo(){
	number.push_back(false);
}

void normalize(boost::dynamic_bitset<>  &fibonumber){
//TODO
}

void prepare_fibonacci_numbers(unsigned long long n){
	if (Fibo::fibonacci_numbers.empty()){
		Fibo::fibonacci_numbers.push_back(1);
		Fibo::fibonacci_numbers.push_back(2);
	}
	
	while (Fibo::fibonacci_numbers.back() < n)
		Fibo::fibonacci_numbers.push_back(
				Fibo::fibonacci_numbers.back() +
		                Fibo::fibonacci_numbers[Fibo::fibonacci_numbers.size() - 2]);
	
}

Fibo::Fibo(unsigned long long n){
	prepare_fibonacci_numbers(n);
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
