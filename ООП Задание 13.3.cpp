//Создайте множество (контейнер set) для хранения элементов типа Point (класс Point должен быть шаблонным!).
//Сохраните в этом множестве 5 элементов типа Point.Выведите элементы этого множества на экран.
//Найдите один из элементов множества.

#include <iostream>
#include <set>
using namespace std;

template<class T>
class Point
{
	T x;
	T y;
public:
	Point() {
		cout << "Введите координату точки по оси Х: ";
		cin >> x;
		cout << "Введите координату точки по оси Y: ";
		cin >> y;
	}
	Point(T a, T b) {
		x = a;
		y = b;
	}


	T getPointX() const{
		return x;
	}

	T getPointY() const{
		return y;
	}

	T setPointX(T a) {
		x = a;
		return x;
	}

	T setPointY(T b) {
		y = b;
		return y;
	}

	bool operator<(const Point<int>& point)const {
		if (x < point.x) {
			return true;
		}
		else if (x == point.x && y < point.y) {
			return true;
		}
		else return false;
		
	}
};

ostream& operator<<(ostream& os, const Point<int>& point) {
	os << "Координата Х: " << point.getPointX() << "\nКоордината У: " << point.getPointY() << endl;
	return os;
}
istream& operator>>(istream& is, Point<int>& point) {
	int a, b;
	is >> a >> b;
	point.setPointX(a);
	point.setPointY(b);
	return is;
}

int main()
{
	setlocale(LC_ALL, "ru");

	Point<int> A(22, 2);
	Point<int> B(0, 11);
	Point<int> C(1, 5);
	Point<int> D(33, 20);
	Point<int> E(1, 0);

	set<Point<int>> point;
	point.insert(A);
	point.insert(B);
	point.insert(C);
	point.insert(D);
	point.insert(E);

	set<Point<int>>::iterator it = point.begin();
	while (it != point.end()) {
		cout << *it << endl;
		it++;
	}

	cout << "\nПоиск необходимого элемента:\n";

	Point<int> P;
	cout << endl;

	it = point.find(P);
	if (it == point.end()) {
		cout << "Элемент не найден!\n" << P;
	}
	else {
		cout << "Элемент найден!\n" << *it << endl;
	}
}
