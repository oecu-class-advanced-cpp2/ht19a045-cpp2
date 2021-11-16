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
bool is_prime(const unsigned n);
int main() {
	std::cout << "入力は空白(スペース)区切りでa d nの順に入力する" << std::endl;
	std::cout << "0 0 0の入力でプログラム終了" << std::endl;
	int a, b, c;
	// 入力は空白(スペース)区切りでa d nの順に入力する
	// 0 0 0の入力でプログラム終了
	for (;;) {
		std::cin >> a >> b >> c;
		if ((a == 0 && b == 0) && c == 0)
			break;
		std::cout << nth_prime(a, b, c) << std::endl;
	}
	// 以下、同様に、入出力例通りになるか確認せよ。
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
