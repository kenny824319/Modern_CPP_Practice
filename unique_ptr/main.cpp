#include <bits/stdc++.h>
#include "ImageManager.h"
#include "Image.h"
#include "Kenny.h"

using namespace std;
using namespace Kenny;

int main()
{
    ImageManager imgManager;
    int new_w = 100;
    int new_h = 100;
    imgManager.SetNewImg(new_w, new_h);
    
    unique_ptr<char> pCharMakeUnique = make_unique<char>('a');
    cout << "pCharMakeUnique = " << *pCharMakeUnique << endl;
    
    // std::make_unique example
    int w = 10;
    int h = 20;
    unique_ptr<Image> img = make_unique<Image>(w, h);

    //std::make_unique with 1D array
    int len = 10;

    // Use std::unique_ptr<T[]> like T[]
    
    // int
    unique_ptr<int[]> pInt1DAry = make_unique<int[]>(len);
    for(int i = 0;i < len;++i)
    {
        pInt1DAry[i] = i + 1;
    }
    Demo1DAryNoUseptr(pInt1DAry, len);
    
    // char
    unique_ptr<char[]> pChar1DAry = make_unique<char[]>(len);
    char ch = 'a';
    for(int i = 0;i < len;++i)
    {
        pChar1DAry[i] = ch++;
    }
    Demo1DAryNoUseptr(pChar1DAry, len);

    // Use std::unique_ptr<T[]> like T*

    // int
    unique_ptr<int[]> pInt1DAry2 = make_unique<int[]>(len);
    int *pInt = pInt1DAry2.get();
    for(int i = 0;i < len;++i)
    {
        *pInt = len - i;
        pInt++;
    }
    Demo1DAryUseptr(pInt1DAry2, len);

    // char
    unique_ptr<char[]> pChar1DAry2 = make_unique<char[]>(len);
    ch = 'j';
    char *pChar = pChar1DAry2.get();
    for(int i = 0;i < len;++i)
    {
        *pChar = ch--;
        pChar++;
    }

    Demo1DAryUseptr(pChar1DAry2, len);

    // std::make_unique with 2D array
    int row = 2;
    int col = 3;

    // Use like T[][]
    // int
    unique_ptr<unique_ptr<int[]>[]> pInt2DAry = make_unique<unique_ptr<int[]>[]>(row);
    int cnt = 1;
    for(int i = 0;i < row;++i)
    {
        pInt2DAry[i] = make_unique<int[]>(col);
        for(int j = 0;j < col;++j)
        {
            pInt2DAry[i][j] = cnt++;
        }
    }
    Demo2DAry(pInt2DAry, row, col);

    // char
    unique_ptr<unique_ptr<char[]>[]> pChar2DAry = make_unique<unique_ptr<char[]>[]>(row);
    ch = 'a';
    for(int i = 0;i < row;++i)
    {
        pChar2DAry[i] = make_unique<char[]>(col);
        for(int j = 0;j < col;++j)
        {
            pChar2DAry[i][j] = ch++;
        }
    }
    Demo2DAry(pChar2DAry, row, col);

    // change 2D ary size
    // int
    // using new
    int new_row = row + 2;
    int new_col = col + 2;
    cnt = 1;
    pInt2DAry.reset(new unique_ptr<int[]> [new_row]);

    for(int i = 0;i < new_row;++i)
    {
        pInt2DAry[i].reset(new int [new_col]);
        for(int j = 0;j < new_col;++j)
        {
            pInt2DAry[i][j] = cnt++;
        }
    }
    Demo2DAry(pInt2DAry, new_row, new_col);

    // using make_unique
    cnt = 1;
    new_row *= 2;
    new_col *= 2;
    pInt2DAry.reset(make_unique<unique_ptr<int[]>[]>(new_row).release()); 
    /* 
    這邊要用release()而不是get()
    原因在於如果使用.get()得到make_unique創建出的unique_ptr其託管的raw pointer
    將這個raw pointer再交由另一個unique_ptr所託管
    這會造成double free的問題
    而使用release()會讓原先的unique_ptr讓出他的託管權
    此時移交給另一個unique_ptr就不會有問題了
    */
   for(int i = 0;i < new_row;++i)
   {
        pInt2DAry[i].reset(make_unique<int[]>(new_col).release());
        for(int j = 0;j < new_col;++j)
        {
            pInt2DAry[i][j] = cnt++;
        }
   }
   Demo2DAry(pInt2DAry, new_row, new_col);


   // Custom Deleter
   DeleterType<FILE> FileDeleter = [](FILE *f)
   {
        if(f != nullptr)
        {
            fclose(f);
        }
   };
   unique_ptr<FILE, decltype(FileDeleter)> pFile(fopen("file.txt", "w"), FileDeleter);

   row = 2;
   col = 3;
   cnt = 1;
   auto Int2DAryDeleter = [row](int **p2DAry)
    {
        if(p2DAry != nullptr)
        {
            for(int i = 0;i < row;++i)
            {
                delete [] p2DAry[i];
            }
            delete [] p2DAry;
        }
    };

    unique_ptr<int*, decltype(Int2DAryDeleter)> pInt2D(new int* [row], Int2DAryDeleter);
    int **p2DAry = pInt2D.get();
    for(int i = 0;i < row;++i)
    {
        p2DAry[i] = new int [col];
        int *it = p2DAry[i];
        for(int j = 0;j < col;++j)
        {
            *it = cnt++;
            it++;
        }
    }
    for(int i = 0;i < row;++i)
    {
        int *it = p2DAry[i];
        for(int j = 0;j < col;++j)
        {
            cout << (*it) << ' ';
            it++;
        }
        cout << endl;
    }

    // swap
    len = 5;
    unique_ptr<int[]> pAry1 = make_unique<int[]>(len);
    for(int i = 0;i < len;++i) pAry1[i] = -1;
    unique_ptr<int[]> pAry2 = make_unique<int[]>(len * 2);
    for(int i = 0;i < len * 2;++i) pAry2[i] = -2;
    cout << "Original pAry1:\n";
    Demo1DAryNoUseptr(pAry1, len);
    cout << "Original pAry2:\n";
    Demo1DAryNoUseptr(pAry2, len * 2);
    pAry1.swap(pAry2);
    cout << "After swap pAry1:\n";
    Demo1DAryNoUseptr(pAry1, len * 2);
    cout << "After swap pAry2:\n";
    Demo1DAryNoUseptr(pAry2, len);

    // assign
    pAry2 = move(pAry1);
    Demo1DAryNoUseptr(pAry2, len*2);
}
