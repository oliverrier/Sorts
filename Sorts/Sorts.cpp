#include <iostream>
#include <vector>
#include <cassert>

void insertSort(std::vector<int>& tab)
{
    for (int i = 1; i < tab.size(); i++) 
    {
        int key = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > key) 
        {
            tab[j + 1] = tab[j];
            --j;
        }
        tab[j + 1] = key;
    }
};

void fusion(std::vector<int>& tab, int start, int middle, int end)
{
    int const sizeLeft = middle - start + 1;
    int const sizeRight = end - middle;

    std::vector<int> leftArray(sizeLeft + 1);
    std::vector<int> rightArray(sizeRight + 1);

    for (int i = 1; i < sizeLeft; i++)
    {
        leftArray[i] = tab[start + i - 1];
    }
    for (int i = 1; i < sizeRight; i++)
    {
        rightArray[i] = tab[middle + i];
    }

    leftArray.push_back(std::numeric_limits<int>::max());
    rightArray.push_back(std::numeric_limits<int>::max());
    int i = 0;
    int j = 0;

    for (int k = start; k < end; k++)
    {
        if (leftArray[i] <= rightArray[j]) {
            tab[k] = leftArray[i];
            ++i;
        }
        else
        {
            tab[k] = rightArray[j];
            ++j;
        }
    }
}

void fusionSort(std::vector<int>& tab, int start, int end) 
{
    int middle = 0;
    if (start < end) 
    {
        middle = std::floor((start + end) / 2);
        fusionSort(tab, start, middle);
        fusionSort(tab, middle + 1, end);
        fusion(tab, start, middle, end);
    }
}

void bubbleSort(std::vector<int>& tab)
{
    for (int i = 0; i < tab.size(); i++) 
    {
        for (int j = tab.size() - 1; j > i; j--)
        {
            if (tab[j] < tab[j - 1])
            {
                std::swap(tab[j], tab[j - 1]);
            }
        }
    }
}


void swapBySort(std::vector<int>& tab) 
{
    int n = tab.size();
    std::vector<int> P;
    for (int i = 0; i < n; i++)
    {
        P[i] = std::rand(std::pow(n, 3)) + 1
    }
}



int main()
{

    std::vector<int> tabToSort;
    tabToSort.push_back(2);
    tabToSort.push_back(5);
    tabToSort.push_back(9);
    tabToSort.push_back(3);
    tabToSort.push_back(7);
    tabToSort.push_back(4);
    tabToSort.push_back(8);
    tabToSort.push_back(1);
    tabToSort.push_back(6);
    // fusionSort(tabToSort, 0, tabToSort.size() - 1);
    bubbleSort(tabToSort);
    std::cout << "Welcome to the sorting exercise!\n";
    for (int i = 0; i < tabToSort.size(); i++) {
        std::cout << "tabToSort[" << i << "] : " << tabToSort[i] << std::endl;
    }

}
