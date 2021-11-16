#include <iostream>
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n);
bool is_prime(const unsigned n);
int main() {
	std::cout << "���͂͋�(�X�y�[�X)��؂��a d n�̏��ɓ��͂���" << std::endl;
	std::cout << "0 0 0�̓��͂Ńv���O�����I��" << std::endl;
	int a, b, c;
	// ���͂͋�(�X�y�[�X)��؂��a d n�̏��ɓ��͂���
	// 0 0 0�̓��͂Ńv���O�����I��
	for (;;) {
		std::cin >> a >> b >> c;
		if ((a == 0 && b == 0) && c == 0)
			break;
		std::cout << nth_prime(a, b, c) << std::endl;
	}
	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
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
		if (n % i == 0) return false; // (6�̔{��)-1
		if (n % (i + 2) == 0) return false; // (6�̔{��)+1
	}

	return true;
}
