/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <sstannis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:48:50 by sstannis          #+#    #+#             */
/*   Updated: 2019/09/29 20:05:09 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

char	**ft_strarrdup(char **str)
{
	char	**res;
	size_t	len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	if (!(res = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int		ft_strarraylen(char **array)
{
	int res;

	res = 0;
	while (array[res])
		res++;
	return (res);
}

void	ft_strarrayfree(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	mult_error(t_stack **a, char **args)
{
	ft_stackfree(a);
	ft_strarrayfree(args);
	write(2, "Error : invalid parameters\n", 27);
	exit(1);
}

void	cmn_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
