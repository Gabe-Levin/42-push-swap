/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:40 by glevin            #+#    #+#             */
/*   Updated: 2024/10/01 16:45:42 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_int(const char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (i == ft_strlen(str))
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (1);
}

bool	check_single_input(char *raw_input)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(raw_input, ' ');
	while (str[i])
	{
		if (!is_int(str[i]))
			return (false);
		i++;
	}
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (true);
}

bool	validate_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		if (!check_single_input(argv[1]))
		{
			ft_printf("Error\n");
			return (false);
		}
	}
	else
	{
		while (++i < argc)
		{
			if (!is_int(argv[i]))
			{
				ft_printf("Error\n");
				return (false);
			}
		}
	}
	return (true);
}
