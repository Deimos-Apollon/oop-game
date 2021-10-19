//
// Created by Deimos on 13.10.2021.
//

#include "Randomer.h"

unsigned int Randomer::get_random_int(unsigned int min_int_included, unsigned int max_int_included) {
    static std::random_device rd;// only used once to initialise (seed) engine
    std::uniform_int_distribution<int> uni(static_cast<int>(min_int_included),
                                           static_cast<int>(max_int_included)); // guaranteed unbiased

    return uni(rd);
}
