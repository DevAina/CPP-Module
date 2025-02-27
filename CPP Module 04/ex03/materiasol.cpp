/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiasol.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:16:02 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/21 18:37:49 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materiasol.hpp"

t_materiasol	*endMateriasol(t_materiasol *materia)
{
	if (!materia)
		return (NULL);
	while (materia->next)
		materia = materia->next;
	return (materia);
}

void    addBack(t_materiasol **materia, t_materiasol * nw)
{
	t_materiasol	*lastMateria;

	if (!(*materia))
		*materia = nw;
	else if (materia && nw)
	{
		lastMateria = endMateriasol(*materia);
		lastMateria->next = nw;
	}
}
