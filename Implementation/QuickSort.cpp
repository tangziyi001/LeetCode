#import <iostream>
#import <vector>
using namespace std;

int all[10] = {4,5,2,3,6,1,7,8,3,9};;
void myswap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(int l, int r){
	int pi = all[r];
	int i = 0;
	for(int j = 0; j < r; j++){
		if(all[j] <= pi){
			myswap(&(all[i]),&(all[j]));
			i++;
		}
	}
	myswap(&all[i],&all[r]);
	return i;
}

void rec(int l, int r){
	if(l < r){
		int p = partition(l,r);
		rec(l,p-1);
		rec(p+1,r);
	}
}
int main(){

	rec(0,9);
	for(int i = 0; i < 10; i++){
		cout << all[i] << endl;
	}

	return 0;
}