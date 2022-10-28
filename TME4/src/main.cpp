#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>

#include "Compte.h"
#include "Banque.h"

#define N_COMPTES 10
#define SOLDEINITIAL 100

using namespace std;
using namespace pr;

// void work(int index){
//     std::cout << "started "<< index << endl;
//     auto r = ::rand() % 20; // 0 to 20 ms
//     std::this_thread::sleep_for (std::chrono::milliseconds(r));
//     std::cout << "finished "<< index << endl;
// }

// void createAndWait(int N){
//     std::vector<thread> threads;
//     for(int i = 0; i < N; ++i){
//         threads.push_back(thread(work, i));
//         threads.emplace_back(thread(work, i));
//     }
//     for(auto & t:threads)
//         t.join();
// }

// const int JP = 10000;
// void jackpot(Compte & c){
//     for(int i = 0; i < JP; i++)
//         c.crediter(i);
// }

const int NB_THREAD = 10;

void transferer(Banque& b, int loop){
    std::cout << "started..." << endl;

    int index {};
    size_t i;
    size_t j;


    do{
        int m = ::rand() % (100+1);
        i = ::rand() % (N_COMPTES+1);
        j = ::rand() % (N_COMPTES+1);

        std::cout << "transferer le montant " << m << " de " << i << " à " << j << "..." << endl;
        b.transfert(i, j, m);
        index++;
        auto r = ::rand() % 20; // 0 to 20 ms
        std::this_thread::sleep_for (std::chrono::milliseconds(r));
     }while(index != loop);

    std::cout << "finished "<< index << endl;
}

int main(){
    vector<thread> threads;
    int solde {SOLDEINITIAL};
    Banque b = Banque(N_COMPTES, solde);
    int loop {1000};

    for(int i = 0; i < NB_THREAD; ++i){
        threads.emplace_back(transferer, std::ref(b), loop);
    }

    for(auto & t:threads)
        t.join();
    
    return 0;
}