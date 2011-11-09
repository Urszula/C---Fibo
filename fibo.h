#include <boost/dynamic_bitset.hpp>
#include <vector>


class Fibo {
	
	private:
		boost::dynamic_bitset<> number;
	public:
		static std::vector<unsigned long long> fibonacci_numbers;
		Fibo();
		Fibo(unsigned long long n);
		explicit Fibo(const std::string  &str);
		Fibo(const Fibo& anotherFibo);

		
};

Fibo& operator+ (Fibo const&, Fibo const&);
