#include "PmergeMe.hpp"
#include <deque>
#include <algorithm>
#include <iostream>

static size_t jacobsthalque(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthalque(n - 1) + 2 * jacobsthalque(n - 2);
}

void checkifsortedque(std::deque<int>& que)
{
    for(size_t i = 0; i<(que.size() -1); i++)
    {
        if(que[i] > que[i+1])
        {
            std::cout << "\033[31m[ERROR] Vector is NOT sorted ❌\033[0m\n";
        }
    }
    std::cout << "\033[32m[OK] Vector is sorted ✔️\033[0m\n";
}

static std::vector<size_t> generateJacobOrderque(size_t size)
{
    std::vector<size_t> order;
    if (size == 0)
        return order;

    std::vector<size_t> J;
    for (size_t k = 1; ; k++)
    {
        size_t jk = jacobsthalque(k);
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

void mergeInsertSortDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pendings;
    size_t n = deq.size();

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];

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

    bool hasLeftover = false;
    int leftover = 0;
    if (n % 2 != 0)
    {
        hasLeftover = true;
        leftover = deq[n - 1];
    }

    mergeInsertSortDeque(mainChain);

    std::vector<size_t> jacobOrder = generateJacobOrderque(pendings.size());
    std::vector<bool> inserted(pendings.size(), false);

    for (size_t i = 0; i < jacobOrder.size(); i++)
    {
        size_t p = jacobOrder[i];
        if (p < pendings.size())
        {
            std::deque<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), pendings[p]);
            mainChain.insert(pos, pendings[p]);
            inserted[p] = true;
        }
    }

    for (size_t i = 0; i < pendings.size(); i++)
    {
        if (!inserted[i])
        {
            std::deque<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), pendings[i]);
            mainChain.insert(pos, pendings[i]);
        }
    }

    if (hasLeftover)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }

    deq = mainChain;
}
