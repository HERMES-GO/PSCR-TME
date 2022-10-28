#pragma once

#include "Queue.h"
#include "Job.h"
#include <vector>
#include <thread>

namespace pr {

class Pool {
	Queue<Job> queue;
	std::vector<std::thread> threads;
public:
	Pool(int qsize) :queue(qsize){}

	inline static void poolWorker(Queue<Job> & queue){
		while(true){
			Job *j = queue.pop();
			if(j == nullptr) break;
			j->run();
			delete j;
		}
	}
	inline void start (int nbthread){
		for(int i = 0; i < nbthread; i++){
			threads.emplace_back(poolWorker, std::ref(queue));
		}
	}
	inline void submit (Job * job){
		// ??
	}
	inline void stop(){
		queue.setBlocking(false);
		for(auto & t:threads){
			t.join();
		}
	}
	
	~Pool(){}
};

}
