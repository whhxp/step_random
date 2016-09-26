#include "step_random.h"
/*
template <class T>
step_random<T>::step_random (T a, T b, double Step):
first(a), second(b), step(Step)
{
    try
    {
        if (step == 0)
        {
            throw -1;
        }
    }
    catch(int x)
    {
        std::cout<<"Exception "<<x<<" : random number step is 0.\n";
        exit(-1);
    }
}*/
/*
template <>
step_random<std::string>::step_random(std::string str1):s1(str1)
{

    try
    {
        if (s1.empty())
        {
            throw 1;
        }
    }
    catch(int x)
    {
        std::cout<<"Exception "<<x<<" : random string is empty.\n";
        exit(1);
    }
}

template <>
std::string step_random<std::string>::get_random_string()
{
    std::string s2="get_random_string";
    return s2;
}
*/
template <class T>
void step_random<T>::display_dist(T total_num)
{
    std::vector<unsigned> vals(lround(second-first));
    for (int i=0; i< total_num; i++)
    {
        unsigned v = get_random();
        if ((v-first) < vals.size())
        {
            ++vals[v-first];
        }
    }

    for (size_t j = 0, counter = first; j != vals.size(); ++j, ++counter)
        std::cout << counter << ":\t"<< int(vals[j])<<"\t"
             <<lround(total_num/(second-first))-int(vals[j])<<"\t"
            <<std::string(vals[j],'*')<< std::endl;

}

template <class T>
void step_random<T>::set_min(T Min)
{
    first = Min;
}

template <class T>
void step_random<T>::set_max(T Max)
{
    second = Max;
}

template <class T>
T step_random<T>::get_random()
{

    std::random_device rd;
    std::default_random_engine gen(rd());
    T min=first/step;
    T max=second/step;
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen)*step;
}
