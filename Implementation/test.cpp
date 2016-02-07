#import <iostream>
#import <vector>
using namespace std;
vector<int> *b;
void cc(){
	(*b)[0] = 1;
}
int main(){
	vector<int> a(10,0);
	*b = a;
	cc();
	
	for(int i = 0; i < 10; i++){
		cout << a[i] << endl;
	}
	return 0;
}