#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef vector<vector<string> > vvs;

int main()
{
	ifstream infile("tweet_input/tweets.txt");
	infile >> noskipws;
	int nums[3] = { 0 };//figure out how many words in each tweet
	int i=0;
	char chr;
	while (infile >> chr){   
		switch (chr){
		case '\n':
			++nums[i];
			i += 1;
			break;
		case ' ':  
			++nums[i];  
			break;
		default:;
		}
	}
	nums[i-1]++;
	infile.close();

	int m, n;
	m = n = 0;
	
	vvs words;
	words.resize(3);
	for (m = 0; m < 3; m++)		words[m].resize(nums[m]);

	ifstream infile2("tweet_input/tweets.txt"); //read words from tweets.txt
	int num= 0;
	string str;
	for (i = 0; i < 3;i++){            
		while (num < nums[i] - 1){
			getline(infile2, str, ' ');
			words[i][num] = str;
			num++;
		}
		getline(infile2, str, '\n');
		words[i][num] = str;
		num = 0;
	}
	infile2.close();

	int uni_nums[3];                       //compare words in each tweet, get the number of unique words
	for (i = 0; i < 3; i++) uni_nums[i] = nums[i];
	i = 0;
	while (i <3){                              
		for (m = 0; m < nums[i]; m++){
			for (n = m+1; n <nums[i]; n++){
				if (words[i][m] == words[i][n]) uni_nums[i]--;
			}
		}
		i++;
	}

	float median_unique[3] = { 0 };//get the median of the set of unique words per tweet 
	median_unique[0] = uni_nums[0];
	for (i = 1; i < 3; i++){
		median_unique[i] = (median_unique[i - 1]*i + uni_nums[i])/(i+1);
	}
	ofstream ofile; //save the result in ft2.txt
	ofile.open("tweet_output/ft2.txt");
	ofile << "median_unique" << endl;
	for (m = 0; m < 3; m++){
		ofile  << median_unique[m] << endl;
	}
	ofile.close();
	return 0;
}
