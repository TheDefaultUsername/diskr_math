#include<iostream>
#include<vector>
#include<queue>
int size;

int source;
int target;

int getway(std::vector<int>&way,std::vector<std::vector<int> > matrix) {

    std::vector<int>used(size,-1);
    way.clear();
    used.at(source)=source;
    std::queue<int> possible_points;
    possible_points.push(source);
    bool flag = true;
    while (flag) {
        int now;
        now=possible_points.front();
        if (now==target) {flag==false; break;} 
        possible_points.pop();
        for (int i = 0; i<size; i++) {
            if ((matrix[now][i]>0) && used[i]==-1) {
                possible_points.push(i);
                used.at(i)=now;
                if (i==target) {flag = false; break;}
            }
        }
        if (possible_points.back()==target) { flag=false; break;} 
        if (possible_points.size()==0) { flag=false; break;}
    }
    if (used[target]==-1) {return 0;}
    int weight;
    {
        int i = target;
        weight=matrix[used.at(i)][i];
        while (i!=source) {
            if(matrix[used.at(i)][i]<weight && matrix[used.at(i)][i]>0) weight=matrix[used.at(i)][i];
            way.push_back(i);
            i=used.at(i);
        }
        way.push_back(source);
    }
    return weight;
}

int main() {
    source = 0;
    target = 1;
    std::cin>>size;
    std::vector<std::vector<int> > matrix (size, std::vector<int>(size));
    for(int i =0; i< size; i++) {
        for(int j =0; j <size;j++){
            std::cin>>matrix[i][j];
        }
    }

    int weight;
    int max_weight = 0;
    std::vector<int> way;
    bool flag = true;
    while (flag)
    {   weight = getway(way, matrix);
        if (weight==0) {flag = false; break;}
        for (int i=0; i<way.size()-1; i++) {
            int a = way.at(i);
            int b = way.at(i+1);
            if (matrix[b][a]==weight) matrix[b][a]=0;
        }
        if (weight>max_weight) max_weight=weight;
    }
    std::cout<<max_weight<<std::endl;
}
