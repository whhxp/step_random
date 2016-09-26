

#include "step_random.h"
int main(int argc, char *argv[])
{
    double min=1;
    double max=101;
    double step=1;


    //Test for random number with step
    step_random <double> *obj = new step_random <double> (min, max, step);
    obj->set_min(100);
    obj->set_max(200);
    for (int i = 0; i < 100; i++)
    {
        std::cout<<obj->get_random();
        if (i % 10 == 9)
            std::cout<<std::endl;
        else
            std::cout<<"\t";
    }
    //obj->display_dist(1000);
    delete obj;

    //Test for random string splited by comma","
    step_random <std::string> *obj2 = new step_random <std::string> ("aa,bb,cc,dd,ee,ff,gg,hh,ii");
    for (int i = 0; i < 100; i++)
    {
        std::cout<<obj2->get_random_string();
        if (i % 10 == 9)
            std::cout<<std::endl;
        else
            std::cout<<"\t";
    }
    delete obj2;
    return 0;
}
