#include <benchmark/benchmark.h>
#include "add.h"


static void escape (void * p) {
    asm volatile ("" : : "g"(p) : "memory");
}

static void clobber()
{
    asm volatile("" : : : "memory");
}

static void BM_ProfileAdd(benchmark::State & state)
{
    int a = 1;
    int b = 2;

    for (auto _ : state) {
        int res = add(a, b);
        escape(&res);
    }
}


BENCHMARK(BM_ProfileAdd)->Range(8, 8192);

BENCHMARK_MAIN();
