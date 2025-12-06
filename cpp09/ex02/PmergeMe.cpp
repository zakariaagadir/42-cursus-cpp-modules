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


void mergeInsertSortque(std::vector<int>& vect)
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

    mergeInsertSortque(mainChain);

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