// For the Binary Treeeeeeeeeeee!!!!!!!!!!!!!!!!!
#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std; 

int main()
{
	int N;
	while(~scanf("%d", &N)){
		priority_queue<int, deque<int, allocator<int> >, less<int> > BT;
		while(N--){
			int input;
			cin >> input;
			BT.push(input);
		}
		cout << "Start Binary Tree!!" << endl;
		int i, j, k;
		int size_q = BT.size();
		for(i = 1, j = 0, k = 1; i <=size_q; i++){
			j++;
			cout << BT.top() << " ";
			BT.pop();
			if(j == k){
				cout << endl;
				k = k << 1;
				j = 0;
			}
		}
		cout << endl;
	}
	return 0;
}
