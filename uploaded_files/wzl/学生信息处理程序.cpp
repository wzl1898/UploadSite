#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;
class Student 
{
	private:
		double score1;
		double score2;
		double score3;
		double score4;
		char c;
		double average;
		char name[21];
		int age;
		int number;
	public:
		void input(void);
		void output(void);
		void calculate(void);
};
void Student::input(void)
{
	cin.getline(name, 21, ',');
	cin >> age >> c >> number >> c >> score1 >> c >> score2 >> c >> score3 >> c >> score4;
}
void Student::calculate(void)
{
	average = (score1 + score2 + score3 + score4) / 4;
}
void Student::output(void)
{
	cout << name << "," << age << "," << number << "," << average;
}
int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
