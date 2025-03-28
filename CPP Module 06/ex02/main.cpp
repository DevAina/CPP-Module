/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:44:46 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/26 15:08:16 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdentifyRealType.hpp"

int main()
{
    Base *gen = generate();

    identify(*gen);
    delete gen;
    return (0);
}
