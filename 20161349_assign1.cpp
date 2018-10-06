#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(int num1);
void printVector(vector<int> vIn);

int main()
{
	//to make prime numbers
	vector<int> prime_nums;
	int max_num = 10000;
	int count=1;
	
	// bringing input.txt file
	ifstream myfile;
	myfile.open("input.txt",ios::in);
	
	
	//input two numbers
	int first_num;
	int second_num;
	
	myfile >> first_num >> second_num;
	//output of two numbers
	int apple;
	int boy;
	//storing the sum and products of vectors
	int sum_of_elem=0;
	int prod;
	
	
	// making prime numbers
	while(true)
	{
		count += 1;
		if (is_prime(count)==1)
			prime_nums.push_back(count);
		if (prime_nums.size()> max_num-1)
			break;
	}	
	
	//printVector(prime_nums);	
	//cout << "The size of vector is  " <<prime_nums.size()<< endl; 	
	// making new vectors that are needed
	vector<int>::iterator first = prime_nums.begin() + (first_num-1);
	vector<int>::iterator last = prime_nums.begin() + second_num;
	vector<int> needed_prime(first,last);
	

	//cout << "The vector for answer is " <<endl;
	//printVector(needed_prime);
	//cout << "the size of new vector is " << needed_prime.size() <<endl;
		
	// finding the sum of all prime numbers in vector
	for (vector<int>::iterator it2 =needed_prime.begin(); it2 != needed_prime.end();++it2)
		sum_of_elem += *it2;

	apple = sum_of_elem;
	cout << "sum of all elements are: " << apple<< endl;
	
	// initializing first remainder
	int p = needed_prime.front();
	int remainder = p%second_num;
	// finding the modulus of products
	for (vector<int>::iterator it3 = needed_prime.begin()+1; it3 != needed_prime.end();++it3)
		
	remainder = (remainder*(*it3)%second_num);
		
	boy = remainder;
	cout << "remainder of the products of elements are: " << boy << endl;	
	//creating output.txt file
	ofstream file;
	file.open("output.txt");
	file << apple  << " " << boy;
	file.close();
	return 0;
	


}

bool is_prime(int num1)
{
	for (int i=2;i<int(sqrt(num1)+1);i++)
	{
		if(num1%i==0)
		return false;
	}
	return true;
}

void printVector(vector<int> vIn)
	{
		vector<int>::iterator it;
		for(it= vIn.begin(); it!=vIn.end();++it)
			cout<< *it<<" ";
	}
	

