/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:45:45 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/27 18:52:56 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

/*int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria*   tmp0;
    AMateria*   tmp1;
    tmp0 = src->createMateria("ice");
    me->equip(tmp0);
    tmp1 = src->createMateria("cure");
    me->equip(tmp1);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    delete tmp0;
    delete tmp1;
    return 0;
}*/

/*int main()
{
    std::cout << "=== Test 1 : Création de Materias ===" << std::endl;
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    std::cout << "Type de ice : " << ice->getType() << std::endl;
    std::cout << "Type de cure : " << cure->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 2 : Clonage de Materias ===" << std::endl;
    AMateria* clonedIce = ice->clone();
    AMateria* clonedCure = cure->clone();
    std::cout << "Type de clonedIce : " << clonedIce->getType() << std::endl;
    std::cout << "Type de clonedCure : " << clonedCure->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 3 : Création de Character ===" << std::endl;
    Character bob("Bob");
    std::cout << "Nom du personnage : " << bob.getName() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 4 : Équipement de Materias ===" << std::endl;
    bob.equip(ice);
    bob.equip(cure);
    bob.equip(clonedIce);
    bob.equip(clonedCure);
    std::cout << "Materias équipées avec succès." << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 5 : Utilisation de Materias ===" << std::endl;
    bob.use(0, bob);
    bob.use(1, bob);
    bob.use(2, bob);
    bob.use(3, bob);
    std::cout << std::endl;

    std::cout << "=== Test 6 : Déséquipement de Materias ===" << std::endl;
    bob.unequip(2);
    bob.unequip(3);
    std::cout << "Materias déséquipées avec succès." << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 7 : Copie profonde de Character ===" << std::endl;
    Character alice("Alice");
    alice = bob;
    std::cout << "Nom du nouveau personnage : " << alice.getName() << std::endl;
    alice.use(0, alice);
    alice.use(1, alice);
    std::cout << std::endl;

    std::cout << "=== Test 8 : Création de MateriaSource ===" << std::endl;
    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());
    std::cout << "Materias apprises avec succès." << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 9 : Création de Materias par MateriaSource ===" << std::endl;
    AMateria* newIce = source.createMateria("ice");
    AMateria* newCure = source.createMateria("cure");
    std::cout << "Type de newIce : " << newIce->getType() << std::endl;
    std::cout << "Type de newCure : " << newCure->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 10 : Utilisation de nouvelles Materias ===" << std::endl;
    bob.equip(newIce);
    bob.equip(newCure);
    bob.use(2, bob);
    bob.use(3, bob);
    std::cout << std::endl;

    std::cout << "=== Test 11 : Copie profonde de MateriaSource ===" << std::endl;
    MateriaSource sourceCopy;
    sourceCopy = source;
    AMateria* copiedIce = sourceCopy.createMateria("ice");
    AMateria* copiedCure = sourceCopy.createMateria("cure");
    std::cout << "Type de copiedIce : " << copiedIce->getType() << std::endl;
    std::cout << "Type de copiedCure : " << copiedCure->getType() << std::endl;
	std::cout << std::endl;

    std::cout << "=== Nettoyage de la mémoire ===" << std::endl;
    delete ice;
    delete cure;
    delete clonedIce;
    delete clonedCure;
    delete newIce;
    delete newCure;
    delete copiedIce;
    delete copiedCure;

    std::cout << "Tous les tests ont été exécutés avec succès !" << std::endl;
    return (0);
}*/

int main()
{
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    Character* Bob = new Character("BOb");
    Bob->equip(ice);
    Bob->equip(cure);
    Bob->equip(ice);
    Bob->equip(cure);

    Bob->unequip(1);
    Bob->unequip(3);

    Character alice("Alice");
    alice = *Bob;
    delete Bob;
    delete ice;
    delete cure;

}
