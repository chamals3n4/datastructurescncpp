#include <iostream>
#include <ostream>

class Diagonal{
private:
    int *A;
    int n;
public:
    Diagonal(int n){
        this->n=n;
        A = new int[n];
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
};

void Diagonal::set(int i,int j,int x){
    if(i==j)
        A[i-1]=x;
}

int Diagonal::get(int i,int j){
    if(i==j)
        return A[i-1];
    else
        return 0;;
}

void Diagonal::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                std::cout << A[i] << " " ;
            else
                std::cout << "0 " ;
        }
        std::cout<<std::endl;
    }

}

int main(){
    Diagonal d(4);
    d.set(1, 1, 5);
    d.set(2, 2, 5);
    d.set(3, 3, 5);
    d.set(4, 4, 5);
    std::cout << "element in 3,3 is " << d.get(3, 3) << std::endl;
    std::cout << "displaying matrix" << std::endl;
    d.display();
    return 0;
}

