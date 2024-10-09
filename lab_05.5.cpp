#include <iostream>
using namespace std;

int recursionDepth = 0;  
int maxDepth = 0;        


int binomialCoefficient(int n, int k) 
{
    recursionDepth++;  
    if (recursionDepth > maxDepth) maxDepth = recursionDepth;

    if (k == 0 || k == n) 
    {
        recursionDepth--;  
        return 1;
    }

    int result = binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
    recursionDepth--;  
    return result;
}


void printPascalTriangle(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            cout << binomialCoefficient(i, j) << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int n;
    cout << "Введіть кількість рядків для трикутника Паскаля: ";
    cin >> n;
    
    printPascalTriangle(n);
    
    cout << "Максимальна глибина рекурсії: " << maxDepth << endl;
    
    return 0;
}



