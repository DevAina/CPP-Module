/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:46:15 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/10 18:48:50 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Form::Form(): name(), isSigned(false), gradeToSign(130), gradeToexecute(140)
{
}

Form::Form(const std::string nm, const int gradeSign, const)
