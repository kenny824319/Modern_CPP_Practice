#pragma once
#include <bits/stdc++.h>

namespace Kenny
{

    template<typename T>
    using DeleterType = void(*)(T*);

    template<typename T>
    static void Demo1DAryNoUseptr(std::unique_ptr<T[]> &Ary, int size)
    {
        for(int i = 0;i < size;++i)
        {
            std::cout << Ary[i] << ' ';
        }
        std::cout << std::endl;
    }

    template<typename T>
    static void Demo1DAryUseptr(std::unique_ptr<T[]> &Ary, int size)
    {
        T *ptr = Ary.get();
        for(int i = 0;i < size;++i)
        {
            std::cout << *ptr << ' ';
            ptr++;
        }
        std::cout << std::endl;
    }

    template<typename T>
    static void Demo2DAry(std::unique_ptr<T[]> &Ary, int row, int col)
    {
        for(int i = 0;i < row;++i)
        {
            for(int j = 0;j < col;++j)
            {
                std::cout << Ary[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}