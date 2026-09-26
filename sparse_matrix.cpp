#include <iostream>
using namespace std;

struct Sparse
{
    int row;
    int col;
    int value;
};

int main(){
    Sparse sparse[2500];

    int n;
    cout<<"Enter size of your array: ";
    cin>>n;

    int count = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int x;
            cout<<"Enter value of row "<<i<<" and column "<<j<<": ";
            cin>>x;

            if(x!=0)
            {
                sparse[count+1] = {i, j, x};
                count++;
            }
        }

    sparse[0] = {n, n, count};

    cout<<"\nSparse of your array:\n\nRows    Cols    Values\n";
    for(int i=0; i<=count; i++)
    {
        cout<<sparse[i].row<<"       "<<sparse[i].col<<"       "<<sparse[i].value<<endl;
    }

    return 0;
}