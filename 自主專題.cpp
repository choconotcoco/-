#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() 
{
    string date, line,sth;
    int money,choice;
    long long int sum = 0;
    cout << " ================================記帳系統======================================" << endl;
    ifstream infile("records.txt");
    if (!infile) //未建檔
    {
        ofstream outfile("records.txt");
        outfile << " =========日期==================收入和支出==================備註===============" << endl;
        outfile.close();
    }
    ifstream insumfile("sum.txt");
    if (insumfile) {
        insumfile >> sum; 
        insumfile.close();
    }
    else {
        ofstream outsumfile("sum.txt");
        outsumfile << 0;  
        outsumfile.close();
        sum = 0;
    }
    while (1)
    {
        
        cout << " (1)新增紀錄\n" << " (2)查詢紀錄\n" <<" (3)清空所有紀錄\n" << " (4)退出此系統\n" << " ";
        cin >> choice;
        if (choice == 1 || choice == 2||choice==3||choice==4)
        {
            
            switch (choice)
            {
            case 1:
            {
                ofstream outfile("records.txt", ios::app);
                cout << " 日期範例輸入：2025/05/24\n" << " 收入和支出範例輸入：60 or -10" << endl;
                cout << " 請輸入日期：" << endl<<" ";
                cin >> date;
                cout << " 請輸入收入 or 支出：" << endl<<" ";
                cin >> money;
                cout << " 備註：";
                cin >> sth;
                sum += money;
                if (!outfile)
                {
                    cout << "無法打開檔案" << endl;
                    return 1;
                }
                outfile << "   \t" << date << "  \t\t   " << money << "\t\t\t   " <<sth<< endl;
                outfile.close();
                ofstream sumFile("sum.txt");
                sumFile << sum;
                sumFile.close();
                infile.close();
            }
                
                break;
            case 2:
            {
                ifstream readFile("records.txt");
                if (!readFile) {
                    cout << "無法讀取記錄檔案！" << endl;
                    return 1;
                }
                while (getline(readFile, line))
                {
                    cout << line << endl;
                }
                readFile.close();
                cout << endl;
                cout << " ==總金額==========================================" << endl;
                cout << "    "<<sum<<"元\n";
                
            }   
                break;
            case 3: // 清空紀錄
            {
                ofstream outfile("records.txt", ios::trunc); // trunc 表示清空
                if (!outfile) {
                    cout << "無法清空記錄檔案！" << endl;
                    return 1;
                }
                outfile << " =========日期==================收入和支出==================備註===============" << endl;
                outfile.close();
                cout << "所有紀錄已清空。\n";
                sum = 0;
                ofstream sumFile("sum.txt");
                sumFile << 0;
                sumFile.close();
                
                break;
            }
            case 4:
                return 0;
                break;
            }
        }
        else
        {
            cout << " 其他功能尚未開發";
    
           
        }
        cout << endl;
    }
    return 0;
}
