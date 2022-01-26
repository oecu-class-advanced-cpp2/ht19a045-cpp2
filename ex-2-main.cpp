#include <iostream>
#include <string>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		int num = 0;
	public:
		mcxi(std::string strNum);

		mcxi(int a, int b) { num = a + b; };

		int getNum() { return num; };

		std::string to_string();
	};

	mcxi operator + (mcxi mcxi1, mcxi mcxi2)
	{
		mcxi dt(mcxi1.getNum(), mcxi2.getNum());
		return dt;
	}

	mcxi::mcxi(std::string strNum)
	{
		int memoNum = 0;
		int check[3] = { 0,0,0 };
		for (size_t index = 0; index < strNum.length(); index++)
		{
			switch (strNum[index])
			{
			case 'm':
				if (check[0] < 1)check[0] = 1;
				else check[0] = 999;

				if (0 == memoNum) num += 1000;
				else
				{
					num += memoNum * 1000;
					memoNum = 0;
				}
				check[2] = 0;
				break;
			case 'c':
				if (check[0] < 2) check[0] = 2;
				else check[0] = 999;

				if (0 == memoNum) num += 100;
				else
				{
					num += memoNum * 100;
					memoNum = 0;
				}
				check[2] = 0;
				break;
			case 'x':
				if (check[0] < 3) check[0] = 3;
				else check[0] = 999;

				if (0 == memoNum) num += 10;
				else
				{
					num += memoNum * 10;
					memoNum = 0;
				}
				check[2] = 0;
				break;
			case 'i':
				if (check[0] < 4) check[0] = 4;
				else check[0] = 999;

				if (0 == memoNum) num += 1;
				else num += memoNum;
				check[2] = 0;
				break;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				memoNum = strNum[index] - '0';
				check[2]++;
				break;
			default:
				check[1] = 999;
				break;
			}
			if (check[2] > 1) break;
		}
		if ((999 == check[0] || 999 == check[1]) || check[2] > 1) {
			std::cout << "入力値が正しくありません." << std::endl;
		}
	}

	std::string mcxi::to_string()
	{
		std::string str;
		int memoNum = num;
		int m = memoNum / 1000;
		if (m > 0)
		{
			if (m == 1) str += 'm';
			else
			{
				str += std::to_string(m);
				str += 'm';
			}
			memoNum = memoNum - (m * 1000);
		}
		int c = memoNum / 100;
		if (c > 0)
		{
			if (c == 1) str += 'c';
			else
			{
				str += std::to_string(c);
				str += 'c';
			}
			memoNum = memoNum - (c * 100);
		}
		int x = memoNum / 10;
		if (x > 0)
		{
			if (x == 1) str += 'x';
			else
			{
				str += std::to_string(x);
				str += 'x';
			}
			memoNum = memoNum - (x * 10);
		}
		if (memoNum > 0)
		{
			if (memoNum == 1) str += 'i';
			else
			{
				str += std::to_string(memoNum);
				str += 'i';
			}
		}
		return str;
	}

	bool result_test(const std::string result1, const std::string result2)
	{
		if (result1 == result2) return true;
		return false;
	}

	void mcxi_test(const std::string a, const std::string b, const std::string result)
	{
		cpp2::mcxi testA(a);
		cpp2::mcxi testB(b);
		cpp2::mcxi testResult = testA + testB;
		std::cout << std::boolalpha << result_test(result, testResult.to_string()) << std::endl;
	}
} // namespace cpp2
int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	cpp2::mcxi result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;
	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	cpp2::mcxi result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	cpp2::mcxi result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << " " << result2.getNum() << std::endl;
	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	cpp2::mcxi result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	cpp2::mcxi result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	cpp2::mcxi result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	cpp2::mcxi result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	cpp2::mcxi result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	cpp2::mcxi result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	cpp2::mcxi result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;

	cpp2::mcxi_test("xi", "x9i", "3x");
	cpp2::mcxi_test("i", "9i", "x");
	cpp2::mcxi_test("c2x2i", "4c8x8i", "6cx");
	cpp2::mcxi_test("m2ci", "4m7c9x8i", "5m9c9x9i");
	cpp2::mcxi_test("9c9x9i", "i", "m");
	cpp2::mcxi_test("i", "9m9c9x8i", "9m9c9x9i");
	cpp2::mcxi_test("9m8c7xi", "c2x8i", "9m9c9x9i");
	cpp2::mcxi_test("i", "m", "mi");
	cpp2::mcxi_test("m9i", "i", "mx");
	cpp2::mcxi_test("9m8c7xi", "c2x8i", "9m9c9x9i");

	cpp2::mcxi test1("abc");
	cpp2::mcxi test2("4mm8i");
	cpp2::mcxi test3("4m88i");

	return 0;
}
