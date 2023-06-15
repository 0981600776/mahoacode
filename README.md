#include <bits/stdc++.h>
//8h43
using namespace std;

int gcd(int a, int m){
    if (a == 0)
        return m;
    if (m == 0)
        return a;
    if (a == m)
        return a;
    if (a < m)
        return gcd(a, m - a);
    return gcd(a - m, m);
}
int oclit(int a, int m){
    int m0 = m;
    int s = 0, t = 1;
    if (m == 1)
        return 0;
    while (a > 1){
        int q = a / m;
        int tam = m;
        m = a % m, a = tam;
        tam = s;
        s = t - q * s;
        t = tam;
    }
    return (t % m0 + m0) % m0;
}
string mahoa(string s1, int a, int b){
    string s = "";
    for (int i = 0; i < s1.length(); i++){
        if (isupper(s1[i]))
            s += char ((a * (s1[i] - 'A') + b) % 26 + 'A');
        else
            s += char ((a * (s1[i] - 'a') + b) % 26 + 'a');
    }
    return s;
}
string giaima(string s2, int a, int b){
    string s = "";
    int a_inv = oclit(a,26);
    for (int i = 0; i < s2.length(); i++){
        if (isupper(s2[i]))
            s += char ((a_inv * (s2[i] - 'A' - b) + 26) % 26 + 'A');
        else
            s += char ((a_inv * (s2[i] - 'a' - b) + 26) % 26 + 'a');
    }
    return s;
}
int main(){
    int a,b;
    cout << "Nhap khoa a: ";
    cin>>a;
    cout << "Nhap khoa b: ";
    cin>>b;
    if (gcd(a,26) == 1){
        cout << "Khoa giai ma la:\n\tK(giai ma) = K(" << oclit(a,26) << ", " << b << ")" << endl;
        string s1, s2;
        cout << "Nhap xau ky tu 1: ";
        cin.ignore();
        cin>>s1;
        cout << "Nhap xau ky tu 2: ";
        cin>>s2;
        cout << "Ban ma: " << mahoa(s1,a,b) << endl;
        cout << "Ban ro: " << giaima(s2,a,b) << endl;
        if (mahoa(s1,a,b) == s2)
            cout << "Ban da nhap dung!" << endl;
        else
            cout << "Ban da nhap sai!" << endl;
        if(giaima(s2,a,b) == s1)
            cout << "Ban da nhap dung!" << endl;
        else
            cout << "Ban da nhap sai!" << endl;
    }
    else
        cout << "Khong ton tai khoa giai ma" << endl;

    return 0;
}
