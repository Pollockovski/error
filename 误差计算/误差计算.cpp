#include<iostream>
#include<vector>
#include<conio.h>
#include<iomanip>
using namespace std;
int kbh;

vector<string> ch = { "请输入有多少个数据:","请依次输入数据:" ,"是否考虑系统误差(Y/N):","按下任意键退出。","是否手动输入系统误差？(Y/N)","请输入系统误差:","请输入最大仪器误差:" ,"请输入保留几位小数:" };
vector<string> ru = { "Пожалуйста, введите, сколько данных:","Пожалуйста, вводите данные:" ,"Учитывать ли систематические ошибки(Y/N):","Нажмите любую клавишу для выхода.","Системная ошибка введена вручную?(Y/N)","Пожалуйста, введите системную ошибку:","Пожалуйста, введите максимальную погрешность прибора:" ,"Пожалуйста, введите сколько значащих цифр:" };
vector<string> lo;

void main()
{
	string dw = "kg";
	int num;
	char bl;
	double xavr, xsum, Sxavr;
	xsum = 0;
	Sxavr = 0;
	vector<double>x;
	vector<double>xxa;
	lo = ch;
	cout << lo[0];//输入有多少个数据
	cin >> num;
	x.resize(num);
	double Ssys;
	cout << lo[4];
	cin >> bl;
	if (bl == 'y' || bl == 'Y')
	{
		cout << lo[5];
		cin >> Ssys;
	}
	else {
		double D;
		cout << lo[6];
		cin >> D;
		Ssys = sqrt(D * D / 9 + D * D / 12);
	}
	int a;
	cout << lo[7];
	cin >> a;
	cout << "请输入单位:";
	cin >> dw;
	while (true) {
		xsum = 0;
		Sxavr = 0;
		xavr = 0;
		cout << "请依次输入数据:" << endl;
		for (int i = 0; i < x.size(); i++)
		{
			cin >> x[i];
			xsum += x[i];
		}
		xavr = xsum / num;
		for (int i = 0; i < x.size(); i++)
		{
			xxa.push_back(x[i] - xavr);
			Sxavr += xxa[i] * xxa[i];
		}
		if (num > 1)
		{
			Sxavr /= num * (num - 1);
		}
		Sxavr = sqrt(Sxavr);
		Sxavr = sqrt(Sxavr * Sxavr + Ssys * Ssys);
		cout << fixed << setprecision(a) << xavr << "±";
		cout << fixed << setprecision(a) << Sxavr << dw << endl;
		x.resize(0);
		xxa.resize(0);
		x.resize(num);
		cout << "按下任意键继续。按下C改变系统误差，数据数量和单位" << endl;
		while (true)
		{
			kbh = 0;
			if (_kbhit())
			{
				kbh = _getch();
				if (kbh == 99 || kbh == 97)
				{
					cout << lo[0];//输入有多少个数据
					cin >> num;
					x.resize(num);
					Ssys = 0;
					cout << lo[4];
					cin >> bl;
					if (bl == 'y' || bl == 'Y')
					{
						cout << lo[5];
						cin >> Ssys;
					}
					else {
						double D;
						cout << lo[6];
						cin >> D;
						Ssys = sqrt(D * D / 9 + D * D / 12);
					}
					cout << lo[7];
					cin >> a;
					cout << "请输入单位:";
					cin >> dw;
				}
				break;
			}
		}
	}
	cout << lo[3] << endl;
	while (true)
	{
		if (_kbhit())
		{
			break;
		}
	}
}