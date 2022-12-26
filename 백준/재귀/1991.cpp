#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node
{
    char left, right;
};
int n;
Node graph[300];

void preorder(char root)
{
    if (root == '.')
        return;
    else
        cout << root;
    if (graph[root].left == '.' && graph[root].right == '.')
    {
        return;
    }

    preorder(graph[root].left);
    preorder(graph[root].right);
}
void postorder(char root)
{
    if (root == '.')
    {
        return;
    }
    if (graph[root].left == '.' && graph[root].right == '.')
    {
        cout << root;
        return;
    }

    postorder(graph[root].left);
    postorder(graph[root].right);
    cout << root;
}
void inorder(char root)
{
    if (root == '.')
    {
        return;
    }
    if (graph[root].left == '.' && graph[root].right == '.')
    {
        cout << root;
        return;
    }

    inorder(graph[root].left);
    cout << root;
    inorder(graph[root].right);
}
int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char node, left, right;
        cin >> node >> left >> right;
        Node nn = {left, right};
        graph[node] = nn;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";

    return 0;
}