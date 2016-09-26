#ifndef STEP_RANDOM_H
#define STEP_RANDOM_H

#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>


template <class T>
class step_random
{

    public:
        step_random (T a, T b, double Step);
        step_random (std::string str1);

        std::string get_random_string();


        T get_random();
        void set_min(T Min);
        void set_max(T Max);
        void set_step(double Step);
        void display_dist(T total_num);
    private:
        T first, second;
        double step;
        std::string s1;
};

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

std::vector<std::string> split(const std::string& input, const std::string& regex) {
    // passing -1 as the submatch index parameter performs splitting
    std::regex re(regex);
    std::sregex_token_iterator
        first{input.begin(), input.end(), re, -1},
        last;
    return {first, last};
}

template <>
std::string step_random<std::string>::get_random_string()
{
    std::vector<std::string> v1;
    v1 = split(s1,",|:|-|\\s+");

    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<> dis(0,v1.size()-1);
    return v1[dis(gen)];
}



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



#endif // STEP_RANDOM_H
