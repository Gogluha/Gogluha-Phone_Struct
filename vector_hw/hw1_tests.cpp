#include <gtest/gtest.h>
#include "bmstu_vector.h"
#include "raw_memory.h"
#include <vector>

class without_default_constructor{
public:
    without_default_constructor(int z): z(z){
        static int count_allocs;
        count_allocs = count_allocs + 1;
        if (count_allocs == 10 ){
           throw std::runtime_error("without_default_constructor");

        }

    }

    without_default_constructor() = delete;

    int z;
    int count_allocs = 0;


    static int count_news_allocs;
};

int without_default_constructor::count_news_allocs =0;

Test(TestName_Other, Foo3){
    using namespace bmstu;
    std::vector<without_default_constructor> a();

}