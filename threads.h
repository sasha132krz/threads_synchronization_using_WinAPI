#ifndef LTHREADS_H

// global includes
#include <iostream>

#include <random>


const int sleep_time = 1;

void sleep_ms(int milliseconds); // cross-platform sleep function

void computation();

int threads_init();

unsigned int thread_graph_id();

const char* unsynchronized_threads();

const char* sequential_threads();


#endif