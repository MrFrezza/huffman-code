#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct HeapNode {
	char info;
	unsigned freq;
	HeapNode *left, *right;

	HeapNode(char info, unsigned freq)
	{
		this->right = this->left = NULL;
		this->freq = freq;
		this->info = info;
	}
};

struct compara {
	bool operator()(HeapNode * l, HeapNode * r)
	{
		return (l->freq > r->freq);
	}
};

void printaHuffman(HeapNode *root, string str) 
{
	if (!root)
		return;

	if (root->info != '$')
		cout << root->info << " : " << str << "\n";

	printaHuffman(root->left, str + "0");
	printaHuffman(root->right, str + "1");
}

void montaHuffman(char data[], int freq[], int size)
{
	HeapNode *esq, *dir, *pai;

	priority_queue<HeapNode*, vector<HeapNode*>, compara> heap;

	for (int i = 0; i < size; i++)
	{
		heap.push(new HeapNode(data[i], freq[i]));
	}

	while (heap.size() != 1)
	{
		esq = heap.top();
		heap.pop();

		dir = heap.top();
		heap.pop();

		pai = new HeapNode('$', esq->freq + dir->freq);

		pai->left = esq;
		pai->right = dir;

		heap.push(pai);
	}

	printaHuffman(heap.top(), "");
}


int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	montaHuffman(arr, freq, size);

	system("pause");
	return 0;
}




