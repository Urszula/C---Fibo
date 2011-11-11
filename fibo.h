#include <boost/dynamic_bitset.hpp>
#include <vector>


class Fibo {
	
	private:
		boost::dynamic_bitset<> number;
		static std::vector<unsigned long long> fibonacci_numbers;
	public:
		Fibo();
		Fibo(unsigned long long n);
		explicit Fibo(const std::string  &str);
		Fibo(const Fibo& anotherFibo);
		Fibo& operator= (Fibo const&);
		Fibo& operator+= (Fibo const&);
		Fibo& operator&= (Fibo const&);
		Fibo& operator|= (Fibo const&);
		Fibo& operator^= (Fibo const&);
		Fibo& operator<<= (unsigned int const);
};

Fibo& operator+ (Fibo const&, Fibo const&);
Fibo& operator& (Fibo const&, Fibo const&);
Fibo& operator| (Fibo const&, Fibo const&);
Fibo& operator^ (Fibo const&, Fibo const&);
Fibo& operator<< (Fibo const&, unsigned int const);
bool operator== (Fibo const&, Fibo const&);
bool operator< (Fibo const&, Fibo const&);
bool operator<= (Fibo const&, Fibo const&);
bool operator!= (Fibo const&, Fibo const&);
bool operator> (Fibo const&, Fibo const&);
bool operator>= (Fibo const&, Fibo const&);
