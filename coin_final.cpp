#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
class coin{
private:
    string res;
public:
    coin(int random=0){
        res=(random==0)?"HEAD":"TAIL";
        count++;
    }
    string get_entry(){
        return res;
    }
    void show_entry(){
        cout<<res<<endl;
    }
    static int count;
};
int coin::count=0;
int main(void){
    vector<coin> outcomes;
    int i=0,random=0;
    for(i=0;i<2;i++){
        random=rand()%2;
        outcomes.push_back(random);
    }
    bool done=false;
    while(!done){
        random=rand()%2;
        outcomes.push_back(random);
        if((outcomes.at(coin::count -1)).get_entry()=="HEAD" && (outcomes.at(coin::count -2)).get_entry()=="HEAD" && (outcomes.at(coin::count -3)).get_entry()=="HEAD"){
            done=true;
        }
    }
    int itr=0;
    for(itr=0;itr<coin::count;itr++){
        (outcomes.at(itr)).show_entry();
    }
    cout<<"No. of trials needed : "<<coin::count<<endl;
    return 0;
}
