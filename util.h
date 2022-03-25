#pragma once

#include <ctime>

using namespace std;


struct timer {
    timer() {
        timespec_get(&start, TIME_UTC);
    }

    long get_ms() const {
        timespec t;
        timespec_get(&t, TIME_UTC);
        return (t.tv_sec - start.tv_sec) * 1000 + (t.tv_nsec - start.tv_nsec) / 1'000'000;
    }

    timespec start;
};


template<typename T>
ostream& operator << (ostream& str, const vector<T>& v) {
    str << "{";
    if (v.size() > 0) {
        size_t n = (v.size() <= 52)? v.size() : 50;
        for (int i = 0; i < n - 1; ++i) {
            str << v[i] << ", ";
        }

        if (n < v.size()) {
            str << "..., ";
        }

        str << v.back();
    }
    str << "}";
    return str;
}







