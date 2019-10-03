#include<iostream>
#include<vector>
#include<queue>
int size;

int getway(std::vector<int>&way,std::vector<std::vector<int> > matrix) {

    std::vector<int>used(size,-1);
    way.clear();
    used.at(0)=0;
    std::queue<int> possible_points;
    possible_points.push(0);
    bool flag = true;
    while (flag) {
        int now;
        now=possible_points.front();
        if (now==1) {flag==false; break;} 
        possible_points.pop();
        for (int i = 0; i<size; i++) {
            if ((matrix[now][i]>0) && used[i]==-1) {
                possible_points.push(i);
                used.at(i)=now;
                if (i==1) {flag = false; break;}
            }
        }
        if (possible_points.back()==1) { flag=false; break;} 
        if (possible_points.size()==0) { flag=false; break;}
    }
    if (used[1]==-1) {return 0;}
    int weight;
    {
        int i = 1;
        weight=matrix[used.at(i)][i];
        while (i!=0) {
            if(matrix[used.at(i)][i]<weight && matrix[used.at(i)][i]>0) weight=matrix[used.at(i)][i];
            way.push_back(i);
            i=used.at(i);
        }
        way.push_back(0);
    }
    return weight;
}

int main() {

    std::cin>>size;
    std::vector<std::vector<int> > matrix (size, std::vector<int>(size));
    for(int i =0; i< size; i++) {
        for(int j =0; j <size;j++){
            std::cin>>matrix[i][j];
        }
    }

    std::vector<std::vector<int> > flow (size, std::vector<int>(size,0));
    int weight;
    std::vector<int> way;
    bool flag = true;
    while (flag)
    {   weight = getway(way, matrix);
        if (weight==0) {flag = false; break;}
        for (int i=0; i<way.size()-1; i++) {
            int a,b;
            a=way.at(i+1);
            b=way.at(i);
            matrix[a][b]-=weight;
            matrix[b][a]+=weight;
            flow[a][b]+=weight;
            flow[b][a]-=weight; 

        }
    }
    int rate=0;
    for (int i = 0; i<size; i++) {
        rate+=flow[0][i];
    }
    std::cout<<rate<<std::endl;
}
