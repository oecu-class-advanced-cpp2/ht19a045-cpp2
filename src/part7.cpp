#include <iostream>
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n);

/* --------------------------------------------------------------- */
/*
* is_prime
*
* 与えられた正整数 n が素数ならtrue、素数でないならfalseを返す
*
*/
/* -------------------------------------------------------------- */
bool is_prime(const unsigned n);
int main() {
	std::cout << nth_prime(367, 186, 151) << " " << 92809 << std::endl;
	std::cout << nth_prime(179, 10, 203) << " " << 6709 << std::endl;
	std::cout << nth_prime(271, 37, 39) << " " << 12037 << std::endl;
	std::cout << nth_prime(103, 230, 1) << " " << 103 << std::endl;
	std::cout << nth_prime(27, 104, 185) << " " << 93523 << std::endl;
	std::cout << nth_prime(253, 50, 85) << " " << 14503 << std::endl;
	std::cout << nth_prime(1, 1, 1) << " " << 2 << std::endl;
	std::cout << nth_prime(9075, 337, 210) << " " << 899429 << std::endl;
	std::cout << nth_prime(307, 24, 79) << " " << 5107 << std::endl;
	std::cout << nth_prime(331, 221, 177) << " " << 412717 << std::endl;
	std::cout << nth_prime(259, 170, 40) << " " << 22699 << std::endl;
	std::cout << nth_prime(269, 58, 102) << " " << 25673 << std::endl;
	return 0;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n)
{
	std::vector<int> myArray;
	int counter = 0;
	for (int i = 0; i < CPP2_PRIME_UPPER_LIMIT; i++)
	{
		int num = a + (i * d);
		if (is_prime(num)) {
			myArray.push_back(num);
			counter++;
			if (counter == n)
				break;
		}
	}
	return myArray[n - 1];
}

bool is_prime(const unsigned n) {
	switch (n) {
	case 0:
	case 1: return false;
	case 2:
	case 3: return true;
	}

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (unsigned i = 5; i * i <= n; i += 6) {
		if (n % i == 0) return false; // (6の倍数)-1
		if (n % (i + 2) == 0) return false; // (6の倍数)+1
	}

	return true;
}
