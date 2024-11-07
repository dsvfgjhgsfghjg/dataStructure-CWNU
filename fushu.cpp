#define  _CRT_SECURE_NO_WARNINGS //关闭报错
#include <iostream>
using namespace std;
#include <string>
#include <vector>


struct complex {
	double real;
	double imag;

	complex (double real = 0.0,double imag = 0.0) : real(real), imag(imag) {}

	void print() const {
		std::cout << "当前复数为：" << endl;
		if (real != 0||imag == 0) {
			std::cout << real;
		}
		if (imag != 0.0) {
			if (imag > 0) std::cout << "+";
			std::cout << imag << "i";
		}
		else if (imag < 0) {
			std::cout << imag << "i";
		}
		std::cout << std::endl;
	}
	void clear() {
		real = 0;
		imag = 0;
	}

	complex add(const std::vector<complex>& list, complex& sum) const {

		for (const auto& c : list) {
			sum.real += c.real;
			sum.imag += c.imag;
		}
		return sum;
	}

	complex sub(const std::vector<complex>& list, complex& sum) const {
		for (const auto& c : list) {
			sum.real -= c.real;
			sum.imag -= c.imag;
		}
		return sum;
	}

	complex mult(const complex& other) const {
		complex result;
		result.real = real * other.real - imag * other.imag;
		result.imag = real * other.imag + imag * other.real;
		return result;
	}

	complex div(const complex& other) {
		complex numerator;
		complex denominator;
		complex value;
		complex conjOtherComplex;
		value.real = real;
		value.imag = imag;
		conjOtherComplex.real = other.real;
		conjOtherComplex.imag = -(other.imag);
		//构造共轭复数
		numerator = value.mult(conjOtherComplex);
		denominator = other.mult(conjOtherComplex);
		if (denominator.real == 0.0 && denominator.imag == 0.0) {
			cout << "除数不为零";
			return value;
		}
		else {
			return numerator.mult(complex(1.0 / denominator.real, -denominator.imag / denominator.real));
		}
	}
};

int main() {
	complex sum = complex(0.0, 0.0);
	int flag = 1;
	// 打印标题

	cout << "******************************" << endl;
	cout << "  复数运算系统  " << endl;
	cout << "******************" << endl << endl;

	// 打印分隔线
	cout << "     Menu:        " << endl;
	cout << "------------------" << endl;

	// 打印菜单项
	vector<string> menuItems = { "【1】打印当前复数值", "【2】加法运算", "【3】减法运算", "【4】乘法运算","【5】除法运算","【6】清除数据","【7】退出系统"};
	for (const string& item : menuItems) {
		cout << "  " << item << endl;
	}

	// 底部装饰
	cout << "------------------" << endl;

	while (flag == 1) {

		int option;
		cout << "   Choose an option" << endl;
		if (scanf_s("%d", &option)==0) {
			cout << "错误的选项！" << endl;
		}
		switch (option)
		{
		case 1: {
			sum.print();
			break;
		}
			case 2:{
				std::vector<complex> complexList;
				int n;
				std::cout << "请输入复数的数量: ";
				std::cin >> n;

				for (int i = 0; i < n; ++i) {
					double real, imag;
					std::cout << "请输入第 " << (i + 1) << " 个复数的实部和虚部（用空格分隔）: ";
					std::cin >> real >> imag;

					complexList.push_back(complex(real, imag));
				}

				// 累加 complexList 中的复数到 sum
				sum = sum.add(complexList,sum);
				sum.print(); // 打印累加后的结果
				break;
			}
			case 3: {
				std::vector<complex> complexList;
				int n;
				std::cout << "请输入复数的数量: ";
				std::cin >> n;
				for (int i = 0; i < n; ++i) {
					double real, imag;
					std::cout << "请输入第 " << (i + 1) << " 个复数的实部和虚部（用空格分隔）: ";
					std::cin >> real >> imag;

					complexList.push_back(complex(real, imag));
				}
				sum = sum.sub(complexList, sum);
				sum.print();
				break;
			}
			case 4: {
				complex multiplies = complex(0.0, 0.0);
				double real, imag;

				std::cout << "请输入倍数（用空格隔开实虚部 如：1 0）: ";
				std::cin >> real >> imag;

				sum = sum.mult(complex(real,imag));
				sum.print();
				break;
			}
			case 5: {
				double real, imag;
				std::cout << "请输入除数（用空格隔开实虚部 如：1 0）: ";
				std::cin >> real >> imag;

				sum = sum.div(complex(real, imag));
				sum.print();
				break;
			}
			case 6: {
				sum.clear();
				sum.print();
				break;
			}
			case 7: {
				cout << "欢迎下次使用！" << endl;
				flag = 0;
				break;
			}
		default:
			cout << "错误的选项！" << endl;
			break;
		}
	}
}//
// Created by Orchi on 24-9-26.
//
