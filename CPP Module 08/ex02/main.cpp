/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:30:02 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/15 09:36:35 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <stack>

void	PrintHeaderTest(std::string test)
{
	std::cout << "\e[1;21;33;7m" << test << "\e[0m" << std::endl; 
}


int main()
{
	{
		PrintHeaderTest("============= TEST MAIN ==============");
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		MutantStack<int, std::list<int> > test;
		std::cout << std::endl;
	}

	{
		PrintHeaderTest("========== Basic functionality and iteration ==========");
		MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Top element: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size after pop: " << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        std::cout << "Elements in MutantStack (forward): ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Elements in MutantStack (reverse): ";
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;
		std::cout << std::endl;
	}

	{
		PrintHeaderTest("========== Copy constructor and assignment operator ==========");
		 MutantStack<int> mstack1;
        mstack1.push(1);
        mstack1.push(2);
        mstack1.push(3);
        
        MutantStack<int> mstack2(mstack1);
        MutantStack<int> mstack3;
        mstack3 = mstack1;
        
        mstack1.push(4);
        
        std::cout << "\nCopy constructor and assignment test:" << std::endl;
        std::cout << "Original stack size: " << mstack1.size() << std::endl;
        std::cout << "Copied stack size: " << mstack2.size() << std::endl;
        std::cout << "Assigned stack size: " << mstack3.size() << std::endl;
        
        std::cout << "Copied stack content: ";
        for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
		std::cout << std::endl;
	}
	{
		PrintHeaderTest("========== TEST USING OTHER CONTAINER  ==========");
        std::cout << "\e[1;42mstd::vector\e[0m\n";
		MutantStack<int, std::vector<int> > mstack;
        mstack.push(100);
        mstack.push(200);
        mstack.push(300);

        std::cout << "Using std::vector as underlying container: ";
        for (MutantStack<int, std::vector<int> >::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Random access test (vector only): ";
        MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
        std::cout << "First element: " << it[0] << ", Second element: " << it[1] << std::endl;
		std::cout << std::endl;

        std::cout << "\e[1;42mstd::list\e[0m\n";
        MutantStack<int, std::list<int> > mstacklst;
        mstacklst.push(10);
        mstacklst.push(20);
        mstacklst.push(30);

        std::cout << "Using std::list as underlying container: ";
        for (MutantStack<int, std::list<int> >::iterator it = mstacklst.begin(); it != mstacklst.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
	}
	return 0;
}
