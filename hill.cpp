#include <bits/stdc++.h>

using namespace std;
//9h11
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
void timkgiai(int khoa[][2], int kgiai[][2]){
    int det = (khoa[0][0] * khoa[1][1] - khoa[0][1] * khoa[1][0]) % 26;
    int x = oclit(det, 26);
    kgiai[0][0] = (x * khoa[1][1]) % 26;
    kgiai[0][1] = ((x * (- khoa[0][1])) % 26 + 26) % 26;
    kgiai[1][0] = ((x * (- khoa[1][0])) % 26 + 26) % 26;
    kgiai[1][1] = (x * khoa[0][0]) % 26;
    cout << "Khoa giai ma la: \n\t";
    cout << kgiai[0][0] << "\t" << kgiai[0][1] << "\n\t" << kgiai[1][0] << "\t" << kgiai[1][1] << endl;
}
string mahoa(string s1, int khoa[][2]){
    string s = "";
    for(int i = 0; i < s1.length(); i += 2){
        int ro1 = tolower(s1[i]) - 'a';
        int ro2 = tolower(s1[i+1]) - 'a';

        int ma1 = (ro1 * khoa[0][0] + ro2 * khoa[1][0]) % 26;
        int ma2 = (ro1 * khoa[0][1] + ro2 * khoa[1][1]) % 26;

        if (islower(s1[i]))
            s += ma1 + 'a';
        else
            s += ma1 + 'A';
        if(islower(s1[i+1]))
            s += ma2 + 'a';
        else
            s += ma2 + 'A';
    }
    return s;
}
string giaima(string s2, int kgiai[][2]){
    string s = "";
    for(int i = 0; i < s2.length(); i += 2){
        int ma1 = tolower(s2[i]) - 'a';
        int ma2 = tolower(s2[i+1]) - 'a';

        int ro1 = (ma1 * kgiai[0][0] + ma2 * kgiai[1][0]) % 26;
        int ro2 = (ma1 * kgiai[0][1] + ma2 * kgiai[1][1]) % 26;

        if (islower(s2[i]))
            s += ro1 + 'a';
        else
            s += ro1 + 'A';
        if(islower(s2[i+1]))
            s += ro2 + 'a';
        else
            s += ro2 + 'A';
    }
    return s;
}
int main(){
    int a,b,c,d,khoa[2][2], kgiai[2][2];
    cout << "Nhap phan tu a: ";
    cin>>a;
    cout << "Nhap phan tu b: ";
    cin>>b;
    cout << "Nhap phan tu c: ";
    cin>>c;
    cout << "Nhap phan tu d: ";
    cin>>d;
    khoa[0][0] = a;
    khoa[0][1] = b;
    khoa[1][0] = c;
    khoa[1][1] = d;
    timkgiai(khoa,kgiai);
    string s1, s2;
    cin.ignore();
    cout << "Nhap xau ky tu 1: ";
    cin>>s1;
    cout << "Nhap xau ky tu 2: ";
    cin>>s2;
    cout << "Ban ma: " << mahoa(s1, khoa) << endl;
    cout << "Ban ro: " << giaima(s2, kgiai) << endl;

    if(mahoa(s1, khoa) == s2)
        cout << "Ban da nhap dung!" << endl;
    else
        cout << "Ban da nhap sai!" << endl;
    if(giaima(s2, kgiai) == s1)
        cout << "Ban da nhap dung!" << endl;
    else
        cout << "Ban da nhap sai!" << endl;
    return 0;
}
