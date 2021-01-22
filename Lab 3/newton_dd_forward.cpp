#include<iostream>
#include<iomanip>
#define MAX 4
using namespace std;


float calcS(float s, float n) {
    float temp = s;
    for (int i = 1;i < n;i++) {
        temp *= (s - i);
    }
    return temp;
}
int fact(int n) {
    if (n <= 0)return 1;
    return n * fact(n - 1);
}
float newton_forward_dIff(float xn[], float fxn[][MAX], float x) {

    for (int i = 1; i < MAX; i++)
        for (int j = 0; j < MAX - i; j++)
            fxn[j][i] = fxn[j + 1][i - 1] - fxn[j][i - 1];


	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX-i;j++)
			cout<<fxn[i][j]<<setw(4)<<"\t";
		cout<<endl;		
	}

    float p = fxn[0][0];
    float s = (x - xn[0]) / (xn[1] - xn[0]);
    for (int i = 1;i < MAX;i++)
        p = p + (calcS(s, i) * fxn[0][i]) / fact(i);


    return p;
}

int main() {
    system("CLS");
    float xn[MAX] = { 1,2,3,4 };
    float fxn[MAX][MAX];
    fxn[0][0] = 0;
    fxn[1][0] = 0.6931;
    fxn[2][0] = 1.0986;
    fxn[3][0] = 1.3863;
    


    float ans = newton_forward_dIff(xn, fxn, 3.5);

    cout << endl << "Root: " << ans;
}
