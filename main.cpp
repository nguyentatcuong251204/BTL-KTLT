
#include "function.h"
#define filename "output.txt"
#define eps 0.5
using namespace std;


int main(){
    double r;
    vector<double> heso,itv;
    while (1)
    {
        main_menu();
        int a;
        cin>>a;
        if (a <= 0 || a >= 8){
            cout<<"Lua chon khong ton tai, vui long nhap lai !"<<endl;
        }
        switch(a)
        {
        case 1:
            int n,decimal;
            cout << "Nhap vao bac cua da thuc : ";
            cin >> n;
            cout<<endl;
            infunction(heso,n);
            break;
        case 2:
            if (heso.size()==0){
                cout << "Chua nhap ham so"<<endl;
            }
            else{
                r=range(heso);
                int choose;
                cout << "Nhap vao so chu so thap phan hien thi sau dau phay : ";
                cin >> decimal;
                while(1){
                    extra_menu();
                    cout << "Nhap lua chon tu ban phim"<<endl;
                    cin >> choose;
                    if (choose == 1){
                        output_range(decimal,r);
                    }
                    else if (choose == 2){
                        export_range(decimal,r,filename);
                    }
                    else if (choose == 3){
                        read_file(filename);
                    }
                    else if (choose == 4){
                        delete_file(filename);
                        break;
                    }
                    else{
                        cout<<"Lua chon khong ton tai. Vui long nhap lai"<<endl;
                    }
                }
            }
            break;
        case 3:
            if (heso.size() == 0){
                cout<<"Chua nhap da thuc. Hay quay lai buoc 1"<<endl;
            }
            else{
                cout << "Nhap vao so chu so thap phan hien thi sau dau phay : "<<endl;
                cin>>decimal;
                while(1){
                    extra_menu();
                    cout << "Nhap lua chon tu ban phim"<<endl;
                    int choose;cin>>choose;
                    interval(itv, heso, eps, decimal, choose, filename);
                    if (choose == 4) break;
                }
            }
            
            break;
        case 4:
            if (itv.size() == 0){
                cout<<"Chua tim khoang cach li"<<endl;
            }
            else{
                cout<<itv.size()<<endl;
                cout<<"Khoang cach li ("<<itv[0]<<" ,"<<itv[1]<<")"<<endl;
                int gd = DETECT, gm;
                initgraph(&gd, &gm, nullptr);

                int x_center = getmaxx() /2 ;
                int y_center = getmaxy() /2;
                int scale = 25;
                drawAxes(x_center, y_center);
                drawPolynomialGraph(heso, x_center, y_center, scale, itv[0], itv[1]);
                cout<<"Nhan phim T de quay lai MENU"<<endl;
                getch();
                closegraph();
                break;
            }
        case 5:
            int iter,choose;
            cout << "Nhap vao so chu so thap phan hien thi sau dau phay : "<<endl;
            cin >> decimal;
            cout << "Nhap vao so lan lap "<<endl;
            cin >> iter;
            while(1){
                extra_menu();
                cout<<"Nhap vao lua chon"<<endl;
                cin>>choose;
                solution1(heso, itv, iter, decimal, choose, filename);
                if (choose == 4) break;
            }
            break;
        
        case 6:
            double ep;
            cout << "Nhap vao so chu so thap phan hien thi sau dau phay : "<<endl;
            cin >> decimal;
            cout << "Nhap vao sai so "<<endl;
            cin >> ep;

            while(1){
                extra_menu();
                cout<<"Nhap vao lua chon"<<endl;
                cin>>choose;
                solution2(heso, itv, ep, decimal, choose, filename);
                if (choose == 4) break;
            }
            break;
        case 7:
            return 0;
            
        }

    }
    
}