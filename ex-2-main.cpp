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
		int num;
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
		switch (strNum[0])
		{
		case 'm':
			num = 1000;
			break;
		case 'c':
			num = 100;
			break;
		case 'x':
			num = 10;
			break;
		case 'i':
			num = 1;
			break;
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			num = strNum[0] - '0';
			break;
		default:
			break;
		}
		for (const auto & str : strNum)
		{
			if (str == strNum[0]) continue;
			switch (str)
			{
			case 'm':
				num *= 1000;
				break;
			case 'c':
				num *= 100;
				break;
			case 'x':
				num *= 10;
				break;
			case 'i':
				if (num % 10 == 0) num += 1;
				else num *= 1;
				break;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				num += str - '0';
				break;
			default:
				break;
			}
		}
	}

	std::string mcxi::to_string()
	{
		return std::to_string(num);
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
	std::cout << "6cx" << " " << result2.to_string() << std::endl;
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

	return 0;
}
