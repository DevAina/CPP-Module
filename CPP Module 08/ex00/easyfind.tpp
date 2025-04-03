template <typename T>
typename T::iterator    easyfind(T& containers, int nb)
{
    typename T::iterator    it = std::find(containers.begin(), containers.end(), nb);
    if (it == containers.end())
        throw std::out_of_range("\033[1;31mValue not found\033[0m");
    return (it);
}
