#include <iostream>
#include<string>
#include <vector>
#include<fstream>
#include<iomanip>

using namespace std;

void main(){
	ifstream ifile("tweet_input\\tweets.txt");//read words from tweets.txt
	if (!ifile){
		cout << "fail to open file " << endl;
		exit(0);
	}
	string data[100];
	int size,i;
	for (i = 0; i < 100; i++){
		if (!ifile.eof()){
			ifile >> data[i];
		}
		else{
			ifile.close();
			size= i;
			break;
		}
	}

	int a, b;	
	int *pnum = (int*)malloc(size*sizeof(int));
	for (i = 0; i < size; i++) pnum[i] = 1;
	string ts;
	int t;
	for (a = 1; a < size; a++){
		for (b = size - 1; b >= a; b--){
			if (data[b - 1] > data[b]){       //range words according to ASCII Code.
				ts = data[b - 1];
				t = pnum[b - 1];
				data[b - 1] = data[b];
				pnum[b - 1] = pnum[b];
				data[b] = ts;
				pnum[b] = t;
			}
			if (data[b - 1] == data[b]){     //merge same words,count word frequency
				pnum[b - 1] = pnum[b - 1]+ pnum[b];
				int m;
				for (m = b; m < size; m++){
					data[m] = data[m + 1];
					pnum[m] = pnum[m + 1];
				}
				b += 1;
				size = size - 1;
			}
		}			
	}

	ofstream ofile;     //save the result in ft1.txt
	ofile.open("tweet_output\\ft1.txt");
	ofile << "words tweeted"<<endl;
	for (a = 0; a < size; a++){
		ofile << setw(25) << data[a] << setw(10) << pnum[a] << endl;
	}
	ofile.close();
}
