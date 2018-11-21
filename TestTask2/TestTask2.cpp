#include "stdafx.h"
#include <fstream>
#include <iostream> 
#include <vector>
#include <locale>
#include <list>
#include <algorithm>
using namespace std;

int FIND(vector<pair<string,string>> vec,string key,int n) 
{
	for (int i = 0; i < n; i++)
	{
		if (vec[i].first == key)
			return i;
	}
}

// ����������
bool comp(pair <string, list<string>>  a, pair <string, list<string>>  b)
{
	return a.first < b.first;
}

int main()
{

	// � �������� ��������� ������ ������ ������ (����), ��� ��� ��������, ��� � ������������ ����� ���� ��������� ����������� (������ 2)
	// ������ ������ � ���� ������� �������
	// ������� ������ 
	/*	8
		Stas X
		Artem X
		Sasha X
		Dima Stas
		Ivan Artem
		Kirill Artem
		Maksim Ivan */

	setlocale(LC_ALL, "Russian");
	int N;
	ifstream fin("Data.txt");
	fin >> N;
	vector < pair<string, list<string> >> Record(N); // ������ �������
	vector < pair<string, string>> Mans(N-1); 
	pair <string, string> Boss;
	// ������� ������������
	Boss.first = "X";
	Boss.second = "0";
	Mans.push_back(Boss);
	for (int i = 0; i < N-1; i++)
	{
		fin >> Mans[i].first;
		fin >> Mans[i].second;
	}
	fin.close();
	for (int i = 0; i < N; i++) 
	{
		Record[i].first = Mans[i].first;
		Record[i].second.push_back(Mans[i].second);
	}

	// ���������� ������
	for (int i = 0; i < N; i++)
	{
		string sought = Mans[i].second; // ��� ����������, �������� ����
		while (Record[i].second.back()!= "0")
		{
			int ind = FIND(Mans, sought, N);
			Record[i].second.push_back(Mans[ind].second);
			sought = Mans[ind].second;
		}
	}
	// ���������� ����������� �� �����
	sort(Record.begin(), Record.end(),comp);

	for (int i = 0; i < N-1; i++)
	{
		cout << Record[i].first << " " << Record[i].second.size()-1 << endl;
	}

    return 0;
}

