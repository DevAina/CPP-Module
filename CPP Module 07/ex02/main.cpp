/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:08:36 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/02 14:45:10 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include "Array.hpp"

// Définition des codes de couleur ANSI
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_GOLD  "\033[1;0m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"

void print_header(const std::string& text)
{
    std::cout << COLOR_CYAN << "\n[ " << text << " ]" << COLOR_RESET << std::endl;
}

void print_test_result(bool success, const std::string& message)
{
    if (success)
        std::cout << COLOR_GOLD << "[PASS] " << message << COLOR_RESET << std::endl;
    else
        std::cout << COLOR_RED << "[FAIL] " << message << COLOR_RESET << std::endl;
}

int main()
{
    print_header("TEST 1 : Default constructor and size()");
    {
        Array<int> empty;
        print_test_result(empty.getSize() == 0, "Size of default array should be 0");

        try
        {
            empty[0];
            print_test_result(false, "Accessing empty array should throw");
        }
        catch (const std::exception& e)
        {
            print_test_result(true, "Exception correctly thrown for empty array");
        }
    }

    print_header("TEST 2 : Constructor with size and default values");
    {
        Array<int> arr(5);
        print_test_result(arr.getSize() == 5, "Size should be 5");

        bool all_zero = true;
        for (unsigned int i = 0; i < arr.getSize() ; ++i)
        {
            if (arr[i] != 0)
                all_zero = false;
        }
        print_test_result(all_zero, "All elements initialized to 0");

        arr[2] = 42;
        print_test_result(arr[2] == 42, "Element modification and access");
    }

    print_header("TEST 3 : Copy constructor and deep copy");
    {
        Array<int> original(3);
        original[0] = 1;
        original[1] = 2;
        original[2] = 3;

        Array<int> copy(original);
        copy[1] = 99;

        print_test_result(original[1] == 2 && copy[1] == 99, "Deep copy verification");
    }

    print_header("TEST 4 : Assignment operator and deep copy");
    {
        Array<int> arr1(2);
        arr1[0] = 5;
        arr1[1] = 10;

        Array<int> arr2(arr1);
        try
        {
            arr2[0] = -5;
        }
        catch (const std::exception& err)
        {
            std::cout << err.what() << std::endl;
        }
        print_test_result(arr1[0] == 5 && arr2[0] == -5, "Deep assignment verification");
    }

    print_header("TEST 5 : Out-of-bounds exceptions");
    {
        Array<std::string> arr(3);

        try
        {
            arr[3] = "test";
            print_test_result(false, "Should throw for index 3");
        }
        catch (const std::exception& e)
        {
            print_test_result(true, "Exception thrown for index 3");
        }

        try
        {
            arr[-1] = "test";
            print_test_result(false, "Should throw for negative index");
        } 
        catch (const std::exception& e)
        {
            print_test_result(true, "Exception thrown for negative index");
        }
    }

    print_header("TEST 6 : Different data types");
    {
        Array<float> float_arr(4);
        print_test_result(float_arr.getSize() == 4, "Float array size correct");
        float_arr[3] = 3.14f;
        print_test_result(float_arr[3] == 3.14f, "Float element access");

        Array<std::string> str_arr(2);
        str_arr[1] = "Hello";
        print_test_result(str_arr[1] == "Hello", "String element access");
    }

    print_header("TEST 7 : Complex type behavior");
    {
        Array< Array<int> > matrix(2);
        matrix[0] = Array<int>(3);
        matrix[1] = Array<int>(3);

        matrix[0][2] = 42;
        print_test_result(matrix[0][2] == 42, "Nested array access");
    }

    std::cout << COLOR_MAGENTA << "\nAll tests completed!" << COLOR_RESET << std::endl;
    return 0;
}
