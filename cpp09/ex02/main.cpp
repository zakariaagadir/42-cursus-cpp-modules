#include "PmergeMe.hpp"


static size_t jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<size_t> generateJacobOrder(size_t size)
{
    std::vector<size_t> order;

    if (size == 0)
        return order;

    std::vector<size_t> J;
    for (size_t k = 1; ; k++)
    {
        size_t jk = jacobsthal(k);
        if (jk >= size)
            break;
        J.push_back(jk);
    }

    order.push_back(0);
    if (size == 1)
        return order;

    size_t prev = 1;
    for (size_t i = 1; i < J.size(); i++)
    {
        size_t start = J[i];
        size_t end = J[i - 1];

        for (size_t j = (start > 0 ? start - 1 : 0); j >= end; j--)
        {
            order.push_back(j);
            if (j == end)
                break;
        }
        prev = start;
    }

    if (prev < size)
    {
        size_t j = size - 1;
        do {
            order.push_back(j);
        } while (j-- > prev);
    }

    return order;
}


void mergeInsertSort(std::vector<int>& vect)
{
    if (vect.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pendings;
    int n = vect.size();

    for (int i = 0; i + 1 < n; i += 2)
    {
        int a = vect[i];
        int b = vect[i + 1];

        if (a <= b)
        {
            mainChain.push_back(b);
            pendings.push_back(a);
        }
        else
        {
            mainChain.push_back(a);
            pendings.push_back(b);
        }
    }

    int leftover;
    bool hasLeftover = false;
    if (n % 2 != 0)
    {
        leftover = vect[n - 1];
        hasLeftover = true;
    }

    mergeInsertSort(mainChain);

    std::vector<size_t> jacobOrder = generateJacobOrder(pendings.size());
    std::cout << "generateJacobOrder " << pendings.size() << " : ";
    for(size_t i = 0; i < jacobOrder.size(); i++)
        std::cout << jacobOrder[i] << " ";
    std::cout << std::endl;
    std::vector<bool> inserted(pendings.size(), false);

    for (size_t i = 0; i < jacobOrder.size(); i++)
    {
        size_t p = jacobOrder[i];
        if (p < pendings.size())
        {
            std::vector<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), pendings[p]);
            mainChain.insert(pos, pendings[p]);
            inserted[p] = true;
        }
    }

    for (size_t i = 0; i < pendings.size(); i++)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), pendings[i]);
            mainChain.insert(pos, pendings[i]);
        }
    }

    if (hasLeftover)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }

    vect = mainChain;
}

void checkifsorted(std::vector<int> vect)
{
    for(size_t i = 0; i<(vect.size() -1); i++)
    {
        if(vect[i] > vect[i+1])
        {
            std::cout << "\033[31m[ERROR] Vector is NOT sorted ❌\033[0m\n";
        }
    }
    std::cout << "\033[32m[OK] Vector is sorted ✔️\033[0m\n";
}

int main(int argc, char* argv[])
{
    std::vector<int> vect;
    std::queue<int> que;
    double buffer;
    if(argc < 2)
    {
        std::cerr<<"ERROR"<<std::endl;
        return 1;
    }
    for(int i = 1; i < argc; i++)
    {
        std::string s = argv[i];
        for (size_t j = 0; j < s.size(); j++)
        {
            if(!isdigit(s[j]))
            {
                std::cerr<<"Error"<<std::endl;
                return 1;
            }
        }
        if(s.size() > 11)
        {
            std::cerr<<"Error"<<std::endl;
            return 1;
        }
        buffer = std::atof(s.c_str());
        if(buffer > INT_MAX || buffer < 0)
        {
            std::cerr<<"Error"<<std::endl;
            return 1;
        }
        vect.push_back((int)buffer);
        que.push((int)buffer);
    }

    std::cout << "Before: ";
    for(size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";
    std::cout << std::endl;

    clock_t start = clock();
    mergeInsertSort(vect);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After: ";
    for(size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of 5 elements: " << std::fixed << std::setprecision(5)<< elapsed << " us" << std::endl;
    checkifsorted(vect);
    
    return 0;
}
