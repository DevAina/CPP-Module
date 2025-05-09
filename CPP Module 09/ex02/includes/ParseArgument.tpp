template <typename Container>
void	AddElement(std::string& element, Container& container)
{
	long	number;

	if (!element.empty())
	{
		number = atol(element.c_str());
		if (number > std::numeric_limits<int>::max())
			throw	std::invalid_argument("\e[31;1;21mError: Argument not valid. INT_MAX and is limit.\e[0m");
		int cast = static_cast<int>(number);

		container.push_back(cast);
		element.clear();
	}
}

template <typename Container>
void	ParseArgument(const char *arg, Container& container)
{
	std::string	currentNumber;

	for (int i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] == ' ')
		{
			AddElement(currentNumber, container);
			continue ;
		}
		if (isdigit(arg[i]))
			currentNumber += arg[i];
		else
			throw std::invalid_argument("\e[21;1;31mError: Argument must be digit and positive.\e[0m");
	}
	AddElement(currentNumber, container);
}

template <typename Container>
Container	ParseInput(const int& argc, char **argv)
{
	Container	container;
	for (int i = 1; i < argc; i++)
	{
		ParseArgument(argv[i], container);		
	}
	return (container);
}

