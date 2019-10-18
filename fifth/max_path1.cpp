#include<iostream>
#include<vector>
#include<queue>

int main() {
    int size;
    std::cin>>size;
    std::vector<std::vector<int> > matrix(size, std::vector<int>(size,0));
    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            std::cin>>matrix[i][j];
    std::vector<int> cap(size,0);
    for (int i=0;i<size;i++)
        cap[0]+=matrix[0][i];
    std::queue<int> w; w.push(0);
    while (!w.empty()) {
        for (int i=0;i<size;i++)
            if ((cap[w.front()]>matrix[w.front()][i] ? matrix[w.front()][i] : cap[w.front()])>cap[i]) {
                cap[i]=(cap[w.front()]<matrix[w.front()][i] ? cap[w.front()] : matrix[w.front()][i]);
                w.push(i);
            }
        w.pop();
    }
    std::cout<<cap[1]<<std::endl;
}
