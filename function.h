
#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <graphics.h>
using namespace std;
void main_menu();
void extra_menu();
void output_range(int decimal, int r);
void output_interval(int decimal, double a, double b, int count);
void output_solution(int decimal, double x, int count );
void export_range(int decimal, double r, string filename);
void export_interval(int decimal, double a, double b, string filename, int count);
void export_solution(int decimal, double x, int count, ofstream& outfile );

void read_file(string filename);
void delete_file(string filename);
double fx(vector<double>& a , double x);
double derivative1(vector<double>& a, double x);
double derivative2(vector<double>& a,double x);
double dx(vector<double>& a, double x, double d);
double range(vector<double>& a);
void infunction(vector<double>& a,int n);
bool isFileEmpty(string& filename);
void interval(vector<double>& itv, vector<double>& a, double eps, int decimal, int choose, string filename);
void drawAxes(int x_center, int y_center);
void drawPolynomialGraph(vector<double>& a, int x_center, int y_center, int scale, double x_start, double x_end);
double derivative2(vector<double>& a,double x);
double dx(vector<double>& a, double x, double d);
void m1_M1(vector<double>& a, vector<double>& itv, vector<double>& m1M1);
bool check_condition(vector<double>& a, vector<double>& itv);
void solution1(vector<double>& a, vector<double>& itv, int iter, int decimal, int choose, string filename);
void solution2(vector<double>& a, vector<double>& itv, double ep, int decimal, int choose, string filename);
void output_solution(int decimal, double x, int count );





