/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiasol.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:28 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/21 18:37:09 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOL_HPP
# define MATERIASOL_HPP

# include <iostream>
class AMateria;

typedef struct s_materiasol
{
    AMateria    *tmp;
    struct s_materiasol *next;
}   t_materiasol;

void    addBack(t_materiasol **materia, t_materiasol *nw);
t_materiasol *endMateriasol(t_materiasol *materia);

#endif
