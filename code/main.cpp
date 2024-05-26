#include "cc.hpp"
#include "cm.hpp"

#include <chrono>
#include <iostream>

static const int CYCLES = 1e5;
static const int WARMING = 100;
static const char* const measure_suffix = " ns/shape";

void init_cc(shape_base** figs);
void init_cm(shape_struct* figs);

double ns_per_cycle(auto start, auto end, int cycles)
{
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return time_taken / cycles;
}

int main()
{
    // unsync the I/O of C and C++.
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);

#ifndef CLEAN
    {
        std::cout << "CLEAN CODE" << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        shape_base** figs;

        double sum = 0;
        for (int i = 0; i < WARMING; ++i) {
            figs = new shape_base*[CYCLES];
            init_cc(figs);
            sum += TotalAreaVTBL(CYCLES, figs);

            for (int i = 0; i < CYCLES; i++) {
                delete figs[i];
            }
            delete[] figs;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "warming\t" << ns_per_cycle(start, end, WARMING * CYCLES) << measure_suffix << std::endl;
        std::cout << "result: " << sum / WARMING << std::endl;

        start = std::chrono::high_resolution_clock::now();
        figs = new shape_base*[CYCLES];
        init_cc(figs);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "init\t" << ns_per_cycle(start, end, CYCLES) << measure_suffix << std::endl;

        start = std::chrono::high_resolution_clock::now();
        double area = TotalAreaVTBL(CYCLES, figs);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "calc\t" << ns_per_cycle(start, end, CYCLES) << measure_suffix << std::endl;

        std::cout << "area: " << area << std::endl;

        delete[] figs;
    }
#else
    std::cout << std::endl
              << std::endl;

    {
        std::cout << "CASEY MURATORI" << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        shape_struct* figs;

        double sum = 0;
        for (int i = 0; i < WARMING; ++i) {
            figs = new shape_struct[CYCLES];
            init_cm(figs);
            sum += GetAreaStructs4(CYCLES, figs);
            delete[] figs;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "warming\t" << ns_per_cycle(start, end, WARMING * CYCLES) << measure_suffix << std::endl;
        std::cout << "result: " << sum / WARMING << std::endl;

        start = std::chrono::high_resolution_clock::now();
        figs = new shape_struct[CYCLES];
        init_cm(figs);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "init\t" << ns_per_cycle(start, end, CYCLES) << measure_suffix << std::endl;

        start = std::chrono::high_resolution_clock::now();
        double area = GetAreaStructs4(CYCLES, figs);
        end = std::chrono::high_resolution_clock::now();

        std::cout << "calc\t" << ns_per_cycle(start, end, CYCLES) << measure_suffix << std::endl;

        std::cout << "area: " << area << std::endl;

        delete[] figs;
    }
#endif
    return 0;
}

void init_cm(shape_struct* figs)
{
    for (int i = 0; i < CYCLES; ++i) {
        switch ((int)(M_SQRT2 * i) % 4) { // pseudo randomize figure order
        case 0:
            figs[i] = { Shape_Square, (float)i + 1.0f, (float)i + 1.0f };
            break;
        case 1:
            figs[i] = { Shape_Circle, (float)i + 1.0f, (float)i + 1.0f };
            break;
        case 2:
            figs[i] = { Shape_Rectangle, (float)i + 1.0f, (float)i + 2.0f };
            break;
        case 3:
            figs[i] = { Shape_Right_Triangle, (float)i + 1.0f, (float)i + 2.0f };
            break;
        }
    }
}

void init_cc(shape_base** figs)
{
    for (int i = 0; i < CYCLES; ++i) {
        switch ((int)(M_SQRT2 * i) % 4) { // pseudo randomize figure order
        case 0:
            figs[i] = new square((float)i + 1.0f);
            break;
        case 1:
            figs[i] = new circle((float)i + 1.0f);
            break;
        case 2:
            figs[i] = new rectangle((float)i + 1.0f, (float)i + 2.0f);
            break;
        case 3:
            figs[i] = new right_triangle((float)i + 1.0f, (float)i + 2.0f);
            break;
        }
    }
}
