
#include "function.h"
using namespace std;
#define colWidth1 35
#define colWidth2 35
//Hàm tạo menu
void main_menu() {
    cout << "\x1b[32m ____________________________________________________________________________________________\n";
    cout << "|                                    \x1b[34mChon chuc nang\x1b[32m                                          |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m1. Nhap ham so\x1b[32m                                                                            |\n";
    cout <<"|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m2. Tim mien chua nghiem \x1b[32m                                                                  |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m3. Tim khoang cach li nghiem (a, b) bang phuong phap chia doi thoa man |a-b|<=0.5\x1b[32m         |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m4. Ve do thi ham so tren khoang cach li nghiem (a, b)\x1b[32m                                     |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m5. Tim nghiem gan dung tren khoang cach li nghiem va danh gia sai so theo 2 cach\x1b[32m          |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m6. Tim nghiem gan dung tren khoang cach li nghiem theo cong thuc sai so |x(n)-x(n-1)|<=e\x1b[32m  |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m7. Thoat chuong trinh\x1b[32m                                                                     |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "\x1b[31mCach dung menu: Nhap lua chon bang ban phim\n";
    cout << "\x1b[37m";
    
}
//Hàm tạo menu phụ
void extra_menu(){
    cout << "\x1b[32m ____________________________________________________________________________________________\n";
    cout << "|                                    \x1b[34mNhap lua chon\x1b[32m                                           |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m1. In ra ket qua tren man hinh\x1b[32m                                                            |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m2. Xuat ket qua ra file van ban\x1b[32m                                                           |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m3. Hien thi ket qua tu file van ban\x1b[32m                                                       |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "|  \x1b[33m4. Menu\x1b[32m                                                                                   |\n";
    cout << "|____________________________________________________________________________________________|\n";
    cout << "\x1b[37m";
    
}
// Hàm tính giá trị của đa thức tại x
double fx(vector<double>& a, double x) {
    int n = a.size();
    double result = 0;
    for (int i = 0; i < n; ++i) {
        result += a[i] * pow(x, n - 1 - i);
    }
    return result;
}

// Hàm tính đạo hàm của đa thức tại x
double derivative1(vector<double>& a, double x) {
    int n = a.size();
    double result = 0;
    for (int i = 0; i < n; ++i) {
        result += (n - i - 1) * a[i] * pow(x, n - i - 2);
    }
    return result;
}

double derivative2(vector<double>& a,double x){
    int n=a.size();
    double result=0;
    for(int i = 0; i < n-1 ; i++){
        result += (n-i)*(n-i-1)*a[i]*pow(x,n-i-2);
    }
    return result;
}

double dx(vector<double>& a, double x, double d){
    return -(fx(a,x)*(x-d))/(fx(a,x)-fx(a,d));
}

// Hàm tính bán kính nghiệm
double range(vector<double>& a) {
    int n = a.size();
    double max = abs(a[0])/abs(a[0]);
    for(int i = 0;i < n;i++){
        if (abs(a[i])/abs(a[0]) > max){
            max = abs(a[i])/abs(a[0]);
        }
    }
    return 1+max;
}

//Hàm nhập vào hệ số của đa thức
void infunction(vector<double>& a,int n){
    for(int i = 0;i <= n;i++){
        cout << "Nhap vao he so cua x^" << n-i << " : ";
        double x;cin >> x;
        a.push_back(x);
        cout << endl;
    }
}
//Hàm kiểm tra file văn bản rỗng
bool isFileEmpty(string& filename){
    ifstream infile(filename);
    if (!infile){
        cout << "Khong the mo file" << endl;
    }
    if (infile.peek() == EOF) {
        return true; // Nếu file rỗng, trả về true
    } else {
        return false; // Nếu file không rỗng, trả về false
    }
}

void output_range(int decimal, int r){
    ostringstream ss;
    ss << fixed << setprecision(decimal);
    ss << "(" << r << ", " << -r << ")";
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "| " << setw(colWidth1) << left << "Ban kinh nghiem"
            << " | " << setw(colWidth2) << left << "Khoang nghiem" << "           |" << endl;
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "| " << setw(colWidth1) << left << fixed << setprecision(decimal) << r
            << " | " << setw(colWidth2) << left << ss.str() << "           |" << endl;
    cout << "+-------------------------------------------------------------------------------------+" << endl;
}
void output_interval(int decimal, double a, double b, int count){
    ostringstream ss;
    ss << fixed << setprecision(decimal);
    ss << "(" << a << ", " << b << ")";
    if (count == 1){
        cout << "+-------------------------------------------------------------------------------------+" << endl;
        cout << "| " << setw(colWidth1) << left << "Lan lap"
                << " | " << setw(colWidth2) << left << "Khoang nghiem" << "           |" << endl;
        cout << "+-------------------------------------------------------------------------------------+" << endl;

        cout << "| " << setw(colWidth1) << left << count
                << " | " << setw(colWidth2) << left << ss.str() << "           |" << endl;
        cout << "+-------------------------------------------------------------------------------------+" << endl;
    }
    else{
        cout << "| " << setw(colWidth1) << left << count
                << " | " << setw(colWidth2) << left << ss.str() << "           |" << endl;
        cout << "+-------------------------------------------------------------------------------------+" << endl;
    }
}
void output_solution(int decimal, double x, int count ){
    // ostringstream ss;
    // ss << fixed << setprecision(decimal);
    // ss << "(" << a << ", " << b << ")";
    if (count == 1){
        cout << "+-------------------------------------------------------------------------------------+" << endl;
        cout << "| " << setw(colWidth1) << left << "Lan lap"
                << " | " << setw(colWidth2) << left << "Nghiem" << "           |" << endl;
        cout << "+-------------------------------------------------------------------------------------+" << endl;

        cout << "| " << setw(colWidth1) << left << count
                << " | " << setw(colWidth2) << left << fixed << setprecision(decimal) << x << "           |" << endl;
        cout << "+-------------------------------------------------------------------------------------+" << endl;
    }
    else{
        cout << "| " << setw(colWidth1) << left << count
                << " | " << setw(colWidth2) << left << fixed <<setprecision(decimal) << x << "           |" << endl;
        cout << "+-------------------------------------------------------------------------------------+" << endl;
    }
}

void export_solution(int decimal, double x, int count, ofstream& outfile ){
    if (count == 1){
        outfile << "+-------------------------------------------------------------------------------------+" << endl;
        outfile << "| " << setw(colWidth1) << left << "Lan lap"
                << " | " << setw(colWidth2) << left << "Nghiem" << "           |" << endl;
        outfile << "+-------------------------------------------------------------------------------------+" << endl;

        outfile << "| " << setw(colWidth1) << left << count
                << " | " << setw(colWidth2) << left << fixed << setprecision(decimal) << x << "           |" << endl;
        outfile << "+-------------------------------------------------------------------------------------+" << endl;
    }
    else{
        outfile << "| " << setw(colWidth1) << left << count
                << " | " << setw(colWidth2) << left << fixed <<setprecision(decimal) << x << "           |" << endl;
        outfile << "+-------------------------------------------------------------------------------------+" << endl;
    }
}
void export_range(int decimal, double r, string filename){
    ofstream outfile(filename);
    if (!outfile){
        cout<<"Khong the mo file"<<endl;
    }
    ostringstream ss;
    ss << fixed << setprecision(decimal);
    ss << "(" << -r << ", " << r << ")";
    outfile << "+-------------------------------------------------------------------------------------+" << endl;

    outfile << "| " << setw(colWidth1) << left << "Ban kinh nghiem"
            << " | " << setw(colWidth2) << left << "Khoang nghiem" << "           |" << endl;
    outfile << "+-------------------------------------------------------------------------------------+" << endl;
    outfile << "| " << setw(colWidth1) << left  << fixed << setprecision(decimal) << r
            << " | " << setw(colWidth2) << left << ss.str() << "           |" << endl;
    outfile << "+-------------------------------------------------------------------------------------+" << endl;
    cout <<"Xuat file thanh cong !"<<endl;
    outfile.close();
}
void export_interval(int decimal, double a, double b, ofstream& outfile, int count){
    ostringstream ss;
    ss << fixed << setprecision(decimal);
    ss << "(" << a << ", " << b << ")";
    if (count == 1){
        outfile << "+-------------------------------------------------------------------------------------+" << endl;
        outfile << "| " << setw(colWidth1) << left << "Lan lap"
                << " | " << setw(colWidth2) << left << "Khoang nghiem" << "           |" << endl;
        outfile << "+-------------------------------------------------------------------------------------+" << endl;

        outfile << "| " << setw(colWidth1) << left << count
                << " | " << setw(colWidth2) << left << ss.str() << "           |" << endl;
        outfile << "+-------------------------------------------------------------------------------------+" << endl;
    }
    else{
        outfile << "| " << setw(colWidth1) << left << count
                << " | " << setw(colWidth2) << left << ss.str() << "           |" << endl;
        outfile << "+-------------------------------------------------------------------------------------+" << endl;
    }
}
void read_file(string filename){
    if (isFileEmpty(filename)){
        cout << "File rong, khong co noi dung de doc"<<endl;
    }
    else{
        ifstream inFile(filename);
        string line;
        while (getline(inFile, line)) {
            cout << line <<endl;
        }
        inFile.close();
    }
}
void delete_file(string filename){
    ofstream outfile(filename,ofstream::out);
    outfile.close();
}
void interval(vector<double>& itv, vector<double>& a, double eps, int decimal, int choose, string filename){
    double r=range(a);
    double left=-r; double right=r;

    if (choose == 1){
        int i=1;
        while(left<right && abs(left-right)>eps){
            double mid=(left+right)/2;
            output_interval(decimal, left, right, i);
            if (fx(a,mid) == 0){
                if (fx(a,mid-0.00000001)*fx(a,mid+0.00000001)<0){
                    cout<<"Khoang cach li nghiem la ("<<fixed<<setprecision(decimal)<<mid-0.1<<" ,"<<fixed<<setprecision(decimal)<<mid+0.1<<")"<<endl;
                    itv.clear();
                    itv.push_back(mid-0.1);
                    itv.push_back(mid+0.1);
                }
                else{
                    cout<<"Khong ton tai khoang cach li tren mien chua nghiem"<<endl;
                }
                return;
            }
            else if (fx(a,mid)*fx(a,left)>0 || fx(a,mid)*fx(a,right)<0)
            {
                left=mid;
            }
            else if (fx(a,mid)*fx(a,right)>0 || fx(a,mid)*fx(a,left)<0){
                right=mid;
            }
            i+=1;
        }

        if (fx(a,left)*fx(a,right) < 0){
            itv.clear();
            itv.push_back(left);
            itv.push_back(right);
            cout<<"Khoang cach li nghiem la ("<<fixed<<setprecision(decimal)<<left<<" ,"<<fixed<<setprecision(decimal)<<right<<")"<<endl;
        }
        else{
            cout<<"Khong ton tai khoang cach li tren mien chua nghiem"<<endl;
        }
    }
    else if (choose == 2){
        ofstream outfile(filename);
        int i=1;
        if (!outfile){
            cout<<"Khong the mo file"<<endl;
        }
        while(left<right && abs(left-right)>eps){
            double mid=(left+right)/2;
            export_interval(decimal, left, right, outfile, i);
            if (fx(a,mid) == 0){
                if (fx(a,mid-0.00000001)*fx(a,mid+0.00000001)<0){
                    
                    outfile<<"Khoang cach li nghiem la ("<<fixed<<setprecision(decimal)<<mid-0.1<<" ,"<<fixed<<setprecision(decimal)<<mid+0.1<<")"<<endl;
                    itv.clear();
                    itv.push_back(mid-0.1);
                    itv.push_back(mid+0.1);
                }
                else{
                    outfile<<"Khong ton tai khoang cach li tren mien chua nghiem"<<endl;
                }
                return;
            }
            else if (fx(a,mid)*fx(a,left)>0 || fx(a,mid)*fx(a,right)<0)
            {
                left=mid;
            }
            else if ((fx(a,mid)*fx(a,right)>0) || (fx(a,mid)*fx(a,left)<0)){
                right=mid;
            }
            i+=1;
        }
        if (fx(a,left)*fx(a,right) < 0){
            itv.clear();
            itv.push_back(left);
            itv.push_back(right);
            outfile<<"Khoang cach li nghiem la ("<<fixed<<setprecision(decimal)<<left<<" ,"<<fixed<<setprecision(decimal)<<right<<")"<<endl;
        }
        else{
            outfile<<"Khong ton tai khoang cach li tren mien chua nghiem"<<endl;
        }
        outfile.close();
    }
    else if (choose == 3){
        read_file(filename);

    }
    else{
        while(left<right && abs(left-right)>eps){
            double mid=(left+right)/2;
            if (fx(a,mid) == 0){
                if (fx(a,mid-0.00000001)*fx(a,mid+0.00000001)<0){
                    itv.clear();
                    itv.push_back(mid-0.1);
                    itv.push_back(mid+0.1);
                }
                else{
                    cout<<"Khong ton tai khoang cach li"<<endl;
                }
                return;
                
            }
            else if (fx(a,mid)*fx(a,left)>0 || fx(a,mid)*fx(a,right)<0)
            {
                left=mid;
            }
            else if (fx(a,mid)*fx(a,right)>0 || fx(a,mid)*fx(a,left)<0){
                right=mid;
            }
            itv.clear();
            itv.push_back(left);
            itv.push_back(right);
        }
        delete_file(filename);
    }
    
}
void drawPolynomialGraph(vector<double>& a, int x_center, int y_center, int scale, double x_start, double x_end) {
    setcolor(YELLOW);

    double step = 0.00001;
    for (double x = x_start; x < x_end ; x+=step) {
        double y=fx(a,x);
        int x_pixel = x_center + (x * scale);
        int y_pixel = y_center - (y * scale);
        putpixel(x_pixel, y_pixel, YELLOW);
    }
}
void drawAxes(int x_center, int y_center) {
    setcolor(WHITE);
    // Vẽ trục X
    line(0, y_center, getmaxx(), y_center);
    // Vẽ trục Y
    line(x_center, 0, x_center, getmaxy());
}

void m1_M1(vector<double>& a, vector<double>& itv, vector<double>& m1M1){
    vector<double> d1;
    for(double i=itv[0]; i<itv[1]; i+=0.00000001){
        d1.push_back(abs(derivative1(a,i)));
    }
    auto min1=min_element(d1.begin(), d1.end());
    auto max1=max_element(d1.begin(), d1.end());
    m1M1.push_back(*min1);
    m1M1.push_back(*max1);

}
bool check_condition(vector<double>& a, vector<double>& itv){
    vector<double> d1; vector<double> d2;
    for(double i=itv[0]; i<itv[1]; i+=0.000001){
        d1.push_back(derivative1(a,i));
        d2.push_back(derivative2(a,i));
    }
    auto max_d1=max_element(d1.begin(), d1.end());
    auto min_d1=min_element(d1.begin(), d1.end());
    auto max_d2=max_element(d2.begin(), d2.end());
    auto min_d2=min_element(d2.begin(), d2.end());

    if (((*max_d1)*(*min_d1)>0) && ((*max_d2)*(*min_d2)>0)) return 1;
    return 0;

}

void solution1(vector<double>& a, vector<double>& itv, int iter, int decimal, int choose, string filename){
    if (choose == 1){
        if (a.size() == 2){
            cout<<"Phuong trinh bac 1 co nghiem duy nhat "<<fixed<<setprecision(decimal)<<-a[1]/a[0]<<endl;
            return;
        }
        if (a.size () == 1){
            cout<<"Ham hang"<<endl;
            return;
        }
        if (check_condition(a,itv)){
            cout<<"Thuc hien phuong phap day cung..."<<endl;
            double x,d,tmp;
            vector<double> m1M1;
            m1_M1(a, itv, m1M1);
            if(derivative2(a,(itv[0]+itv[1])/2)*fx(a,x)>0){
                int cnt=1;
                d=itv[0];                                           ;
                x=itv[1];
                while(cnt <= iter){
                    tmp=x;
                    x=x+dx(a,x,d);
                    output_solution(decimal, x, cnt);
                    cnt+=1;
                }

            }
            else{
                int cnt=1;
                d=itv[1];
                x=itv[0]; 
                while(cnt <= iter){
                    tmp=x;
                    x=x+dx(a,x,d);
                    output_solution(decimal, x, cnt);
                    cnt+=1;
                }
            }
            cout<<"Gia tri m1 = min(|f(x|) tren doan ("<<fixed<<setprecision(decimal)<<itv[0]<<" ,"<<fixed<<setprecision(decimal)<<itv[1]<<") la : "
            <<fixed<<setprecision(decimal)<<m1M1[0]<<endl;
            cout<<"Gia tri M1 = max(|f(x|) tren doan ("<<fixed<<setprecision(decimal)<<itv[0]<<" ,"<<fixed<<setprecision(decimal)<<itv[1]<<") la : "
            <<fixed<<setprecision(decimal)<<m1M1[1]<<endl;
            cout<<"Tinh theo cong thuc 1, sai so |xn-x*| <=  "<<fixed<<setprecision(decimal)<<abs(fx(a, x))/m1M1[0]<<endl;
            cout<<"Tinh theo cong thuc 2, sai so |xn-x*| <=  "<<fixed<<setprecision(decimal)<<(m1M1[1]-m1M1[0])/m1M1[0]*abs(x-tmp)<<endl;
        }
        else{
            cout<<"Khong thoa man dieu kien phuong phap day cung"<<endl;
        }
    }
    else if (choose == 2){
        ofstream outfile(filename);
        if (a.size() == 2){
            outfile<<"Phuong trinh bac 1 co nghiem duy nhat "<<fixed<<setprecision(decimal)<<-a[1]/a[0]<<endl;
            return;
        }
        if (a.size () == 1){
            cout<<"Ham hang"<<endl;
            return;
        }
        if (check_condition(a,itv)){
            cout<<"Thuc hien phuong phap day cung..."<<endl;
            double x,d,tmp;
            vector<double> m1M1;
            m1_M1(a, itv, m1M1);
            if(derivative2(a,(itv[0]+itv[1])/2)*fx(a,x)>0){
                int cnt=1;
                d=itv[0];                                           ;
                x=itv[1];
                while(cnt <= iter){
                    tmp=x;
                    x=x+dx(a,x,d);
                    export_solution(decimal, x, cnt,outfile);
                    cnt+=1;
                }

            }
            else{
                int cnt=1;
                d=itv[1];
                x=itv[0]; 
                while(cnt <= iter){
                    tmp=x;
                    x=x+dx(a,x,d);
                    export_solution(decimal, x, cnt,outfile);
                    cnt+=1;
                }
            }
            outfile<<"Gia tri m1 = min(|f(x|) tren doan ("<<fixed<<setprecision(decimal)<<itv[0]<<" ,"<<fixed<<setprecision(decimal)<<itv[1]<<") la : "
            <<fixed<<setprecision(decimal)<<m1M1[0]<<endl;
            outfile<<"Gia tri M1 = max(|f(x|) tren doan ("<<fixed<<setprecision(decimal)<<itv[0]<<" ,"<<fixed<<setprecision(decimal)<<itv[1]<<") la : "
            <<fixed<<setprecision(decimal)<<m1M1[1]<<endl;
            outfile<<"Tinh theo cong thuc 1, sai so |xn-x*| <=  "<<fixed<<setprecision(decimal)<<abs(fx(a, x))/m1M1[0]<<endl;
            outfile<<"Tinh theo cong thuc 2, sai so |xn-x*| <=  "<<fixed<<setprecision(decimal)<<(m1M1[1]-m1M1[0])/m1M1[0]*abs(x-tmp)<<endl;
        }
        else{
            outfile<<"Khong thoa man dieu kien phuong phap day cung"<<endl;
        }
        outfile.close();
    }
    else if (choose == 3){
        read_file(filename);
    }
    else{
        delete_file(filename);
    }
}
void solution2(vector<double>& a, vector<double>& itv, double ep, int decimal, int choose, string filename){
    if (a.size() == 2){
        cout<<"Phuong trinh bac 1 co nghiem duy nhat "<<fixed<<setprecision(decimal)<<-a[1]/a[0]<<endl;
        return;
        }
    if (a.size () == 1){
        cout<<"Ham hang"<<endl;
        return;
    }
    if (choose == 1){
        if (check_condition(a,itv)){
            cout<<"Thuc hien phuong phap day cung..."<<endl;
            double x,d,tmp;
            vector<double> m1M1;
            m1_M1(a, itv, m1M1);
            if(derivative2(a,(itv[0]+itv[1])/2)*fx(a,x)>0){
                int cnt=1;
                d=itv[0];                                           ;
                x=itv[1];
                while(fx(a,x) >= ep*m1M1[0]){
                    tmp=x;
                    x=x+dx(a,x,d);
                    output_solution(decimal, x, cnt);
                    cnt+=1;
                }

            }
            else{
                int cnt=1;
                d=itv[1];
                x=itv[0]; 
                while(fx(a,x) >= ep*m1M1[0]){
                    tmp=x;
                    x=x+dx(a,x,d);
                    output_solution(decimal, x, cnt);
                    cnt+=1;
                }
            }
            
        }
        else{
            cout<<"Khong thoa man dieu kien phuong phap day cung"<<endl;
        }
    }
    else if (choose == 2){
        ofstream outfile(filename);
        if (check_condition(a,itv)){
            cout<<"Thuc hien phuong phap day cung..."<<endl;
            double x,d,tmp;
            vector<double> m1M1;
            m1_M1(a, itv, m1M1);
            if(derivative2(a,(itv[0]+itv[1])/2)*fx(a,x)>0){
                int cnt=1;
                d=itv[0];                                           ;
                x=itv[1];
                while(abs(fx(a,x)) >= ep*m1M1[0]){
                    tmp=x;
                    x=x+dx(a,x,d);
                    export_solution(decimal, x, cnt,outfile);
                    cnt+=1;
                }

            }
            else{
                int cnt=1;
                d=itv[1];
                x=itv[0]; 
                while(abs(fx(a,x)) >= ep*m1M1[0]){
                    tmp=x;
                    x=x+dx(a,x,d);
                    export_solution(decimal, x, cnt,outfile);
                    cnt+=1;
                }
            }
            
        }
        else{
            outfile<<"Khong thoa man dieu kien phuong phap day cung"<<endl;
        }
        outfile.close();
    }
    else if (choose == 3){
        read_file(filename);
    }
    else{
        delete_file(filename);
    }

}